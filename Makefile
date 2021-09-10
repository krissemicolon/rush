.POSIX:

CC = gcc
CFLAGS= -Wall

csh: src/main.c
	rm -f csh
	$(CC) $(CFLAGS) src/main.c -o csh

run: 
	@$(CC) $(CLAGS) src/main.c -o csh
	@./csh
	@rm -f csh

clean:
	rm -f csh

.PHONY: clean run