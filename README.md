# Pacman game C++ tutorial for game's assignment of Advance Programing Course

## Main game structure

- Engine: Contain all character, map. Control the game loop. In one loop, collect all 
charactor states and handle these. By these states, drawing all to the screen.

-  Pacman charactor: moving, eat, died
    -  Moving: Control by keyboard. Has velocity and directions. Check colision

- Map: load map from txt map. 