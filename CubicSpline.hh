//
// CubicSpline.hh
// GAIA-2.1.1
//
// Header file for the "CubicSpline" class. This object facilitates natural
// cubic spline interpolation. Once instantiated the
// constructor builds the spline polynomials on the intervals of the (x, y)
// data provided and retains them for later invocation. Parallelized using
// OpenMP.
//
// Copyright (C) Geoffrey Lentner 2015. All rights reserved.
// See LICENCE file. (GPL v2.0)
//
// contact: Geoffrey Lentner, B.S.
//          Graduate Student / Researcher
//          102 Natural Science Building
//          Department of Physics & Astronomy
//          University of Louisville
//          Louisville, KY 40292 USA
//
// email:   geoffrey.lentner@louisville.edu
//
// updated: 2015-1-19 13:10:30 EST
//

#ifndef _CubicSpline_HH
#define _CubicSpline_HH

#include <vector>
#include <string>

template<class T = double>
class CubicSpline {

public:

    // default constructor
    CubicSpline( ) { }
    
    // constructor for new data set
    CubicSpline( const std::vector<T>& _x_, const std::vector<T>& _y_,
             int parallel = 0, bool sorted = false );
    
    // copy constructor
    CubicSpline( const CubicSpline& );
    
    // default destructor
    ~CubicSpline( ) { }
    
    // interpolate onto new grid
    std::vector<T> interpolate( const std::vector<T>& new_x,
        bool fixed = false, T value = 0 );
    
protected:
    
    // recursive quicksort of data arrays
    void quicksort( const long& , const long& );
    
    // meta quicksort with parallel threads
    void quicksort( );
    
    // spline building function
    void build_splines( );
    
    // local copies of input arrays _x_ and _y_
    std::vector<T> x, y;
    
    // coefficients for spline polynomials
    std::vector<T> a, b, c, d;
    
    // modified coefficients, "Thomas Algorithm"
    std::vector<T> c_prime, d_prime;
    
    // values of derivatives at knots
    std::vector<T> k;
    
    // last element in vectors
    int n;
    
private:
    
    class SplineError : public std::exception {
    
    public:
        
        explicit SplineError( const char* msg ):
            _msg( msg ) { }
        
        explicit SplineError( const std::string& msg ):
            _msg( msg ) { }
        
        virtual ~SplineError( ) throw( ) { }
        
        virtual const char *what( ) const throw( ) {
            
            return ( "SplineError: " + _msg ).c_str( );
        }
        
    protected:
        
        std::string _msg;
    };
};
    
#endif
































