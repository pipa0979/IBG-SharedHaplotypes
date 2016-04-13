This is the version 2 of the IBG-SharedHaplotype program. With in-program compression.

There are 2 flags (which are discussed in the readme file):

Flags used:
--in <filename.int>
--out <somefilename.log>

There's a makefile as well. The log file with be formed automatically with the name <inputfilename>.log


To compile:
make all

To run:
./SharedHaplotype --in out1.pop1.gen20.chr10.int --out testoutput --min_bp 100002 



Size file before compression:	274.6 MB
Size file before compression:	31.7  MB
Compression Ratio:	8.662 