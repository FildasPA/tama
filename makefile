CC       = g++
CFLAG    = -W -Wall -ansi -pedantic
LDFLAGS  =
SOURCES  = src
BINARIES = bin
SRC = $(wildcard $(SOURCES)/*.cpp)
OBJ = $(addprefix $(BINARIES)/,$(notdir $(SRC:.cpp=.o)))

EXEC = ./tama

all: makeBIN
	g++ src/main.cpp -o $(EXEC) -L src/SFML -lsfml-graphics -lsfml-window -lsfml-system $(CFLAG)
	./$(EXEC)

test: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BINARIES)/%.o: $(SOURCES)/%.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

makeBIN:
	@mkdir -p $(BINARIES)

clean:
	rm -f *.o

mrproper: clean
	rm -rf bin/
	rm -f exe
