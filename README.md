# The Collatz Conjecture
Finds the Total Stopping Time of a Number ```n``` in ```3x+1```.

## Notes
Seems to be the case that memoization is not the best method even for numbers close to ```2^64``` and far beyond

There are three commands available after build:
1. ```brute```   - Fast, Single Threaded, supports 64 bit integers
2. ```brute2```  - Fast, Single Threaded, supports literally every integer > 0
3. ```collatz``` - Slow, Multithreaded, supports 64 bit integers, but is just too slow

### ```brute``` command
* No Manual Multitasking takes place
* Is Amazing (in terms of performance)
* Capable of calculating Stopping Time where the number does not shoot off past ```18 446 744 073 709 551 615``` (the upper bound of a ```uint64_t``` in ```C++```)

### ```brute2``` command
* No Manual Multitasking takes place
* Is even more amazing (in terms of performance)
* Capable of calculating stopping time for all positive integers

### ```collatz``` command
* Manual Multitasking implemented
* Is extremely slow - Time to calculate stopping time for ```10 000``` is approximately 100s
* Memoizes the stopping time for every value less than argument before calculating argument value
* Do not use

### My Recommendation
Use ```brute2```
#### Reasons:
1. The performance lost to ```brute``` is negligible
2. Is unbounded, can literally calculate stopping time of every number (if every number has a stopping time)

## Building and Running
### Building
#### Pre-requisites
1. C++ Compiler installed (tested and built with MinGW-w64) - [MinGW-w64 Download](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download)
2. Add MinGW's bin path to your PATH environment variable.

#### Steps
In Terminal:
* ```g++ brute.cpp -o brute```
* ```g++ brute2.cpp include/BigInt.cpp -o brute2```

### Running
Depending on Terminal, find out how to run executables.
* In Command Prompt:
  * ```brute [number]```
  * ```brute2 [number]```
* In powershell:
  * ```.\brute [number]```
  * ```.\brute2 [number]```
* In bash:
  * ```./brute [number]```
  * ```./brute2 [number]```

#### Examples
The below commands will Find the Total Stopping Time for ```392``` (which is ```27```) in the Collatz Conjecture.

##### Example in Command Prompt
* ```brute 392```
* ```brute2 392```

##### Example in Powershell
* ```.\brute 392```
* ```.\brute2 392```

##### Example in Bash
* ```./brute 392```
* ```./brute2 392```
