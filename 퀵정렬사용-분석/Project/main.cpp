#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include "project.h"

#define TABLE_SIZE 100 //127-24125, 255-17107, 511 - 14503, 1023 - 12885 2047- 12~~~

int compare = 0; //비교횟수 comparison
int indexed_num = 0; // 색인한 단어의 갯수
int indexed_doc = 0; // 색인된 txt수
char doc_name[10][100];

void build_dictionary(char *fname);
int hash(char *key);
void create_table(hash_link *hlp, char *alphabat);
void create_place(place_link *wtp);
void search(char *alphabet);

hash_table table[TABLE_SIZE];

void main()
{
	printf("********** Command **********\n");
	printf(" R: Read file and Index\n");
	printf(" S: Search Word, Q: Quit\n");
	printf("*****************************\n");

	while (1)
	{
		char c, search_word[50];
		printf("\n Command > ");
		c = getch();
		putch(c);
		c = toupper(c);
		switch (c)
		{

		case 'R':
			build_dictionary("document1.txt");
			build_dictionary("document2.txt");
			build_dictionary("document3.txt");
			build_dictionary("document4.txt");
			build_dictionary("document5.txt");
			build_dictionary("document6.txt");
			build_dictionary("document7.txt");
			build_dictionary("document8.txt");
			build_dictionary("document9.txt");
			printf("\n\n  Total number of documents: %d", indexed_doc);
			printf("\n  Total number of indexed words: %d", indexed_num);
			printf("\n  Total number of comparison: %d\n", compare);
			break;
		case 'S':
			printf("\n Search Word > ");
			scanf("%s", search_word);
			search(search_word);
			break;
		case 'Q':
			printf("\n");
			exit(1);
		default:
			break;
		}


	}
}

void create_table(hash_link *hlp, char *alphabat)
{
	int i = 0;
	hash_link n_table = (hash_link)malloc(sizeof(hash_table));
	n_table->next_tablelink = NULL;
	n_table->strlen = 0; //길이 초기화
	for (i = 0; i < 10; i++)  //모든 txt파일에서 변수를 초기화시킴 (처음 만드므로 !)
	{
		n_table->freq[i] = 0; //출연빈도 일단 0으로 초기화시킴
		n_table->existence[i] = false; //일단 0으로 초기화 
		n_table->place[i].rear_cursor = 0; //뒷커서 초기화!
	}
	strcpy(n_table->word, alphabat); //받은 단어 복사 
	((*hlp)->next_tablelink) = n_table; //테이블 연결시킴
	(*hlp) = n_table;  // 생성완료
}

void create_place(place_link *wtp)  //새 place를 생성한다.  
{
	place_link n_place = (place_link)malloc(sizeof(place)); //동적할당
	(*wtp)->next_place = n_place;  //새로운거 연결시킴
	n_place->next_place = NULL;   //연결할 다음거에는 아무것도 없으므로 null
	(*wtp) = n_place;           // 새로운 변수
	(*wtp)->rear_cursor = 0;   //뒷커서 초기화
}


int hash(char *key)
{
	int result = 0;
	while (*key)
	{
		result += *key++;
	}
	return result%TABLE_SIZE;
}

void search(char* alphabet)
{

	hash_link hlp;  //hash link pointer
	int priority[10]; // 출현 빈도에 따라 우선순위를 정할 변수
	boolean table_check[10] = { 0 }; // 정렬된 문서를 체크할 배열
	int i = 0, j = 0, encl_word = indexed_doc; // 단어를 포함한 문서수를 저장
	char temp[100];  //임시 저장
	compare = 0;  //비교회수 
	strcpy(temp, alphabet); // 받은 단어를 임시로 저장해놓는다.
	while (temp[i] != '\0') //  임시로 저장한 단어의 끝을 null값으로 알려줌 
	{
		alphabet[j++] = tolower(temp[i]);  //대소문자 변경 함수
		i++;
	}
	alphabet[j] = '\0'; //  임시로 저장한 단어의 끝을 null값으로 알려줌 
	if (alphabet[0] == '\0') //빈단어는 예외
	{
		printf("\n  '%s'는(은) 올바른 단어가 아닙니다 !", temp);
		return;
	}
	hlp = &table[hash(alphabet)];
	while (hlp->strlen != j && hlp->next_tablelink) // 테이블에서 맞는 단어를 찾는 과정, 일단 글자수가 맞지않으면 비교자체를 하지않는다 
		hlp = hlp->next_tablelink;
	compare++;
	while (strcmp(hlp->word, alphabet) != 0)
	{
		if (!hlp->next_tablelink) // 테이블에서 찾는 단어가 없을경우
		{
			printf("\n \"%s\" 는 없는 단어입니다 !!\n", alphabet);
			return;
		}
		hlp = hlp->next_tablelink;  //다음 테이블 탐색
		compare++;  //비교횟수증가 strcmp를 썻으므로.
	}
	for (i = 0; i < indexed_doc; i++)
	{
		int max_top = INT_MAX;
		int top, top_index;
		top = 0;
		for (j = 0; j < indexed_doc; j++)
		{
			if ((hlp->freq[j] > top) && table_check[j] == 0)
			{
				top = hlp->freq[j]; // 찾는 단어가 많이 등장하는 문서부터 정리하기 위함
				top_index = j;
			}
		}
		if (hlp->freq[i] == 0)
			encl_word--;
		priority[i] = top_index; // 우선순위 부여
		table_check[top_index] = 1; // 확인완료 표시
		max_top = top;
	}
	printf("======================================");
	for (i = 0; i < encl_word; i++) // 찾는 단어가 있는 txt파일수 만큼 반복
	{
		place_link plp = &hlp->place[priority[i]];
		FILE *ifp = fopen(doc_name[priority[i]], "r");
		char p_word[100];
		printf("\n <%s> %s: %d\n", doc_name[priority[i]], temp, hlp->freq[priority[i]]);
		while (1)
		{
			fseek(ifp, plp->front_cursor, SEEK_SET);
			if (plp->front_cursor != 0) // 맨 앞 커서가 파일의 맨앞이 아닐경우 ...처리
				printf("...");
			for (j = 0; j < 9; j++)
			{
				if (fscanf(ifp, "%s", p_word) == 0) // 읽을 단어 없으면 for문 탈출
					break;
				printf(" %s", p_word);
				long ft = ftell(ifp); // 현재 위치를 기록한다
				if (ftell(ifp) >= plp->rear_cursor) // 커서가 뒷단어를 4개이상 표시 하지 않게한다.
					break;
			}
			if (fscanf(ifp, "%s", p_word) > 0) // 더 읽을 단어가 있다면 ...처리
				printf(" ...");
			printf("\n");
			if (plp->next_place != NULL) // 찾는 단어가 또 있으면 다음 place로 이동한다
				plp = plp->next_place;
			else
				break;
		}
		fclose(ifp);
	}
	printf("\n Total number of comparison: %d\n", compare);
	printf("======================================\n");
}





void build_dictionary(char* fname)
{
	FILE *ifp; // 파일 포인터 선언
	int file_pointer[4] = { 0 }; // 커서의 현위치를 저장한다
	int file_pointer_index = 4; // 인덱스 변수 4인 이유는 앞뒤 3글자를 표현하기 위함이다
	int i;
	place_link cursor[4] = { 0 }; //place의 주소를 저장한다
	int cursor_index = 4; //  인덱스 변수 4인 이유는 앞뒤 3글자를 표현하기 위함이다
	hash_link hlp; // hash link pointer
	place_link plp; // place link pointer
	long ft = 0; // 커서 저장
	char string[100]; // 문자열 자체를 저장함
	char alphabet[100]; // 오직 영문자만 저장함
	if (indexed_doc == 10) // 문서 최대수 달성시
	{
		printf("\n  파일을 이미 다 읽었습니다!\n");
		return;
	}
	strcpy(doc_name[indexed_doc], fname); // 문서이름 저장, 우선순위로 나타낼때 이용
	if ((ifp = fopen(fname, "r")) == NULL) // 파일 열기를 실패했을경우
	{
		printf("\n  파일을 찾지 못했습니다\n", fname);
		return;
	}
	while (fscanf(ifp, "%s", string) == 1) // 문자열 없을때까지 반복함
	{
		indexed_num++;
		int i, j;  // string[i]는 영문자만 받는것이아니라 문자 자체를 받는다 (1개씩)	
		i = j = 0;  //영문자만 alphabet[j]에 저장하고 단어의 끝을 알리기위해 마지막 부분에는 NULL값을 저장한다.
		while (string[i] != '\0')
		{
			alphabet[j++] = tolower(string[i]);
			if (alphabet[j - 1] == NULL) //특수문자 제외
			{
				j--;
			}

			i++; //문자수 카운트 
		}
		if (!j)	continue; // 문자 없는경우 다음 문자열로 이동
		alphabet[j] = '\0'; // 마지막을 문자열의 끝을 알리는 '\0' 삽입 

							//단어를 저장 하기 전에 읽은 단어에 key값을 부여하고 저장 하기 위한 과정이다 
		hlp = &table[hash(alphabet)]; // == hash_table을 가르키는 구조체 변수 tp에다가 해싱을 거친 단어를 저장한 table[해싱으로 변환한 키값]을 저장한다.
		while (hlp->strlen != j && hlp->next_tablelink) //빈 테이블로 이동한다
		{
			hlp = hlp->next_tablelink; //다음 테이블로 이동 
		}

		//스트링 비교를 수행하려고 하는데 스트링 비교를 실행 하지않을경우네는 --처리를 해 반복횟수를 0으로 만든다  
		compare++; // strcmp 카운트
		while (hlp->strlen == 0 || strcmp(alphabet, hlp->word) != 0) // 단어를 찾을때까지 혹은 단어가 일치 하지 않을때 까지 반복
																	 //반복 조건 단어 길이가 0이거나 (단어가 없거나) , 받은 단어가 테이블이 가르키는 단어와 다를때 반복
																	 //단어가 채워지고 같은 단어가 아닐경우 반복 중단 
		{
			if (hlp->strlen == 0) // strcmp가 수행되지 않았을경우 카운팅 --
			{
				compare--;
			}
			if (!(hlp->next_tablelink)) // 단어에 해당하는 table 없을경우 새로생성 
										// tp 가 null가리킬 경우
			{
				create_table(&hlp, alphabet); //새테이블 생성
				break;
			}
			hlp = hlp->next_tablelink;  //tp는 현재 뉴테이블이다,. 뉴테이블이 가리키는 next_word가 가리키는 주소를 tp에다가 저장
			compare++; //비교횟수 증가
		}

		hlp->freq[indexed_doc]++; // 해당문서의 단어 출현수 증가 
		hlp->existence[indexed_doc] = true; // 해당문서에 단어가 출현함을 확인
		hlp->strlen = j; //단어길이 j
		plp = &hlp->place[indexed_doc]; // 단어 위치 플레이스에 기록. 

		while (plp->rear_cursor != 0)
		{
			if (plp->next_place) // 맨뒤 플레이스까지 이동함 null나올때까지 반복
				plp = plp->next_place;
			else
				break;
		}
		if (plp->rear_cursor != 0) // 새로운 플레이스를 만듬
		{

			create_place(&plp);
		}
		plp->next_place = NULL;
		cursor[cursor_index++ % 5] = plp; // 지금 단어를 기록한다
		plp->front_cursor = file_pointer[(file_pointer_index - 5) % 5]; // 1,2,3번째 단어 기록 
		if (cursor_index > 9) // 7단어 초과하면 기록안함
			cursor[cursor_index % 5]->rear_cursor = ftell(ifp); //ifp 파일 포인터 변수
		file_pointer[file_pointer_index++ % 5] = ftell(ifp); //현재 위치를 입력함
	}
	for (i = 0; i < 5; i++) // 남은 단어 뒷커서 가장 뒤로 기록함
	{
		cursor[cursor_index++ % 5]->rear_cursor = ftell(ifp);
	}
	indexed_doc++; //문서 인덱스후 다음문서 인덱스찾는용
	fclose(ifp);   //txt 닫음
	printf("\n  인덱스 완료! ( -> %s )", fname);
}

