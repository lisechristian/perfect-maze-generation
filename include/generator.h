/*
** EPITECH PROJECT, 2021
** generator.h
** File description:
** functions prototypes
*/

#ifndef MY_H_
#define MY_H_
#include <stdbool.h>

//lib
int my_getnbr(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);

//struct
typedef struct maze_s {
    unsigned int line;
    unsigned int col;
    char **tab;
} maze_t;

typedef struct vector_s {
    int x;
    int y;
} vector_t;

typedef struct maybe_vector_s {
    vector_t vec;
    bool is_defined;
} maybe_vector_t;

//src
void allocate_maze(maze_t *maze);
void create_maze(maze_t *maze);
void create_path(maze_t *maze);
void display_maze(maze_t *maze);
#endif
