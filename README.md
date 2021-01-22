# libasm
The aim of this project is to get familiar with assembly language.

# How to started
Nasm Tutorial. I noticed that the command to execute the assembled code was different:
<!-- 1: nasm -f macho64 your_file.asm
2: ld -macosx_version_min 10.7.0 -lSystem $(executable_name) your_file.o
3: ./$(executable_name) -->
- https://cs.lmu.edu/~ray/notes/nasmtutorial/

# Really important stuff
"The Stack" is a frequently-used area of memory designed for functions to use as temporary storage.  This is normally where you store values while calling another function: you can't store values in the scratch registers, because the function could change them." https://www.cs.uaf.edu/2015/fall/cs301/lecture/09_16_stack.html
-> USE PUSH AND POP

# Compile on Mac
gcc -m64 -g *.o main.c -o main
nasm -fmacho64 %%%%%%.s -o %%%%%%.o

# Compile on VM (Linux)
Syscall: https://chromium.googlesource.com/chromiumos/docs/+/master/constants/syscalls.md

# Note for myself after 1st correction
Passing fd1 = 0, fd2 = 0 and calling ft_read made the second ft_write to return -1 directly. 