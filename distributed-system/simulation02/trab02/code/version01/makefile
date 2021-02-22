all: version01

version01: version01.o smpl.o rand.o
	$(LINK.c) -o $@ -Bstatic version01.o smpl.o rand.o -lm

smpl.o: smpl.c smpl.h
	$(COMPILE.c)  -g smpl.c 

version01.o: version01.c smpl.h
	$(COMPILE.c) -g  version01.c

rand.o: rand.c
	$(COMPILE.c) -g rand.c

clean:
	$(RM) *.o version01 relat saida

