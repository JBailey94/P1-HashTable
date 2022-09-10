CFLAGS = -g -Wall -Werror=return-type -Werror=uninitialized
CC = g++

OBJECTS = main.o FileProcessor.o PasswordGenerator.o HashTable.o
TESTS = t1-hashtable t2-passwordgenerator t3-fileprocessor
CATCH = test/catch/catch_amalgamated.o

# program related compilation
main: $(OBJECTS)
	$(CC) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $<

# RM is a implicit variable, make -p for more info
.PHONY : clean
clean: 
	$(RM) *.o test/*.o $(addprefix test/,$(TESTS)) main core rawdata.txt encrypteddata.txt

# test related compilation, $@ means target name, $^ targets dependencies
$(TESTS): $(CATCH)
	$(CC) $(CFLAGS) -o test/$@ $^
	test/$@ --success

test-all: $(TESTS)
t1-hashtable: test/t1-hashtable.cpp HashTable.o
t2-passwordgenerator: test/t2-passwordgenerator.cpp PasswordGenerator.o
t3-fileprocessor: test/t3-fileprocessor.cpp FileProcessor.o
