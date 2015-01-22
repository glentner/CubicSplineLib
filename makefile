
library: hello libCubicSpline CSLtest goodbye

libCubicSpline: CubicSpline.o
	ar -rv libCubicSpline.a CubicSpline.o
	ranlib libCubicSpline.a

%.o: %.cc %.hh
	g++ -c $*.cc -fopenmp

CSLtest: CubicSplineTest.cc
	g++ -o RunCubicSplineTest CubicSplineTest.cc -L. -lCubicSpline -fopenmp -std=c++11

.PHONY: clean hello goodbye

clean:
	rm -rf *.o *.a 

hello:
	@echo 
	@echo " Compiling the Cubic Spline Library for C++ "
	@echo

goodbye:
	@echo
	@echo " Recommend setting variables for linking."
	@echo 
	@echo " example: "
	@echo
	@echo " export CSLSYS=~/path/to/CubicSplineLib"
	@echo " export CSLINC=\"-I\$$CSLSYS -L\$$CSLSYS -lCubicSpline -fopenmp\""
	@echo
	@echo " and compile with:"
	@echo
	@echo " g++ myprogram.cc \$$CSLINC"
	@echo
