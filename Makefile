CFLAGS  = -m64 -g
SFLAGS  = -fmacho64
CC      = gcc
FILES 	= ft_strcmp.s ft_strcpy.s ft_strlen.s ft_write.s

OBJ	= $(FILES:%.s=%.o)

all: $(OBJ)
	$(CC) $(CFLAGS) *.o main.c -o main
$(OBJ): $(FILES)
	nasm $(SFLAGS) $(FILES)