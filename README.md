# libasm
The aim of this project is to get familiar with assembly language.

# How to started
Nasm Tutorial. I noticed that the command to execute the assembled code was different:
<!-- 1: nasm -f macho64 your_file.asm
2: ld -macosx_version_min 10.7.0 -lSystem $(executable_name) your_file.o
3: ./$(executable_name) -->
- https://cs.lmu.edu/~ray/notes/nasmtutorial/

# Compile
gcc -m64 -g *.o main.c -o main
nasm -fmacho64 %%%%%%.s -o %%%%%%.o