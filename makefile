################
#   Makefile   #
################

# Exécutables
EXTAMA  = tama
EXTEST  = test
DEFAULT = $(EXTEST)

#####################
#   Configuration   #
#####################

# Règle par défaut
default: makebin $(DEFAULT)

# Compilateur
CC      = g++
CFLAGS  = -W -Wall -ansi -pedantic

# Dossiers
BIN     = bin
SRC     = src
SUBDIR  = conf entities lib main menus

# Objets à créer par dossier
CONF    =
ENTI    = Food.o Object.o Pet.o User.o
LIB     = file.o types.o
MAIN    = tama.o
MENUS   = List.o Shop.o

# Principaux exécutables
SFML1   =
SFML2   = -lsfml-system -lsfml-graphics -lsfml-window
# SFML1   = -I./src/SFML/include
# SFML2   = -I./src/SFML/lib -lsfml-system -lsfml-graphics -lsfml-window

TAMA1   = src/main/tama.cpp $(SFML1) -o bin/tama.o
TAMA2   = bin/tama.o -o $(EXTAMA) $(SFML2)

# LTAMA   = $(CONF) $(ENTI) $(LIB)
# OTAMA   = $(addprefix $(BIN)/,$(LTAMA))

# Test
LTEST   = $(EXTEST).o $(CONF) $(ENTI) $(LIB)
OTEST   = $(addprefix $(BIN)/,$(LTEST))

# MKTAMA  = $(OTAMA)

#################
#   Variables   #
#################

# Choisit l'exécutable par défaut s'il n'y a pas d'argument
EXE = $(MAKECMDGOALS)
ifeq ($(EXE),)
	EXE = $(DEFAULT)
endif

# Récupère les dépendances selon l'exécutable choisi
ifeq ($(EXE),$(EXTAMA))
	DEP = $(TAMA)
else ifeq ($(EXE),$(EXTEST))
	DEP = $(OTEST)
endif

# Configuration du PATH
VPATH   = $(SRC)/%.cpp $(addprefix $(SRC)/,$(SUBDIR))

################
#   Compiler   #
################

# Compiler les .o
$(BIN)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

# Compiler et exécuter
$(EXE): cc$(EXE) FORCE
	./$(EXE)

# Compiler un exécutable
cc$(EXE): $(DEP)
	$(CC) $(CFLAGS) $^ -o $(EXE)

##########################
#   Compiler avec SFML   #
##########################

# Tamagotchi
tama: tamao cctama FORCE
	./$(EXE)

tamao:
	$(CC) -c $(TAMA1)

cctama:
	$(CC) $(TAMA2)


############################
#   Compiler par dossier   #
############################

# Objets de conf/
conf: $(CONF)

# Objets de entities/
entities: $(ENTI)

# Objets de lib/
lib: $(LIB)

# Objets de menu/
menus: $(MENUS)

################
#   Nettoyer   #
################

# Supprimer les .o
clean:
	rm -f $(BIN)/*.o

# Tout nettoyer
mrproper: clean
	rm -rf $(BIN)
	rm -f  $(EXTAMA)
	rm -f  $(EXTEST)

zero: mrproper

##############
#   Autres   #
##############

# Créer le dossier bin
makebin:
	mkdir -p $(BIN)

FORCE:
