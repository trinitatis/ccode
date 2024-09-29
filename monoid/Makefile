.PHONY: run rebuild clean 

CC = gcc
FLAGC = -Wall -Wextra -Werror -std=c11 -g
EXEC = a.out

all: main

# --------------------------------
main: monoid_str.o
	$(CC) $^ -o $(EXEC)
monoid_str.o: monoid_str.c
	$(CC) $(FLAGC) -c $^
# --------------------------------

rebuild: clean all

clean:
	rm -rf *.o $(EXEC)

run: rebuild
	./$(EXEC)