#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv, char **envp) {


        FILE *p;
	char filename[100];
        strcpy(filename, "/home/david/www/tmp/");
        strcat(filename, "ludavid.json");

        char redata[100];
        p = fopen(filename, "r");
        fgets(redata, 100, p);
        fclose(p);

	printf("%s", redata);
	return 0;

/*
	char *a = "HI";
	FILE *p;
	p = fopen("123.txt", "w");
	fprintf(p, "123%s\n", a);
	fclose(p);
*/	return 0;
}
