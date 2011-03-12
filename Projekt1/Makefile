CC      = g++ -Wall -Os
CXX     = g++ -Wall -Os
OBJECTS  = main.o GMatrix.o

all: main

.c.o:
	$(CXX) -c $< -o $@

clean:
	rm -f *.o main

main: $(OBJECTS)
