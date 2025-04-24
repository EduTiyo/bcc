CC=gcc

P1=ex01
P2=ex02

FLAGS=-lm -lpthread

PROGS=$(P1) $(P2)

all: $(PROGS)

$(P1): $(P1).c
	$(CC) $(P1).c -o $(P1)

$(P2): $(P2).c
	$(CC) $(P2).c -o $(P2) $(FLAGS)

clean:
	rm $(PROGS)