#pragma once
struct english 
{
	char *e;//指向英文地址
	char *c;//指向中文地址
};
//计算行数
int lineNum();

//读取单词文档
struct english * readFile(int lines);

//输入要查找的数据内容
void ImportData(char *sum,int num);

//查找对应的单词
int inSert(struct english * m, char *str, int lines);

//释放空间
void FreeData(struct english * m, int lines);


