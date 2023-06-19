CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++11
DEPS = pieza.hpp torre.hpp
OBJT = pieza.o torre.o test_torre.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test_torre: $(OBJT)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o