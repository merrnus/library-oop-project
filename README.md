# Library Management System

A comprehensive library management system demonstrating advanced OOP concepts in C++, including inheritance, polymorphism, exceptions, and file I/O.

## Features

### M1 (Composition & Basics)
- Object composition (Library → Book → Author)
- Rule of Three implementation
- Operator overloading
- const correctness

### M2 (Inheritance & Advanced OOP)
- **Inheritance Hierarchy**: Item (base) → Book, Magazine, DVD, AudioBook (derived)
- **Polymorphism**: Virtual functions (display, calculateLateFee, clone)
- **Smart Pointers**: unique_ptr for automatic memory management
- **Exception Handling**: Custom exception hierarchy (LibraryException + 3 derived)
- **File I/O**: Load items from text files (books.txt, magazines.txt, dvds.txt, audiobooks.txt)
- **Dynamic Casting**: Safe downcasting with dynamic_cast
- **Static Members**: Track total library instances
- **Copy-and-Swap Idiom**: Deep copy with proper resource management

## Project Structure
```
library-oop-project/
├── include/
│   ├── Item.h              (Base class)
│   ├── Book.h              (Derived from Item)
│   ├── Magazine.h          (Derived from Item)
│   ├── DVD.h               (Derived from Item)
│   ├── AudioBook.h         (Derived from Item - 4th class)
│   ├── Author.h
│   ├── Library.h
│   └── LibraryExceptions.h (Exception hierarchy)
├── src/
│   ├── Item.cpp
│   ├── Book.cpp
│   ├── Magazine.cpp
│   ├── DVD.cpp
│   ├── AudioBook.cpp
│   ├── Author.cpp
│   ├── Library.cpp
│   └── main.cpp
├── data/
│   ├── books.txt
│   ├── magazines.txt
│   ├── dvds.txt
│   └── audiobooks.txt
└── CMakeLists.txt
```

## Building and Running
```bash
# Configure
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug

# Build
cmake --build build

# Run
./build/oop
```

## Data Files Format

**books.txt:**
```
title|author_name|author_country|year|stock
```

**magazines.txt:**
```
title|publisher|year|issue_number
```

**dvds.txt:**
```
title|director|year|duration
```

**audiobooks.txt:**
```
title|narrator_name|narrator_country|year|duration|format
```

## Design Decisions

### Why Inheritance?
The Item base class provides a common interface for all library items, allowing polymorphic behavior and code reuse.

### Why Smart Pointers?
`unique_ptr` provides automatic memory management, preventing memory leaks and simplifying ownership semantics.

### Why Exception Hierarchy?
Custom exceptions allow specific error handling for different failure scenarios (item not found, duplicates, invalid data).

## Development Note
This project was developed with assistance from Claude (Anthropic) for learning C++ and OOP concepts. All code has been reviewed, understood, and tested by the developer.

---

# Nu primesc notă pentru că nu am pus titlu și descriere

### Folosiți template-ul corespunzător grupei voastre!

| Laborant  | Link template                                |
|-----------|----------------------------------------------|
| Dragoș B  | https://github.com/Ionnier/oop-template      |
| Tiberiu M | https://github.com/MaximTiberiu/oop-template |
| Marius MC | https://github.com/mcmarius/oop-template     |

### Important!

Aveți voie cu cod generat de modele de limbaj la care nu ați contribuit semnificativ doar dacă documentați riguros acest proces.
Codul generat pus "ca să fie"/pe care nu îl înțelegeți se punctează doar pentru puncte bonus, doar în contextul
în care oferă funcționalități ajutătoare și doar dacă are sens.

Codul din proiect trebuie să poată fi ușor de înțeles și de modificat de către altcineva. Pentru detalii, veniți la ore.

O cerință nu se consideră îndeplinită dacă este realizată doar prin cod generat.

- **Fără cod de umplutură/fără sens!**
- **Fără copy-paste!**
- **Fără variabile globale!**
- **Fără atribute publice!**
- **Pentru T2 și T3, fără date în cod!** Datele vor fi citite din fișier, aveți exemple destule.
- **Obligatoriu** fișiere cu date mai multe din care să citiți, obligatoriu cu biblioteci externe: fișiere (local sau server) sau baze de date
- obligatoriu (TBD) să integrați cel puțin două biblioteci externe pe lângă cele pentru stocare

### Tema 0

- [x] Nume proiect (poate fi schimbat ulterior)
- [x] Scurtă descriere a temei alese, ce v-ați propus să implementați

## Tema 1

#### Cerințe
- [x] definirea a minim **3-4 clase** folosind compunere cu clasele definite de voi; moștenirile nu se iau în considerare aici
- [x] constructori de inițializare cu parametri pentru fiecare clasă
- [x] pentru o aceeași (singură) clasă: constructor de copiere, `operator=` de copiere, destructor
<!-- - [ ] pentru o altă clasă: constructor de mutare, `operator=` de mutare, destructor -->
<!-- - [ ] pentru o altă clasă: toate cele 5 funcții membru speciale -->
- [x] `operator<<` pentru **toate** clasele pentru afișare (`std::ostream`) folosind compunere de apeluri cu `operator<<`
- [x] cât mai multe `const` (unde este cazul) și funcții `private`
- [x] implementarea a minim 3 funcții membru publice pentru funcționalități netriviale specifice temei alese, dintre care cel puțin 1-2 funcții mai complexe
  - nu doar citiri/afișări sau adăugat/șters elemente într-un/dintr-un vector
- [x] scenariu de utilizare **cu sens** a claselor definite:
  - crearea de obiecte și apelarea tuturor funcțiilor membru publice în main
  - vor fi adăugate în fișierul `tastatura.txt` DOAR exemple de date de intrare de la tastatură (dacă există); dacă aveți nevoie de date din fișiere, creați alte fișiere separat
- [x] minim 50-55% din codul propriu să fie C++, `.gitattributes` configurat corect
- [x] tag de `git`: de exemplu `v0.1`
- [x] serviciu de integrare continuă (CI) cu **toate bifele**; exemplu: GitHub Actions
- [ ] code review #1 2 proiecte

## Tema 2

#### Cerințe
- [x] separarea codului din clase în `.h` (sau `.hpp`) și `.cpp`
- [x] moșteniri:
  - minim o clasă de bază și **3 clase derivate** din aceeași ierarhie
  - ierarhia trebuie să fie cu bază proprie, nu derivată dintr-o clasă predefinită
  - [x] funcții virtuale (pure) apelate prin pointeri de bază din clasa care conține atributul de tip pointer de bază
    - minim o funcție virtuală va fi **specifică temei** (i.e. nu simple citiri/afișări sau preluate din biblioteci i.e. draw/update/render)
    - constructori virtuali (clone): sunt necesari, dar nu se consideră funcții specifice temei
    - afișare virtuală, interfață non-virtuală
  - [x] apelarea constructorului din clasa de bază din constructori din derivate
  - [x] clasă cu atribut de tip pointer la o clasă de bază cu derivate; aici apelați funcțiile virtuale prin pointer de bază, eventual prin interfața non-virtuală din bază
    - [x] suprascris cc/op= pentru copieri/atribuiri corecte, copy and swap
    - [x] `dynamic_cast`/`std::dynamic_pointer_cast` pentru downcast cu sens
    - [x] smart pointers (recomandat, opțional)
- [x] excepții
  - [x] ierarhie proprie cu baza `std::exception` sau derivată din `std::exception`; minim **3** clase pentru erori specifice distincte
    - clasele de excepții trebuie să trateze categorii de erori distincte (exemplu de erori echivalente: citire fișiere cu diverse extensii)
  - [x] utilizare cu sens: de exemplu, `throw` în constructor (sau funcție care întoarce un obiect), `try`/`catch` în `main`
  - această ierarhie va fi complet independentă de ierarhia cu funcții virtuale
- [x] funcții și atribute `static`
- [x] STL
- [x] cât mai multe `const`
- [x] funcții *de nivel înalt*, de eliminat cât mai mulți getters/setters/funcții low-level
- [x] minim 75-80% din codul propriu să fie C++
- [x] la sfârșit: commit separat cu adăugarea unei noi clase derivate fără a modifica restul codului, **pe lângă cele 3 derivate deja adăugate** din aceeași ierarhie
  - noua derivată nu poate fi una existentă care a fost ștearsă și adăugată din nou
  - noua derivată va fi integrată în codul existent (adică va fi folosită, nu adăugată doar ca să fie)
- [x] tag de `git` pe commit cu **toate bifele**: de exemplu `v0.2`
- [ ] code review #2 2 proiecte

## Tema 3

#### Cerințe
- [ ] 2 șabloane de proiectare (design patterns)
- [ ] o clasă șablon cu sens; minim **2 instanțieri**
  - [ ] preferabil și o funcție șablon (template) cu sens; minim 2 instanțieri
- [ ] minim 85% din codul propriu să fie C++
<!-- - [ ] o specializare pe funcție/clasă șablon -->
- [ ] tag de `git` pe commit cu **toate bifele**: de exemplu `v0.3` sau `v1.0`
- [ ] code review #3 2 proiecte

## Instrucțiuni de compilare

Proiectul este configurat cu CMake.

Instrucțiuni pentru terminal:

1. Pasul de configurare
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
# sau ./scripts/cmake.sh configure
```

Sau pe Windows cu GCC folosind Git Bash:
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -G Ninja
# sau ./scripts/cmake.sh configure -g Ninja
```

La acest pas putem cere să generăm fișiere de proiect pentru diverse medii de lucru.


2. Pasul de compilare
```sh
cmake --build build --config Debug --parallel 6
# sau ./scripts/cmake.sh build
```

Cu opțiunea `parallel` specificăm numărul de fișiere compilate în paralel.


3. Pasul de instalare (opțional)
```sh
cmake --install build --config Debug --prefix install_dir
# sau ./scripts/cmake.sh install
```

Vezi și [`scripts/cmake.sh`](scripts/cmake.sh).

Observație: folderele `build/` și `install_dir/` sunt adăugate în fișierul `.gitignore` deoarece
conțin fișiere generate și nu ne ajută să le versionăm.


## Resurse

- adăugați trimiteri **detaliate** către resursele externe care v-au ajutat sau pe care le-ați folosit
