all: task03

task03: task03.o smpl.o rand.o
	$(LINK.c) -o $@ -Bstatic task03.o smpl.o rand.o -lm

smpl.o: smpl.c smpl.h
	$(COMPILE.c)  -g smpl.c 

task03.o: task03.c smpl.h
	$(COMPILE.c) -g  task03.c

rand.o: rand.c
	$(COMPILE.c) -g rand.c

clean:
	$(RM) *.o task03 relat saida

