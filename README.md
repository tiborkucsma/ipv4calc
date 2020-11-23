# ipv4calc
Az SZTE Számítógép hálózatok 2020/I. IB407g-19 kurzuson feladott szorgalmi feladat valamivel bővített változata. A programban 3 alparancs van: subnet, ipinfo, wildcard. A subnet parancs valósítja meg az eredeti szorgalmi feladatot, használata például: `ipv4calc subnet 197.14.26.11 5`. Részletes információk minden parancsról a program help menüjében érhetők el: `ipv4calc help`. Elérhető egy `-b` opció is, ami akármely parancshoz megadható, ennek hatására minden cím és maszk binárisan kerül kiírásra. Van egy 4. parancs ami nincs teljesen kész, a vlsm, ez elérhető a `feature/vlsm-feature` branchen.
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
