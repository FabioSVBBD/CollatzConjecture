# CollatzConjecture
Finds the Total Stopping Time of a Number ```n``` in ```3x+1```.

## Building and Running
### Building
#### Pre-requisites
C++ Compiler installed (tested and built with MinGW x64)

#### Steps
In Terminal:
    ```g++ collatz.cpp -o collatz```
    ```g++ brute.cpp -o brute```


### Runnning
Depending on Terminal, find out how to run executables from cmd.
In powershell and bash:
    ```.\collatz [number]```
    ```.\brute [number]```

#### Example in Powershell/Bash
```.\collatz 392```
```.\brute 392```
The above command will Find the Total Stopping Time for 392 in the Collatz Conjecture.

### Notes
#### ```collatz``` command
* Capable of calculating Stopping Time of +- 3000
* Uses Multitasking with ```std::thread```s

#### ```brute``` command
* Capable of calculating Stopping Time up to ```+-3x10^(17)``` or 3 Hundred Quadrillion
* Does not multitask
