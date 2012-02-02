#include <stdio.h>
#include <getopt.h>

void help();

int main(int argc, char *argv[])
{
	int c;

	while (1)
	{
		static struct option long_options[] =
		{
			{"help",	no_argument,	0,	'h'},
			{0, 0, 0, 0}
		};
		int option_index = 0;
		c = getopt_long(argc, argv, "h", long_options, &option_index);

		if(c == -1)
			break;

		switch(c)
		{
			case 'h':
			help();
			break;
		}
	}
}

void help()
{
	printf("This is the help file, should bring lots of help\n");
}
