CC       = g++
CFLAG    = -W -Wall -ansi -pedantic
LDFLAGS  =
SOURCES  = src
BINARIES = bin

EXEC = ./tama


all: makeBIN
	g++ src/main.cpp -o $(EXEC) -L src/SFML -lsfml-graphics -lsfml-window -lsfml-system $(CFLAG)
	./$(EXEC)

makeBIN:
	@mkdir -p $(BINARIES)

clean:
	rm -f *.o

mrproper: clean
	rm -rf bin/
	rm -f exe
