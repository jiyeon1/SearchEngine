#pragma once
#define MAX_CHAR 100000
#define TABLE_SIZE 26
int num_document;//������ �ڷ� ��
int num_word;//�� �ܾ� ��
int num_compare_string;//���ΰ����� ���ڿ� �� Ƚ��
int num_compare_search;//�˻������� ���ڿ� �� Ƚ��
char text_file[CHAR_MAX];//������ �о�� ������ ���� ���ڿ�
char result_file[10][MAX_CHAR] = { 0 };
int max_file[10] = { 0 }; //���Ϻ� �� Ƚ�� ���� �迭 -> insertion sort���� �� �迭
int max_file_temp[10] = { 0 };//���Ϻ� �� Ƚ�� ���� �迭 -> �ܾ� ���� Ƚ�� ����� ���� �����صδ� �迭
int max_num[10] = { 0,1,2,3,4,5,6,7,8,9 }; //��Ƚ���� ���� ���Ϻ��� ������ �迭 �ʱ�ȭ�� 1���� ���ʴ��

typedef struct element *element_ptr;
typedef struct element {
	char word[MAX_CHAR];//��¿� �ܾ�
	char search_word[MAX_CHAR];//�˻��� �ܾ�
	char file_name[MAX_CHAR];
	element_ptr last;
	element_ptr next;
	/* other fields */
} element;
//����Ʈ���� ���� ��� ������
typedef struct node *tree_ptr;
typedef struct node {
	element_ptr item;
	tree_ptr left_child;
	tree_ptr right_child;
	tree_ptr link;
}node;
void insert_node(element_ptr item);//��� ����
tree_ptr  hash_table[TABLE_SIZE];//�ؽ����̺�

void search();
void search_ready(char* file_name, char* search_word);//�˻� �غ�
tree_ptr search_node(tree_ptr tree, char* key);//��� �˻�
void save_result(tree_ptr result_node, char* file_name);//�˻���� ����
void make_hashtable(char* file_name);//hash table ����
int hash(char* key);//�ؽ� �Լ�
void insertion_sort(int list[], int store[], int n);//���� ����
void print_search(char* search_word);//�˻��� ��� ���
void print_index();//�ε��� �� ���
void textcolor(int color_number);//���� �� �ٲٱ�