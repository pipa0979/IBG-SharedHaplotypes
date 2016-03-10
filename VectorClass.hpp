/*
 * VectorClass.hpp
 *
 *  Created on: Mar 1, 2016
 *      Author: Piyush
 */

#ifndef VECTORCLASS_HPP_
#define VECTORCLASS_HPP_
class VectorClass
{
public:
	unsigned long int h_ID;	/*Name of the individual*/
	unsigned long int chr;	/* ".int" file number */
	unsigned long int hap;	/* 0 or 1 (0 = Top, 1= Bottom)*/
	unsigned long int st;	/*Beginning of the haplotype sequence of a particular hap_index*/
	unsigned long int en;	/*ending of the haplotype sequence of a particular hap_index*/
	unsigned long int hap_index;	/* haplotype number (that particular chromosome strand)*/
	int root_hap;	/* when we have several populations, the genetic information comes from w*/
	unsigned long int sn_no;
	VectorClass(unsigned long int h_ID=0, unsigned long int chr=0, unsigned long int hap=0,
				unsigned long int st=0,unsigned long int en=0, unsigned long int hap_index=0,
				unsigned long int root_hap=0, unsigned long int sn_no=0) :
																		h_ID(h_ID) , chr(chr),hap(hap),
																		st(st), en(en), hap_index(hap_index),
																		root_hap(root_hap),sn_no(sn_no)
	{}
	VectorClass();
};
#endif /* VECTORCLASS_HPP_ */
