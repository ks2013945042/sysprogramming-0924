#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
//	FILE *fp;
	int fd;
	int word = 0, ch = 0, line = 0;
	char c;
//	fp = fopen(argv[1], O_RDONLY);
	if((fd = open(argv[1], O_RDONLY)) == -1)
		printf("파일 열기 오류\n");
	else printf("파일 %s 열기 성공: %d\n", argv[1], fd);
	while((c = getc(fd)) != EOF)
	{
		word++;
		if(c >= 'a' && c <= 'Z') ch++;
		else if(c == '\n') line++;
	}
	close(fd);

	printf("문자 수: %d\n단어 수: %d\n라인 수: %d\n", word, ch, line);
	return 0;
}
