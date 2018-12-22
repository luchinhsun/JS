#include <stdio.h>

int main() {

	char name[20], tel[50], field[20], areaCode[20], code[20];
  	int age;

  	sscanf("name:john age:40 tel:082-313530", "%s", name);
  	printf("%s\n", name);

 	sscanf("name:john age:40 tel:082-313530", "%1s", name);
  	printf("%s\n", name);

  	sscanf("welcome name:john age:40 tel:082-313530", "%[^4]4%s", name, field);
  	printf("%s\n%s\n", name, field);

	sscanf("name:john age:40 tel:082-313530", "%[^:]", field);
  	printf("%s\n", field);

	return 0;
}
