CC = gcc
CFLAGS = -Wall -Wextra

jogo: src/main.c src/campeoes.h src/casas.h
	$(CC) $(CFLAGS) src/main.c -o jogo

clean:
	rm -f jogo