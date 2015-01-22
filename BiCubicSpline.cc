//
// BiCubicSpline.cc
// GAIA-2.1.1
//
// Source file for the "BiCubicSpline" class. This object facilitates natural
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