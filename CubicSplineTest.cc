#include <cmath>
#include <fstream>
#include <iostream>
#include <random>

#include "CubicSplineLib"

#define pi 3.1415926

double function( double );
std::vector<double> linspace( double, double, int );

int main( ) {

	// sample sinc(x) on -6pi < x < 6pi
	double start = -6.0 * pi;
	double finish = 6.0 * pi;
	double range = finish - start;
	std::random_device device;
	std::mt19937_64 random_number( device( ) );
	int knots = 50;
	std::vector<double> x_data, y_data;

	for ( int i = 0; i < knots; i++ ) {

		x_data.push_back( start + range*random_number( )/random_number.max( ) );
		y_data.push_back( sin( x_data[i] ) / x_data[i] );
	}

	// resample onto higher resolution fixed grid
	int resolution = 1e5;
	std::vector<double> new_y, new_x = linspace( start, finish, resolution );
	
	try {
		
		CubicSpline<double> my_data( x_data, y_data, 2); // the 2 says omp_set_num_threads(2)
		new_y = my_data.interpolate( new_x );

	} catch( std::exception& error ) {

		std::cerr << error.what( ) << std::endl;
		return -1;
	}

	// output results
	std::ofstream original("original_data.txt"), resampled("resampled_data.txt");
	
	if ( original.is_open( ) ) {

		for ( int i = 0; i < knots; i++ )
			original << x_data[i] << " " << y_data[i] << std::endl;

		original.close( );
	}

	if ( resampled.is_open( ) ) {

		for ( int i = 0; i < resolution; i++ )
			resampled << new_x[i] << " " << new_y[i] << std::endl;

		resampled.close( );
	}

	return 0;
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
