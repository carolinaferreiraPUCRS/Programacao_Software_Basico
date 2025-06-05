
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

OBJS = diretores.o filmes.o atores.o

all: app1 app2 app3

app1: app1.c $(OBJS)
	$(CC) $(CFLAGS) -o app1 app1.c $(OBJS)

app2: app2.c $(OBJS)
	$(CC) $(CFLAGS) -o app2 app2.c $(OBJS)

app3: app3.c $(OBJS)
	$(CC) $(CFLAGS) -o app3 app3.c $(OBJS)

diretores.o: diretores.c diretores.h
	$(CC) $(CFLAGS) -c diretores.c

filmes.o: filmes.c filmes.h diretores.h
	$(CC) $(CFLAGS) -c filmes.c

atores.o: atores.c atores.h
	$(CC) $(CFLAGS) -c atores.c

clean:
	rm -f *.o app1 app2 app3
