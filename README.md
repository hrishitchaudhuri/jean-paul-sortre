# Assignment 1 (Design and Analysis of Algorithms -- UE19CS251)

```
@author: hrishit chaudhuri
```

To start, run the following commands.  
```
$ make makedir
$ make
```
  
The following directory structure has been maintained:
```
|-- src
|   |-- driver.c                // contains driver code and main() function
|   |-- utils.c                 // contains all necessary helper functions as required by problem statement
|   |-- utils.h                 // corresponding header file for utils.c
|
|-- out                         // contains all logged data
|-- plots                       // contains .png images of necessary plots
|-- scripts
|   |-- plotter.py              // executable script; generates plots using matplotlib.pyplot
|
|-- bin                         // will contain binary image after running make.
|-- obj                         // will contain object files after running make.
|-- debug                       // will contain debug binaries after running make.
```
  
The makefile supports the following PHONY commands:
```
make makedir := generates necessary directories for binary files.
make := generates necessary binary and object files, and places them in correct directories.
make debug := generates debug binaries using gdb and places them in correct directories.
make clean := cleans up the directories and restores original configuration of the project.
```
