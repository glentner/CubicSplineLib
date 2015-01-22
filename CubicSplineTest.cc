#include "CubicSpline.hh"
#include "mt19937.hh"

#include <cmath>
#include <fstream>
#include <iostream>

#define pi 3.1415926

double function( double );
std::vector<double> linspace( double, double, int );

int main( ) {

	int knots = 30;
	std::vector<double> x; x.resize( knots );
	std::vector<double> y; y.resize( knots );

	mt19937 generator( time(NULL) );

	double start  = -5. * pi;
	double finish =  5. * pi;
	double range  = finish - start;

	for ( int i = 0; i < knots; i++ ) {

		x[i] = start + range * generator.random_real( );
		y[i] = function( x[i] );
	}

	CubicSpline<double> cubicspline( x, y, 4 );

	int n = 10000;
	std::vector<double> new_x = linspace( start, finish, n );
	std::vector<double> new_y = cubicspline.interpolate( new_x );

	std::ofstream output; output.open("data1.txt");

	if ( output.is_open( ) ) {

		for ( int i = 0; i < knots; i++ )
			output << x[i] << " " << y[i] << std::endl;

		output.close( );

	} else {

		std::cerr << "IOError: Failed to open data1.txt!" << std::endl;
	}

	output.open("data2.txt");

	if ( output.is_open( ) ) {

		for ( int i = 0; i < n; i++ )
			output << new_x[i] << " " << new_y[i] << std::endl;

	} else {

		std::cerr << "IOError: Failed to open data2.txt!" << std::endl;
	}

	return 0;
}

double function( double x ) {

	return sin( x ) / x;
}

std::vector<double> linspace( double start, double finish, int points ) {

	std::vector<double> grid;
	double range = finish - start;
	double space = range / ( points - 1 );
	grid.push_back( start );
	for ( int i = 1; i < points; i++ )
		grid.push_back( start + (double)(i+1) * space );

	return grid;
}
