GPP = g++
INCLUDE = -Ibuild
FLAGS = -Wall -pedantic -ansi -Iinclude
PROGRAMA = main

bin/$(PROGRAMA): build/vivo.o build/teste.o build/vampiro.o build/janela.o build/rgba.o
	g++ -o $@ $^ `sdl2-config --cflags --libs`

build/vivo.o: src/vivo.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/teste.o: src/teste.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/vampiro.o: src/vampiro.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/janela.o: src/janela.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/rgba.o: src/rgba.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

#build/inimigo.o: src/inimigo.cpp
#	$(GPP) $(FLAGS) -c -o $@ $^

clean_obj:
	rm build/*.o

clean_bin:
	rm bin/$(PROGRAMA)

clean_all:
	rm build/*.o
	rm bin/$(PROGRAMA)
