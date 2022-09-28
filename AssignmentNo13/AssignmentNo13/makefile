# fritz ammon
# cs202 section 1002
# assignment 13
# makefile

# -----
# compile the source code

all: stackTest eval

stackTest: stackTest.o				# depends on stackTest.o
	g++ stackTest.o -o stackTest		# create stackTest executable

stackTest.o: stackTest.cpp linkedStack.h	# depends on stackTest.cpp linkedStack.h
	g++ -c stackTest.cpp -o stackTest.o	# create object file named stackTest.o

eval: eval.o					# depends on eval.o
	g++ eval.o -o eval			# create eval executable

eval.o:	eval.cpp				# depends on eval.cpp
	g++ -c eval.cpp -o eval.o		# create object file named eval.o

# -----
# clean by removing object files.

.PHONY : clean					# in case there is a clean file

clean:
	rm *.o					# remove all with .o extension