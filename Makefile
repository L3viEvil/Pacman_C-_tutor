LIBFLAGS = -lSDL2 -lSDL2_image
SRC = ./src/cpp
HEADER = ./src/header

output: main.o Engine.o Pacman.o Map.o LTexture.o
	g++ main.o Engine.o Pacman.o Map.o LTexture.o -o output $(LIBFLAGS)

Pacman.o: $(SRC)/Pacman.cpp 
	g++ -c $(SRC)/Pacman.cpp -I $(HEADER)

LTexture.o: $(SRC)/LTexture.cpp 
	g++ -c $(SRC)/LTexture.cpp -I $(HEADER)

Map.o: $(SRC)/Map.cpp 
	g++ -c $(SRC)/Map.cpp -I $(HEADER)

Engine.o: $(SRC)/Engine.cpp 
	g++ -c $(SRC)/Engine.cpp -I $(HEADER)

main.o: $(SRC)/main.cpp
	g++ -c -g $(SRC)/main.cpp -I $(HEADER) 
