project5.exe: main.o
	g++ dictionary.o KeyValue.o main.o -o project5.exe

main.o: dictionary.o KeyValue.o
	g++ -c main.cpp -o main.o

dictionary.o: dictionary.cpp
	g++ -c dictionary.cpp -o dictionary.o

KeyValue.o: KeyValue.cpp
	g++ -c KeyValue.cpp -o KeyValue.o

clean:
	rm *.o
	rm *.exe