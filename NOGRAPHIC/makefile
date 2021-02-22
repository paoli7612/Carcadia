run: main.out
	./main.out

main.out: sprite.o
	g++ main.cpp sprite.o -o main.out

sprite.o:
	g++ sprite.cpp -c 

clean:
	rm *.out *.o