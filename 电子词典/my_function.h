#pragma once
struct english 
{
	char *e;//ָ��Ӣ�ĵ�ַ
	char *c;//ָ�����ĵ�ַ
};
//��������
int lineNum();

//��ȡ�����ĵ�
struct english * readFile(int lines);

//����Ҫ���ҵ���������
void ImportData(char *sum,int num);

//���Ҷ�Ӧ�ĵ���
int inSert(struct english * m, char *str, int lines);

//�ͷſռ�
void FreeData(struct english * m, int lines);


