all:
	g++ -g -I${workspaceRoot}/include/SDL2 -L${workspaceRoot}/lib src/main.cpp -lSDL2main -lSDL2 -o "builds/engine.exe"