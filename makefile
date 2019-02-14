FLAGS=-Wall -Wextra -DDEBUG -g -std=c++14
all: lab3

lab3: star.o planet.o lab3.o
	g++ $(FLAGS) star.o planet.o lab3.o -o lab3

star.o: Star.cpp
	g++ -c $(FLAGS) Star.cpp -o star.o

planet.o: Planet.cpp
	g++ -c $(FLAGS) Planet.cpp -o planet.o

lab3.o: lab3.cpp
	g++ -c $(FLAGS) lab3.cpp -o lab3.o

run: all
	./lab3

clean:
	rm star.o planet.o lab3.o lab3

memcheck: all
	valgrind --leak-check=full ./lab3

push: clean
	git add -A
	git commit -am "commit from makefile"
	git push
