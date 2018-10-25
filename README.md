Document version 1.0

1 - Introduction
COREWAR
Corewar -> arene virtuel où des champion en pseudo asm s'affrontent jusqu'au dernier
Le jeu va donc créer une machine virtuelle dans laquelle les programmes (écrits pas les joueurs) s’affrontent. L’objectif de chaque programme est de « survivre ». Par « survivre » on entends exécuter une instruction spéciale (live) qui veut dire « je suis en vie ». Ces programmes s’éxecutent simultanément dans la machine virtuelle et ce dans un même espace mémoire, et peuvent donc écrire les uns sur les autres. Le gagnant du jeu est le dernier a avoir exécuté l’instruction « live ».
Le projet va donc se decouper en 3 partie :
- L’asm : il va permetre de convertir les champions en langage capable d’etre lu par la vm
- La Vm : Elle va heberger les binaires des champ et leurs fournir un environement d’execution
- Les champions
2 - Programme : a) ASM
La partie ASM à pour but de convertire le fichier asm (.s) en fichier executable par le programme corewar (.core).
Usage :
./asm [-BdDehHopSstu] [file.s]
-B : print the binary version of the source code.
-d : show which of the opcodes needed a description oct. -D : print the decimal version of the source code.
-e : make the compiler sensible for errors.
-h : show this message.
-H : print the hexa-decimal version of the source code.
-o : show description of op-codes.
-p : Print a detailed description of the source file. -s : print symboles table.
-S : show label size of op-code.
-t : show informations about type of each op-code. -u : print usage.
B) Champions
- Les champs sont ecrits en pseudo asm dans des fichier .s.


Nous detailerons plus tard le fonctionement exact des champions C) COREWAR
L'executable CORWAR lance la vm avec jusqu'a 4 champ en parametre Usage :
./corewar [champ.s] {[-v] [-h] [-dump [int]] [[-n number_champ] champion_N.cor]
-v : visu -h : help
-dump : exit le programme et renvois le dernier print de la vm apres x boucle du programme (ex : ./corware -dump 0 champ.core -> renvois le visu de la vm apres 0 tours de boucle) -> interet ? le debug (plus d info : https://cdiese.fr/les-dumps-memoire-en-5-min/)
  
     Comment jouer ?
-n : pour definir un id de depart au champ (optionel)
Nous utiliseront 17 instructions assembleur reconnues par la machine. Un code machine est composé d'un mnémonique (ou instruction / opcode) et de un ou deux arguments représentant des adresses mémoires. Une ligne de code source (qui une fois compilée occupe une case mémoire) est donc composée ainsi :
<instruction> <type argument 1> <argument 1> <type argument 2> <argument 2>
Fonctionement :
La machine virtuelle est constituée d'une mémoire et d'une structure contenant l'état de chaque joueur et de chaque processus. La mémoire est circulaire, c'est-à-dire que les adresses mémoire sont toujours calculées modulo M. Plus généralement, toute l'arithmétique de la machine virtuelle est réalisée modulo M.
  
  
  
  
  Usefull link :
https://fr.wikipedia.org/wiki/Mode_d%27adressage#Adressage_relatif
http://www.enseignement.polytechnique.fr/profs/informatique/Jean-Christophe.Filliatre/10- 11/INF431/core_war/sujet.pdf
https://www.exploit-db.com/docs/french/13878-[french]-hzv-e-zine-2.pdf http://nicolab.chez.com
A noter que la version du corewar demandé par 42 differe de la version originale
