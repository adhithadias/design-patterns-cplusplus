CC=g++
CFLAGS=-I./ -I/usr/include/boost/ -I/usr/include/gtest/
# have to have pthread to compile gtest
# not sure if I have to include -lgtest_main also
LIBS=-L/usr/lib/x86_64-linux-gnu/ -L/home/min/a/kadhitha/software/googletest/build/lib/ -lboost_serialization -lgtest -lpthread
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