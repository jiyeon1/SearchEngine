#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include "project.h"

void main()
{
	char search_word[50];

	build("document1.txt");
	build("document2.txt");
	build("document3.txt");
	build("document4.txt");
	build("document5.txt");
	build("document6.txt");
	build("document7.txt");
	build("document8.txt");
	build("document9.txt");
	printf("Total number of documents: %d \n", indexed_doc);
	printf("Total number of indexed words: %d \n", indexed_num);
	printf("Total number of comparison: %d \n", comp);

	while (1)
	{
		printf("Enter Your word. If you wanna terminate this program, Enter Q/q : ");
		textcolor(14);
		scanf("%s", search_word);
		textcolor(7);

		if (strcmp(search_word, "Q") == 0 || strcmp(search_word, "q") == 0) {
			printf("\n");
			exit(1);
		}
		else {
			search(search_word);
		}
	}
	return 0;
}

char to_small(char *str)
{
	if (96 < *str && *str < 123)
		return  *str;
	else if (64 < *str && *str < 91)
		return *str + 32;
	else return NULL;
}

void create_table(hash_link *hlp, char *alphabat)
{
	int i = 0;
	hash_link n_table = (hash_link)malloc(sizeof(hash_table));
	n_table->next_tablelink = NULL;
	n_table->strlen = 0;

	for (i = 0; i < 10; i++) {
		n_table->freq[i] = 0;
		n_table->existence[i] = false;
		n_table->place[i].rear_cursor = 0;
	}

	strcpy(n_table->word, alphabat);
	((*hlp)->next_tablelink) = n_table;
	(*hlp) = n_table;
}

void create_place(place_link *wtp)
{
	place_link n_place = (place_link)malloc(sizeof(place));
	(*wtp)->next_place = n_place;
	n_place->next_place = NULL;
	(*wtp) = n_place;
	(*wtp)->rear_cursor = 0;
}


int hash(char *key)
{
	return(transform(key) % TABLE_SIZE);
}

int transform(char *key)
{
	int number = 0;
	while (*key) {
		number += *key++;
	}

	return number;
}

void search(char* alphabet)
{
	hash_link hlp;
	int priority[10];
	boolean table_check[10] = { 0 };
	int i = 0, j = 0, encl_word = indexed_doc;
	char temp[100];
	comp = 0;
	strcpy(temp, alphabet);

	while (temp[i] != '\0') {
		alphabet[j++] = to_small(temp + i);
		i++;
	}
	alphabet[j] = '\0';

	hlp = &table[hash(alphabet)];
	
	while (hlp->strlen != j && hlp->next_tablelink) {
		hlp = hlp->next_tablelink;
		comp++;
	}

	while (strcmp(hlp->word, alphabet) != 0) {
		if (!hlp->next_tablelink) {
			textcolor(2);
			printf("\n\"%s\" does not exist.\n", alphabet);
			textcolor(7);
			return;
		}
		
		hlp = hlp->next_tablelink;
		comp++;
	}

	for (i = 0; i < indexed_doc; i++) {
		int max_top = INT_MAX;
		int top, top_index;
		top = 0;

		for (j = 0; j < indexed_doc; j++) {
			if ((hlp->freq[j] > top) && table_check[j] == 0) {
				top = hlp->freq[j];
				top_index = j;
			}
		}

		if (hlp->freq[i] == 0)
			encl_word--;

		priority[i] = top_index;
		table_check[top_index] = 1;
		max_top = top;
	}
	//printf("\n");
	for (i = 0; i < encl_word; i++) {
		place_link plp = &hlp->place[priority[i]];
		FILE *ifp = fopen(doc_name[priority[i]], "r");
		char p_word[100];
		printf("\n <%s> %s: ", doc_name[priority[i]], temp);
		textcolor(2);
		printf("%d\n", hlp->freq[priority[i]]);
		textcolor(7);

		while (1) {
			int s = 0;

			fseek(ifp, plp->front_cursor, SEEK_SET);
			if (plp->front_cursor != 0)
				printf("...");
			for (j = 0; j < 9; j++) {
				if (fscanf(ifp, "%s", p_word) == 0)
					break;

				printf(" %s", p_word);

				long ft = ftell(ifp);
				if (ftell(ifp) >= plp->rear_cursor)
					break;
			}
			if (fscanf(ifp, "%s", p_word) > 0)
				printf(" ...");

			printf("\n");

			if (plp->next_place != NULL)
				plp = plp->next_place;
			else
				break;
		}

		fclose(ifp);
	}

	textcolor(2);
	printf("\nTotal number of comparison: %d\n\n", comp);
	textcolor(7);
}

void build(char* fname)
{
	FILE *ifp;
	int file_pointer[4] = { 0 };
	int file_pointer_index = 4;
	int i;
	place_link cursor[4] = { 0 };
	int cursor_index = 4;
	hash_link hlp;
	place_link plp;
	long ft = 0;
	char string[100];
	char alphabet[100];

	if (indexed_doc == 10) {
		return;
	}

	strcpy(doc_name[indexed_doc], fname);

	if ((ifp = fopen(fname, "r")) == NULL) {
		printf("\nFiles not founded\n", fname);
		return;
	}

	while (fscanf(ifp, "%s", string) == 1) {
		indexed_num++;
		int i, j;
		i = j = 0;

		while (string[i] != '\0') {
			alphabet[j++] = to_small(string + i);
			if (alphabet[j - 1] == NULL) {
				j--;
			}

			i++;
		}

		if (!j)   continue;
		alphabet[j] = '\0';

		hlp = &table[hash(alphabet)];
		while (hlp->strlen != j && hlp->next_tablelink) {
			hlp = hlp->next_tablelink;
		}
		comp++;

		while (hlp->strlen == 0 || strcmp(alphabet, hlp->word) != 0) {
			if (hlp->strlen == 0) {
				comp--;
			}

			if (!(hlp->next_tablelink)) {
				create_table(&hlp, alphabet);
				break;

			}

			hlp = hlp->next_tablelink;
			comp++;
		}

		hlp->freq[indexed_doc]++;
		hlp->existence[indexed_doc] = true;
		hlp->strlen = j;
		plp = &hlp->place[indexed_doc];

		while (plp->rear_cursor != 0) {
			if (plp->next_place)
				plp = plp->next_place;
			else
				break;
		}

		if (plp->rear_cursor != 0) {

			create_place(&plp);
		}

		plp->next_place = NULL;
		cursor[cursor_index++ % 4] = plp;
		plp->front_cursor = file_pointer[(file_pointer_index - 4) % 4];

		if (cursor_index > 7)
			cursor[cursor_index % 4]->rear_cursor = ftell(ifp);
		file_pointer[file_pointer_index++ % 4] = ftell(ifp);
	}

	for (i = 0; i < 4; i++) {
		cursor[cursor_index++ % 4]->rear_cursor = ftell(ifp);
	}

	indexed_doc++;
	fclose(ifp);
}

void textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}