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
			{"list",	required_argument,		NULL,	'l'},
			{0, 0, 0, 0}
		};
		int option_index = 0;
		c = getopt_long(argc, argv, "ha:l:", long_options, &option_index);

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

			case 'l':
				list_id(atoi(optarg)); //todo: fix better casting
			break;
			
		}
	}
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
		return; // todo: exit
	}
	// file opened properly; return FILE pointer
	return fp;
}


