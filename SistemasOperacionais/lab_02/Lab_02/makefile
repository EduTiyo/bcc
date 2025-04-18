CC=gcc -Wall

P1=ex1
P2=ex2
P3=ex3
P4=ex4

PROGS=$(P1) $(P2) $(P3) $(P4)

.PHONY: all clean

all: $(PROGS)

$(P1):	$(P1).c
	$(CC) $(P1).c -o $(P1)
	
$(P2):	$(P2).c
	$(CC) $(P2).c -o $(P2)
	
$(P3):	$(P3).c
	$(CC) $(P3).c -o $(P3)
	
$(P4):	$(P4).c
	$(CC) $(P4).c -o $(P4)


clean:
	rm -f $(PROGS)