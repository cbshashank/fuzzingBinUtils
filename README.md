We crashed nm, objdump, and some test programs using 2 fuzzers: ZZUF and AFL. We compared the two fuzzing tools, in terms of efficacy and code coverage (using gcov).

Please see presentation.pdf for more information.

This is only one part of the project (the zzuf stuff):

Crashing tools in binUtils 2.25 using ZZUF.
--------------------------------------------


Ensure that you have zzuf installed.


Example on how to use ZZUF: see zzufExample_Segfault folder. Examine vuln2.c, and run the shellcode. 
You will see that zzuf was able to find a segfault in a vulnerable program.

Crashing objdump: see zzuf_ObjdumpCrash folder. Examine vuln2.c, and run the shellcode. You will see that we successfully crashed (found a bug) in Objdump.

Feel free to contact me for clarification: cbshashank (at) gmail