#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 100

const char consonants[] = "bcdfghjklmnpqrstvwxyz";
const char vowels[] = "aeiou";

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
		if ((*p) > 64 && (*p) < 91) {
			(*p) += 32;
		}
	}
	return s;
}

int main() {
	char* input = (char*)malloc(INPUT_SIZE);
	List* input_list = init_list();
	Node* np;
	
	
	printf("Input some words: ");
	
	if (fgets(input, INPUT_SIZE, stdin) == NULL) {
		printf("Input error: input string too long.\n");
		return 1;
	}
	
	input = to_lower(input);
	printf("%s", input);
	printf("List size: %d\n", input_list->size);
	
}
