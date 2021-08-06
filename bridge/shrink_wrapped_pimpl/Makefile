CC=g++
CFLAGS=-I./ -I/usr/include/boost/
LIBS=-L/usr/lib/x86_64-linux-gnu/ -L./

SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)

# $@ left item from :
# $< first right item from :
# $^ all right items from :


%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -rf *.o main