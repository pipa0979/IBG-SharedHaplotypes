//============================================================================
// Name        : SharedHaplotypeMatching.cpp
// Author      : Piyush
// Version     :
// Copyright   :
// Description :
//1. Call ReadFiles.cpp. It checks the integrity of the file.
//2.
//============================================================================
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string.h>
#include <cstdio>
#include "ReadFiles.hpp"
#include "SortFile.hpp"
#include "Part.hpp"
#include "VectorClass.hpp"
part::part()
{
}
part::part(ReadFiles fileData)
{
	fileName=fileData.getFileName();
	//std::cout<<fileName<<std::endl;
}
std::string part::quickSort_hapindex(part ind)
{
	SortFile compute;
	return compute.ComputeSorting(ind);	//Sort the file
}

void part::computation_haplotype(part ind1,part ind2)
{
	std::string eachi;	//for indexing
	std::stringstream ss;
	fileName=quickSort_hapindex(ind1);//Call sorting algo here
	std::ifstream f_indexing(fileName.c_str());	//Open file to create objects
	std::vector <VectorClass> vec;
	unsigned long int counter=0;
	while(getline(f_indexing,eachi))
	{
		counter++;
		if (!strcmp("h_ID chr hap st en hap_index root_pop",eachi.c_str()))	/*Correct .int file is opened*/
				continue;
		ss<<eachi;	//Copy the each line to stringstream
		ss>>ind1.h_ID;	/*get the h_ID i..e the name of the individual from .int file*/
		ss>>ind1.chr;
		ss>>ind1.hap;
		ss>>ind1.st;
		ss>>ind1.en;
		ss>>ind1.hap_index;
		ss>>ind1.root_pop;
		ss.str("");	/*Since one value is extracted, clear the stringstream*/
		ss.clear();	/*Clear state flags*/
		std::ifstream f2(fileName.c_str()); /*restart inner loop from the top of the file each time*/
		vec.push_back(VectorClass(ind1.h_ID, ind1.chr, ind1.hap,ind1.st,ind1.en,ind1.hap_index,ind1.root_pop,counter));
	}	//Outer while loop
	f_indexing.close();
	std::string each,every;
	unsigned long int vec_size= vec.size();
	//unsigned long int c_=0;	/*Top counter*/
	//unsigned long int cr_=0;	/*Run down Counter*/
	std::cout<<"ind1 "<<"ind2 "<<"chr "<<"start "<<"end "<<"bp_distance "<<"hap1 "<<"hap2"<<std::endl;
	for (unsigned long int i=0;i<vec_size;i++)
	{
		for (unsigned long int j=i;j<vec_size;j++)
			{
			 if (vec[i].hap_index == vec[j].hap_index)
				{
					if(vec[i].h_ID == vec[j].h_ID)	// If it's the same individual
						continue;
					bool flag=false;//false or true
					if(std::max(vec[i].st,vec[j].st) <= std::min(vec[i].en,vec[j].en))	//if(std::max(ind1.st,ind2.st) - std::min(ind1.en,ind2.en) <= 0)
						flag=true;
					else
						flag=false;	//pass. No intervals in common
					if(flag==true)
						{

							std::cout<<vec[i].h_ID <<" "	//individual 1
									 <<vec[j].h_ID <<" "	//individual 2
									 <<vec[i].chr  <<" "; //chromosome file number. Can also be ind2.chr since the chr is the .int file number
							std::cout<<std::max(vec[i].st,vec[j].st)<<" "	//start
									 <<std::min(vec[i].en,vec[j].en)<<" ";	//end

						}
					else
							continue;//No common interval.

					std::cout<< std::min(vec[i].en,vec[j].en)  -   std::max(vec[i].st,vec[j].st)  + 1 <<" ";	//bp_distance
					std::cout<<vec[i].hap<<" ";//hap1 // happlotype 0 or 1 for individual 1
					std::cout<<vec[j].hap<<std::endl;//hap1 // happlotype 0 or 1 for individual 1
					//getchar();


				}
			else if (vec[i].hap_index < vec[j].hap_index)
			{
				//cr_=j;
				break;
			}
			else
			{	//std::cout<<"Counter c_ = "<<c_<<std::endl;
				std::cout<<vec[i].sn_no<<" "<<vec[j].sn_no<<std::endl;
				std::cout<<vec[i].h_ID<<" "<<vec[i].chr<<" "<<vec[i].hap<<" "<<vec[i].st<<" "<<vec[i].en<<" "<<vec[i].hap_index<<" "<<vec[i].root_hap<<std::endl;
				std::cout<<vec[j].h_ID<<" "<<vec[j].chr<<" "<<vec[j].hap<<" "<<vec[j].st<<" "<<vec[j].en<<" "<<vec[j].hap_index<<" "<<vec[j].root_hap<<std::endl<<std::endl;
				std::cerr<<"Wrong sorting... ERROR!!!"<<std::endl;
				exit(0);
			}
		}	//Inner for loop closed
	}	//Outer for loop closed

	if (remove(fileName.c_str())!=0)
	{

	}
}//Function closed




/*
 void part::computation_haplotype(part ind1,part ind2)
{
	std::string each,every;
	std::stringstream ss;
	fileName=quickSort_hapindex(ind1);//Call sorting algo here



	std::cout<<fileName<<std::endl;
	std::ifstream f1(fileName.c_str());
	std::cout<<"ind1 "<<"ind2 "<<"chr "<<"start "<<"end "<<"bp_distance "<<"hap1 "<<"hap2"<<std::endl;
	unsigned long int ind1_max_haplotype=0;
	unsigned long int ind2_max_haplotype=0;
	while(getline(f1,each))
	{
		if (!strcmp("h_ID chr hap st en hap_index root_pop",each.c_str()))	//Correct .int file is opened
				continue;

		ss<<each;	//Copy the each line to stringstream
		ss>>ind1.h_ID;	//get the h_ID i..e the name of the individual from .int file
		ss>>ind1.chr;
		ss>>ind1.hap;
		ss>>ind1.st;
		ss>>ind1.en;
		ss>>ind1.hap_index;	ind1_max_haplotype=ind1.hap_index;
		ss>>ind1.root_pop;
		ss.str("");	//Since one value is extracted, clear the stringstream
		ss.clear();	//Clear state flags
		std::ifstream f2(fileName.c_str()); //restart inner loop from the top of the file each time
		while (getline(f2,every))
		{
			if (!strcmp("h_ID chr hap st en hap_index root_pop",every.c_str()))	//Correct .int file is opened

				//std::cout<<"skip"<<std::endl;
				continue;
			}
			ss<<every;
			ss>>ind2.h_ID;	//get the h_ID i..e the name of the individual from .int file
			ss>>ind2.chr;
			ss>>ind2.hap;
			ss>>ind2.st;
			ss>>ind2.en;
			ss>>ind2.hap_index;	ind2_max_haplotype=ind2.hap_index;
			ss>>ind2.root_pop;
			ss.str("");
			ss.clear();	//Clear state flags
			if(ind1.h_ID == ind2.h_ID )	//Shouldn't compare with self.
			{
				continue;
			}
			if(ind1_max_haplotype<ind2_max_haplotype)
			{
				break;
			}
			std::cout<<"OUTER LOOP--->	";
			std::cout<<ind1.h_ID<<"	" <<ind1.chr<<"	"<<ind1.hap<<"	"<<ind1.st<<"	"<<ind1.en<<"	"<<ind1.hap_index<<"	"<<ind1.root_pop<<std::endl;
			std::cout<<"INNER LOOP--->	";
			std::cout<<ind2.h_ID<<"	" <<ind2.chr<<"	"<<ind2.hap<<"	"<<ind2.st<<"	"<<ind2.en<<"	"<<ind2.hap_index<<"	"<<ind2.root_pop<<std::endl<<std::endl;

			//Start computing the output
			if(ind1.hap_index == ind2.hap_index)	//if it's the same haplotype
			{
				bool flag=false;//false or true
				//if(std::max(ind1.st,ind2.st) - std::min(ind1.en,ind2.en) <= 0)
				if(std::max(ind1.st,ind2.st) <= std::min(ind1.en,ind2.en))
				{
					flag=true;
				}
				else
				{
					flag=false;	//pass. No intervals in common
				}
				if(flag==true)
				{
					std::cout<<ind1.h_ID <<" "	//individual 1
							 <<ind2.h_ID <<" "	//individual 2
							 <<ind1.chr  <<" "; //chromosome file number. Can also be ind2.chr since the chr is the .int file number
					std::cout<<std::max(ind1.st,ind2.st)<<" "	//start
							 <<std::min(ind1.en,ind2.en)<<" ";	//end
				}
				else
				{
					continue;//No common interval.
				}
				std::cout<<  std::min(ind1.en,ind2.en)-   std::max(ind1.st,ind2.st)  + 1 <<" ";	//bp_distance
				std::cout<<ind1.hap<<" ";//hap1 // happlotype 0 or 1 for individual 1
				std::cout<<ind2.hap<<std::endl;//hap1 // happlotype 0 or 1 for individual 1
			}
			else
			{
				continue;
			}


		}//Inner while loop
		f2.close();
	}//Outer while loop
	f1.close();
}//Function closed

 */
