CPPFLAGS= -c -g -Wall -pedantic -std=c++17 -iquote inc

__start__: main.out
	./main.out

main.out:  obj/main.o obj/MacierzOb.o obj/Macierz.o obj/Wektor.o obj/Dr3D_gnuplot_api.o obj/Obiekt3D.o obj/prostopadloscian.o obj/dron.o
	g++ -o main.out obj/main.o obj/MacierzOb.o obj/Macierz.o obj/Wektor.o obj/Dr3D_gnuplot_api.o obj/Obiekt3D.o obj/prostopadloscian.o obj/dron.o -lpthread

obj/main.o: src/main.cpp inc/Draw3D_api_interface.hh inc/Dr3D_gnuplot_api.hh inc/Wektor.hh inc/Macierz.hh inc/MacierzOb.hh inc/Obiekt3D.hh inc/prostopadloscian.hh inc/dron.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Wektor.o src/Wektor.cpp

obj/Macierz.o: src/Macierz.cpp inc/Macierz.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Macierz.o src/Macierz.cpp

obj/MacierzOb.o: src/MacierzOb.cpp inc/MacierzOb.hh inc/Macierz.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/MacierzOb.o src/MacierzOb.cpp

obj/Obiekt3D.o: src/Obiekt3D.cpp inc/Obiekt3D.hh inc/Macierz.hh inc/Wektor.hh inc/MacierzOb.hh
	g++ ${CPPFLAGS} -o obj/Obiekt3D.o src/Obiekt3D.cpp

obj/prostopadloscian.o: src/prostopadloscian.cpp inc/Macierz.hh inc/MacierzOb.hh inc/Wektor.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/prostopadloscian.hh inc/Obiekt3D.hh
	g++ ${CPPFLAGS} -o obj/prostopadloscian.o src/prostopadloscian.cpp

obj/dron.o: src/dron.cpp inc/Macierz.hh inc/MacierzOb.hh inc/Wektor.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/prostopadloscian.hh inc/dron.hh inc/Obiekt3D.hh
	g++ ${CPPFLAGS} -o obj/dron.o src/dron.cpp

clear:
	rm main.out main.o Dr3D_gnuplot_api.o
