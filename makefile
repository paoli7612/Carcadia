run: play
	./play.out

game: map.o
	g++ main.cc map.o -lsfml-graphics -lsfml-window -lsfml-system -o play.out

create_map: map.o
	g++ editor/create.cc map.o -o create.out

map.o: classes/map.cc
	g++ classes/map.cc -c

clean:
	rm *.out *.o -r
