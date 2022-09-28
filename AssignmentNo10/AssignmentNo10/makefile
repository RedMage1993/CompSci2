# Make file for ast10.

OBJS = main.o
CC	= g++

all: main

main: $(OBJS)
	$(CC) -g -o main $(OBJS)

main.o:	main.cpp
	$(CC) -c -g main.cpp

# -----
# clean by removing object files.

clean:
	rm	$(OBJS)

