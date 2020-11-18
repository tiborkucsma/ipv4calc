# ipv4calc
Az SZTE Számítógép hálózatok 2020/I. kurzuson feladott szorgalmi feladat valamivel bővített változata.
## Build & futtatás
### Linux
Első lépésként ajánlott a `source ./linux-setup-env.sh` futtatása, ez hozzáad két elérési utat a path-hez ami megkönnyíti az elkészített program futtatását. A `linux-build-gmake.sh` shell script futattása után legenerálódnak a buildeléshez szükséges Makefileok a `generated` mappába, majd automatikusan lefut a make is. Ezek után már használhatjuk is a programot.
```sh
$ source ./linux-setup-env.sh
$ ./linux-build-gmake.sh
$ ipv4calc help # Ez kiírja a program help menüjét, amelyben a használatához szükséges minden infó megtalálható
```
### Windows
#### Visual Studio 2019
Az egyetlen szükséges lépés a `windows-build-vs2019.bat` batch szkript futtatása. Ez után a futtatható állomány létrejön, és a `build/bin/ipv4calc/Debug` mappában lesz elérhető. Ebben a mappában nyissunk egy terminált, és használjuk a programot a következő képpen:
```sh
$ ipv4calc help # Ez kiírja a program help menüjét, amelyben a használatához szükséges minden infó megtalálható
```
