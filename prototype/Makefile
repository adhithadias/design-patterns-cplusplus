CC=g++
CFLAGS=-I./
LIBS=
_OBJ = main.o

# $@ left item from :
# $< first right item from :
# $^ all right items from :


%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -rf *.o main