run: bin/play.out
	./bin/play.out

./bin/play.out: bin/map.o bin/game.o bin/window.o bin/world.o bin/player.o bin/images.o
	g++ src/main.cpp \
		bin/map.o \
		bin/game.o \
		bin/window.o bin/world.o \
		bin/images.o \
		bin/player.o \
		-lsfml-graphics -lsfml-window -lsfml-system \
			-o bin/play.out

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

clean:
	rm bin/*