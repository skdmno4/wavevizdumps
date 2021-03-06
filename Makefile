CC = g++
OBJNAME = waveviz
DEBUG = -g
LFLAGS = $(DEBUG)
SANITIZER ?= address
CFLAGS += --std=c++14 -Wall $(DEBUG)
CFLAGS += -DASY -pthread

$(OBJNAME): waveviz.cpp
	$(CC) $(CFLAGS) waveviz.cpp -o $(OBJNAME)

clean:
	rm -rf *.o $(OBJNAME) *.json
