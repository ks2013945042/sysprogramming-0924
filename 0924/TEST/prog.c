#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#define BUF 100
int main(int argc, char* argv[]){
	FILE *fp1;
	FILE *fp2;
	char buffer1[BUF];
	char buffer2[BUF];
	int count = 0;
	
	if((fp1 = fopen(argv[1], O_RDONLY)) == NULL){
		fprintf(stderr, "오픈에러.\n");
		exit(1);
	}

	if((fp2 = fopen(argv[2], O_RDONLY)) == NULL){
		fprintf(stderr, "오픈에러.\n");
		exit(1);
	}

	while(fgets(buffer1, BUF, fp1)){
		while(fgets(buffer2, BUF, fp2)){
			if(strcmp(buffer1, buffer2) != 0)
				printf("%s", buffer1);
			break;
			count = count + 1;
		}
	}
	printf("비교 횟수 %d\n", count);
	fclose(fp1);
	fclose(fp2);
	return 0;
}
