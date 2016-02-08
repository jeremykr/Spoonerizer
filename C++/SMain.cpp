#include "Spoonerizer.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	Spoonerizer S = Spoonerizer();
	char* input;
	cout << "Enter some words: ";
	cin >> input;
	S.spoon(input);
	return 0;
}
