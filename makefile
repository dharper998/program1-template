FLAGS=-Wall -Wextra -DDEBUG -g -std=c++14
all: program1

program1: star.o planet.o program1.o
	g++ $(FLAGS) star.o planet.o program1.o -o program1

star.o: Star.cpp
	g++ -c $(FLAGS) Star.cpp -o star.o

planet.o: Planet.cpp
	g++ -c $(FLAGS) Planet.cpp -o planet.o

program1.o: program1.cpp
	g++ -c $(FLAGS) program1.cpp -o program1.o

run: all
	./program1

clean:
	rm star.o planet.o program1.o program1

memcheck: all
	valgrind --leak-check=full ./program1

push:
	git add -A
	git commit -am "commit from makefile"
	git push
