DROP TABLE IF EXISTS CERTIFICADO, VOO, AERONAVE, FUNCIONARIO;


-- 1. Encontre os nomes das aeronaves tais que TODOS os pilotos certificados para operá-las
-- ganhem mais do que $80.000.

	SELECT nomeAero
    FROM AERONAVE a
    WHERE NOT EXISTS (
		SELECT *
        FROM CERTIFICADO c NATURAL JOIN FUNCIONARIO f
        WHERE c.idAero = a.idAero AND salario <= 80000);   


-- 2. Para cada piloto que é certificado para mais do que três aeronaves, encontre o idFuncion
-- e a distLimite máxima das aeronaves para as quais ele ou ela é certificado.
	
	SELECT c.idFuncion, MAX(distLimite) as distLimiteMax
    FROM CERTIFICADO c NATURAL JOIN AERONAVE a
    GROUP BY c.idFuncion
    HAVING COUNT(*) > 3;
    
    

-- 3. Encontre os nomes dos pilotos cujos salários são menores do que o preço da rota mais
-- barata de Los Angeles a Honolulu.

	SELECT f.nomeFuncion
    FROM FUNCIONARIO f
    WHERE f.salario < (SELECT min(preco)
					   FROM VOO
                       WHERE origem = 'Los Angeles' AND destino = 'Honolulu');

-- 4. Para todas as aeronaves com distLimite maior do que 1.000 milhas, encontre o nome da
-- aeronave e o salário médio de todos os pilotos certificados para essa aeronave.

	SELECT nomeAero, avg(f.salario) as salarioMedio
    FROM AERONAVE a, FUNCIONARIO f, CERTIFICADO c
    WHERE a.idAero = c.idAero AND f.idFuncion = c.idFuncion AND a.distLimite > 1000
    GROUP BY a.idAero;
    
-- 5. Encontre os nomes dos pilotos certificados para alguma aeronave Boeing.

	SELECT nomeFuncion
    FROM CERTIFICADO c, AERONAVE a, FUNCIONARIO f
    WHERE c.idAero=a.idAero AND f.idFuncion=c.idFuncion AND nomeAero LIKE 'Boeing%';

-- 6. Encontre os idAeros de todas as aeronaves que podem ser usadas nas rotas de Los Angeles
-- a Chicago.

	SELECT idAero
    FROM AERONAVE a
    WHERE a.distLimite > (SELECT distancia
						  FROM VOO
                          WHERE origem = 'Los Angeles' AND destino = 'Chicago');

-- 7. Identifique as rotas que podem ser pilotadas por todo piloto que ganha mais do que
-- $100.000.

	SELECT DISTINCT origem, destino
    FROM VOO, FUNCIONARIO
    WHERE salario > 100000;

-- 8. Imprima os nomeFuncions dos pilotos que podem operar aeronaves com distLimite maior
-- do que 3.000 milhas, mas que não são certificados em nenhuma aeronave Boeing.

	SELECT DISTINCT nomeFuncion
    FROM FUNCIONARIO f, AERONAVE a, CERTIFICADO c
    WHERE f.idFuncion=c.idFuncion AND a.idAero=c.idAero AND distLimite > 3000 AND
		f.idFuncion NOT IN (SELECT c2.idFuncion
					FROM FUNCIONARIO f2, CERTIFICADO c2
                    WHERE f2.idFuncion=c2.idFuncion AND a.nomeAero LIKE 'Boeing%');

	SELECT DISTINCT nomeFuncion
    FROM FUNCIONARIO f, CERTIFICADO c1, AERONAVE a1
    WHERE f.idFuncion=c1.idFuncion AND c1.idAero=a1.idAero AND f.idFuncion NOT IN (
		SELECT c.idFuncion
        FROM CERTIFICADO c NATURAL JOIN AERONAVE a
        WHERE distLimite > 3000 AND nomeAero LIKE 'Boeing%');
        
-- 9. Um cliente deseja viajar de Madison a New York com no máximo UMA escala de vôo.
-- Liste a escolha de horários de partida de Madison se o cliente quer chegar em New York
-- antes de 18 h.

-- 10. Compute a diferença entre o salário médio de um piloto e o salário médio de todos os
-- funcionários (incluindo os pilotos).

	SELECT
		(SELECT AVG(salario) FROM FUNCIONARIO WHERE idFuncion IN (SELECT idFuncion FROM CERTIFICADO)) -
        (SELECT AVG(salario) FROM FUNCIONARIO AS diferenca_salario_piloto_funcionario);

-- 11. imprima o nome e o salário de todo não piloto cujo salário é maior do que o salário médio
-- dos pilotos.

	SELECT nomeFuncion, salario
    FROM FUNCIONARIO
    WHERE idFuncion NOT IN (SELECT idFuncion
							FROM CERTIFICADO)
	AND salario > (SELECT avg(salario)
				   FROM FUNCIONARIO
                   WHERE idFuncion IN (SELECT idFuncion
									   FROM CERTIFICADO));
                                       
    
-- 12. Imprima os nomes dos funcionários que são certificados APENAS em aeronaves com dis-
-- tância limite maior do que 1.000 milhas.

	SELECT DISTINCT nomeFuncion
    FROM AERONAVE A, CERTIFICADO C, FUNCIONARIO F
    WHERE A.idAero = C.idAero AND C.idFuncion = F.idFuncion  AND A.distLimite > 1000 AND
		NOT EXISTS (SELECT *
					FROM AERONAVE A2, CERTIFICADO C2
                    WHERE A2.idAero = C2.idAero AND F.idFuncion = C2.idFuncion AND A2.distLimite <= 1000);

-- 13. Imprima os nomes dos funcionários que são certificados apenas em aeronaves com distân-
-- cia limite maior do que 1.000 milhas, mas que sejam certificados para, no mínimo, duas
-- aeronaves desse tipo.

	SELECT DISTINCT nomeFuncion
    FROM AERONAVE A, CERTIFICADO C, FUNCIONARIO F
    WHERE A.idAero = C.idAero AND C.idFuncion = F.idFuncion  AND A.distLimite > 1000 AND
		NOT EXISTS (SELECT *
					FROM AERONAVE A2, CERTIFICADO C2
                    WHERE A2.idAero = C2.idAero AND F.idFuncion = C2.idFuncion AND A2.distLimite <= 1000 AND 
						EXISTS (SELECT C.idFuncion, COUNT(*)
								FROM CERTIFICADO C
                                GROUP BY C.idFuncion
                                HAVING COUNT(*) > 1));

-- 14. Imprima os nomes dos funcionários que são certificados apenas em aeronaves com distância
-- limite maior do que 1.000 milhas e que são certificados em alguma aeronave Boeing.











CREATE TABLE VOO(
	nroVoo INTEGER PRIMARY KEY,
	origem VARCHAR(20),
	destino VARCHAR(20),
	distancia INTEGER,
	partida TIMESTAMP,
	chegada TIMESTAMP,
	preco DECIMAL(7,2)
);

CREATE TABLE AERONAVE(
	idAero INTEGER PRIMARY KEY,
	nomeAero VARCHAR(30),
	distLimite INTEGER
);

CREATE TABLE FUNCIONARIO(
	idFuncion INTEGER PRIMARY KEY,
	nomeFuncion VARCHAR(30),
	salario INTEGER
);

CREATE TABLE CERTIFICADO(
	idFuncion INTEGER,
	idAero INTEGER,
	PRIMARY KEY(idFuncion,idAero),
	FOREIGN KEY(idFuncion) REFERENCES FUNCIONARIO(idFuncion),
	FOREIGN KEY(idAero) REFERENCES AERONAVE(idAero)
);

INSERT INTO VOO(nroVoo, origem, destino, distancia, partida, chegada, preco) VALUES (99,'Los Angeles','Washington D.C.',2308,'2005/04/12 09:30','2005/04/12 21:40',235.98), (13,'Los Angeles','Chicago',1749,'2005/04/12 08:45','2005/04/12 20:45',220.98), (346,'Los Angeles','Dallas',1251,'2005/04/12 11:50','2005/04/12 19:05',225.43), (387,'Los Angeles','Boston',2606,'2005/04/12 07:03','2005/04/12 17:03',261.56), (7,'Los Angeles','Sydney',7487,'2005/04/12 22:30','2005/04/14 6:10',1278.56), (2,'Los Angeles','Tokyo',5478,'2005/04/12 12:30','2005/04/13 15:55',780.99), (33,'Los Angeles','Honolulu',2551,'2005/04/12 09:15','2005/04/12 11:15',375.23), (34,'Los Angeles','Honolulu',2551,'2005/04/12 12:45','2005/04/12 15:18',425.98), (76,'Chicago','Los Angeles',1749,'2005/04/12 08:32','2005/04/12 10:03',220.98), (68,'Chicago','New York',802,'2005/04/12 09:00','2005/04/12 12:02',202.45), (7789,'Madison','Detroit',319,'2005/04/12 06:15','2005/04/12 08:19',120.33), (701,'Detroit','New York',470,'2005/04/12 08:55','2005/04/12 10:26',180.56), (702,'Madison','New York',789,'2005/04/12 07:05','2005/04/12 10:12',202.34), (4884,'Madison','Chicago',84,'2005/04/12 22:12','2005/04/12 23:02',112.45), (2223,'Madison','Pittsburgh',517,'2005/04/12 08:02','2005/04/12 10:01',189.98), (5694,'Madison','Minneapolis',247,'2005/04/12 08:32','2005/04/12 09:33',120.11), (304,'Minneapolis','New York',991,'2005/04/12 10:00','2005/04/12 1:39',101.56),(149,'Pittsburgh','New York',303,'2005/04/12 09:42','2005/04/12 12:09',116.50);
INSERT INTO AERONAVE(idAero, nomeAero,	distLimite) VALUES (1,'Boeing 747-400',8430), (2,'Boeing 737-800',3383), (3,'Airbus A340-300',7120), (4,'British Aerospace Jetstream 41',1502), (5,'Embraer ERJ-145',1530), (6,'SAAB 340',2128), (7,'Piper Archer III',520), (8,'Tupolev 154',4103), (16,'Schwitzer 2-33',30), (9,'Lockheed L1011',6900), (10,'Boeing 757-300',4010), (11,'Boeing 777-300',6441), (12,'Boeing 767-400ER',6475), (13,'Airbus A320',2605), (14,'Airbus A319',1805), (15,'Boeing 727',1504);
INSERT INTO FUNCIONARIO(idFuncion, nomeFuncion,	salario) VALUES (242518965,'James Smith',120433), (141582651,'Mary Johnson',178345), (011564812,'John Williams',153972), (567354612,'Lisa Walker',256481), (552455318,'Larry West',101745), (550156548,'Karen Scott',205187), (390487451,'Lawrence Sperry',212156), (274878974,'Michael Miller',99890), (254099823,'Patricia Jones',24450), (356187925,'Robert Brown',44740), (355548984,'Angela Martinez',212156), (310454876,'Joseph Thompson',212156), (489456522,'Linda Davis',127984), (489221823,'Richard Jackson',23980), (548977562,'William Ward',84476), (310454877,'Chad Stewart',33546), (142519864,'Betty Adams',227489), (269734834,'George Wright',289950), (287321212,'Michael Miller',48090), (552455348,'Dorthy Lewis',92013), (248965255,'Barbara Wilson',43723), (159542516,'William Moore',48250), (348121549,'Haywood Kelly',32899), (090873519,'Elizabeth Taylor',32021), (486512566,'David Anderson',743001), (619023588,'Jennifer Thomas',54921), (015645489,'Donald King',18050), (556784565,'Mark Young',205187), (573284895,'Eric Cooper',114323), (574489456,'William Jones',105743), (574489457,'Milo Brooks',20);
INSERT INTO CERTIFICADO(idFuncion, idAero) VALUES (567354612,1),(567354612,2), (567354612,10), (567354612,11), (567354612,12), (567354612,15), (567354612,7), (567354612,9), (567354612,3), (567354612,4), (567354612,5), (552455318,2), (552455318,14), (550156548,1), (550156548,12), (390487451,3), (390487451,13), (390487451,14), (274878974,10), (274878974,12), (355548984,8), (355548984,9), (310454876,8), (310454876,9), (548977562,7), (142519864,1), (142519864,11), (142519864,12), (142519864,10), (142519864,3), (142519864,2), (142519864,13), (142519864,7), (269734834,1), (269734834,2), (269734834,3), (269734834,4), (269734834,5), (269734834,6), (269734834,7), (269734834,8), (269734834,9), (269734834,10), (269734834,11), (269734834,12), (269734834,13), (269734834,14), (269734834,15), (552455318,7), (556784565,5), (556784565,2), (556784565,3), (573284895,3), (573284895,4), (573284895,5), (574489456,8), (574489456,6), (574489457,7), (242518965,2), (242518965,10), (141582651,2), (141582651,10), (141582651,12), (011564812,2), (011564812,10), (356187925,6), (159542516,5), (159542516,7), (090873519,6);
