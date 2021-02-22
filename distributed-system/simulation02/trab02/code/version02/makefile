all: version02

version02: version02.o smpl.o rand.o
	$(LINK.c) -o $@ -Bstatic version02.o smpl.o rand.o -lm

smpl.o: smpl.c smpl.h
	$(COMPILE.c)  -g smpl.c 

version02.o: version02.c smpl.h
	$(COMPILE.c) -g  version02.c

rand.o: rand.c
	$(COMPILE.c) -g rand.c

clean:
	$(RM) *.o version02 relat saida

