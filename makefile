GAME_C = src/game.cpp
EDITOR_C = src/editor.cpp
MAP_C = src/map.cpp
PLAYER_C = src/player.cpp

GAME_OUT = bin/game.out
EDITOR_OUT = bin/editor.out
MAP_O = bin/map.o
PLAYER_O = bin/player.o

run: $(GAME_OUT)
	./$(GAME_OUT)

editor: $(EDITOR_OUT)
	./$(EDITOR_OUT)

test: $(MAP_O)
	g++ tests/create_map.cpp $(MAP_O) -o bin/create_map.out

clean:
	rm bin/*

SFML = -lsfml-graphics -lsfml-window -lsfml-system

$(GAME_OUT): $(GAME_C) $(MAP_O) $(PLAYER_O)
	g++ $(GAME_C) $(MAP_O) $(PLAYER_O) -o $(GAME_OUT) $(SFML)

$(EDITOR_OUT): $(EDITOR_C) $(MAP_O)
	g++ $(EDITOR_C) $(MAP_O) -o $(EDITOR_OUT) $(SFML)

$(MAP_O): $(MAP_C)
	g++ $(MAP_C) -c -o $(MAP_O)

$(PLAYER_O): $(PLAYER_C)
	g++ $(PLAYER_C) -c -o $(PLAYER_O)