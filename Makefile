CFLAGS  = -m64 -g
SFLAGS  = -fmacho64
CC      = gcc
FILES 	= ft_strcmp.s ft_strlen.s ft_write.s ft_strcpy.s

OBJ	= $(FILES:%.s=%.o)

all: $(OBJ)
	$(CC) $(CFLAGS) *.o main.c -o main
$(OBJ): $(FILES)
	nasm $(SFLAGS) $(FILES)