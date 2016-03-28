###Version 1 of the shared haplotype program.


Output is redirected to  gzip pipeline rather than using compression in the program.


There are 2 flags:
--in <filename.int>
--log <somefilename.log>


To compile:
make all

To run:
./SharedHaplotype --in out1.pop1.gen20.chr10.int --log out1.pop1.gen20.chr10.log > output.txt
