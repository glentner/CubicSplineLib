//
// BiCubicSpline.hh
// GAIA-2.1.1
//
// Header file for the "BiCubicSpline" class. This object facilitates natural
// cubic spline interpolation in two dimensions. Once instantiated the
// constructor builds the spline polynomials on the intervals of the (x, y, z)
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

#ifndef _BICUBICSPLINE_HH_
#define _BICUBICSPLINE_HH_

#include <vector>
#include <string>
#include "CubicSpline.hh"

template<class T = double>
class BiCubicSpline {
    
public:
    
    BiCubicSpline( ) { }
    BiCubicSpline( const std::vector<T>& _x_, const std::vector<T>& _y_,
                  std::vector<T>& _z_, bool parallel = 0 );
    BiCubicSpline( const BiCubicSpline& );
    
    ~BiCubicSpline( ) { }
    
    std::vector<std::vector<T>> interpolate( const std::vector<T>& new_x,
        const std::vector<T>& new_y, bool fixed = false, const T& value = 0 );
    
    T interpolate( const T& new_x, const T& new_y,
                  bool fixed = false, const T& value = 0);
    
protected:
    
    CubicSpline **cubicspline;
    std::vector<T> x, y, z;
    
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

































