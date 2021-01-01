#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include "project.h"

int main() {
	make_hashtable("document1.txt");
	make_hashtable("document2.txt");
	make_hashtable("document3.txt");
	make_hashtable("document4.txt");
	make_hashtable("document5.txt");
	make_hashtable("document6.txt");
	make_hashtable("document7.txt");
	make_hashtable("document8.txt");
	make_hashtable("document9.txt");

	print_index();

	while (1) {
		search();
	}
}
void search()
{

	char search_word[MAX_CHAR] = { 0 }; //찾는단어저장배열
										//strcpy(text_file,"");//파일을읽어와저장해놓을문자열
	for (int i = 0; i < 10; i++)
		strcpy(result_file[i], "");
	//파일별빈도횟수저장배열-> insertion sort에서쓸배열
	for (int i = 0; i < 10; i++)
		max_file[i] = 0;
	for (int i = 0; i < 10; i++)
		max_file_temp[i] = 0;//파일별빈도횟수저장배열-> 단어등장횟수출력을위해저장해두는배열
	for (int i = 0; i <= 9; i++) {
		max_num[i] = i;
	}
	printf("\n Enter Your word >> ");
	textcolor(14);
	scanf("%s", search_word); //찾는단어검색받음
	textcolor(7);

	strlwr(search_word);//검색단어소문자로바꿈

	search_ready("document1.txt", search_word);
	search_ready("document2.txt", search_word);
	search_ready("document3.txt", search_word);
	search_ready("document4.txt", search_word);
	search_ready("document5.txt", search_word);
	search_ready("document6.txt", search_word);
	search_ready("document7.txt", search_word);
	search_ready("document8.txt", search_word);
	search_ready("document9.txt", search_word);

	print_search(search_word);
}
void search_ready(char* file_name, char* search_word)
{

	int search_index = hash(search_word);//해싱
	tree_ptr result_node = search_node(hash_table[search_index], search_word);//search함수로찾는단어의노드반환
	save_result(result_node, file_name);
}

tree_ptr search_node(tree_ptr tree, char * key)
{
	if (tree == NULL)   return NULL; //tree가없으면널값반환
	else {
		int temp = strcmp(key, tree->item->search_word);//key값과tree의key값비교
		num_compare_search++;
		switch (temp) {
		case 0://트리의key값이같으면
			return tree;//현재트리노드반환
		case -1://트리의key값이크면
			return   search_node(tree->left_child, key);//left_child로들어가서검색
		case 1://트리의key값이작으면
			return   search_node(tree->right_child, key);//right child로들어가서검색
		}
	}
}

void save_result(tree_ptr result_node, char* file_name)
{
	if (result_node == NULL) {//받아온트리노드가없으면
		return;
	}
	tree_ptr temp;

	char text[MAX_CHAR] = { 0 }; //이을텍스트를저장
	for (temp = result_node; temp; temp = temp->link) {
		if (strcmp(temp->item->file_name, file_name) == 0) {
			max_file[file_name[8] - '0']++; //파일별빈도횟수+1
			char tmp[MAX_CHAR] = { 0 }; //한줄저장
			int count = 0;
			for (element_ptr word_ptr = temp->item; word_ptr; word_ptr = word_ptr->last) {
				count++;
				if (count > 5) {//전단어가4개를넘어가면
					char q[MAX_CHAR] = { 0 };//임시문자열
					strcpy(q, tmp); //q에tmp 임시저장
					strcpy(tmp, "..."); //tmp에...   대입
					strcat(tmp, q);   //tmp에저장해둔q 이어붙임
					break;
				}
				char q[MAX_CHAR] = { 0 };//임시문자열
				strcpy(q, tmp); //q에tmp임시저장
				strcpy(tmp, word_ptr->word);//tmp에현재단어대입
				strcat(tmp, " "); //띄어쓰기
				strcat(tmp, q);   //tmp에저장해둔문자열이어붙임
			}
			count = 0;
			for (element_ptr word_ptr = temp->item->next; word_ptr; word_ptr = word_ptr->next) {
				count++;
				if (count > 4) {//나중단어가4개를넘어가면
					strcat(tmp, "...");//... 이어붙임
					break;
				}
				strcat(tmp, word_ptr->word);//현재단어이어붙임
				strcat(tmp, " "); //띄어쓰기
			}
			strcat(tmp, "\n");
			strcat(text, tmp);//한줄text에저장해둠
		}
	}
	strcat(result_file[file_name[8] - '0'], text);//text를저장

	for (int i = 0; i < 10; i++) {
		max_file_temp[i] = max_file[i]; //등장횟수복사해둠
	}
}

void print_search(char * search_word) {
	insertion_sort(max_file, max_num, 10); //빈도가많은순으로정렬

	for (int j = 0; j < 10; j++) { //빈도가많은순으로정렬된파일번호에따라출력
		if (strcmp(result_file[max_num[j]], "") == 0) { //단어가더이상없는파일이면그만출력
			if (j == 0) {
				printf("검색 결과가 없습니다.\n");
				return;
			}
			break;
		}
		printf("   <document");
		textcolor(11);
		printf("%d", max_num[j]);
		textcolor(7);
		printf(".txt>  %s : ", search_word);
		textcolor(11);
		printf("%d\n", max_file_temp[max_num[j]]);
		textcolor(7);

		printf("  %s\n", result_file[max_num[j]]);
	}
	printf("   Total number of comparison : ");
	textcolor(14);
	printf("%d\n\n", num_compare_search);
	textcolor(7);
}
void insertion_sort(int list[], int store[], int n) { //삽입정렬
	for (int i = 1; i < n; i++) {
		int next = list[i];

		int j;
		for (j = i - 1; j >= 0 && (next > list[j]); j--) //빈도횟수가전파일보다크면파일번호와같이바꾸기
		{
			list[j + 1] = list[j];
			store[j + 1] = store[j];
		}
		list[j + 1] = next;
		store[j + 1] = i;
	}
}
void make_hashtable(char* file_name) {
	FILE *of = fopen(file_name, "r");
	num_document++;
	element_ptr last_element = NULL;   //전 단어 노드를 가리키는 포인터

	char token[CHAR_MAX];
	while (fscanf(of, "%s", token) != EOF) {
		/***HASHTABLE에 삽입**/
		element_ptr temp = (element_ptr)malloc(sizeof(element));
		temp->last = NULL;
		temp->next = NULL;
		strcpy(temp->file_name, file_name);   //파일명 저장
		strcpy(temp->word, token);      //출력용단어 저장

		char tmp[MAX_CHAR] = { 0 };
		if (isalpha_made(token[0]) == 0) {//첫글자가 영문자가 아니면
			int flag = 0; //영문자를 만나지 않으면 0, 만나면 1
			int index = 0;
			for (int i = 1; i < token[i] != '\0'; i++) {
				if (flag == 0 && isalpha_made(token[i]) == 0) {//계속 영문자가 아닌 문자 등장하면
					continue;
				}
				else if (flag == 1 && isalpha_made(token[i]) == 0) {//영문자 -> 문자
					if (token[i + 1] == '\0')//마지막 문자
						break;
					else index++;
				}
				else if (isalpha_made(token[i]) != 0 && flag == 0) {//문자 -> 영문자
					flag = 1;
					index = i;
					tmp[i - index] = tolower(token[i]);//문자 소문자로 저장
				}
				else {//계속 영문자 등장
					tmp[i - index] = tolower(token[i]);//문자 소문자로 저장
				}
			}
		}
		else {//첫글자가 영문자이면
			int index = 0;
			for (int i = 0; token[i] != '\0'; i++) {
				if (isalpha_made(token[i]) == 0) {//영문자가 아니면
					if (token[i + 1] == '\0')//마지막 문자면
						break;
					else index++;
				}
				else {
					tmp[i - index] = tolower(token[i]);//문자 소문자로 저장
				}
			}
		}
		textcolor(14);
		strcpy(temp->search_word, tmp); //검색용 단어 저장
		textcolor(7);

		temp->last = last_element;         //전 단어를 가리키는 포인터 저장
		if (last_element != NULL)         //전 단어가 존재하면
			last_element->next = temp;      //전 단어가 다음단어를 가리키도록 포인터 저장
		last_element = temp;            //전노드를 가리키는 포인터에 자기 자신 저장

		insert_node(temp);               //노드 추가
	}
}

int hash(char *   key)
{
	return tolower(key[0]) - 'a';//검색용단어의첫글자로해싱
}

void insert_node(element_ptr item)
{
	int i = hash(item->search_word); //해싱된숫자

	//새로운단어의노드생성
	tree_ptr new_node = (tree_ptr)malloc(sizeof(node));
	new_node->item = item;
	new_node->left_child = NULL;
	new_node->right_child = NULL;
	new_node->link = NULL;

	if (hash_table[i] == NULL) {//root가널값이면루트에다가노드생성
		num_word++;
		hash_table[i] = new_node;
		return;
	}
	tree_ptr temp = hash_table[i];
	while (temp != NULL) {
		int num = strcmp(temp->item->search_word, item->search_word); //현재트리노드와비교
		num_compare_string++;
		if (num == 0) {//같은값이있으면
					   //링크드리스트로연결한다
			tree_ptr p = temp;
			for (p = temp; p->link != NULL; p = p->link);
			p->link = new_node;
			return;
		}
		else if (num == 1) {//temp의key값이삽입할key값보다크다면
			if (temp->left_child == NULL) { //비어있다면 
				temp->left_child = new_node;//왼쪽노드에삽입
				num_word++;
				return;
			}
			temp = temp->left_child;
		}
		else if (num == -1) {//temp의key값이삽입할key값보다작다면
			if (temp->right_child == NULL) {//비어있다면
				temp->right_child = new_node;//오른쪽노드에삽입
				num_word++;
				return;
			}
			temp = temp->right_child;
		}
	}
}

void print_index()
{
	printf(" Total number of documents: %d\n", num_document);
	printf(" Total number of indexed words: %d\n", num_word);
	printf(" Total number of comparison: %d\n", num_compare_string);
}

int isalpha_made(char a)
{ //알파벳인지 아닌지 확인하는 함수
	if ((a >= 'a'&& a <= 'z') || (a >= 'A'&& a <= 'Z'))
		return 1;
	else
		return 0;
}
void textcolor(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}