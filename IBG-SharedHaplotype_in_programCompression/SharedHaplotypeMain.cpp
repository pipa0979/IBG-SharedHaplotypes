//============================================================================
// Name        : SharedHaplotypeMatching.cpp
// Author      : Piyush
// Version     :
// Copyright   :
// Description : Main Program. Entry gate.
//============================================================================
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <sstream>
#include "ReadFiles.hpp"
#include "Part.hpp"
#include "Flags.hpp"

int main(int argc,char *argv[]) {
clock_t begin = clock();

ReadFiles inpfile;
std::string INPFILENAME="";
std::string OUTPUTFILENAME="";
std::string LOGFILENAME="";
unsigned long int MIN_BP_DISTANCE=100000;

for (int i=1;i<argc;i++)
{
	if(strcmp(argv[i],"--in")==0)
		{
			INPFILENAME=argv[++i];
			//LOGFILENAME=INPFILENAME;
		}

	else if(strcmp(argv[i],"--min_bp")==0)
		{
			std::stringstream(argv[++i]) >> MIN_BP_DISTANCE;

		}
	else if (strcmp(argv[i],"--out")==0)
		{
			OUTPUTFILENAME=argv[++i];
		}
	else
		{
			std::cerr<<"Error in "<<argv[i]<< " flag. No such flag exists"<<std::endl;
			exit(0);
		}
}


/*ERROR CHECKING*/

if ( (strcmp(INPFILENAME.c_str(),"") ==0 )  ||	(INPFILENAME.find(".int")==std::string::npos ) || (INPFILENAME.find_last_of(".int") !=  (INPFILENAME.size() -1)) )	
	{
		std::cerr<<"--in <filename.int> not provided. "<<std::endl;
		exit(0);
	}
Flags flag;
flag.setMIN_BP_DISTANCE(MIN_BP_DISTANCE);

//ERROR CHECKING
if(!inpfile.readFile(INPFILENAME,OUTPUTFILENAME))
	{
		std::cerr<<"Couldn't open file "<<INPFILENAME<<" program is exiting"<<std::endl;
		exit(0);
	}
if (OUTPUTFILENAME=="")
	{
		std::cerr<<"--out <filename> not provided"<<std::endl;
		exit(0);
	}

part ind(inpfile);
ind.setFlags(flag);
part compute;
compute.computation_haplotype(ind);
LOGFILENAME= INPFILENAME.substr(0,INPFILENAME.find(".int"));
std::ofstream writeLogFile((LOGFILENAME+".log").c_str());	//Create the NON-compressed file
clock_t end = clock();
double elapsed_secs = double(end - begin) ;//  			/CLOCKS_PER_SEC

if (!writeLogFile.is_open())
	{
		std::cerr<<LOGFILENAME<<" cannot be created.. Program exiting"<<std::endl;
		exit(0);
	}
writeLogFile<<" The elapsed time is "<<elapsed_secs <<" secs."<<std::endl;
writeLogFile.close();

return 0;
}


/*
//ERROR CHECKING
if (OUTPUTFILENAME=="")
	{
		std::cerr<<"--out <filename> not provided"<<std::endl;
		exit(0);
	}
if(!inpfile.readFile(INPFILENAME,OUTPUTFILENAME))
{
	std::cerr<<"Couldn't open file "<<INPFILENAME<<" program is exiting"<<std::endl;
	exit(0);
}
part ind1(inpfile);
part ind2(inpfile);
part compute;
//compute.quickSort_hapindex(ind1);
compute.computation_haplotype(ind1,ind2);



LOGFILENAME= INPFILENAME.substr(0,INPFILENAME.find(".int"));
std::ofstream writeLogFile((LOGFILENAME+".log").c_str());	//Create the NON-compressed file


clock_t end = clock();
double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

if (!writeLogFile.is_open())
	{
		std::cerr<<LOGFILENAME<<" cannot be created.. Program exiting"<<std::endl;
		exit(0);
	}
writeLogFile<<" The elapsed time is "<<elapsed_secs <<" secs."<<std::endl;
writeLogFile.close();

return 0;
}
*/