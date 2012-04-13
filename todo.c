#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <regex.h>

#include "todo.h"

int main(int argc, char *argv[])
{
	int c;
	unsigned int iseed = (unsigned int)time(NULL);
	srand(iseed);

	if(argc == 1){
		list_all();
		return 0;
	}
	while (1)
	{
		static struct option long_options[] =
		{
			{"help",	no_argument,			NULL,	'h'},
			{"add",     	required_argument,		NULL,	'a'},
			{"show",	required_argument,		NULL,	's'},
			{"list",	required_argument,		NULL,	'l'},
			{0, 0, 0, 0}
		};
		int option_index = 0;
		c = getopt_long(argc, argv, "ha:s:l:", long_options, &option_index);

		if(c == -1)
			break;

		switch(c)
		{

			case 'h':
				help();
			break;

			case 'a':
				add_todo(optarg);
			break;

			case 's':
				list_id(atoi(optarg)); //todo: fix better casting
			break;
			case 'l':
				search(optarg);
			break;
			
		}
	}
	return 0;
}

void help()
{
	printf("This is the help file, should bring lots of help\n");
}

void add_todo(char string[])
{
	int id = (unsigned int)(rand()/100000.0); // todo: new id scheme

	FILE *fp;
	fp = open_list("ar");
	fprintf(fp, "%d\t%s\n", id, string);
	fclose(fp);


	printf("Added task with id %d:\t%s\n", id, string);
}

void list_all()
{
	FILE *fp;
	fp = open_list("r");
	char line[4096]; // todo: define line buffer somewhere
	while(fgets(line, sizeof(line), fp)){
		printf("%s", line);
	}
	fclose(fp);
}

// show task with given id. too naive now.
void list_id(int id)
{
	char id_string[32];
	sprintf(id_string, "%i",id);
	FILE *fp;
	fp = open_list("r");
	char line[4096]; // todo: define line buffer somewhere
	while(fgets(line, sizeof(line), fp)){
		if(strstr(line, id_string)){
			printf("%s", line);
		}
	}

	fclose(fp);
}

FILE *open_list(char *mode)
{
	FILE *fp;
	fp = fopen("todofile", mode); // todo: define filename somewhere
	if (fp == NULL) {
		fprintf(stderr, "No tasks added\n");
		return NULL; // todo: exit
	}
	// file opened properly; return FILE pointer
	return fp;
}

/* search each line in todofile for pattern*/
void search(char string[]) {
    regext_t reg;
	FILE *fp;
    char line[4096];

    regcomp(&reg, string, 0);
	fp = open_list("r");
    while(fgets(line, sizeof(line), fp)){
    }
}

