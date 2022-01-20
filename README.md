# The Collatz Conjecture
Finds the Total Stopping Time of a Number ```n``` in ```3x+1```.

## Notes
Seems to be the case that memoization is not the best method even for numbers close to ```2^64``` \
\
There is one command available after build:
1. ```brute``` - Fast, Single Threaded

### ```brute``` command
* No Manual Multitasking takes place
* Is Amazing (in terms of performance)
* Capable of calculating Stopping Time up to ```18 446 744 073 709 551 615``` or just below 18.5 Quintillion in less than a tenth of a second

## Building and Running
### Building
#### Pre-requisites
1. C++ Compiler installed (tested and built with MinGW-w64) - [MinGW-w64 Download](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download)
2. Add MinGW's bin path to your PATH environment variable.

#### Steps
In Terminal:
* ```g++ brute.cpp -o brute```


### Running
Depending on Terminal, find out how to run executables.
* In Command Prompt:
  * ```brute [number]```
* In powershell:
  * ```.\brute [number]```
* In bash:
  * ```./brute [number]```

#### Examples
The below commands will Find the Total Stopping Time for ```392``` (which is ```27```) in the Collatz Conjecture.

##### Example in Command Prompt
* ```brute 392```

##### Example in Powershell
* ```.\brute 392```

##### Example in Bash
* ```./brute 392```
