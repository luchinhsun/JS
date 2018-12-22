#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	//char name = "home";
	char *value;

	value = getenv("HOME");

//	if(strcasecmp(value,"name") == 0)
	printf("Environment variable is %s\n", value);

	return 0;
}
