CC       = g++
CFLAG    = -W -Wall -ansi -pedantic
LDFLAGS  =
SOURCES  = src
BINARIES = bin

SRC  = $(wildcard $(SOURCES)/*.cpp)
OBJ  = $(addprefix $(BINARIES)/,$(notdir $(SRC:.cpp=.o)))
EXEC = exe


all: makeBIN $(EXEC)
	./$(EXEC)

exe: $(OBJ)
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
