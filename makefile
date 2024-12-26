all: derle bagla calistir

derle:
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Liste.cpp -o ./lib/Liste.o
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/DNA.cpp -o ./lib/DNA.o

bagla:
	g++ ./lib/main.o ./lib/Liste.o ./lib/Dugum.o ./lib/DNA.o -o ./bin/program

calistir:
	./bin/program

clean:
	rm -f ./lib/*.o ./bin/program
