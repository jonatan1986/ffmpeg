
CFLAGS= -std=c++14 -pedantic -Werror -fpermissive -Wall -c

all: ffmpeg


ffmpeg: main.o
	g++ -o ffmpeg main.o

main.o: main.cpp parser.h jsonFormat.h
	g++ $(CFLAGS) main.cpp
