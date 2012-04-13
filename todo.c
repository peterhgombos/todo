#include "todo.h"

#define MORA_LENGTH 45
const char* mora[] = {"wa", "wi", "wu", "we", "wo",
                      "ra", "ri", "ru", "re", "ro",
                      "ya", "yi", "yu", "ye", "yo",
                      "ma", "mi", "mu", "me", "mo",
                      "ha", "hi", "hu", "he", "ho",
                      "na", "ni", "nu", "ne", "no",
                      "ta", "ti", "tu", "te", "to",
                      "sa", "si", "su", "se", "so",
                      "ka", "ki", "ku", "ke", "ko"};


/* generates an unused id according to the id scheme */
char* generate_id(){
	FILE *fp;
	fp = open_list("r");
	char line[4096]; // todo: define line buffer somewhere
    char* id = malloc(6*sizeof(char));
    int done =0;
    /* we just keep guessing at an unused id until we strike gold.
     * todo: do this in a way that doesn't potentially run forever.
     */
    while(!done){
        sprintf(id, "%s%s\t", mora[rand()%MORA_LENGTH], mora[rand()%MORA_LENGTH]);
        fseek(fp, 0, SEEK_SET);
        done = 1;
        while(fp && fgets(line, sizeof(line), fp)){
            if(strstr(line,id)){
               done = 0; 
            }
        }
    }
	fclose(fp);
    id[5]='\0';
    return id;
}



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
			{0, 0, 0, 0}
		};
		int option_index = 0;
		c = getopt_long(argc, argv, "ha:s:", long_options, &option_index);

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
				list_id(optarg); //todo: fix better casting
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
    char* id = generate_id();

	FILE *fp;
	fp = open_list("ar");
	fprintf(fp, "%s\t%s\n", id, string);
	fclose(fp);


	printf("Added task with id %s:\t%s\n", id, string);
    free(id);
}

void list_all()
{
	FILE *fp;
	fp = open_list("r");
	char line[4096]; // todo: define line buffer somewhere
	while(fp && fgets(line, sizeof(line), fp)){
		printf("%s", line);
	}
	fclose(fp);
}

// show task with given id. too naive now.
void list_id(char* id)
{
	FILE *fp;
	fp = open_list("r");
	char line[4096]; // todo: define line buffer somewhere
	while(fp && fgets(line, sizeof(line), fp)){
		if(strstr(line,id)){
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

