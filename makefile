OBJS	= Longhorn.o Account.o Savings.o Checking.o
SOURCE	= Longhorn.cpp Account.cpp Savings.cpp Checking.cpp
HEADER	= Account.h Savings.h Checking.h
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Longhorn.o: Longhorn.cpp
	$(CC) $(FLAGS) Longhorn.cpp -std=c++11

Account.o: Account.cpp Account.h
	$(CC) $(FLAGS) Account.cpp -std=c++11

Savings.o: Savings.cpp Savings.h
	$(CC) $(FLAGS) Savings.cpp -std=c++11

Checking.o: Checking.cpp Checking.h
	$(CC) $(FLAGS) Checking.cpp -std=c++11


clean:
	rm -f $(OBJS) $(OUT)