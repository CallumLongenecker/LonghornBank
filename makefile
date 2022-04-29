OBJS	= Longhorn.o Account.o
SOURCE	= Longhorn.cpp Account.cpp
HEADER	= Account.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Longhorn.o: Longhorn.cpp Account.h
	$(CC) $(FLAGS) Longhorn.cpp -std=c++11

Account.o: Account.cpp
	$(CC) $(FLAGS) Account.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUT)