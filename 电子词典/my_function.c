#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_function.h"

//输入要查找的数据内容
void ImportData(char *sum, int num)
{
	printf("请输入要查找的英文或中文\n");
	fgets(sum, num, stdin);
	sum[strlen(sum) + 1] = 0;
	return;
}

//计算行数
int lineNum()
{
	FILE *fp = fopen("./dict.txt", "r");
	if (!fp)
	{
		perror("");
	}
	char sum[1000];
	int j = 0;
	while (1)
	{
		if (fgets(sum, sizeof(sum), fp) != NULL)
		{
			j++;
		}
		else
		{
			break;
		}
	}
	/*printf("j=%d\n", j/2);*/
	fclose(fp);
	return j / 2;
}

//读取单词文档
struct english * readFile(int lines) 
{
	FILE *fp = fopen("./dict.txt", "r");
	if (!fp) 
	{
		perror("");
	}
	struct english *p = (struct english *)malloc(sizeof(struct english)*lines);
	char buf[1000];
	for (int i = 0; i >= 0; i++) 
	{
		char *q=fgets(buf, sizeof(buf), fp);
		if (q == NULL) 
		{
			break;
		}
		p[i].e = (char *)malloc(strlen(buf+1)+1);
		strcpy(p[i].e,buf+1 );
		q=fgets(buf, sizeof(buf), fp);
		if (q == NULL)
		{
			break;
		}
		p[i].c = (char *)malloc(strlen(buf+6)+1);
		strcpy(p[i].c, buf+6 );
	}	
	fclose(fp);
	return p;
}

//查找对应的单词
int inSert(struct english * m,char *str,int lines)
{
	
	for(int i=0;i<lines;i++)
	{
		
		if (strcmp(str,m[i].e)== 0)
		{
			printf("翻译结果为:\n");
			printf("%s\n",m[i].c);
			return 1;
			break;
		}
	}
	return 0;
}

//释放空间
void FreeData(struct english * m, int lines) 
{
	for (int i = 0; i<lines; i++)
	{
		free(m[i].e);
		free(m[i].c);
	}
	free(m);
}
