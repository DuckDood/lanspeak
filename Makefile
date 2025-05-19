all: obj/ build/ obj/main.o build/client obj/server.o build/server 

clean:
	rm -r obj build/ 
.PHONY: clean

obj/:
	mkdir -p obj/

build/:
	mkdir -p build/

obj/main.o: src/main.cpp
	${CXX} src/main.cpp -c -o obj/main.o 

build/client: obj/main.o 
	${CXX} obj/main.o  -o build/client -lncurses -lsfml-network -lsfml-system 

obj/server.o: src/server.cpp
	${CXX} src/server.cpp -c -o obj/server.o 

build/server: obj/server.o 
	${CXX} obj/server.o  -o build/server -lncurses -lsfml-network -lsfml-system 

