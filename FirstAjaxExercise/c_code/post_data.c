#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv, char **envp) {

        char *method, *query;
	char *lenstr;
	long len;
	char *pr, *fname, *lname, *add, *ph, *gen;

        /*
       	char *env_val;
       	char *env_name;
       	for (char **env = envp; *env != 0; env++) {
               	env_name = *env;
               	env_val=getenv(env_name);
               	printf("%s = %s\n", env_name, env_val);
       	}*/

	method=getenv("REQUEST_METHOD");
	lenstr = getenv("CONTENT_LENGTH");

        if(strcasecmp(method,"POST")==0) {
		if(lenstr == NULL || sscanf(lenstr,"%ld",&len)!=1)
			printf("<P>Error in invocation - wrong FORM probably.");
		else{
			fgets(query, len+1, stdin);
		}
        }

	pr = strstr(query,"fname");
	fname = pr+6;
	pr = strstr(query,"lname");
        lname = pr+6;
	pr = strstr(query,"address");
        add = pr+8;
	pr = strstr(query,"phone");
        ph = pr+6;
	pr = strstr(query,"gender");
        gen = pr+7;

	pr = strchr(fname,'&');
	if(pr)	*pr=0;
	pr = strchr(lname,'&');
        if(pr)  *pr=0;
	pr = strchr(add,'&');
        if(pr)  *pr=0;
	pr = strchr(ph,'&');
        if(pr)  *pr=0;
	pr = strchr(gen,'&');
        if(pr)  *pr=0;

	printf("HTTP/1.1 200 OK\r\n\r\n");

        printf("<html>");
	printf("fname:%s<br>", fname);
	printf("lname:%s<br>", lname);
	printf("address:%s<br>", add);
	printf("phone:%s<br>", ph);
	printf("gender:%s<br>", gen);
        printf("</html>\r\n\r\n");

	FILE *fp;
	char filename[100];
	strcpy(filename, "/home/david/www/tmp/");
	strcat(filename, fname);
	strcat(filename, lname);
	strcat(filename, ".json");
	fp = fopen(filename, "w");
	fprintf(fp, "{\"address\":\"%s\",\"phone\":\"%s\",\"gender\":\"%s\"}", add, ph, gen);
	fclose(fp);
        return 0;
}

