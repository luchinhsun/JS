#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv, char **envp) {

	char *method, *query;
	char *lenstr;
        long len;
	char *pr, *fname, *lname;
	FILE *p;

	/*
	char *env_val;
	char *env_name;
	for (char **env = envp; *env != 0; env++) {
		env_name = *env;
		env_val=getenv(env_name);
		printf("%s = %s\n", env_name, env_val);
	}

	method=getenv("REQUEST_METHOD");

	if(strcasecmp(method,"GET")==0) {
		query=getenv("QUERY_STRING");
		//p = fopen("/home/david/www/tmp/test", "r");
		//fgets(query, 60, p);
    		//fclose(p);
	}

	printf("HTTP/1.1 200 OK\r\n\r\n");

	printf("<html>");

	printf("%s", query);

	printf("</html>\r\n\r\n");
	*/

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
	pr = strchr(fname,'&');
        if(pr)  *pr=0;
        //pr = strchr(lname,'&');
        //if(pr)  *pr=0;

	char fullname[100];
	strcpy(fullname, fname);
	strcat(fullname, lname);
	char filename[100];
	strcpy(filename, "/home/david/www/tmp/");
	strcat(filename, fullname);
	strcat(filename, ".json");

	char redata[100];
	p = fopen(filename, "r");
	if(p == NULL){
		printf("HTTP/1.1 200 OK\r\n\r\n");
		//printf("<html>");
		//printf("Content-type:text/html\n\n");
        	printf("There is no such person");

        	//printf("</html>\r\n\r\n");
	}else{
		fgets(redata, 100, p);
		fclose(p);

		printf("HTTP/1.1 200 OK\r\n\r\n");
		//printf("Content-type:text/html\n\n");

       		//printf("<html>");

       		printf("%s", redata);

       		//printf("</html>\r\n\r\n");
	}
	return 0;
}
