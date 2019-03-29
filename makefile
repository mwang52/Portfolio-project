all: 
	g++ -std=c++11 main.cpp Conn4_pls.cpp conn4_Diagonal.cpp Conn4_abstrct.cpp Chamber.cpp -o exe
clean:
	rm *exe
