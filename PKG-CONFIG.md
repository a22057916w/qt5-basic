## Linux Cli: pkg-config

pkg-config is a computer program that defines and supports a unified interface for querying `installed libraries` for the purpose of compiling software that depends on them. It allows programmers and installation scripts to work without explicit knowledge of detailed library path information. 

It outputs various information about installed libraries. This information may include: 
* Parameters (flags) for C or C++ compiler
* Parameters (flags) for linker
* Version of the package in question

## Synogsis
When a library is installed (automatically through the use of an RPM, deb, or other binary packaging system or by compiling from the source), a `.pc` file should be included and placed into a directory with other `.pc` files usually in `usr/lib/pkgconfig`. This file has several entries.

These entries typically contain a list of dependent libraries that programs using the package also need to compile. Entries also typically include the location of header files, version information and a description. 

Here is an example `.pc` file for `Qt5Widgets`: 
```
prefix=/usr
exec_prefix=${prefix}
libdir=${prefix}/lib
includedir=${prefix}/include/qt


Name: Qt5 Widgets
Description: Qt Widgets module
Version: 5.15.2
Libs: -lQt5Widgets 
Cflags: -DQT_WIDGETS_LIB -I${includedir}/QtWidgets -I${includedir}
Requires: Qt5Core Qt5Gui
```
