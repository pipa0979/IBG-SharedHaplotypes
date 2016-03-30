###Version 1.1 of the shared haplotype program.


Output is redirected to  gzip pipeline rather than using compression in the program.


There is 1 flag:
--in <filename.int>

The output is piped using:	| gzip > output.gz 

To compile:
make all

To run:
./SharedHaplotype --in out1.pop1.gen20.chr10.int | gzip > output.gz