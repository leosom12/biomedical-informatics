all: task01

task01: task01.o smpl.o rand.o
	$(LINK.c) -o $@ -Bstatic task01.o smpl.o rand.o -lm

smpl.o: smpl.c smpl.h
	$(COMPILE.c)  -g smpl.c 

task01.o: task01.c smpl.h
	$(COMPILE.c) -g  task01.c

rand.o: rand.c
	$(COMPILE.c) -g rand.c

clean:
	$(RM) *.o task01 relat saida

