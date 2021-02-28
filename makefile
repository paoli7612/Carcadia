run: play.out
	./play.out

play.out: map.o
	g++ main.cc map.o -lsfml-graphics -lsfml-window -lsfml-system -o play.out

editor: map.o
	g++ maps/editor.cc map.o -o editor.out

map.o: classes/map.cc
	g++ classes/map.cc -c

change_spawn: editor
	./editor.out spawn

clean:
	rm *.out *.o -r
