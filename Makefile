CFLAGS = -g -Wall 
CC = g++

objects = Main.o FileProcessor.o PasswordGenerator.o HashTable.o

main: $(objects)
	$(CC) -o Main $(objects)

HashTable.o : HashTable.cpp
FileProcessor.o : FileProcessor.h FileProcessor.cpp
PasswordGenerator.o : PasswordGenerator.h PasswordGenerator.cpp
Main.o : Main.cpp

.PHONY : clean
clean: 
	rm Main $(objects)