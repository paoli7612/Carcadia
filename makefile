GAME_C = src/game.cpp
GAME_OUT = bin/game.out

EDITOR_C = src/editor.cpp
EDITOR_OUT = bin/editor.out

LOOP_C = src/loop.cpp
LOOP_O = bin/loop.o

MAP_C = src/map.cpp
MAP_O = bin/map.o

PLAYER_C = src/player.cpp
PLAYER_O = bin/player.o

MAP_PRINT_OUT = bin/map_print.out
MAP_NEW_OUT = bin/map_new.out
MAP_DELETE_OUT = bin/map_delete.out
MAP_DOOR_OUT = bin/map_door.out

SFML = -lsfml-graphics -lsfml-window -lsfml-system

game: $(GAME_OUT)
	./$(GAME_OUT)

editor: $(EDITOR_OUT)
	./$(EDITOR_OUT) $(map)

# make map_print map="spawn"
map_print: $(MAP_PRINT_OUT)
	./$(MAP_PRINT_OUT) $(map)

# make map_new map="home"
map_new: $(MAP_NEW_OUT)
	./$(MAP_NEW_OUT) $(map)

# make map_delete map="home"
map_delete: $(MAP_DELETE_OUT)
	./$(MAP_DELETE_OUT) $(map)

# max map_door map="spawn"
map_door: $(MAP_DOOR_OUT)
	./$(MAP_DOOR_OUT) $(map)

$(MAP_PRINT_OUT): $(MAP_O)
	g++ tests/map_print.cc $(MAP_O) -o $(MAP_PRINT_OUT)

$(MAP_NEW_OUT): $(MAP_O)
	g++ tests/map_new.cc $(MAP_O) -o $(MAP_NEW_OUT)

$(MAP_DELETE_OUT): $(MAP_O)
	g++ tests/map_delete.cc $(MAP_O) -o $(MAP_DELETE_OUT)

$(MAP_DOOR_OUT): $(MAP_O)
	g++ tests/map_door.cc $(MAP_O) -o $(MAP_DOOR_OUT)

test: $(MAP_O)
	g++ tests/test_map.cc $(MAP_O) -o bin/test_map.out
	g++ tests/test_map_door.cc $(MAP_O) -o bin/test_map_door.out
	g++ tests/test_map_tile.cc $(MAP_O) -o bin/test_map_tile.out
	g++ tests/test_map_read.cc $(MAP_O) -o bin/test_map_read.out

clean: 
	rm bin/*.o bin/*out

$(GAME_OUT): $(GAME_C) $(MAP_O) $(LOOP_O) $(PLAYER_O)
	g++ $(GAME_C) $(MAP_O) $(LOOP_O) $(PLAYER_O) -o $(GAME_OUT) $(SFML)

$(EDITOR_OUT): $(EDITOR_C) $(MAP_O) $(LOOP_O)
	g++ $(EDITOR_C) $(MAP_O) $(LOOP_O) -o $(EDITOR_OUT) $(SFML)


$(LOOP_O): $(LOOP_C)
	g++ $(LOOP_C) -c -o $(LOOP_O)

$(MAP_O): $(MAP_C)
	g++ $(MAP_C) -c -o $(MAP_O)

$(PLAYER_O): $(PLAYER_C)
	g++ $(PLAYER_C) -c -o $(PLAYER_O)