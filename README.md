# Chess-Game

Juego de ajedrez hecho completamente con c++ en el cual se usa herencia de clases
y polimorfismo.

Para ejecutar el programa test_*.cpp:

Usando makefile:
make test_*
./test_*

Sin usar makefile:
g++ -c -o pieza.o pieza.cpp -Wall -Werror -Wextra -std=c++11
g++ -c -o *.o *.cpp -Wall -Werror -Wextra -std=c++11
g++ -c -o test_*.o test_*.cpp -Wall -Werror -Wextra -std=c++11
g++ -o test_* pieza.o *.o test_*.o -Wall -Werror -Wextra -std=c++11
./test_*
