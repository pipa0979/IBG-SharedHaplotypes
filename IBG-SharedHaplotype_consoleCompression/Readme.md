###Version 1.1 of the shared haplotype program.


Output is redirected to  gzip pipeline rather than using compression in the program.


There are 3 flags:
--in <filename.int>	#Provide the input .int filename
--min_bp	#Defaults to 100000
--out outputfilename

The output is piped using:	| gzip > output.gz 

To compile:
make all

To run:
./SharedHaplotype --in out1.pop1.gen20.chr10.int --min_bp 100001 --out testoutput