CC = g++
CFLAGS = -Wall -std=c++11
OBJ = main.o vigenere.o

all: VigenereCipher

VigenereCipher: $(OBJ)
	$(CC) $(CFLAGS) -o VigenereCipher $(OBJ)

main.o: main.cpp vigenere.h
	$(CC) $(CFLAGS) -c main.cpp

vigenere.o: vigenere.cpp vigenere.h
	$(CC) $(CFLAGS) -c vigenere.cpp

clean:
	rm -f *.o VigenereCipher

