all: reptrack 

reptrack: main.o Reptrack.o TimsTools.o Group.o Date.o 
	g++ -o  bin/reptrack obj/*.o -pthread -g

main.o: src/main.cpp
	g++ -c -std=c++11 -o obj/main.o src/main.cpp

TimsTools.o: src/TimsTools.cpp
	g++ -c -std=c++11 -o obj/TimsTools.o src/TimsTools.cpp

Reptrack.o: src/Reptrack.cpp
	g++ -c -std=c++11 -o obj/Reptrack.o src/Reptrack.cpp

Group.o: src/Group.cpp
	g++ -c -std=c++11 -o obj/Group.o src/Group.cpp

Date.o: src/Date.cpp
	g++ -c -std=c++11 -o obj/Date.o src/Date.cpp

clean: 
	rm obj/*.o bin/*

data_files:
	mkdir /home/tim/code/reptrack/data
	touch /home/tim/code/reptrack/data/snake_data.txt

install:
	cp bin/* /usr/local/bin/
