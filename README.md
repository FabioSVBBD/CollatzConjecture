# The Collatz Conjecture
Finds the Total Stopping Time of a Number ```n``` in ```3x+1```.

## Notes
Seems to be the case that memoization is not the best method even for numbers close to ```2^64``` and far beyond

There are four commands available after build:
1. ```brute```   - Fast, Single Threaded, supports 64 bit integers
2. ```brute2```  - Fast, Single Threaded, supports literally every integer > 0
3. ```collatz``` - Slow, Multithreaded, supports 64 bit integers, but is just too slow
4. ```brute3``` - Fastest, Single Threaded. Essentially brute2 but uses Arbitrary Precision Arithmetic [new]

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
1. C++ Compiler installed (tested and built with MinGW-w64)
  * For windows: [MinGW-w64 Download For Windows](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download)
  * For Linux: ```sudo apt-get install gcc-mingw-w64```
  * For macOS: ```sudo port install mingw-w64```
2. Add MinGW's bin path to your PATH environment variable.
3. If you have chosen to use a different C++ compiler, it should work but the build command will differ from those below.

#### Steps
In Terminal:
* ```g++ brute.cpp -o brute```
* ```g++ brute2.cpp -o brute2```

###### Optionally include ```-O3 -march=native``` flag for maximum performance

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

## Collected Data
* Test Cases:
  1. ```10^(15)``` takes an average of ```0s``` to calculating stopping time of ```275```
  2. ```10^(30)``` takes an average of ```0.005s``` to calculating stopping time of ```467```
  3. ```10^(100)``` - A Googol takes an average of ```0.06s``` to calculate stopping of ```1 855```
  4. ```10^(500)``` takens an average of ```1.83s``` to calculate stopping time of ```8 377```
  5. ```10^(1000)``` takes an average of ```7.54s``` to calculate stopping time of ```18 178```
  6. ```10^(2000)``` takes an average of ```30.6s``` to calculate stopping time of ```37 431```


###### Comments
Thank you to [William Chanrico](https://github.com/williamchanrico) who's [BigInt class](https://github.com/williamchanrico/biginteger-cpp/blob/master/BigInt.cpp) was used in building ```brute2``` \
Thank you to [Mordecai Velasco](https://github.com/mrdcvlsc) who's [bint class](https://github.com/mrdcvlsc/APA/tree/main/bint) was used in building ```brute3```
