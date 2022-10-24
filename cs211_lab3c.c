
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX 100

typedef struct {
	char last[15],
		first[15];
	} NAME;

typedef struct{
	char street[25],
		city[15],
		state[3];
	long zip;
	} ADDRESS;

typedef struct{
	NAME name;
	ADDRESS address;
	} LABEL;

int getlabel(FILE *fp, LABEL *customer);

void putlabel(FILE *fp, LABEL *customer);	

void sort(LABEL *names[], int number);

int main()
{
	int i,
		number = 0;

	char more = 'Y',
		in_name[15],
		out_name[15];

	LABEL *names[MAX];

	FILE *in_file,
	   *out_file;

	puts("***   Label Sorting Program    ***");
	puts("press the enter key to map files to terminal\n");
	printf("Input file containing unsorted labels :");
	fgets(in_name, sizeof(in_name), stdin);
	in_name[strcspn(in_name, "\n")] = 0;

	printf("Output file to contain sorted labels  :");
	fgets(out_name,sizeof(out_name), stdin);
    out_name[strcspn(out_name, "\n")] = 0;

	if (strlen(in_name) == 0)
		in_file = stdin;
	else
	{
		in_file = fopen(in_name, "r");
		if (in_file == NULL)
		{
			printf("Can't open input: %s", in_name);
			exit(0);
		}
	}
	if (strlen(out_name) == 0)
		out_file = stdout;
	else
	{
		out_file = fopen(out_name, "w");
		if (out_file == NULL)
		{
			printf("Can't open output: %s", out_name);
			exit(0);
		}
	}

	while (more == 'Y' || more == 'y')
	{
		if (number < MAX)
		{
		 	names[number] = (LABEL *)calloc(1, sizeof(LABEL));
		 	if (names[number] != NULL)
			{
				if (getlabel(in_file, names[number]) == EOF)
				{
					free(names[number]);
					break;
				}
				++number;
				if (in_file == stdin)
				{
					printf("more labels? (Y/N): ");
					more = getchar();
				}
			}
			else
			{
				printf("<<< Out of Memore >>>");
				break;
			}
		}
		else
		{
			printf("<<<  Maximum No. of Labels is %d. >>>\n", MAX);
			break;
		}
	}
	sort(names, number);
	for (i = 0; i<number; i++)
		putlabel(out_file, names[i] );
	fclose(in_file);
	fclose(out_file);	

return 0;			
}



int getlabel(FILE *fp, LABEL *customer)
{
	int num;
	if (fp == stdin)
		printf("Enter Name                   :");
	fscanf(fp, "%s %s%*c ", customer -> name.first, customer -> name.last);

	if (fp == stdin)
		printf("Enter street                 :");
	fgets(customer->address.street, 25,fp);

	if (fp== stdin)
		printf("Enter city, state & zip      :");
	return fscanf(fp, "%s %s %ld%*c", customer->address.city,
					customer->address.state,
					&customer->address.zip);
}


	
void putlabel(FILE *fp, LABEL *customer)	
{
	fprintf(fp, "\n%s, %s\n%s%s %s %ld\n",
			customer->name.last,
			customer->name.first,
			customer->address.street,
			customer->address.city,
			customer->address.state,
			customer->address.zip);
}

void sort(LABEL *names[], int number)
{
	#define TRUE 1
	#define FALSE 0

	int notsorted = TRUE,
		i;

	LABEL *ptr;

	--number;

	while(notsorted)
	{
		notsorted = FALSE;
		for (i=0;i<number;i++)
		{
			if (strcmp(names[i]->name.last, names[i+1]->name.last)>0)
			{
				notsorted = TRUE;
				ptr = names[i];
				names[i] = names[i+1];
				names[i+1] = ptr;
			}
		}
	}
}
