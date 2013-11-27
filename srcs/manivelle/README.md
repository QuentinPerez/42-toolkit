# Manivelle
===

## WARNING
Please remember to check MANUALY your code too when using Manivelle, some errors aren't be checked otherwise.
You need python 2.3 to use this script !

#### Who did it ?
The Manivelle is made by stherman, it a fork of duponc_j norm checker with some ameliorations and adaptations.

#### What is "Manivelle" ?
Manivelle is a 42School norm checker. It is an syntax analyser who can be used to check basic norm errors on your C code.

===
### INSTALLATION
To install Manivelle, please follow these steps:
1: Add these lines to your ~/.bashrc (or any .shellrc)

    export PATH=$PATH:~/bin

2: Then copy the two files in the ~/bin (create if doesn't exist or copy to any other bin folder)

3: Last, reload your shell to apply.

===
### USAGE
python norme.py <dir to scan> [-verbose] [-score] [-libc]

-verbose: print all "open failed" messages
-score: print how much fails you have
-libc: check the if the libc is in the code
-malloc: enable malloc warning (default)
-printline: print witch line failed the test (default)
-return: check return values
-comment: never check comments
