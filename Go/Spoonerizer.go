package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
	"math/rand"
	"time"
)

func isVowel(c byte) bool {
	// Returns true if character is a vowel,
	// false otherwise.
	if c=='a'||c=='e'||c=='i'||c=='o'||c=='u' {
		return true;
	}
	return false;
}

func recombine(heads []string, tails []string) string {
	// Randomly combines the heads with the tails, and returns
	// result as a string.
	rand.Seed(time.Now().UTC().UnixNano());
	headIndex := int32(1 + rand.Intn(len(heads)-1));
	var output string;
	
	for i := 0; i < len(tails); i++ {
		if heads[headIndex] != "" || tails[i] != "" {
			output += heads[headIndex] + tails[i] + " ";
			headIndex = (headIndex + 1) % int32(len(heads));
		}
	}
	output = output[:len(output)-1];
	return output;
}

func splitInput(input []string) ([]string, []string) {
	// Splits each word from the input list into two lists:
	// heads = the characters up to the first vowel in the word.
	// tails = the characters from the first vowel to the end of the word.
	var heads []string;
	var tails []string;
	vowelIndex := 0;
	vowelFound := false;
	
	for i := 0; i < len(input); i++ {
		vowelIndex = 0;
		vowelFound = false;
		for j := 0; j < len(input[i]); j++ {
			if isVowel(input[i][j]) {
				vowelFound = true;
				vowelIndex = j;
				heads = append(heads, input[i][:j]);
				tails = append(tails, input[i][j:]);
				break;
			}
		}
		if !vowelFound {
			heads = append(heads, input[i]);
			tails = append(tails, "");
		}
	}
	return heads, tails;
}

func tokenize(s string) []string {
	// Custom tokenizing function.
	// Tokenizes on spaces.
	var output []string;
	var word []byte;
	spacesFound := 0;
	
	for i := 0; i < len(s); i++ {
		if s[i] == byte(' ') {
			if spacesFound == 0 && len(word) > 0 {
				output = append(output, string(word));
				word = make([]byte, 0);
			} else {
				spacesFound++;
			}
		} else {
			spacesFound = 0;
			word = append(word, s[i]);
		}
	}
	if len(word) > 0 {
		output = append(output, string(word));
	}
	return output;
}

func main() {
	reader := bufio.NewReader(os.Stdin);
	fmt.Print("Enter some words: ");
	inputText, _ := reader.ReadString('\n');
	inputText = strings.ToLower(inputText);
	inputText = strings.Trim(inputText, "\n");
	input := tokenize(inputText);
	
	if len(input) == 0 {
		fmt.Println();
	} else if len(input) == 1 {
		fmt.Println(input[0]);
	} else {
		heads, tails := splitInput(input);
		output := recombine(heads, tails);
		fmt.Println(output);
	}
}
