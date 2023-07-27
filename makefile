
CC = g++ 
CFLAGS = -lpthread -lconfig++
CPPFLAGS = -I 
FOLDER = -I include 

SOURSES = test/test_frame.cpp src/NBD.cpp src/FRAME.cpp src/Reactor.cpp src/ThreadPool.cpp src/WorkerThread.cpp src/ThreadMap.cpp src/StaticListener.cpp src/Transmitter.cpp
SOURSES_2 = test/test_minion.cpp src/Reactor.cpp src/ThreadPool.cpp src/WorkerThread.cpp src/ThreadMap.cpp src/Receiver.cpp src/Minion.cpp

EXECUTABLE = master
EXECUTABLE_2 = minion

.PHONY : all, debug, release, clean

all:$(EXECUTABLE) $(EXECUTABLE_2)

debug: CFLAGS += -g
debug: $(EXECUTABLE)

release: CFLAGS += -DNDEBUG -O3
release: $(EXECUTABLE)

$(EXECUTABLE): $(SOURSES)
	$(CC)  $(SOURSES)  $(FOLDER) $(CFLAGS) -o master

$(EXECUTABLE_2): $(SOURSES_2)
	$(CC)  $(SOURSES_2)  $(FOLDER) $(CFLAGS) -o minion
		
clean:
	rm *.out
