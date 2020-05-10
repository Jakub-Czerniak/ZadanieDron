CPPFLAGS= -c -g -Wall -pedantic -std=c++17 

__start__: main.out
	./main.out

main.out: Dr3D_gnuplot_api.o main.o
	g++ -o main.out main.o MacierzOb.o Macierz.o Wektor.o Dr3D_gnuplot_api.o prostopadloscian.o dron.o -lpthread

main.o: main.cpp Dr3D_gnuplot_api.hh MacierzOb.hh Macierz.hh Wektor.hh prostopadloscian.hh
	g++ ${CPPFLAGS} -o main.o main.cpp

Dr3D_gnuplot_api.o: Dr3D_gnuplot_api.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o Dr3D_gnuplot_api.o Dr3D_gnuplot_api.cpp

Dr3D_gnuplot_api.hh: Draw3D_api_interface.hh
	touch Dr3D_gnuplot_api.hh

MacierzOb.o: MacierzOb.cpp MacierzOb.hh Macierz.hh Wektor.hh
	g++ ${CPPFLAGS} -o MacierzOb.o Macierz.cpp

Macierz.o: Macierz.cpp Macierz.hh Wektor.hh
	g++ ${CPPFLAGS} -o Macierz.o Macierz.cpp

Wektor.o: Wektor.cpp Wektor.hh
	g++ ${CPPFLAGS} -o Wektor.o Wektor.cpp

prostopadloscian.o: prostopadloscian.cpp Macierz.hh MacierzOb.hh Wektor.hh Dr3D_gnuplot_api.hh Draw3D_api_interface.hh
	g++ ${CPPFLAGS} -o prostopadloscian.o prostopadloscian.cpp

dron.o: dron.cpp Macierz.hh MacierzOb.hh Wektor.hh Dr3D_gnuplot_api.hh Draw3D_api_interface.hh prostopadloscian.hh
	g++ ${CPPFLAGS} -o dron.o dron.cpp
clear:
	rm main.out main.o Dr3D_gnuplot_api.o
