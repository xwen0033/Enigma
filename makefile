enigma: main.o errors.o 
	g++ -Wall -g main.o errors.o -o enigma

main.o: main.cpp  errors.h
	g++ -Wall -g -c main.cpp

errors.o: errors.cpp errors.h
	g++ -Wall -g -c errors.cpp

clean:
	rm -f *.o enigma