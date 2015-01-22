Cubic Spline Library
====================

This small C++ library contains my working code for performing
natural cubic spline interpolation in one, two, and three
dimensions.

The CubicSpline class is fully functional.

BiCubicSpline and TriCubicSpline are still being developed.
Documentation and usage will be provided in the future.

##Short Example Usage
```C++
// create spline object
CubicSpline<double> raw_data( x, y, 2 );

// resample 'x' data 
std::vector<double> new_y = raw_data.interpolate( new_x );
```

