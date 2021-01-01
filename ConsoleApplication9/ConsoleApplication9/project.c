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

	char search_word[MAX_CHAR] = { 0 }; //ã�´ܾ�����迭
										//strcpy(text_file,"");//�������о�������س������ڿ�
	for (int i = 0; i < 10; i++)
		strcpy(result_file[i], "");
	//���Ϻ���Ƚ������迭-> insertion sort�������迭
	for (int i = 0; i < 10; i++)
		max_file[i] = 0;
	for (int i = 0; i < 10; i++)
		max_file_temp[i] = 0;//���Ϻ���Ƚ������迭-> �ܾ����Ƚ����������������صδ¹迭
	for (int i = 0; i <= 9; i++) {
		max_num[i] = i;
	}
	printf("\n Enter Your word >> ");
	textcolor(14);
	scanf("%s", search_word); //ã�´ܾ�˻�����
	textcolor(7);

	strlwr(search_word);//�˻��ܾ�ҹ��ڷιٲ�

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

	int search_index = hash(search_word);//�ؽ�
	tree_ptr result_node = search_node(hash_table[search_index], search_word);//search�Լ���ã�´ܾ��ǳ���ȯ
	save_result(result_node, file_name);
}

tree_ptr search_node(tree_ptr tree, char * key)
{
	if (tree == NULL)   return NULL; //tree��������ΰ���ȯ
	else {
		int temp = strcmp(key, tree->item->search_word);//key����tree��key����
		num_compare_search++;
		switch (temp) {
		case 0://Ʈ����key���̰�����
			return tree;//����Ʈ������ȯ
		case -1://Ʈ����key����ũ��
			return   search_node(tree->left_child, key);//left_child�ε����˻�
		case 1://Ʈ����key����������
			return   search_node(tree->right_child, key);//right child�ε����˻�
		}
	}
}

void save_result(tree_ptr result_node, char* file_name)
{
	if (result_node == NULL) {//�޾ƿ�Ʈ����尡������
		return;
	}
	tree_ptr temp;

	char text[MAX_CHAR] = { 0 }; //�����ؽ�Ʈ������
	for (temp = result_node; temp; temp = temp->link) {
		if (strcmp(temp->item->file_name, file_name) == 0) {
			max_file[file_name[8] - '0']++; //���Ϻ���Ƚ��+1
			char tmp[MAX_CHAR] = { 0 }; //��������
			int count = 0;
			for (element_ptr word_ptr = temp->item; word_ptr; word_ptr = word_ptr->last) {
				count++;
				if (count > 5) {//���ܾ4�����Ѿ��
					char q[MAX_CHAR] = { 0 };//�ӽù��ڿ�
					strcpy(q, tmp); //q��tmp �ӽ�����
					strcpy(tmp, "..."); //tmp��...   ����
					strcat(tmp, q);   //tmp�������ص�q �̾����
					break;
				}
				char q[MAX_CHAR] = { 0 };//�ӽù��ڿ�
				strcpy(q, tmp); //q��tmp�ӽ�����
				strcpy(tmp, word_ptr->word);//tmp������ܾ����
				strcat(tmp, " "); //����
				strcat(tmp, q);   //tmp�������صй��ڿ��̾����
			}
			count = 0;
			for (element_ptr word_ptr = temp->item->next; word_ptr; word_ptr = word_ptr->next) {
				count++;
				if (count > 4) {//���ߴܾ4�����Ѿ��
					strcat(tmp, "...");//... �̾����
					break;
				}
				strcat(tmp, word_ptr->word);//����ܾ��̾����
				strcat(tmp, " "); //����
			}
			strcat(tmp, "\n");
			strcat(text, tmp);//����text�������ص�
		}
	}
	strcat(result_file[file_name[8] - '0'], text);//text������

	for (int i = 0; i < 10; i++) {
		max_file_temp[i] = max_file[i]; //����Ƚ�������ص�
	}
}

void print_search(char * search_word) {
	insertion_sort(max_file, max_num, 10); //�󵵰���������������

	for (int j = 0; j < 10; j++) { //�󵵰��������������ĵ����Ϲ�ȣ���������
		if (strcmp(result_file[max_num[j]], "") == 0) { //�ܾ���̻���������̸�׸����
			if (j == 0) {
				printf("�˻� ����� �����ϴ�.\n");
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
void insertion_sort(int list[], int store[], int n) { //��������
	for (int i = 1; i < n; i++) {
		int next = list[i];

		int j;
		for (j = i - 1; j >= 0 && (next > list[j]); j--) //��Ƚ���������Ϻ���ũ�����Ϲ�ȣ�Ͱ��̹ٲٱ�
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
	element_ptr last_element = NULL;   //�� �ܾ� ��带 ����Ű�� ������

	char token[CHAR_MAX];
	while (fscanf(of, "%s", token) != EOF) {
		/***HASHTABLE�� ����**/
		element_ptr temp = (element_ptr)malloc(sizeof(element));
		temp->last = NULL;
		temp->next = NULL;
		strcpy(temp->file_name, file_name);   //���ϸ� ����
		strcpy(temp->word, token);      //��¿�ܾ� ����

		char tmp[MAX_CHAR] = { 0 };
		if (isalpha_made(token[0]) == 0) {//ù���ڰ� �����ڰ� �ƴϸ�
			int flag = 0; //�����ڸ� ������ ������ 0, ������ 1
			int index = 0;
			for (int i = 1; i < token[i] != '\0'; i++) {
				if (flag == 0 && isalpha_made(token[i]) == 0) {//��� �����ڰ� �ƴ� ���� �����ϸ�
					continue;
				}
				else if (flag == 1 && isalpha_made(token[i]) == 0) {//������ -> ����
					if (token[i + 1] == '\0')//������ ����
						break;
					else index++;
				}
				else if (isalpha_made(token[i]) != 0 && flag == 0) {//���� -> ������
					flag = 1;
					index = i;
					tmp[i - index] = tolower(token[i]);//���� �ҹ��ڷ� ����
				}
				else {//��� ������ ����
					tmp[i - index] = tolower(token[i]);//���� �ҹ��ڷ� ����
				}
			}
		}
		else {//ù���ڰ� �������̸�
			int index = 0;
			for (int i = 0; token[i] != '\0'; i++) {
				if (isalpha_made(token[i]) == 0) {//�����ڰ� �ƴϸ�
					if (token[i + 1] == '\0')//������ ���ڸ�
						break;
					else index++;
				}
				else {
					tmp[i - index] = tolower(token[i]);//���� �ҹ��ڷ� ����
				}
			}
		}
		textcolor(14);
		strcpy(temp->search_word, tmp); //�˻��� �ܾ� ����
		textcolor(7);

		temp->last = last_element;         //�� �ܾ ����Ű�� ������ ����
		if (last_element != NULL)         //�� �ܾ �����ϸ�
			last_element->next = temp;      //�� �ܾ �����ܾ ����Ű���� ������ ����
		last_element = temp;            //����带 ����Ű�� �����Ϳ� �ڱ� �ڽ� ����

		insert_node(temp);               //��� �߰�
	}
}

int hash(char *   key)
{
	return tolower(key[0]) - 'a';//�˻���ܾ���ù���ڷ��ؽ�
}

void insert_node(element_ptr item)
{
	int i = hash(item->search_word); //�ؽ̵ȼ���

	//���ο�ܾ��ǳ�����
	tree_ptr new_node = (tree_ptr)malloc(sizeof(node));
	new_node->item = item;
	new_node->left_child = NULL;
	new_node->right_child = NULL;
	new_node->link = NULL;

	if (hash_table[i] == NULL) {//root���ΰ��̸��Ʈ���ٰ�������
		num_word++;
		hash_table[i] = new_node;
		return;
	}
	tree_ptr temp = hash_table[i];
	while (temp != NULL) {
		int num = strcmp(temp->item->search_word, item->search_word); //����Ʈ�����ͺ�
		num_compare_string++;
		if (num == 0) {//��������������
					   //��ũ�帮��Ʈ�ο����Ѵ�
			tree_ptr p = temp;
			for (p = temp; p->link != NULL; p = p->link);
			p->link = new_node;
			return;
		}
		else if (num == 1) {//temp��key���̻�����key������ũ�ٸ�
			if (temp->left_child == NULL) { //����ִٸ� 
				temp->left_child = new_node;//���ʳ�忡����
				num_word++;
				return;
			}
			temp = temp->left_child;
		}
		else if (num == -1) {//temp��key���̻�����key�������۴ٸ�
			if (temp->right_child == NULL) {//����ִٸ�
				temp->right_child = new_node;//�����ʳ�忡����
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
{ //���ĺ����� �ƴ��� Ȯ���ϴ� �Լ�
	if ((a >= 'a'&& a <= 'z') || (a >= 'A'&& a <= 'Z'))
		return 1;
	else
		return 0;
}
void textcolor(int color_number) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}