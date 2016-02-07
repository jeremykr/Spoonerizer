#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 100

typedef struct Node {
	char* data;
	struct Node* next;
} Node;

typedef struct List {
	Node* head;
	Node* tail;
	int size;
} List;

List* init_list() {
	List* L = (List*)malloc(sizeof(List*));
	L->head = NULL;
	L->tail = NULL;
	L->size = 0;
	return L;
}

Node* init_node() {
	Node* N = (Node*)malloc(sizeof(Node*));
	N->data = NULL;
	N->next = NULL;
	return N;
}

void append(List* L, char* s) {
	Node* N = init_node();
	char* s_copy = (char*)malloc(sizeof(s));
	strcpy(s_copy, s);
	N->data = s_copy;
	
	if (!L->size) {
		L->head = L->tail = N;
	} else {
		L->tail->next = N;
		L->tail = N;
	}
	N->next = NULL;
	L->size++;
}

char* to_lower(char* s) {
/* Converts all characters in a string to lowercase. */
	char* p = s;
	for (; *p; p++) {
		if (*p > 64 && *p < 91) {
			*p += 32;
		}
	}
	return s;
}

List* tokenize_input(char* s) {
	List* L = init_list();
	const char delim[3] = " \n";
	char* token;
	
	token = strtok(s, delim);
	
	while(token) {
		append(L, token);
		token = strtok(NULL, delim);
	}
	return L;
}

int is_vowel(char c) {
/*	Returns 1 if character is vowel, 0 otherwise. */
	if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
		return 1;
	} else {
		return 0;
	}
}

void split_lists(List* I, List* H, List* T) {
/* 	Takes a list and splits it into a list containing the consonant heads of words,
	and another containing the rest of the word. */
	Node* p;
	char* head_buffer;
	int head_index = 0;
	char* str_p;
	
	for (p = I->head; p; p = p->next, head_index = 0) {
		/* gather heads */
		head_buffer = (char*)malloc(sizeof(p->data));
		for (str_p = p->data; str_p && !is_vowel(*str_p); str_p++, head_index++) {
		 	head_buffer[head_index] = *str_p;
		}
		head_buffer[head_index] = '\0';
		append(H, head_buffer);
		append(T, str_p);
	}
}

void spoonerize(List* H, List* T) {
	time_t t;
	int random;
	Node* tp;
	Node* hp;
	int i;
	
	H->tail->next = H->head;
	srand((unsigned) time(&t));
	random = rand() % (H->size - 1) + 1;
	
	for (hp = H->head, i = 0; hp && i < random; hp = hp->next, i++); 
	
	for (tp = T->head; tp && hp; tp = tp->next, hp = hp->next) {
		printf("%s", hp->data);
		printf("%s", tp->data);
		if (tp->next) {
			printf(" ");
		}
	}
	printf("\n");
}

int main() {
	char* input = (char*)malloc(INPUT_SIZE);
	List* input_list;
	List* head_list = init_list();
	List* tail_list = init_list();
	
	printf("Input some words: ");
	
	if (fgets(input, INPUT_SIZE, stdin) == NULL) {
		printf("Input error: input string too long.\n");
		return 1;
	}
	
	input = to_lower(input);
	input_list = tokenize_input(input);
	
	if (input_list->size < 2) {
		printf("Input error: not enough words.\n");
		return 1;
	}
	
	split_lists(input_list, head_list, tail_list);
	spoonerize(head_list, tail_list);	
}
