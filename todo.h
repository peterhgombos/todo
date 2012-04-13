void help();
void add_todo(char string[]);
void remove_todo(char*id);
void list_all();
void list_id(char*id);
void print_line_colored(char*line);
FILE *open_list(char*mode);

#define COLOR_RESET 0
#define COLOR_GREEN 1

