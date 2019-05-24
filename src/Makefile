CC=gcc
CFLAGS=-Wall
HFILES=shell.h
OBJ=main.o prompt.o exit.o commands.o signal.o changeDir.o redirect.o

all: shell

shell: $(OBJ)
	$(CC) $(CFLAGS) -o shell $(OBJ)

main.o: main.c $(HFILES)
	$(CC) $(CFLAGS) -c  main.c

prompt.o: prompt.c $(HFILES)
	$(CC) $(CFLAGS) -c prompt.c

exit.o: exit.c $(HFILES)
	$(CC) $(CFLAGS) -c exit.c

commands.o: commands.c $(HFILES)
	$(CC) $(CFLAGS) -c commands.c

signal.o: signal.c $(HFILES)
	$(CC) $(CFLAGS) -c signal.c

changeDir.o: changeDir.c $(HFILES)
	$(CC) $(CFLAGS) -c changeDir.c

redirect.o: redirect.c $(HFILES)
	$(CC) $(CFLAGS) -c redirect.c

clean: 
	$(RM) shell *.o *~
