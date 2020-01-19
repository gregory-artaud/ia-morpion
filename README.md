# ia-morpion

Ce projet a été réalisé dans le cadre de l'unité d'enseignement "Intelligence Artificielle et Jeux" de Polytech' Marseille.
L'objectif de celui-ci était d'implementer un jeu de morpion dans lequel pouvaient se mesurer deux adversaires humains ou un humain et une IA.

### Prerequis

Ce programme contient deux modules d'affichage, l'un dans la console et l'autre via une interface graphique.
L'implementation de l'interface graphique utilise la bibliothèque SDL1.2, il est donc nécessaire de l'avoir installée au préalable sur sa machine.

### Installation

Si les dossiers bin/ et obj/ ne sont pas présents à la racine du projet, exécutez la commande suivante :

```
make install
```
Pour la compilation, voici les deux commandes à utiliser selon l'affichage que vous souhaitez utiliser :

```
make console
```
Pour l'affichage console.

```
make graphic
```
Pour l'affichage graphique.

Apres avoir exécuté l'une de ces deux commandes, il est temps d'exécuter le programme.
L'exécutable se situe dans le dossier bin/. Pour l'exécuter la commande est la suivante :

```
./bin/morpionExe
```
