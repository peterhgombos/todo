#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

void help();
void add_todo(char string[]);
void list_all();
void list_id(int id);
void search(char string[]);
FILE *open_list(char *mode);
