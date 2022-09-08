CFLAGS = -g -Wall -Werror=return-type -Werror=uninitialized
CC = g++

OBJECTS = main.o FileProcessor.o PasswordGenerator.o HashTable.o
TESTS = t1-hashtable t1-passwordgenerator
CATCH = test/catch/catch_amalgamated.o

# program related compilation
main: $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

# RM is a implicit variable, make -p for more info
.PHONY : clean
clean: 
	$(RM) *.o test/*.o $(addprefix test/,$(TESTS)) main core

# test related compilation, $@ means target name, $^ targets dependencies
$(TESTS): $(CATCH)
	$(CC) $(CFLAGS) -o test/$@ $^
	test/$@ --success

test-all: $(TESTS)
t1-hashtable: test/t1-hashtable.cpp HashTable.o
t1-passwordgenerator: test/t1-passwordgenerator.cpp PasswordGenerator.o

