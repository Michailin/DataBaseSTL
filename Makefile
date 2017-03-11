register.o : register.cpp register.h
	g++ -c -std=c++11  register.cpp -o register.o
database.o : database.cpp database.h
	g++ -c -std=c++11  database.cpp -o database.o
main.o : main.cpp
	g++ -c -std=c++11  main.cpp -o main.o
main : main.o database.o register.o
	g++ -std=c++11 main.o database.o register.o -o main
remove :
	rm -f main.o database.o regiser.o
