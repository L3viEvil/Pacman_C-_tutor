LIBFLAGS = -L. -lSDL2 -lSDL2_image
SRC = ./src/cpp
HEADER = ./src/header

output: main.o Engine.o Pacman.o Map.o
	g++ main.o Engine.o -o output #$(LIBFLAGS)

Pacman.o: $(SRC)/Pacman.cpp 
	g++ -c $(SRC)/Pacman.cpp -I $(HEADER)

Map.o: $(SRC)/Map.cpp 
	g++ -c $(SRC)/Map.cpp -I $(HEADER)

Engine.o: $(SRC)/Engine.cpp 
	g++ -c $(SRC)/Engine.cpp -I $(HEADER)

main.o: $(SRC)/main.cpp
	g++ -c -g $(SRC)/main.cpp -I $(HEADER) 
