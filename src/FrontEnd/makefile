BINARY=DTFE
SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:.cpp=.o)
CPP=g++
CPPFLAGS=-O0
LDFLAGS=

all: $(SOURCES) $(BINARY)

$(BINARY): $(OBJECTS) 
	$(CPP) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CPP) -g -c $(CPPFLAGS) $< -o $@

.PHONY: clean

run:
	./DTFE tickets.txt user_info.txt

test: 
	./frontEndtest.sh

clean:
	rm -f $(OBJECTS) $(BINARY)
