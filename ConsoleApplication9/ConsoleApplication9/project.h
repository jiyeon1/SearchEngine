#pragma once
#define MAX_CHAR 100000
#define TABLE_SIZE 26
int num_document;//색인한 자료 수
int num_word;//총 단어 수
int num_compare_string;//색인과정중 문자열 비교 횟수
int num_compare_search;//검색과정중 문자열 비교 횟수
char text_file[CHAR_MAX];//파일을 읽어와 저장해 놓을 문자열
char result_file[10][MAX_CHAR] = { 0 };
int max_file[10] = { 0 }; //파일별 빈도 횟수 저장 배열 -> insertion sort에서 쓸 배열
int max_file_temp[10] = { 0 };//파일별 빈도 횟수 저장 배열 -> 단어 등장 횟수 출력을 위해 저장해두는 배열
int max_num[10] = { 0,1,2,3,4,5,6,7,8,9 }; //빈도횟수가 많은 파일부터 저장할 배열 초기화는 1부터 차례대로

typedef struct element *element_ptr;
typedef struct element {
	char word[MAX_CHAR];//출력용 단어
	char search_word[MAX_CHAR];//검색용 단어
	char file_name[MAX_CHAR];
	element_ptr last;
	element_ptr next;
	/* other fields */
} element;
//이진트리의 노드와 노드 포인터
typedef struct node *tree_ptr;
typedef struct node {
	element_ptr item;
	tree_ptr left_child;
	tree_ptr right_child;
	tree_ptr link;
}node;
void insert_node(element_ptr item);//노드 삽입
tree_ptr  hash_table[TABLE_SIZE];//해시테이블

void search();
void search_ready(char* file_name, char* search_word);//검색 준비
tree_ptr search_node(tree_ptr tree, char* key);//노드 검색
void save_result(tree_ptr result_node, char* file_name);//검색결과 저장
void make_hashtable(char* file_name);//hash table 생성
int hash(char* key);//해시 함수
void insertion_sort(int list[], int store[], int n);//삽입 정렬
void print_search(char* search_word);//검색한 결과 출력
void print_index();//인덱싱 값 출력
void textcolor(int color_number);//글자 색 바꾸기