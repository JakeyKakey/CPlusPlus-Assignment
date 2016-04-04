
Note: My version of CLion/C++/Cygwin wasn't very keen on using relative filepaths such as "ranges.txt", so I've been forced to use absolute filepaths in order to open the data. The robot constructor accepts two strings for locations of poses.txt and ranges.txt respectively and as such, please modify the program accordingly in the main.cpp method on the very first line to change it to the absolute file locations of your choosing. 

As per CMakeLists.txt, the compiler is flagged for -std=C++11, -Wall and -pedantic.

The files included are a screencast of the program compiling and running, a text file output of the grid, CMakeList.txt for CMake/Compiler settings, this README itself as well as my five C++ files.

header.h containing all class declarations.
RobotData.cpp for reading the data in.
Maths.cpp for processing the data.
Grid.cpp for rendering the data.
And of course, main.cpp to start the program.

I've compiled it on CLion 1.2.4 using Cygwin64 2.4.1. As mentioned above, the compiler flag is set to C++11 so I assume the standard library is also up to that version. 

Only standard library is used, from which I use vector,iostream,math,string,fstream.

The sleep function is set to the windows Sleep(2000) where the Linux equivalent would be sleep(2). I've included both 
#include <sys/unistd.h>
#include <w32api/synchapi.h>

so if there's an issues with the 'animation', feel free to change the sleep function located in Grid.cpp > void Grid::updateGrid to the correct one for the OS used.

I think that about covers it all.


