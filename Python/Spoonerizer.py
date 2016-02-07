# Python 3.4.0
import random

vowels = "aeiou"

tokens = input("Input some words: ").lower().split()

initials = []
tails = []

for t in tokens:
	vowel_index = 0
	for c in t:
		if c in vowels:
			vowel_index = t.index(c)
			break
	initials.append(t[:vowel_index])
	tails.append(t[vowel_index:])

initials_index = random.randrange(1, len(tails))
words = []

for t in tails:
	words.append(initials[initials_index] + t + ' ')
	initials_index = (initials_index + 1) % len(initials)
	
words = ''.join(words)
words = words[:-1]
print(words)
