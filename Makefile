CC=g++
EXE_FILE=explore_econdata

all: $(EXE_FILE)

$(EXE_FILE): econdata.o econdata.hpp explore_econdata.cpp
	$(CC) econdata.o explore_econdata.cpp -o $(EXE_FILE)

econdata.o: econdata.hpp econdata.cpp
	$(CC) -c econdata.cpp
