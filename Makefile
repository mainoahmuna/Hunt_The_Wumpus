OBJS	= room.o event.o gold.o wumpus.o bats.o pit.o game.o driver.o
SOURCE	= room.cpp event.cpp gold.cpp wumpus.cpp bats.cpp pit.cpp game.cpp driver.cpp
HEADER	= room.h event.h gold.h wumpus.h bats.h pit.h game.h
OUT	= hunt
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS) 
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

room.o: room.cpp
	$(CC) $(FLAGS) room.cpp 

event.o: event.cpp
	$(CC) $(FLAGS) event.cpp 

gold.o: gold.cpp
	$(CC) $(FLAGS) gold.cpp 

wumpus.o: wumpus.cpp
	$(CC) $(FLAGS) wumpus.cpp 

bats.o: bats.cpp
	$(CC) $(FLAGS) bats.cpp 

pit.o: pit.cpp
	$(CC) $(FLAGS) pit.cpp 

game.o: game.cpp
	$(CC) $(FLAGS) game.cpp 

driver.o: driver.cpp
	$(CC) $(FLAGS) driver.cpp 


clean:
	rm -f $(OBJS) $(OUT)