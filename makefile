run: bin/play.out
	./bin/play.out

editor: bin/editor.out
	./bin/editor.out

bin/play.out: bin/map.o bin/game.o bin/window.o bin/world.o bin/player.o bin/images.o 
	g++ src/main.cpp \
		bin/map.o \
		bin/game.o \
		bin/window.o bin/world.o \
		bin/images.o \
		bin/player.o \
		-lsfml-graphics -lsfml-window -lsfml-system \
			-o bin/play.out

bin/editor.out: bin/map.o bin/editor.o bin/window.o bin/world.o bin/cursor.o bin/images.o bin/tools.o
	g++ src/main2.cpp \
		bin/map.o \
		bin/editor.o \
		bin/window.o bin/tools.o bin/world.o \
		bin/images.o \
		bin/cursor.o \
		-lsfml-graphics -lsfml-window -lsfml-system \
			-o bin/editor.out

bin/map.o: src/map.cpp
	g++ src/map.cpp -c -o bin/map.o

bin/game.o: src/game.cpp
	g++ src/game.cpp -c -o bin/game.o

bin/window.o: src/window.cpp
	g++ src/window.cpp -c -o bin/window.o

bin/world.o: src/world.cpp
	g++ src/world.cpp -c -o bin/world.o

bin/player.o: src/player.cpp
	g++ src/player.cpp -c -o bin/player.o

bin/images.o: src/images.cpp
	g++ src/images.cpp -c -o bin/images.o

bin/editor.o: src/editor.cpp
	g++ src/editor.cpp -c -o bin/editor.o

bin/cursor.o: src/cursor.cpp
	g++ src/cursor.cpp -c -o bin/cursor.o

bin/tools.o: src/tools.cpp
	g++ src/tools.cpp -c -o bin/tools.o

test: bin/map.o
	g++ tests/create_map.cpp bin/map.o -o bin/create_map.out
	g++ tests/reset_map.cpp bin/map.o -o bin/reset_map.out
	g++ tests/editor_cli.cpp bin/map.o -o bin/editor_cli.out
	g++ tests/fill_map.cpp bin/map.o -o bin/fill_map.out
	

clean:
	rm bin/*
