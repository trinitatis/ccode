.PHONY: run rebuild clean 

CC = gcc
FLAGC = -Wall -Wextra -Werror -std=c11 -g
EXEC = a.out

all: main

main: main.o input.o output.o
	$(CC) $^ -o $(EXEC)

main.o: main.c
	$(CC) $(FLAGC) -c $^

input.o: input.c
	$(CC) $(FLAGC) -c $^

output.o: output.c
	$(CC) $(FLAGC) -c $^

rebuild: clean all

clean:
	rm -rf *.o $(EXEC)

run: rebuild
	./$(EXEC)