#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_SIZE 5000
#define BUFF_SIZE 50
#define TOKENS_SIZE 100

const char consonants[] = "bcdfghjklmnpqrstvwxyz";
const char vowels[] = "aeiou";

int main() {
	char input[INPUT_SIZE], buff[BUFF_SIZE];
	char* tokens[TOKENS_SIZE];
	char c;
	int i, start_index, end_index;
	int tokens_index = 0;
	
	// Initialize tokens array
	for (i = 0; i < TOKENS_SIZE; i++) {
		tokens[i] = (char *)malloc(BUFF_SIZE);
	}
	
	printf("Input some words: ");
	
	if (fgets(input, sizeof(input), stdin) == NULL) {
		printf("Input error: input string too long.\n");
		return 1;
	}
	
	for (i = start_index = 0; c; i++) {
		c = input[i];
		if (c == ' ' || c == '\n') {
			end_index = i;
			memcpy(tokens[tokens_index], &input[start_index], end_index - start_index);
			start_index = i + 1;
		}
	}
	
	for (i = 0; i < 2; i++) {
		printf("%s\n", tokens[i]);
	}
	
	printf("%s", input);
	return 0;
}
