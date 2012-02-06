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
			{"help",	no_argument,		0,	'h'},
			{"add",		no_argument,	0,	'a'},
			{0, 0, 0, 0}
		};
		int option_index = 0;
		c = getopt_long(argc, argv, "ha:", long_options, &option_index);

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
			
		}
	}
}

void help()
{
	printf("This is the help file, should bring lots of help\n");
}

void add_todo(char string[])
{
	int id = (unsigned int)(rand()/100000.0);

	FILE *fp;
	fp = fopen("todofile", "ar");
	fprintf(fp, "%d\t%s\n", id, string);
	fclose(fp);


	printf("Added task with id %d:\t%s\n", id, string);
}

void list_all()
{
	FILE *fp;
	if((fp = fopen("todofile", "r")) == NULL){
		fprintf(stderr, "No tasks added\n");
		return;
	}
	char line[4096];
	while(fgets(line, sizeof(line), fp)){
		printf("%s", line);
	}
}
