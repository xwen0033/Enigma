enigma: main.o errors.o enigma.o plugboard.o rotor.o reflector.o
	g++ -Wall -g main.o errors.o enigma.o plugboard.o rotor.o reflector.o -o enigma

main.o: main.cpp enigma.h errors.h
	g++ -Wall -g -c main.cpp

enigma.o: enigma.cpp enigma.h plugboard.h rotor.h reflector.h
	g++ -Wall -g -c enigma.cpp

errors.o: errors.cpp errors.h
	g++ -Wall -g -c errors.cpp

plugboard.o: plugboard.cpp plugboard.h errors.h
	g++ -Wall -g -c plugboard.cpp

rotor.o: rotor.cpp rotor.h errors.h
	g++ -Wall -g -c rotor.cpp

reflector.o: reflector.cpp reflector.h errors.h
	g++ -Wall -g -c reflector.cpp


clean:
	rm -f *.o enigma
