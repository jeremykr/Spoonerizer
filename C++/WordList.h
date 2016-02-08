#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

class Node {
public:
	Node* next;
	char* data;
	
	Node();
};

Node::Node() {
	next = NULL;
	data = NULL;
}

class WordList {
	Node* head;
	Node* tail;
	int size;
public:
	WordList();
	void append(char* s);
	void circularize();
	void printList(); //remove
};

WordList::WordList() {
	head = tail = NULL;
	size = 0;
}

void WordList::append(char* s) {
	Node N = Node();
	char* s_copy = (char*)malloc(sizeof(s));
	strcpy(s_copy, s);
	N.data = s_copy;
	
	if (!size) {
		head = tail = &N;
	} else {
		tail->next = &N;
		tail = &N;
	}
	N.next = NULL;
	size++;
}

void WordList::circularize() {
	tail->next = head;
}

void WordList::printList() {	//remove
	Node* np = head;
	cout << np->data << endl;
}
