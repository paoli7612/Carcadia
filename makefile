run: play
	./play

game: map.o
	g++ main.cc map.o -lsfml-graphics -lsfml-window -lsfml-system -o play

map.o: classes/map.cc
	g++ classes/map.cc -c

clean:
	rm *.out *.o
