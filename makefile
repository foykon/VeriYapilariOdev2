compileandrun: program run 

program:kutuphane main 
	g++ .\lib\FileReader.o .\lib\AVLTRee.o .\lib\Stack.o .\lib\main.o -o .\bin\program 
kutuphane:
	g++ -I ".\include" -c .\src\FileReader.cpp -o .\lib\FileReader.o
	g++ -I ".\include" -c .\src\AVLTRee.cpp -o .\lib\AVLTRee.o
	g++ -I ".\include" -c .\src\Stack.cpp -o .\lib\Stack.o
main: 
	g++ -I ".\include" -c .\src\main.cpp -o .\lib\main.o

run: 
	.\bin\program.exe