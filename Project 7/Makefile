# Links all files to an executable
project7.exe: main.o
	g++ player.o monster.o game.o main.o -o project7.exe

# Compile main with dependencies for the game, player, and monster files
main.o: game.o player.o monster.o
	g++ -c main.cpp -o main.o

# Compile game with its file as a dependency
game.o: game.cpp
	g++ -c game.cpp -o game.o

# Compile player with its file as a dependency
player.o: player.cpp
	g++ -c player.cpp -o player.o

# Compile monster with its file as a dependency
monster.o: monster.cpp
	g++ -c monster.cpp -o monster.o

# Removes all object and executable files
# Command is: make clean
clean:
	rm *.o
	rm *.exe