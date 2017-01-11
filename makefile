################
#   Makefile   #
################

# Exécutables
EXETAMA  = tama
EXESFML  = sfml2
EXETEST  = test
DEFAULT  = $(EXESFML)

#####################
#   Configuration   #
#####################

# Compilateur & options
CC      = g++
CFLAGS  = -W -Wall -ansi -pedantic

# Dossiers
BIN     = bin
SRC     = src
SUBDIR  = conf entities lib main menus
SAVES   = saves

# Objets à créer par dossier
CONF    = files_names.o
ENTI    = Food.o Object.o Pet.o User.o
LIB     = file.o types.o colors.o
MAIN    = tama.o
MENUS   = List.o Shop.o

# Bibliothèques SFML
SFMLL  = -lsfml-system -lsfml-graphics -lsfml-window

###################
#   Dépendances   #
###################

# Définit les dépendances pour tama
LTAMA = $(EXETAMA).o
DTAMA = $(addprefix $(BIN)/,$(LTAMA))

# Définit les dépendances pour sfml
LSFML = $(EXESFML).o
DSFML = $(addprefix $(BIN)/,$(LSFML))

# Définit les dépendances pour test
LTEST = $(EXETEST).o $(CONF) $(ENTI) $(LIB)
DTEST = $(addprefix $(BIN)/,$(LTEST))

#################
#   Variables   #
#################

# Choisit l'exécutable par défaut s'il n'y a pas d'argument
EXE = $(MAKECMDGOALS)
ifeq ($(strip $(EXE)),)
	EXE = $(DEFAULT)
endif

# Définit la règle de compilation à appeler selon l'exécutable choisi,
# c'est-à-dire le type de compilation à effectuer (sfml ou normal).
# Récupère également les dépendances correspondantes.
RULE = N$(EXE)
ifeq ($(EXE),$(EXETAMA))
	DEP  = $(DTAMA)
else ifeq ($(EXE),$(EXETEST))
	DEP = $(DTEST)
else ifeq ($(EXE),$(EXESFML))
	DEP  = $(DSFML)
	RULE = S$(EXE)
endif

$(info dépendances $(DEP))

# Configuration du PATH
VPATH   = $(SRC)/%.cpp $(addprefix $(SRC)/,$(SUBDIR))

########################
#   Règle principale   #
########################

$(EXE): makedir $(RULE)
	./$(EXE)

#################################
#   Compilation (normale) (N)   #
#################################

# Compiler les .o
$(BIN)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

# Compiler et exécuter
N$(EXE): CC$(EXE) ;

# Compiler un exécutable
CC$(EXE): $(DEP)
	-$(CC) $(CFLAGS) $^ -o $(EXE)

###########################
#   Compilation SFML (F)  #
###########################

# Tamagotchi
S$(EXE): makedir SF$(EXE) ;

SF$(EXE):
	$(CC) -c $(SRC)/main/$(EXE).cpp -o $(BIN)/$(EXE).o
	$(CC) $(BIN)/$(EXE).o -o $(EXE) $(SFMLL)

################
#   Nettoyer   #
################

# Supprimer les .o
clean:
	rm -f $(BIN)/*.o

# Tout nettoyer
mrproper: clean
	rm -rf $(BIN)
	rm -f  $(EXETAMA)
	rm -f  $(EXETEST)
	rm -f  $(EXESFML)

zero: mrproper

##############
#   Autres   #
##############

# Créer les dossiers nécessaires
makedir:
	mkdir -p $(BIN)
	mkdir -p $(SAVES)

FORCE:
