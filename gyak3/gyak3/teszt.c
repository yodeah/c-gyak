#include <stdio.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define DEBUG 1

int argtest(int argc, const char** argv);
int checkIfCharsAreNumeric(const char* c);
int checkIfFileExists(const char* filename);

int main(int argc, char** argv){
	FILE *fp;
	if(argtest(argc, argv) == TRUE){
		printf("megfelelo parameterek");
	}
		

	getchar();
    return 0;
}

int argtest(int argc, const char** argv){
	if(argc != 4){
		printf ("A megadott parameterek szama nem megfelelo \n");
		return FALSE;
	}
	
	if(!(argv[1][0] == '-' && (argv[1][1] == 'd' || argv[1][1] == 'o') /*&& sizeof(argv[1]) == 2*/)){
		printf("Elso parameter hibasan van megadva (param %s) \n",argv[1]);
		return FALSE;
	}

	if(checkIfCharsAreNumeric(argv[3]) == FALSE){
		printf("nem numerius a megodtt bytok hossza (param:%s) \n",argv[3]);
		return FALSE;
	}

	checkIfFileExists(argv[2]);

	return TRUE;
}

int checkIfCharsAreNumeric(const char* c){
	int i ;

	if(DEBUG == TRUE)
		printf("checkIfCharsAreNumeric input: %s \n strlen char %d \n", c, strlen(c));

	for(i = 0; i<strlen(c); i++){
		if(!(c[i] <= '9' && c[i] >= '0')){
			return FALSE;
		}
	}

	return TRUE;
}

int checkIfFileExists(const char* filename){
	FILE *fp;

	printf("filename: %s \n", filename);

	fp = fopen(filename, "r");

	if(fp == NULL){
		printf("filenemletezik vagy ures \n");
	}else{
		printf("fgetc: %c \n",fgetc(fp));
	}
}