all: pagerank clean

pagerank: tableaux.o matrices.o pagerank.c tableaux.h matrices.h
	gcc tableaux.c matrices.c pagerank.c -o pagerank

clean:
	rm ./*.o