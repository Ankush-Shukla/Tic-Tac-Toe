all:compile link

compile:
	g++ -IC:\SFML-3.0.0\include -c main.cpp 
link:
	g++ main.o -o app -LC:\SFML-3.0.0\lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
run:
	./app.exe