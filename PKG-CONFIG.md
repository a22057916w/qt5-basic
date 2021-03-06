## Linux Cli: pkg-config

pkg-config is a computer program that defines and supports a unified interface for querying `installed libraries` for the purpose of compiling software that depends on them, which not located in `usr/include`. It allows programmers and installation scripts to work without explicit knowledge of detailed library path information. 

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
* Requires: 連結庫相依連結庫名稱
* Libs: 連結庫編譯所需的 LDFLAGS 參數
* Cflags: 連結庫編譯所需的 CFLAGS 參數

## Options
1. pkg-config --list-all <br>
列出所有可使用的連結庫，位置在 `/usr/lib/pkgconfig` 及 `/usr/local/lib/pkgconfig` 裡面的 `xxx.pc` 檔，新軟體一般都會安裝 `.pc` 檔，沒有可以自己建立，並且設定環境變數 `PKG_CONFIG_PATH` 供 `pkg-config` 尋找 `.pc` 檔路徑。

2. pkg-config --cflags xxxx <br>
取得該連結庫的 CFLAGS 參數。

3. pkg-config --libs xxxx <br>
取得該連結庫的 LDFLAGS 參數。

4. pkg-config --exists xxx <br>
假如連結庫存在則傳回 0。

## Example
```
g++ $(pkg-config --cflags --libs Qt5Widgets) -fPIC -o hello hello.cpp
```
## Reference
* [pkg-config - Wikipedia](https://en.wikipedia.org/wiki/Pkg-config)
* [鳥哥的 Linux 私房菜 -- 第十章、認識與學習BASH](http://linux.vbird.org/linux_basic/0320bash.php)
