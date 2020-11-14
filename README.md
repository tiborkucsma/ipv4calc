# ipv4calc
Az SZTE Számítógép hálózatok 2020/I. kurzuson feladott szorgalmi feladat valamivel bővített változata.
# Build & futtatás
## Linux
Első lépésként ajánlott a `source ./linux-setup-env.sh` futtatása, ez hozzáad két elérési utat a path-hez ami megkönnyíti az elkészített program futtatását. A `linux-gen-gmake.sh` shell script futattása után legenerálódnak a buildeléshez szükséges Makefileok a `generated` mappába. Ebben a mappában a make futtatása után a `build` mappába kerül az elkészült futtatható állomány.
```sh
$ source ./linux-setup-env.sh
$ ./linux-gen-gmake.sh
$ cd generated
$ make
$ cd ..
$ ./ipv4calc -h # Ez kiírja a program help menüjét, amelyben a használatához szükséges minden infó megtalálható
```
## Windows
Egyelőre nem támogatott.
