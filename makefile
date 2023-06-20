CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++11
DEPS = pieza.hpp torre.hpp alfil.hpp
OBJT = pieza.o torre.o test_torre.o
OBJA = pieza.o alfil.o test_alfil.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

test_torre: $(OBJT)
	$(CC) -o $@ $^ $(CFLAGS)

test_alfil: $(OBJA)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o