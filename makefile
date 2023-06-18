CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++11
DEPS = pieza.hpp torre.hpp
OBJ = pieza.o torre.o test_torre.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test_torre: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o