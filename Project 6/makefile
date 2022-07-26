project6.exe: main.o
	g++ driver.o shapes.o main.o -o project6.exe

main.o: driver.o shapes.o
	g++ -c main.cpp -o main.o

driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o

shapes.o: shapes.cpp
	g++ -c shapes.cpp -o shapes.o

clean:
	rm *.o
	rm *.exe