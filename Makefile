.POSIX:

CC = gcc
CFLAGS = -Ofast

rush: src/main.c
	rm -f rush
	$(CC) $(CFLAGS) src/main.c -o rush

run: 
	@$(CC) $(CLAGS) src/main.c -o rush
	@./rush
	@rm -f rush

clean:
	rm -f rush

.PHONY: clean run
