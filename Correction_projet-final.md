# Polytechnique Montréal

Département de génie informatique et génie logiciel

INF1900: Projet initial de système embarqué

# Grille de correction des programmes

Identification:
+ Travail    : Projet final
+ Section #  : 5
+ Équipe #   : 107111
+ Correcteur : Abdul Chaarani

# LISIBILITÉ
## En-têtes en début de programme

| Pénalité par erreur                          | -1.5       |
| -------------------------------------------- | ---------- |
| Noms des auteurs                             |            |
| Description du programme                     |            |
| Identifications matérielles (Broches I/O)    |   X         |
| Table des états ou autres s'il y a lieu      |   X         |
| __Résultat partiel__                         | __(0/1.5)__ |

## Identificateurs significatifs (Autodocumentation)

| Points importants                            | Poids      |
| -------------------------------------------- | ---------- |
| Absence de *chiffres magiques*               | (0/0.5)     |
| Noms de variables décrivent l'intention      | (0.4/0.5)     |
| Noms de fonctions décrivent l'intention      | (0.5/0.5)     |
| __Résultat partiel__                         | __(0.9/1.5)__ |

## Commentaires pertinents

Bonnes raisons d'un commentaire
 + Explication d'un algorithme
 + Procédure peu évidente (ou *hack*)
 + Référence d'extraits de code copiés d'Internet
 + Détail du POURQUOI d'un extrait de code

| Pénalité par erreur                          | -0.5       |
| -------------------------------------------- | ---------- |
| __Résultat partiel__                         | __(0/1.0)__ |


## Indentation

| Points importants                            | Poids      |
| -------------------------------------------- | ---------- |
| Indentation structurée                       | (0.3/0.5)     |
| Indentation uniforme dans le programme       | (0.3/0.5)     |
| __Résultat partiel__                         | __(0.6/1.0)__ |


# MODULARITÉ ET COMPRÉHENSION
## Fonctions bien définies

| Pénalité par erreur                          | -0.5       |
| -------------------------------------------- | ---------- |
| Responsabilité unique d'une fonction         |  X          |
| Maximum de 4 paramètres                      |            |
| Absence de code dupliqué                     |            |
| etc                                          |            |
| __Résultat partiel__                         | __(0.5/1.0)__ |


## Bonne application des concepts de programmation et systèmes embarqués

| Pénalité par erreur                          | -1.0       |
| -------------------------------------------- | ---------- |
| Utilisation appropriée des registres         |            |
| Machine à états codée clairement             |            |
| Délais et minuteries utilisés judicieusement |   -         |
| PWM bien établi                              |            |
| Scrutation et interruptions bien utilisées   |   -         |
| etc                                          |            |
| __Résultat partiel__                         | __(3/4.0)__ |

# FONCTIONNALITÉS
## Git

| Points importants                            | Poids      |
| -------------------------------------------- | ---------- |
| Fichiers aux bons endroits                   | (/1.5)     |
| Absence de fichiers inutiles                 | (/1.5)     |
| __Résultat partiel__                         | __(3/3.0)__ |


## Compilation

| Points importants                            | Poids      |
| -------------------------------------------- | ---------- |
| Absence de messages d'erreurs de compilation | (1.5/1.5)     |
| Absence de messages d'attention (*warning*)  | (0.5/0.5)     |
| __Résultat partiel__                         | __(2/2.0)__ |


## Évaluation boîte noire  

| Points importants                            | Poids      |
| -------------------------------------------- | ---------- |
| Cas normal de fonctionnement                 | (/2.5)     |
| Cas limites observables                      | (/2.5)     |
| __Résultat partiel__                         | __(5/5.0)__ |

# Résultat

__Total des points: 15.0/20__

# Commentaires du correcteur :
- Le nombre R# fait référence à un point du guide de codage.
## LISIBILITÉ

### En-têtes en début de programme
- Manque table des états, identifications matérielles.

### Identificateurs significatifs (Autodocumentation)
- Présence de chiffres magiques, notamment dans les `_delay_ms(125);`
- R4: `#define sensor1 PA0`: sensor1 est une constante et devrait être UPPER_SNAKE_CASE. Préfrérez les constantes que les `#define`
- `UART_Transmission`devrait être en lowerCamelCase.
- R25: booléens prefixés is: `startFound`, `firstTime`, etc
- R45: `LED led1` global 
- 

### Commentaires pertinents
- Présence de code mort
- Commentaires impertinents dans lineSensor.hpp: 
```cpp
bool robotMiddle();         // Robot perfectly in the middle
bool offTrackLeft();   // Robot offset track to the left
bool offTrackRight();  // Robot offset track to the right
bool robotBumpLine();       // Robot bumping into the line
bool isLeftWall();          // Robot is against the left wall
bool isRightWall();         // Robot is against the right wall
    // bruh ...
```
### Indentation
- Lignes avec plusieurs expressions sur une seule ligne. Rend le code plus difficile à lire.
- Application non uniforme du point ci-dessus.
- Parfois `if/else/while` à une ligne avec accolades, et parfois sans. Pro tip: toujours en mettre, même quand il n'y a qu'une expression. Dans le cas où il faut ajouter de la logique, on n'est pas obligé de rajouter des `{}`.


## MODULARITÉ ET COMPRÉHENSION
### Fonctions bien définies
- Les fonctions `movementLogic` et `switchLogic` de `Robot.cpp` sont monolithes. Réduire la responsabilité de ces fonctions en séparant en sous-fonction. 

### Bonne application des concepts de programmation et systèmes embarqués
- L'ISR `ISR(INT0_vect)` ne devrait gérer qu'une variable globale pour être le plus court possible. La logique actuelle devrait être gérée dans le `main`.
- `ISR(TIMER1_COMPB_vect) {}` déclaré, mais non utilisé.
- `set_sleep_mode(SLEEP_MODE_IDLE);` https://tenor.com/view/why-tho-gif-7322403521623739823


## FONCTIONNALITÉS
### Git

### Compilation

### Évaluation boîte noire  
- Évalué durant l'épreuve finale


# Basé sur le commit suivant
```
commit fd7d3fbb4fafff22051e2bfd469db0508c781fa1
Author: JeremieAG <anglaretjeremie@gmail.com>
Date:   Mon Apr 20 15:25:43 2026 -0400

    Type
```

# Fichiers indésirables pertinents
Aucun

# Tous les fichiers indésirables
Aucun

# Sorties de `make` dans les sous-répertoires

## Sortie de `make` dans `projet/`
```
make: *** correction_projet_final/107111/projet/: No such file or directory.  Stop.

```

## Sortie de `make` dans `projet/app`
```
make: *** correction_projet_final/107111/projet/app: No such file or directory.  Stop.

```

## Sortie de `make` dans `projet/lib`
```
make: *** correction_projet_final/107111/projet/lib: No such file or directory.  Stop.

```

## Sortie de `make` dans `app/`
```
make: Entering directory '/home/abdul/GIGL/Charges/H26/INF1900/inf1900-grader/correction_projet_final/107111/app'
(cd ../lib/ && make)
make[1]: Entering directory '/home/abdul/GIGL/Charges/H26/INF1900/inf1900-grader/correction_projet_final/107111/lib'
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c button.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c can.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c debug.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c distanceSensor.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c interpreter.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c LED.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c lineSensor.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c memoire_24.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c memoryReader.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c motor.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c robot.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c sound.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c timer.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c UART.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c wheel.cpp
avr-ar -crs libstatique.a  button.o can.o debug.o distanceSensor.o interpreter.o LED.o lineSensor.o memoire_24.o memoryReader.o motor.o robot.o sound.o timer.o UART.o wheel.o
make[1]: Leaving directory '/home/abdul/GIGL/Charges/H26/INF1900/inf1900-grader/correction_projet_final/107111/lib'
avr-gcc -I. -I/usr/include/simavr -MMD -I ../lib/ -g -mmcu=atmega324pa -Os -std=c++14 -fpack-struct -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c main.cpp
avr-gcc -Wl,-Map,app.elf.map -mmcu=atmega324pa -o app.elf  main.o \
-lm -L ../lib/ -lstatique 
avr-objcopy -j .text -j .data -O ihex app.elf app.hex
make: Leaving directory '/home/abdul/GIGL/Charges/H26/INF1900/inf1900-grader/correction_projet_final/107111/app'

```

## Sortie de `make` dans `lib/`
```
make: Entering directory '/home/abdul/GIGL/Charges/H26/INF1900/inf1900-grader/correction_projet_final/107111/lib'
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c button.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c can.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c debug.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c distanceSensor.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c interpreter.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c LED.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c lineSensor.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c memoire_24.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c memoryReader.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c motor.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c robot.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c sound.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c timer.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c UART.cpp
avr-gcc -I. -I/usr/include/simavr -MMD  -g -mmcu=atmega324pa -Os -std=c++14 -fshort-enums -funsigned-bitfields -funsigned-char -Wall --param=min-pagesize=0 -fno-exceptions -c wheel.cpp
avr-ar -crs libstatique.a  button.o can.o debug.o distanceSensor.o interpreter.o LED.o lineSensor.o memoire_24.o memoryReader.o motor.o robot.o sound.o timer.o UART.o wheel.o
make: Leaving directory '/home/abdul/GIGL/Charges/H26/INF1900/inf1900-grader/correction_projet_final/107111/lib'

```
