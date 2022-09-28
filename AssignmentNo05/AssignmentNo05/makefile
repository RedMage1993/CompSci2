# Make file for compound interest program

OBJS = main.o compoundInterestImp.o
CC	= g++
DEPS = compoundInterest.h

all: main

main: $(OBJS)
	$(CC) -o main $(OBJS)

main.o:	main.cpp $(DEPS)
	$(CC) -c main.cpp

TicTacToeImp.o: compoundInterestImp.cpp $(DEPS)
	$(CC) -c compoundInterestImp.cpp

# -----
# clean by removing object files.

clean:
	rm $(OBJS)

