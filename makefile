all: lip-project 
	 
lip-project: main.o image_processing.o
	g++ -o lip-project main.o image_processing.o
		 
main.o: src/main.cpp include/image_processing.hpp
	g++ -o main.o src/main.cpp -c -W -Wall -ansi -pedantic
		 
image_processing.o: src/image_processing.cpp include/image_processing.hpp
	g++ -o image_processing.o src/image_processing.cpp -c -W -Wall -ansi -pedantic
		 
clean:
	rm -rf *.o *~ lip-project

