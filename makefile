a.out : main.o Member.o
	g++ -o a.out main.o Member.o

main.o : main.cpp Member.h
	g++ -c main.cpp

Member.o : Member.cpp Member.h
	g++ -c Member.cpp