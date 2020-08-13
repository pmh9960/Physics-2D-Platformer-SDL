g++ -c src/*.cpp -std=c++14 -g -Wall -m64 -I include
g++ *.o -o bin/debug/main -lSDL2main -lSDL2 -lSDL2_image
./bin/debug/main