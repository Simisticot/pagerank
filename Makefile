all: pagerank clean

pagerank: tableaux.o matrices.o pagerank.c tableaux.h matrices.h
	gcc -O3 -march=native ggraphe.c tableaux.c matrices.c pagerank.c -o pagerank -lm

clean:
	rm ./*.o
