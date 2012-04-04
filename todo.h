#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void help();
void add_todo(char string[]);
void list_all();
void list_id(int id);
FILE *open_list(char *mode);
