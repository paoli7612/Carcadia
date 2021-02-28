run: play
	./play

game: map.o
	g++ main.cc map.o -lsfml-graphics -lsfml-window -lsfml-system -o play

create_spawn: map.o
	g++ create_spawn.cc map.o -o spawn

map.o: classes/map.cc
	g++ classes/map.cc -c


clean:
	rm *.out *.o
