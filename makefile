GAME_C = src/game.cpp
EDITOR_C = src/editor.cpp

GAME_OUT = bin/game.out
EDITOR_OUT = bin/editor.out

run: $(GAME_OUT)
	./$(GAME_OUT)

editor: $(EDITOR_OUT)
	./$(EDITOR_OUT)

clean:
	rm bin/*

$(GAME_OUT): $(GAME_C)
	g++ $(GAME_C) -o $(GAME_OUT)

$(EDITOR_OUT): $(EDITOR_C)
	g++ $(EDITOR_C) -o $(EDITOR_OUT)