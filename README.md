# Chess-Game

Juego de ajedrez hecho completamente con c++ en el cual se usa herencia de clases
y polimorfismo.

Para ejecutar el programa test_torre.cpp:

Usando makefile:
make test_torre
./test_torre

Sin usar makefile:
g++ -c -o pieza.o pieza.cpp -Wall -Werror -Wextra -std=c++11
g++ -c -o torre.o torre.cpp -Wall -Werror -Wextra -std=c++11
g++ -c -o test_torre.o test_torre.cpp -Wall -Werror -Wextra -std=c++11
g++ -o test_torre pieza.o torre.o test_torre.o -Wall -Werror -Wextra -std=c++11
./test_torre
