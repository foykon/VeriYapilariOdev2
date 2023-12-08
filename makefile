compileandrun: program run 

program:kutuphane main 
	g++ .\lib\FileReader.o .\lib\main.o -o .\bin\program 
kutuphane:
	g++ -I ".\include" -c .\src\FileReader.cpp -o .\lib\FileReader.o
main: 
	g++ -I ".\include" -c .\src\main.cpp -o .\lib\main.o

run: 
	.\bin\program.exe