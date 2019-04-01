# Gnuplot-C++-Interface
### A simple pipe based interface for the popular visualisation program Gnuplot for C++ and Windows.

**Enviorment**:

The project itself was created in Visual Studio 2017 (v141) but the code itself should also be easily compilable with non Microsoft compilers. The class should be able to compile with any C++ compiler for Windows.

**Prerequirements**:
 - Gnuplot should be installed on the computer the programm is supposed to run on. It is not require for the program to compile.
 - Either Gnuplot is installed in its windows default location, or a enviornment variable for "gnuplot" is set or the user needs to set the location to the gnuplot install directory himself (currently in the file "gnuplot.cpp" in the constructor).

**How to use it**:
First, create an instance of the class.
```cpp
Gnuplot gp;
```
Commandes can than be send to gnuplot the following way.
```cpp
Gnuplot gp;
gp.command("plot sin(x)");
```
The command function/macro also supports printf-style formating.
```cpp
Gnuplot gp;
double u = 42.0;
double v = 3.14;
gp.command("a = %f; b = %f", u, v);
gp.command("f(x) = a*x+b");
gp.command("plot f(x)");
```
It is also possible to have multiple instances of the class running at the same time.
```cpp
Gnuplot gp1;
Gnuplot gp2;
gp1.command("plot sin(x)");
gp2.command("plot cos(x)");
```

**License**:

The Code is published under the MIT license.

**Author**:

Michael Buchhorn
