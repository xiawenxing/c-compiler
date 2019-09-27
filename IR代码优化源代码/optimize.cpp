#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<iostream>
#include<string>

#define LINE 1024
static char seps[] = " ,\n";
void someprocess(char *buf, FILE * wp);
void do_mul_oper(char *buf, FILE * wp);


int main()
{
	FILE *fp,*wp;
	char *buf, *filename, *p;
	//printf("input file name:");
	//scanf("%s",filename);
	filename = "multi.ll";
	//filename+=".ll";
	//printf("%s",filename);
	if ((fp=fopen(filename, "r"))==NULL) {
		printf("open file error!!\n");
		return 0 ;
	}
	if ((wp=fopen("result.ll", "w"))==NULL) {
		printf("open file error!!\n");
		return 0;
	}
	buf=(char*)malloc(LINE*sizeof(char));
	while(1) {
		p=fgets(buf,LINE,fp);//	
		someprocess(buf,wp);
		
		if(!p)//跳出循环		
			break;
	}
	fclose(wp);
	system("pause");
	return 0;
}
void someprocess(char *buf, FILE * wp) {
	char * token;
	char temp[1024];
	int flag = 0;
	strcpy(temp, buf);
	token = strtok(temp, seps);
	while (token != NULL)
	{
		/* While there are tokens in "string" */
		if (strcmp(token, "mul") == 0)flag = 1;

		/* Get next token: */
		token = strtok(NULL, seps);
	}
	switch (flag)
	{
	case2:
		break;
	case3:
		break;
	case 1:
		do_mul_oper(buf, wp);
		break;
	case 0:
		fputs(buf, wp);
		break;
	}

}
void do_mul_oper(char *buf, FILE * wp) {
	//%2 = mul i32 %1, 5
	//<result> = shl i32 1, 32
	char * rs[3];
	char * token;
	char temp[1024];
	strcpy(temp, buf);
	int i = 0;
	int count = 0;
	//char *
	token = strtok(temp, seps);
	while (token != NULL)
	{
		/* While there are tokens in "string" */
		if (token[0] == '%') {
			rs[i] = token;
			i++;
		}
		else if (token[0] <= '9'&&token[0] > '0') {
			rs[i] = token;
			count ++;
			i++;
		}
		token = strtok(NULL, seps);

	}
	if (count == 1) {
		int res = 0,i=0;
		//int index;
		char IR1[100] = "  %temp4697 = shl i32 ";
		//char IR2[100] = "  %3 = mul i32 %temp4697, 3\n";
		char IR2[100] = "  ";
		char temp[25];
		if (rs[1][0] <= '9'&&rs[1][0] > '0') {
			//index1 为数字
			while (rs[1][i] != '\0') {
				res = res * 10 + (rs[1][i] - '0');
				i++;
			}
			int exp = 0;
			while (res % 2 == 0) {
				exp++;
				res /= 2;
			}
			_itoa(exp, temp, 10);
			if (exp >= 0) {
				strcat(IR1, rs[2]);
				strcat(IR1, ", ");
				strcat(IR1, temp);
				strcat(IR1, "\n");
				//char IR2[100] = "  %3 = mul i32 %temp4697, 3\n";
				strcat(IR2, rs[0]);
				strcat(IR2, " = mul i32 %temp4697, ");
				_itoa(res, temp, 10);
				strcat(IR2, temp);
				strcat(IR2, "\n");
			}
			
		}
		else {
			while (rs[2][i] != '\0') {
				res = res * 10 + (rs[2][i] - '0');
				i++;
			}

			int exp = 0;
			while (res % 2 == 0) {
				exp++;
				res /= 2;
			}

			_itoa(exp, temp, 10);
			if (exp >= 0) {
				strcat(IR1, rs[1]);
				strcat(IR1, ", ");
				strcat(IR1, temp);
				strcat(IR1, "\n");
				//char IR2[100] = "  %3 = mul i32 %temp4697, 3\n";
				strcat(IR2, rs[0]);
				strcat(IR2, " = mul i32 %temp4697, ");
				_itoa(res, temp, 10);
				strcat(IR2, temp);
				strcat(IR2, "\n");
			}
		}
		std::cout << IR1;
		fputs(IR1, wp);
		fputs(IR2, wp);
	}
}
