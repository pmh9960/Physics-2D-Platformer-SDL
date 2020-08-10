g++ -c src/*.cpp -std=c++14 -g -Wall -m64 -I include -I D:/Library/SDL2-w64/include
g++ *.o -o bin/debug/main -L D:/Library/SDL2-w64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image