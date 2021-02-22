all: task02

task02: task02.o smpl.o rand.o
	$(LINK.c) -o $@ -Bstatic task02.o smpl.o rand.o -lm

smpl.o: smpl.c smpl.h
	$(COMPILE.c)  -g smpl.c 

task02.o: task02.c smpl.h
	$(COMPILE.c) -g  task02.c

rand.o: rand.c
	$(COMPILE.c) -g rand.c

clean:
	$(RM) *.o task02 relat saida

