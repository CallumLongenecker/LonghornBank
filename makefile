a.out: Longhorn.o Account.o
	g++ -o a.out Longhorn.o Account.o

Longhorn.o: Longhorn.cpp Account.h Account.cpp
	g++ -c -std=gnu++0x Longhorn.cpp

Account.o: Account.h Account.cpp
	g++ -c -std=gnu++0x Account.cpp