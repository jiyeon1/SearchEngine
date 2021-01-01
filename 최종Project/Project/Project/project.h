#pragma once
#define _CRT_NO_SECURE_WARNINGS
#define boolean unsigned char
#define true 1
#define false 0
#define TABLE_SIZE 20000

int comp = 0;
int indexed_num = 0;
int indexed_doc = 0;
char doc_name[10][100];

typedef struct place *place_link;
typedef struct place
{
	int front_cursor;
	int rear_cursor;
	place_link next_place;
}place;

typedef struct hash_table *hash_link;
typedef struct hash_table
{
	int strlen;
	int freq[10];
	boolean existence[10];
	char word[100];

	place place[10];
	hash_link next_tablelink;
}hash_table;

hash_table table[TABLE_SIZE];

void textcolor(int color_number);
void build(char *fname);
char to_small(char *str);
int hash(char *key);
int transform(char *key);
void create_table(hash_link *hlp, char *alphabat);
void create_place(place_link *wtp);
void search(char *alphabet);