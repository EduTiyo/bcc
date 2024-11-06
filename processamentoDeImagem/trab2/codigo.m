entrada = imread("pollen.jpg");
figure(1);
imshow(entrada);
saida = zeros(2,889);
saida = entrada;
vetor = zeros(1, 256);

#imagem 1 imagem poderia ter mais contraste, areas com sombras que seriam intensas estao com um cinza um pouco mais claro do que o desejado
#r1 = 90;
#s1 = 45;
#r2 = 140;
#s2 = 210;

#imagem 2 contraste equilibrado, parece ser o mais apropriado
r1 = 100;
s1 = 55;
r2 = 150;
s2 = 220;

#imagem 3 contraste um pouco acentuado demais. regioes sombreadas perderam detalhamento
r1 = 110;
s1 = 65;
r2 = 160;
s2 = 230;

m1 = (s1-0)/(r1-0);
m2 = (s2-s1)/(r2-r1);
m3 = (255-s2)/(255-r2);

for i = 1:91
  vetor(i) = m1*(i-0);
  i+=1;
endfor

for ii = 92:141
  vetor(ii) = s1 + m2*(ii-r1);
  ii+=1;
endfor

for iii = 142:256
   vetor(iii) = s2 + m3*(iii-r2);
   iii+=1;
endfor

figure(2);
plot(0:255, vetor);

for i = 1:889
  for j = 1:889
    saida(i,j) = vetor(entrada(i,j));
  endfor
endfor

figure(3);
imshow(saida);

imwrite(saida, "imgSaida.tif");


