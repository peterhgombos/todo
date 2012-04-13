#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <time.h>

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
			{"help",	no_argument,		NULL,	'h'},
			{"add",     required_argument,		NULL,	'a'},
			{"show",	required_argument,		NULL,	's'},
			{"done",	required_argument,		NULL,	'd'},
			{0, 0, 0, 0}
		};
		int option_index = 0;
		c = getopt_long(argc, argv, "ha:s:d:", long_options, &option_index);

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

			case 'd':
				remove_todo(atoi(optarg)); // todo: fix better casting
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

void remove_todo(int id)
{
	char id_string[32];
	sprintf(id_string, "%i", id);
	FILE *fp;
	char *list_buffer;

	fp = open_list("r");
	fseek(fp, 0L, SEEK_END);
	list_buffer = malloc(ftell(fp)*sizeof(char));
	fseek(fp, 0L, SEEK_SET);

	char line [4096]; // todo: define line buffer somewhere
	while(fgets(line, sizeof(line), fp)){
		if(!strstr(line, id_string)) {
			if(list_buffer[0] == '\0') {
				sprintf(list_buffer, "%s", line);
			} else {
				sprintf(list_buffer, "%s%s", list_buffer, line);
			}
		} else {
			printf("Removed task %s", line);
		}
	}

	fclose(fp);

	fp = open_list("w");
	fprintf(fp, "%s", list_buffer);
	fclose(fp);
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


