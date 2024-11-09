CC = gcc
CFLAGS = -Wall -pthread -std=c99
OBJ = main.o input.o threads.o results.o cleanup.o sync.o
EXEC = mssv

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC)

main.o: main.c input.h threads.h results.h cleanup.h sync.h
	$(CC) $(CFLAGS) -c main.c

input.o: input.c input.h
	$(CC) $(CFLAGS) -c input.c

threads.o: threads.c threads.h sync.h
	$(CC) $(CFLAGS) -c threads.c

results.o: results.c results.h
	$(CC) $(CFLAGS) -c results.c

cleanup.o: cleanup.c cleanup.h
	$(CC) $(CFLAGS) -c cleanup.c

sync.o: sync.c sync.h
	$(CC) $(CFLAGS) -c sync.c

clean:
	rm -f $(EXEC) $(OBJ)

