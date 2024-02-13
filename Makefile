CC=gcc

all: my_graph my_Knapsack

my_graph: my_graph.c my_mat.o
	$(CC) -Wall -g -o my_graph my_graph.c my_mat.o

my_mat.o: my_mat.c my_mat.h 
	$(CC) -c my_mat.c

my_Knapsack: my_Knapsack.c
	$(CC) -Wall -g -o my_Knapsack my_Knapsack.c

valgrind:
	valgrind --leak-check=full ./my_graph
	
.PHONY: clean valgrind
	
clean:
	rm -f *.o *.a *.so my_graph my_Knapsack
