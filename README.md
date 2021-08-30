# ipv4calc
This project was created for an optional task given out at the Computer networks 2020/I. IB407g-19 course of University of Szeged. This program supports 3 commands: subnet, ipinfo and wildcard. The detailed usage of these commands can be found in the help menu of the program: `ipv4calc help`.
## Build & run
### Linux
There is an optional script that makes running the compiled executable easier, you can run it as follows: `source ./linux-setup-env.sh`. To compile the program run the `linux-build-gmake.sh` shell script which generates the Makefiles needed, and then runs make on them. The complete process:
```sh
$ source ./linux-setup-env.sh
$ ./linux-build-gmake.sh
$ ipv4calc help
```
### Windows
#### Visual Studio 2019
The only step needed is to run the `windows-build-vs2019.bat` batch script. After this the exe can be found in the `build/bin/ipv4calc/Debug` folder.
