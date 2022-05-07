objs = bin/main.o bin/entities.o bin/entityMath.o

CCFlags = -std=c++17 -Wall -I include

play: Paraikaze
	./Paraikaze

Paraikaze: $(objs)
	clang++ $(objs) -o Paraikaze -l raylib

bin/main.o: src/main.cpp
	clang++ -c src/main.cpp $(CCFlags) -o bin/main.o 

bin/entities.o: src/entities.cpp
	clang++ -c src/entities.cpp $(CCFlags) -o bin/entities.o

bin/entityMath.o: src/entityMath.cpp
	clang++ -c src/entityMath.cpp $(CCFlags) -o bin/entityMath.o