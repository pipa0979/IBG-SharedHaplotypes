/*
 * SortFile.hpp
 *
 *  Created on: Feb 26, 2016
 *      Author: Piyush
 */

#ifndef SORTFILE_HPP_
#define SORTFILE_HPP_
#include "Part.hpp"

class SortFile {
	unsigned long int a, b, c, d, x, y, z;
public:
	unsigned long int A() const { return a; }
	unsigned long int B() const { return b; }
	unsigned long int C() const { return c; }
	unsigned long int D() const { return d; }
	unsigned long int X() const { return x; }
	unsigned long int Y() const { return y; }
	unsigned long int Z() const { return z; }
    SortFile(unsigned long int a=0, unsigned long int b=0, unsigned long int c=0, unsigned long int d=0,unsigned long int x=0, unsigned long int y=0, unsigned long int z=0) : a(a) , b(b),c(c),d(d), x(x), y(y), z(z)    		{}
    std::string ComputeSorting(part);
};
#endif /* SORTFILE_HPP_ */
