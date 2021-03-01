run: play.out
	./play.out

play.out: src/window.o src/game.o src/world.o src/map.o src/player.o src/sprite.o
	g++ src/main.cc \
		src/window.o src/game.o src/world.o src/map.o \
		src/player.o src/sprite.o \
		-lsfml-graphics -lsfml-window -lsfml-system \
				-o play.out

src/window.o: src/window.cc
	g++ src/window.cc -c -o src/window.o

src/game.o: src/game.cc
	g++ src/game.cc -c -o src/game.o

src/world.o: src/world.cc
	g++ src/world.cc -c -o src/world.o

src/map.o: src/map.cc
	g++ src/map.cc -c -o src/map.o

src/player.o: src/player.cc
	g++ src/player.cc -c -o src/player.o

src/sprite.o: src/sprite.cc
	g++ src/sprite.cc -c -o src/sprite.o

editor: editor.out
	./editor.out

editor.out: src/map.o
	g++ editor/main.cc src/map.o -o editor.out

clean:
	rm *.out src/*.o