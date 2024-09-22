.PHONY: run rebuild clean 

CC = gcc
FLAGC = -Wall -Wextra -Werror -std=c11
EXEC = a.out

all: main

main: main.o
	$(CC) $^ -o $(EXEC)

main.o: main.c
	$(CC) $(FLAGC) -c $^

rebuild: clean all

clean:
	rm *.o $(EXEC)

run: rebuild
	./$(EXEC)