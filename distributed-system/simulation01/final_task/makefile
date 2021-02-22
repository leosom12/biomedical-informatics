all: final_task

final_task: final_task.o smpl.o rand.o
	$(LINK.c) -o $@ -Bstatic final_task.o smpl.o rand.o -lm

smpl.o: smpl.c smpl.h
	$(COMPILE.c)  -g smpl.c 

final_task.o: final_task.c smpl.h
	$(COMPILE.c) -g  final_task.c

rand.o: rand.c
	$(COMPILE.c) -g rand.c

clean:
	$(RM) *.o final_task relat saida

