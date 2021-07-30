CC=g++
CFLAGS=-I./
LIBS=
_OBJ = example.o

# $@ left item from :
# $< first right item from :
# $^ all right items from :


%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

example: $(_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -rf *.o example