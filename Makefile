GPP = g++
INCLUDE = -Ibuild
FLAGS = -Wall -pedantic -ansi -Iinclude
PROGRAMA = main

OBJ = build/vivo.o build/main.o build/vampiro.o build/janela.o build/rgba.o build/monsterCollection.o build/tempo.o build/personagem.o build/allyCollection.o build/guerreiro.o build/controle.o build/camera.o

bin/$(PROGRAMA): $(OBJ)
	g++ -o $@ $^ `sdl2-config --cflags --libs`

build/vivo.o: src/vivo.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/main.o: src/main.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/vampiro.o: src/vampiro.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/janela.o: src/janela.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/rgba.o: src/rgba.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/monsterCollection.o: src/monsterCollection.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/tempo.o: src/tempo.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/personagem.o: src/personagem.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/allyCollection.o: src/allyCollection.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/guerreiro.o: src/guerreiro.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/controle.o: src/controle.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/camera.o: src/camera.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

clean_obj:
	rm build/*.o

clean_bin:
	rm bin/$(PROGRAMA)

clean_all:
	rm build/*.o
	rm bin/$(PROGRAMA)
