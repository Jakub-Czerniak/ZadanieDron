CPPFLAGS= -c -g -Wall -pedantic -std=c++17 -iquote inc

__start__: main.out
	./main.out

main.out:  obj/main.o obj/MacierzOb.o obj/Macierz.o obj/Wektor.o obj/Dr3D_gnuplot_api.o obj/Obiekt3D.o obj/prostopadloscian.o obj/graniastoslup.o obj/sruba.o obj/dron.o obj/dno.o obj/powierzchnia.o obj/prst_przeszkoda.o obj/Wektor3D.o
	g++ -o main.out obj/main.o obj/MacierzOb.o obj/Macierz.o obj/Wektor.o obj/Dr3D_gnuplot_api.o obj/Obiekt3D.o obj/prostopadloscian.o obj/graniastoslup.o obj/sruba.o obj/dron.o obj/dno.o obj/powierzchnia.o obj/prst_przeszkoda.o obj/Wektor3D.o -lpthread

obj/main.o: src/main.cpp inc/Draw3D_api_interface.hh inc/Dr3D_gnuplot_api.hh inc/Wektor.hh inc/Macierz.hh inc/MacierzOb.hh inc/Obiekt3D.hh inc/prostopadloscian.hh inc/graniastoslup.hh inc/sruba.hh inc/dron.hh inc/dno.hh inc/powierzchnia.hh inc/InterfejsDrona.hh inc/przeszkoda.hh inc/prst_przeszkoda.hh inc/Wektor3D.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Wektor.o src/Wektor.cpp

obj/Wektor3D.o: src/Wektor3D.cpp inc/Wektor3D.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Wektor3D.o src/Wektor3D.cpp

obj/Macierz.o: src/Macierz.cpp inc/Macierz.hh inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Macierz.o src/Macierz.cpp

obj/MacierzOb.o: src/MacierzOb.cpp inc/MacierzOb.hh inc/Macierz.hh inc/Wektor.hh inc/Wektor3D.hh
	g++ ${CPPFLAGS} -o obj/MacierzOb.o src/MacierzOb.cpp

obj/Obiekt3D.o: src/Obiekt3D.cpp inc/Obiekt3D.hh inc/Macierz.hh inc/Wektor.hh inc/MacierzOb.hh inc/Wektor3D.hh
	g++ ${CPPFLAGS} -o obj/Obiekt3D.o src/Obiekt3D.cpp

obj/prostopadloscian.o: src/prostopadloscian.cpp inc/Macierz.hh inc/MacierzOb.hh inc/Wektor.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/prostopadloscian.hh inc/Obiekt3D.hh inc/InterfejsDrona.hh inc/Wektor3D.hh
	g++ ${CPPFLAGS} -o obj/prostopadloscian.o src/prostopadloscian.cpp

obj/graniastoslup.o: src/graniastoslup.cpp inc/Macierz.hh inc/MacierzOb.hh inc/Wektor.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/graniastoslup.hh inc/Obiekt3D.hh inc/Wektor3D.hh
	g++ ${CPPFLAGS} -o obj/graniastoslup.o src/graniastoslup.cpp

obj/sruba.o: src/sruba.cpp inc/Macierz.hh inc/MacierzOb.hh inc/Wektor.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/graniastoslup.hh inc/Obiekt3D.hh inc/sruba.hh inc/Wektor3D.hh
	g++ ${CPPFLAGS} -o obj/sruba.o src/sruba.cpp

obj/dron.o: src/dron.cpp inc/dron.hh inc/Macierz.hh inc/MacierzOb.hh inc/Wektor.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/prostopadloscian.hh inc/Obiekt3D.hh inc/graniastoslup.hh inc/sruba.hh inc/dno.hh inc/powierzchnia.hh inc/InterfejsDrona.hh inc/przeszkoda.hh inc/Wektor3D.hh
	g++ ${CPPFLAGS} -o obj/dron.o src/dron.cpp

obj/dno.o: src/dno.cpp inc/dno.hh inc/Obiekt3D.hh inc/Wektor.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/dron.hh inc/InterfejsDrona.hh inc/przeszkoda.hh inc/Wektor3D.hh
	g++ ${CPPFLAGS} -o obj/dno.o src/dno.cpp

obj/powierzchnia.o: src/powierzchnia.cpp inc/powierzchnia.hh inc/Obiekt3D.hh inc/Wektor.hh inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/dron.hh inc/InterfejsDrona.hh inc/przeszkoda.hh inc/Wektor3D.hh
	g++ ${CPPFLAGS} -o obj/powierzchnia.o src/powierzchnia.cpp	

obj/prst_przeszkoda.o: src/prst_przeszkoda.cpp inc/prst_przeszkoda.hh inc/prostopadloscian.hh inc/przeszkoda.hh inc/InterfejsDrona.hh inc/Wektor.hh inc/Wektor3D.hh
	g++ ${CPPFLAGS} -o obj/prst_przeszkoda.o src/prst_przeszkoda.cpp

inc/przeszkoda.hh: inc/InterfejsDrona.hh inc/Wektor3D.hh
	touch inc/przeszkoda.hh

inc/InterfejsDrona.hh: inc/Dr3D_gnuplot_api.hh inc/Draw3D_api_interface.hh inc/Wektor.hh 
	touch inc/InterfejsDrona


clear:
	rm main.out obj/main.o obj/MacierzOb.o obj/Macierz.o obj/Wektor.o obj/Dr3D_gnuplot_api.o obj/Obiekt3D.o obj/prostopadloscian.o obj/graniastoslup.o obj/sruba.o obj/dron.o obj/dno.o obj/powierzchnia.o obj/prst_przeszkoda.o
