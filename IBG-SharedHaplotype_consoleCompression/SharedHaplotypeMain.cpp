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
std::string OUTPUTFILENAME="pass";	/*Not needed. A dummy name passed to make in program and console version of the program consistent.*/
std::string LOGFILENAME="";
unsigned long int MIN_BP_DISTANCE=100000;


for (int i=0;i<argc;i++)
{
	if(strcmp(argv[i],"--in")==0)
		{
			INPFILENAME=argv[++i];
			//LOGFILENAME=INPFILENAME;
		}

	if(strcmp(argv[i],"--min_bp")==0)
		{
			std::stringstream(argv[++i]) >> MIN_BP_DISTANCE;

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




/*ERROR CHECKING*/

//std::cout<<"INPFILENAME = "<<INPFILENAME <<std::endl;
if(!inpfile.readFile(INPFILENAME,OUTPUTFILENAME))
{
	std::cerr<<"Couldn't open file "<<INPFILENAME<<" program is exiting"<<std::endl;
	exit(0);
}
part ind(inpfile);
ind.setFlags(flag);
//part ind2(inpfile);
part compute;
//compute.quickSort_hapindex(ind1);
compute.computation_haplotype(ind);

//compute.computation_haplotype(ind1,ind2);



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
