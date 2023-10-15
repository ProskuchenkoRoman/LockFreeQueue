
CC = g++
CFLAGS = -std=c++17 -Wall -pthread

SOURCES = main.cpp SHA256.cpp TSQueue.cpp LFQueue.cpp HelpFunctions.cpp
HEADERS = Constants.h HelpFunctions.h LFQueue.h Node.h QueueBase.h SHA256.h TSQueue.h
EXECUTABLE = my_program

OBJECTS = $(SOURCES:.cpp=.o)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

.PHONY: clean