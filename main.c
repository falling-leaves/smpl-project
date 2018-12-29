/**
 * 
 * Main entry file for the program
 * 
 **/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/stat.h>

// initialize the present working directory as a SMPL project
int init();

// check if the repository is an SMPL project
int check();

int main(int argc, char const *argv[])
{
	if (argc > 1)
		if (strcmp(argv[1], "init") == 0)
			return init();
	
	return 0;
}

int init()
{
	if (check() >= 0)
	{
		printf("SMPL has already been initialized in the repository.\n");
		return -1;
	}

	// create the main folder
	if (mkdir("./.tasks/", 0777) < 0)
	{
		printf("Cannot generate root folder for application.\n");
		return -1;
	}
	
	// generate the master file
	FILE* mtr = fopen("./.tasks/master", "w");

	if (!mtr)
	{
		printf("Main holder file was not generated.\n");
		return -1;
	}

	// write on the file
	int w = fputs("project", mtr);

	return w | fclose(mtr);
}

int check()
{
	FILE* ck = fopen("./.tasks/master", "r");

	// check if the file exists
	if (!ck)
	{
		printf("The program is not initialized as a SMPL repository\n");
		return -1;
	}

	return fclose(ck);
}
