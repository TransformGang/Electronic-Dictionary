#include <stdio.h>
#include <stdlib.h>
#include "my_function.h"
int main() 
{
	while (1) 
	{
		char sum[20];
		int num = sizeof(sum) / sizeof(sum[0]);
		ImportData(sum,num);
		int lines_num = lineNum();
		struct english *m = readFile(lines_num);
		int n = inSert(m, sum, lines_num);
		if (n != 1)
		{
			printf("ÊäÈë´íÎó!\n");
		}
		FreeData(m, lines_num);
	}
	system("pause");
}