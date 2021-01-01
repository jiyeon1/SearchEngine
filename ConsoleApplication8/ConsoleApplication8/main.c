#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define SPLIT " ()-.,;\"\n"
#define f1 "document1.txt"
#define f2 "document2.txt"
#define f3 "document3.txt"
#define f4 "document4.txt"
#define f5 "document5.txt"
#define f6 "document6.txt"
#define f7 "document7.txt"
#define f8 "document8.txt"
#define f9 "document9.txt"

int numberOfCompare = 0;
int n;

void textcolor(int color_number)

{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

int c(const void *a, const void *b)
{
	numberOfCompare++;
	return strcmp((char *)a, (char *)b);
}

int c2(const void *a, const void *b)
{
	return strcmp((char *)a, (char *)b);
}

FILE *fp1, *fp2, *fp3, *fp4, *fp5, *fp6, *fp7, *fp8, *fp9;
int i, j, k, z;
int j1 = 0, j2 = 0, j3 = 0, j4 = 0, j5 = 0, j6 = 0, j7 = 0, j8 = 0, j9 = 0;
int compare;
char *ptoken1;

char *cdata1[600];
char *cdata2[600];
char *cdata3[600];
char *cdata4[600];
char *cdata5[600];
char *cdata6[600];
char *cdata7[600];
char *cdata8[600];
char *cdata9[600];
char *cdata[6000];
char string1[256];
char string2[256];
char string3[256];
char string4[256];
char string5[256];
char string6[256];
char string7[256];
char string8[256];
char string9[256];
char *char_data;
char temp[20];

char realData[5000][20];
char realData1[500][20];
char realData2[500][20];
char realData3[500][20];
char realData4[500][20];
char realData5[500][20];
char realData6[500][20];
char realData7[500][20];
char realData8[500][20];
char realData9[500][20];




int main(void) {


	//파일 열기
	if ((fp1 = fopen(f1, "r")) == NULL) {
		printf("파일을 열 수 없습니다. \n");
		exit(1);
	}
	if ((fp2 = fopen(f2, "r")) == NULL) {
		printf("파일을 열 수 없습니다. \n");
		exit(1);
	}
	if ((fp3 = fopen(f3, "r")) == NULL) {
		printf("파일을 열 수 없습니다. \n");
		exit(1);
	}
	if ((fp4 = fopen(f4, "r")) == NULL) {
		printf("파일을 열 수 없습니다. \n");
		exit(1);
	}
	if ((fp5 = fopen(f5, "r")) == NULL) {
		printf("파일을 열 수 없습니다. \n");
		exit(1);
	}
	if ((fp6 = fopen(f6, "r")) == NULL) {
		printf("파일을 열 수 없습니다. \n");
		exit(1);
	}
	if ((fp7 = fopen(f7, "r")) == NULL) {
		printf("파일을 열 수 없습니다. \n");
		exit(1);
	}
	if ((fp8 = fopen(f8, "r")) == NULL) {
		printf("파일을 열 수 없습니다. \n");
		exit(1);
	}
	if ((fp9 = fopen(f9, "r")) == NULL) {
		printf("파일을 열 수 없습니다. \n");
		exit(1);
	}


	while (!feof(fp1)) {
		fgets(string1, 256, fp1);	//한 줄씩 string으로 입력
		ptoken1 = strtok(string1, SPLIT);	// 문자열 구분
		while (ptoken1 != NULL) {
			cdata1[j1] = (char *)malloc(50);	//문자열 메모리 선언
			strcpy(cdata1[j1], ptoken1);	//문자열 카피
			j1++;
			ptoken1 = strtok(NULL, SPLIT);
		}
	}


	while (!feof(fp2)) {
		fgets(string2, 256, fp2);	//한 줄씩 string으로 입력
		ptoken1 = strtok(string2, SPLIT);	// 문자열 구분
		while (ptoken1 != NULL) {
			cdata2[j2] = (char *)malloc(50);	//문자열 메모리 선언
			strcpy(cdata2[j2], ptoken1);	//문자열 카피
			j2++;
			ptoken1 = strtok(NULL, SPLIT);
		}
	}

	while (!feof(fp3)) {
		fgets(string3, 256, fp3);	//한 줄씩 string으로 입력
		ptoken1 = strtok(string3, SPLIT);	// 문자열 구분
		while (ptoken1 != NULL) {
			cdata3[j3] = (char *)malloc(50);	//문자열 메모리 선언
			strcpy(cdata3[j3], ptoken1);	//문자열 카피
			j3++;
			ptoken1 = strtok(NULL, SPLIT);
		}
	}

	while (!feof(fp4)) {
		fgets(string4, 256, fp4);	//한 줄씩 string으로 입력
		ptoken1 = strtok(string4, SPLIT);	// 문자열 구분
		while (ptoken1 != NULL) {
			cdata4[j4] = (char *)malloc(50);	//문자열 메모리 선언
			strcpy(cdata4[j4], ptoken1);	//문자열 카피
			j4++;
			ptoken1 = strtok(NULL, SPLIT);
		}
	}

	while (!feof(fp5)) {
		fgets(string5, 256, fp5);	//한 줄씩 string으로 입력
		ptoken1 = strtok(string5, SPLIT);	// 문자열 구분
		while (ptoken1 != NULL) {
			cdata5[j5] = (char *)malloc(50);	//문자열 메모리 선언
			strcpy(cdata5[j5], ptoken1);	//문자열 카피
			j5++;
			ptoken1 = strtok(NULL, SPLIT);
		}
	}


	while (!feof(fp6)) {
		fgets(string6, 256, fp6);	//한 줄씩 string으로 입력
		ptoken1 = strtok(string6, SPLIT);	// 문자열 구분
		while (ptoken1 != NULL) {
			cdata6[j6] = (char *)malloc(50);	//문자열 메모리 선언
			strcpy(cdata6[j6], ptoken1);	//문자열 카피
			j6++;
			ptoken1 = strtok(NULL, SPLIT);
		}
	}


	while (!feof(fp7)) {
		fgets(string7, 256, fp7);	//한 줄씩 string으로 입력
		ptoken1 = strtok(string7, SPLIT);	// 문자열 구분
		while (ptoken1 != NULL) {
			cdata7[j7] = (char *)malloc(50);	//문자열 메모리 선언
			strcpy(cdata7[j7], ptoken1);	//문자열 카피
			j7++;
			ptoken1 = strtok(NULL, SPLIT);
		}
	}


	while (!feof(fp8)) {
		fgets(string8, 256, fp8);	//한 줄씩 string으로 입력
		ptoken1 = strtok(string8, SPLIT);	// 문자열 구분
		while (ptoken1 != NULL) {
			cdata8[j8] = (char *)malloc(50);	//문자열 메모리 선언
			strcpy(cdata8[j8], ptoken1);	//문자열 카피
			j8++;
			ptoken1 = strtok(NULL, SPLIT);
		}
	}


	while (!feof(fp9)) {
		fgets(string9, 256, fp9);	//한 줄씩 string으로 입력
		ptoken1 = strtok(string9, SPLIT);	// 문자열 구분
		while (ptoken1 != NULL) {
			cdata9[j9] = (char *)malloc(50);	//문자열 메모리 선언
			strcpy(cdata9[j9], ptoken1);	//문자열 카피
			j9++;
			ptoken1 = strtok(NULL, SPLIT);
		}
	}



	//소문자 변환
	for (i = 0; i < j1; i++) {
		_strlwr(cdata1[i]);
	}

	for (i = 0; i < j2; i++) {
		_strlwr(cdata2[i]);
	}

	for (i = 0; i < j3; i++) {
		_strlwr(cdata3[i]);
	}

	for (i = 0; i < j4; i++) {
		_strlwr(cdata4[i]);
	}

	for (i = 0; i < j5; i++) {
		_strlwr(cdata5[i]);
	}


	for (i = 0; i < j6; i++) {
		_strlwr(cdata6[i]);
	}


	for (i = 0; i < j7; i++) {
		_strlwr(cdata7[i]);
	}


	for (i = 0; i < j8; i++) {
		_strlwr(cdata8[i]);
	}

	for (i = 0; i < j9; i++) {
		_strlwr(cdata9[i]);
	}


	for (i = 0; i < j1 + j2 + j3 + j4 + j5 + j6 + j7 + j8 + j9; i++)
	{
		cdata[i] = (char *)malloc(sizeof(char) * 50);
	}

	j1--;
	j2--;
	j3--;
	j4--;
	j5--;
	j6--;
	j7--;
	j8--;
	j9--;

	// j1~j4 : 파일마다 중복포함 단어 수

	//merge
	for (i = 0; i < j1; i++)
	{
		cdata[i] = cdata1[i];
	}

	for (i = j1; i < j1 + j2; i++)
	{
		cdata[i] = cdata2[i - j1];
	}

	for (i = j1 + j2; i < j1 + j2 + j3; i++)
	{
		cdata[i] = cdata3[i - j1 - j2];
	}

	for (i = j1 + j2 + j3; i < j1 + j2 + j3 + j4; i++)
	{
		cdata[i] = cdata4[i - j1 - j2 - j3];
	}

	for (i = j1 + j2 + j3 + j4; i < j1 + j2 + j3 + j4 + j5; i++)
	{
		cdata[i] = cdata5[i - j1 - j2 - j3 - j4];
	}

	for (i = j1 + j2 + j3 + j4 + j5; i < j1 + j2 + j3 + j4 + j5 + j6; i++)
	{
		cdata[i] = cdata6[i - j1 - j2 - j3 - j4 - j5];
	}

	for (i = j1 + j2 + j3 + j4 + j5 + j6; i < j1 + j2 + j3 + j4 + j5 + j6 + j7; i++)
	{
		cdata[i] = cdata7[i - j1 - j2 - j3 - j4 - j5 - j6];
	}

	for (i = j1 + j2 + j3 + j4 + j5 + j6 + j7; i < j1 + j2 + j3 + j4 + j5 + j6 + j7 + j8; i++)
	{
		cdata[i] = cdata8[i - j1 - j2 - j3 - j4 - j5 - j6 - j7];
	}

	for (i = j1 + j2 + j3 + j4 + j5 + j6 + j7 + j8; i < j1 + j2 + j3 + j4 + j5 + j6 + j7 + j8 + j9; i++)
	{
		cdata[i] = cdata9[i - j1 - j2 - j3 - j4 - j5 - j6 - j7 - j8];
	}

	int numberOfWord = j1 + j2 + j3 + j4 + j5 + j6 + j7 + j8 + j9;


	for (i = 0; i < numberOfWord; i++)
	{
		strcpy(realData[i], cdata[i]);
	}
	for (i = 0; i < j1; i++)
	{
		strcpy(realData1[i], cdata1[i]);
	}
	for (i = 0; i < j2; i++)
	{
		strcpy(realData2[i], cdata2[i]);
	}
	for (i = 0; i < j3; i++)
	{
		strcpy(realData3[i], cdata3[i]);
	}
	for (i = 0; i < j4; i++)
	{
		strcpy(realData4[i], cdata4[i]);
	}
	for (i = 0; i < j5; i++)
	{
		strcpy(realData5[i], cdata5[i]);
	}
	for (i = 0; i < j6; i++)
	{
		strcpy(realData6[i], cdata6[i]);
	}
	for (i = 0; i < j7; i++)
	{
		strcpy(realData7[i], cdata7[i]);
	}
	for (i = 0; i < j8; i++)
	{
		strcpy(realData8[i], cdata8[i]);
	}
	for (i = 0; i < j9; i++)
	{
		strcpy(realData9[i], cdata9[i]);
	}

	//퀵정렬
	qsort((void *)realData, numberOfWord, sizeof(realData[0]), c2);
	qsort((void *)realData1, j1, sizeof(realData1[0]), c);
	qsort((void *)realData2, j2, sizeof(realData2[0]), c);
	qsort((void *)realData3, j3, sizeof(realData3[0]), c);
	qsort((void *)realData4, j4, sizeof(realData4[0]), c);
	qsort((void *)realData5, j5, sizeof(realData5[0]), c);
	qsort((void *)realData6, j6, sizeof(realData6[0]), c);
	qsort((void *)realData7, j7, sizeof(realData7[0]), c);
	qsort((void *)realData8, j8, sizeof(realData8[0]), c);
	qsort((void *)realData9, j9, sizeof(realData9[0]), c);

	//단어 빈도수 : k로 빈도수 출력도 가능
	for (i = 0; i < numberOfWord; i++) {
		if (i != numberOfWord - 1) {
			numberOfCompare++;
			compare = strcmp(realData[i], realData[i + 1]);
		}
		if (compare != 0 && k != 1) {
			n++;
			k = 1;
		}
		else if (compare != 0 && k == 1) {
			n++;
		}
		else if (compare == 0)
			k++;
	}


	printf("Total number of documents : 9\n");
	printf("Total number of indexed words : %d\n", n);
	printf("Total number of comparison : %d\n", numberOfCompare);



	while (1)
	{
		int numberOfCompare2 = 0;
		printf("Enter Your word. If you wanna terminate this program, Enter Q/q : ");
		char input[105];
		gets(input);

		//q , Q 입력받으면 종료
		if ((input[0] == 'q' || input[0] == 'Q') && input[1] == '\0')
		{
			printf("program terminated.\n");
			return 0;
		}


		int index[105];
		int m = 0;
		int q1 = 0, q2 = 0, q3 = 0, q4 = 0, q5 = 0, q6 = 0, q7 = 0, q8 = 0, q9 = 0; // 파일에 나타난 빈도 수

		for (i = 0; i < numberOfWord; i++)
		{
			numberOfCompare2++;
			if (!strcmp(input, cdata[i]))
			{
				index[m] = i;
				m++;
			}
		}

		index[m] = -1;

		for (i = 0; i < m; i++)
		{
			if (index[i] < j1)
				q1++;
			else if (index[i] < j1 + j2)
				q2++;
			else if (index[i] < j1 + j2 + j3)
				q3++;
			else if (index[i] < j1 + j2 + j3 + j4)
				q4++;
			else if (index[i] < j1 + j2 + j3 + j4 + j5)
				q5++;
			else if (index[i] < j1 + j2 + j3 + j4 + j5 + j6)
				q6++;
			else if (index[i] < j1 + j2 + j3 + j4 + j5 + j6 + j7)
				q7++;
			else if (index[i] < j1 + j2 + j3 + j4 + j5 + j6 + j7 + j8)
				q8++;
			else if (index[i] < j1 + j2 + j3 + j4 + j5 + j6 + j7 + j8 + j9)
				q9++;
		}

		int s1 = 0;
		int s2 = q1;
		int s3 = q1 + q2;
		int s4 = q1 + q2 + q3;
		int s5 = q1 + q2 + q3 + q4;
		int s6 = q1 + q2 + q3 + q4 + q5;
		int s7 = q1 + q2 + q3 + q4 + q5 + q6;
		int s8 = q1 + q2 + q3 + q4 + q5 + q6 + q7;
		int s9 = q1 + q2 + q3 + q4 + q5 + q6 + q7 + q8;

		printf("\n");

		// 출력해주는 과정

		while (q1 != 0 || q2 != 0 || q3 != 0 || q4 != 0 || q5 != 0 || q6 != 0 || q7 != 0 || q8 != 0 || q9 != 0)
		{

			if (q1 >= q2 && q1 >= q3 && q1 >= q4 && q1 >= q5 && q1 >= q6 && q1 >= q7 && q1 >= q8 && q1 >= q9)
			{
				printf("\n");
				printf("<document1.txt> ");
				printf("%s : ", input);
				printf("%d\n", q1);
				while (1)
				{
					if (index[s1] >= 4)
						printf(" ... ");
					for (i = -4; i <= 4; i++)
					{
						if (index[s1] + i >= 0)
						{
							if (i == 0)
							{
								textcolor(14);
							}

							printf("%s ", cdata[index[s1] + i]);

							textcolor(7);

						}
					}
					if (index[s1] < j1 - 4)
						printf(" ... \n");
					else
						printf("\n");

					s1++;
					q1--;

					if (q1 == 0 || index[s1] == -1)
						break;
					continue;
				}
			}
			else if (q2 >= q1 && q2 >= q3 && q2 >= q4 && q2 >= q5 && q2 >= q6 && q2 >= q7 && q2 >= q8 && q2 >= q9)
			{
				printf("\n");
				printf("<document2.txt> ");
				printf("%s : ", input);
				printf("%d\n", q2);
				while (1)
				{
					if (index[s2] >= j1 + 4)
						printf(" ... ");
					for (i = -4; i <= 4; i++)
					{
						if (index[s2] + i >= j1 && index[s2] + i < j1 + j2)
						{
							if (i == 0)
							{
								textcolor(14);
							}

							printf("%s ", cdata[index[s2] + i]);

							textcolor(7);

						}
					}
					if (index[s2] < j1 + j2 - 4)
						printf(" ... \n");
					else
						printf("\n");
					s2++;
					q2--;
					if (q2 == 0 || index[s2] == -1)
						break;
					continue;
				}
			}
			else if (q3 >= q1 && q3 >= q2 && q3 >= q4 && q3 >= q5 && q3 >= q6 && q3 >= q7 && q3 >= q8 && q3 >= q9)
			{
				printf("\n");
				printf("<document3.txt> ");
				printf("%s : ", input);
				printf("%d\n", q3);
				while (1)
				{
					if (index[s3] >= j1 + j2 + 4)
						printf(" ... ");
					for (i = -4; i <= 4; i++)
					{
						if (index[s3] + i >= j1 + j2 && index[s3] + i < j1 + j2 + j3)
						{
							if (i == 0)
							{
								textcolor(14);
							}

							printf("%s ", cdata[index[s3] + i]);

							textcolor(7);

						}
					}
					if (index[s3] < j1 + j2 + j3 - 4)
						printf(" ... \n");
					else
						printf("\n");
					s3++;
					q3--;
					if (q3 == 0 || index[s3] == -1)
						break;
					continue;
				}

			}
			else if (q4 >= q1 && q4 >= q2 && q4 >= q3 && q4 >= q5 && q4 >= q6 && q4 >= q7 && q4 >= q8 && q4 >= q9)
			{
				printf("\n");
				printf("<document4.txt> ");
				printf("%s : ", input);
				printf("%d\n", q4);
				while (1)
				{
					if (index[s4] >= j1 + j2 + j3 + 4)
						printf(" ... ");
					for (i = -4; i <= 4; i++)
					{
						if (index[s4] + i < numberOfWord)
						{
							if (i == 0)
							{
								textcolor(14);
							}

							printf("%s ", cdata[index[s4] + i]);

							textcolor(7);

						}
					}
					if (index[s4] < j1 + j2 + j3 + j4 - 4)
						printf(" ... \n");
					else
						printf("\n");
					s4++;
					q4--;
					if (q4 == 0 || index[s4] == -1)
						break;
					continue;
				}

			}
			else if (q5 >= q1 && q5 >= q2 && q5 >= q3 && q5 >= q4 && q5 >= q6 && q5 >= q7 && q5 >= q8 && q5 >= q9)
			{
				printf("\n");
				printf("<document5.txt> ");
				printf("%s : ", input);
				printf("%d\n", q5);
				while (1)
				{
					if (index[s5] >= j1 + j2 + j3 + j4 + 4)
						printf(" ... ");
					for (i = -4; i <= 4; i++)
					{
						if (index[s5] + i < numberOfWord)
						{
							if (i == 0)
							{
								textcolor(14);
							}

							printf("%s ", cdata[index[s5] + i]);

							textcolor(7);

						}
					}
					if (index[s5] < j1 + j2 + j3 + j4 - 4)
						printf(" ... \n");
					else
						printf("\n");
					s5++;
					q5--;
					if (q5 == 0 || index[s5] == -1)
						break;
					continue;
				}

			}
			else if (q6 >= q1 && q6 >= q2 && q6 >= q3 && q6 >= q4 && q6 >= q5 && q6 >= q7 && q6 >= q8 && q6 >= q9)
			{
				printf("\n");
				printf("<document6.txt> ");
				printf("%s : ", input);
				printf("%d\n", q6);
				while (1)
				{
					if (index[s6] >= j1 + j2 + j3 + j4 + j5 + 4)
						printf(" ... ");
					for (i = -4; i <= 4; i++)
					{
						if (index[s6] + i < numberOfWord)
						{
							if (i == 0)
							{
								textcolor(14);
							}

							printf("%s ", cdata[index[s6] + i]);

							textcolor(7);

						}
					}
					if (index[s6] < j1 + j2 + j3 + j4 + j5 + j6 - 4)
						printf(" ... \n");
					else
						printf("\n");
					s6++;
					q6--;
					if (q6 == 0 || index[s6] == -1)
						break;
					continue;
				}

			}
			else if (q7 >= q1 && q7 >= q2 && q7 >= q3 && q7 >= q4 && q7 >= q5 && q7 >= q6 && q7 >= q8 && q7 >= q9)
			{
				printf("\n");
				printf("<document7.txt> ");
				printf("%s : ", input);
				printf("%d\n", q7);
				while (1)
				{
					if (index[s7] >= j1 + j2 + j3 + j4 + j5 + j6 + 4)
						printf(" ... ");
					for (i = -4; i <= 4; i++)
					{
						if (index[s7] + i < numberOfWord)
						{
							if (i == 0)
							{
								textcolor(14);
							}

							printf("%s ", cdata[index[s7] + i]);

							textcolor(7);

						}
					}
					if (index[s7] < j1 + j2 + j3 + j4 + j5 + j6 + j7 - 4)
						printf(" ... \n");
					else
						printf("\n");
					s7++;
					q7--;
					if (q7 == 0 || index[s7] == -1)
						break;
					continue;
				}

			}
			else if (q8 >= q1 && q8 >= q2 && q8 >= q3 && q8 >= q4 && q8 >= q5 && q8 >= q6 && q8 >= q7 && q8 >= q9)
			{
				printf("\n");
				printf("<document8.txt> ");
				printf("%s : ", input);
				printf("%d\n", q8);
				while (1)
				{
					if (index[s8] >= j1 + j2 + j3 + j4 + j5 + j6 + j7 + 4)
						printf(" ... ");
					for (i = -4; i <= 4; i++)
					{
						if (index[s8] + i < numberOfWord)
						{
							if (i == 0)
							{
								textcolor(14);
							}

							printf("%s ", cdata[index[s8] + i]);

							textcolor(7);

						}
					}
					if (index[s7] < j1 + j2 + j3 + j4 + j5 + j6 + j7 + j8 - 4)
						printf(" ... \n");
					else
						printf("\n");
					s8++;
					q8--;
					if (q8 == 0 || index[s8] == -1)
						break;
					continue;
				}

			}
			else if (q9 >= q1 && q9 >= q2 && q9 >= q3 && q9 >= q4 && q9 >= q5 && q9 >= q6 && q9 >= q7 && q9 >= q8)
			{
				printf("\n");
				printf("<document9.txt> ");
				printf("%s : ", input);
				printf("%d\n", q9);
				while (1)
				{
					if (index[s4] >= j1 + j2 + j3 + j4 + j5 + j6 + j7 + j8 + 4)
						printf(" ... ");
					for (i = -4; i <= 4; i++)
					{
						if (index[s9] + i < numberOfWord)
						{
							if (i == 0)
							{
								textcolor(14);
							}

							printf("%s ", cdata[index[s9] + i]);

							textcolor(7);

						}
					}
					if (index[s9] < j1 + j2 + j3 + j4 + j5 + j6 + j7 + j8 + j9 - 4)
						printf(" ... \n");
					else
						printf("\n");
					s9++;
					q9--;
					if (index[s9] == -1)
						break;
					continue;
				}

			}
		}

		//일치하는 것 없을 때
		if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0 && s5 == 0 && s6 == 0 && s7 == 0 && s8 == 0 && s9 == 0)
			printf("Not Found!!\n");

		printf("\nTotal number of comparision: %d\n", numberOfCompare2);

	}

	//파일 닫기
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
	fclose(fp4);
	fclose(fp5);
	fclose(fp6);
	fclose(fp7);
	fclose(fp8);
	fclose(fp9);

	//동적할당 해제
	for (i = 0; i < j1; i++) {
		free(cdata1[i]);
	}
	for (i = 0; i < j2; i++) {
		free(cdata2[i]);
	}
	for (i = 0; i < j3; i++) {
		free(cdata3[i]);
	}
	for (i = 0; i < j4; i++) {
		free(cdata4[i]);
	}
	for (i = 0; i < j5; i++) {
		free(cdata5[i]);
	}
	for (i = 0; i < j6; i++) {
		free(cdata6[i]);
	}
	for (i = 0; i < j7; i++) {
		free(cdata7[i]);
	}
	for (i = 0; i < j8; i++) {
		free(cdata8[i]);
	}
	for (i = 0; i < j9; i++) {
		free(cdata9[i]);
	}
	return 0;
}

