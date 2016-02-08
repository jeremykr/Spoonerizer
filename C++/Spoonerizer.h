#pragma once
#include "WordList.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;

class Spoonerizer {
	WordList inputList;
	WordList headList;
	WordList tailList;
public:
	Spoonerizer();
	char* spoon(char* s);
private:
	void tokenizeInput(char* s);
	bool isVowel(char c);
	void splitInput();
	char* recombine();
	void printList();
};

Spoonerizer::Spoonerizer() {
	inputList = WordList();
	headList = WordList();
	tailList = WordList();
}

void Spoonerizer::tokenizeInput(char* s) {
	const char delim[3] = " \n";
	char* token;
	
	token = strtok(s, delim);
	
	while(token) {
		inputList.append(token);
		token = strtok(NULL, delim);
	}
} 

bool Spoonerizer::isVowel(char c) {
	if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
		return true;
	} else {
		return false;
	}
}

char* Spoonerizer::spoon(char* s) {
	tokenizeInput(s);
}
