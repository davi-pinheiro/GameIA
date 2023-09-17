GPP = g++
INCLUDE = -Ibuild
FLAGS = -Wall -pedantic -ansi -Iinclude
PROGRAMA = main

bin/$(PROGRAMA): build/vivo.o build/teste.o
	g++ -o $@ $^

build/vivo.o: src/vivo.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/teste.o: src/teste.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

clean_obj:
	rm build/*.o

clean_bin:
	rm bin/$(PROGRAMA)

clean_all:
	rm build/*.o
	rm bin/$(PROGRAMA)
