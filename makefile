run: bin/run.out
	./bin/run.out

editor: bin/editor.out
	./bin/editor.out

bin/run.out: bin/map.o bin/game.o bin/player.o
	g++ src/main_run.cpp \
		bin/map.o \
		bin/game.o \
		bin/player.o \
		-lsfml-graphics -lsfml-window -lsfml-system \
			-o bin/run.out

bin/editor.out: bin/map.o bin/editor.o
	g++ src/main_editor.cpp \
		bin/map.o \
		bin/editor.o \
		-lsfml-graphics -lsfml-window -lsfml-system \
			-o bin/editor.out

tests: bin/map.o
	g++ tests/create_map.cpp bin/map.o -o bin/create_map.out
	g++ tests/grass_map.cpp bin/map.o -o bin/grass_map.out

bin/map.o: src/map.cpp
	g++ src/map.cpp -c -o bin/map.o

bin/editor.o: src/editor.cpp
	g++ src/editor.cpp -c -o bin/editor.o

bin/game.o: src/game.cpp
	g++ src/game.cpp -c -o bin/game.o

bin/player.o: src/player.cpp
	g++ src/player.cpp -c -o bin/player.o

clean:
	rm bin/*
