.PHONY: run rebuild clean 

CC = gcc
FLAGC = -Wall -Wextra -Werror -std=c11 -g
EXEC = a.out

all: main

main: main.o
	$(CC) $^ -o $(EXEC)

main.o: main.c
	$(CC) $(FLAGC) -c $^

rebuild: clean all

clean:
	rm -rf *.o $(EXEC)

run: rebuild
	./$(EXEC)