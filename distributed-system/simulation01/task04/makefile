all: task04

task04: task04.o smpl.o rand.o
	$(LINK.c) -o $@ -Bstatic task04.o smpl.o rand.o -lm

smpl.o: smpl.c smpl.h
	$(COMPILE.c)  -g smpl.c 

task04.o: task04.c smpl.h
	$(COMPILE.c) -g  task04.c

rand.o: rand.c
	$(COMPILE.c) -g rand.c

clean:
	$(RM) *.o task04 relat saida

