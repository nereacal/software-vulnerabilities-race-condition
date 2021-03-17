# software-vulnerabilities-race-condition
Software Vulnerabilities - Race Condition (in C)

## What is
Occurs when more than 1 process access to the same resource. Results for each process may differ between different executions having right results or wrong results.

## Some cases
1. Multiple threads
- Common race conditions in multithreads will occur when executions of each thread are unordered. To prevent this, synchronisation mechanisms should be applied to order executions and avoid some threads accessing to the same resouce at the same time, thus obtain a secuencial execution.
Those synchronisation mechanisms should be set in critical sections (this is the part of the code execute by multiple threads over the shared resource).

2. File Systems
- Verfication time (TOCTOU): Will occur when it is used the name of the file (identifies the file by its name) instead of the handler of the file (identifies the file internally) or verifying the file property.
Given File1 (with Handler H1) and File2 (with Handler H2). If content in File1 is modified the verification of permission will be made on the file name (File1), however if an attacker changes the handler (File2 - H1) the modified file will be (unwanted) File2. To prevent this, the function ```open(file, O_CREAT | O_EXCL)``` will verify if the file is created, create it or generate error.


Vulnerabilities will be programs written in C. First needed is a C compiler in any OS.
### Windows:
MinGW can be downloaded from here https://sourceforge.net/projects/mingw/files/Installer/
Once installed and given an example of program.c :
1.	Open line command (cmd)
2.	Go to MinGM directory \bin
3.	Compile file: ``` gcc.exe -o nameCompiledFile  pathOfFile\Example.c ```
4.	nameCompiledFile.exe will be generated in MinGW\bin
5.	Execute file nameCompiledFile.exe

### Linux:
Most of Linux distros have already compiler installed so it is much easier to execute:
1.	Open terminal and write: ``` gcc -o nameCompiledFile Example_segmentationFault2.c ```
If a program that uses threads is going to be executed then compilance should be:
``` gcc -pthread -o nameCompiledFile Example.c ```
2.	After compilance, program can be executed:
``` ./nameCompiledFile ```

### Use:
Example_race_condition.c program in C creates 70 threads and each one calls a function to increase a shared variable.
Compiling the file and executing it several times will give different solutions.
Example_race_condition_mutex.c program has synchronisation mechanism ```mutex_``` in the critical section (shared variable). 
Compiling the file and executing it several times will give the same solutions.
