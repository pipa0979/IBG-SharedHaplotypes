//============================================================================
// Name        : SharedHaplotypeMatching.cpp
// Author      : Piyush
// Version     :
// Copyright   :
// Description : Input Class
//============================================================================
#ifndef PART_HPP_
#define PART_HPP_
#include <vector>
#include "ReadFiles.hpp"
class part
{
public:
	unsigned long int h_ID;	/*Name of the individual*/
	unsigned long int chr;	/* ".int" file number */
	unsigned long int hap;	/* 0 or 1 (0 = Top, 1= Bottom)*/
    unsigned long int st;	/*Beginning of the haplotype sequence of a particular hap_index*/
    unsigned long int en;	/*ending of the haplotype sequence of a particular hap_index*/
    unsigned long int hap_index;	/* haplotype number (that particular chromosome strand)*/
    int root_pop;	/* when we have several populations, the genetic information comes from which population*/
    std::string fileName;
    void computation_haplotype(part ind1,part ind2);	/*Compute the haplotype matching*/
    void computation_haplotype_output();
    std::string quickSort_hapindex(part);
    part(ReadFiles fileData);
    part();
};
#endif /* PART_HPP_ */
