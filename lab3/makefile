all: program

program: main.o menu.o tablica.o tablica_wysw.o 
	g++ main.o menu.o tablica.o tablica_wysw.o -o program
main.o: menu.cpp
	g++ -c main.cpp
tablica.o: tablica.cpp
	g++ -c tablica.cpp
tablica_wysw.o: tablica_wysw.cpp
	g++ -c tablica_wysw.cpp
menu.o: menu.cpp
	g++ -c menu.cpp

clean:
	rm -f *.o program
