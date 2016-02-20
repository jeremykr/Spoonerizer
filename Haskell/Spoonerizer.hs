import System.Random
import Data.String
import Data.Char

-- Returns true if character is a vowel, false otherwise.
isVowel :: Char -> Bool
isVowel c
	| c == 'a' = True
	| c == 'e' = True
	| c == 'i' = True
	| c == 'o' = True
	| c == 'u' = True
	| otherwise = False

-- Returns a random number between "lower" and "higher" inclusive.
getRandom :: Int -> Int -> IO Int
getRandom lower higher = do
	r <- (randomIO :: IO Int)
	return (mod r (higher - lower) + lower)

-- Returns the index of the first vowel found, or the length
-- of the string if a vowel is not found.
getVowelIndex :: String -> Int
getVowelIndex s =
	let vowelIndexes = [min i (length(s) - 1) | i <- [0..length(s)-1], isVowel(s !! i)]
	in if null vowelIndexes
		then -1
		else minimum vowelIndexes
	
-- Return the consonants before the first vowel of a word.
getHead :: (String, Int) -> String
getHead (s,i)
	| i < 0		= s
	| i == 0	= "" 
	| otherwise = take i s
	
-- Return the letters including and after the first vowel of a word.
getTail :: (String, Int) -> String
getTail (s, i)
	| i < 0		= ""
	| i == 0	= s
	| otherwise = drop i s
	
-- Returns a tuple of two lists:
-- 1. a list of the strings of consonants of each word that precede the first vowel
-- 2. a list of the strings of characters after and including the vowel, for each word
splitList :: [String] -> ([String], [String])
splitList input =
	let vowelIndexes = map getVowelIndex input;
		z = zip input vowelIndexes;
		heads = map getHead z;
		tails = map getTail z;
	in (heads, tails)

-- Recombine heads onto tails in a random order.
recombine :: ([String], [String]) -> Int -> String
recombine (h, t) r =
	let lenh = length h;
		h1 = take r h;
		h2 = drop r h;
		h3 = h2 ++ h1;
		rList = zip h3 t
	in unwords [x ++ y | (x, y) <- rList]

main :: IO ()
main = do
	putStrLn "Enter some words: "
	input <- getLine
	let inputWords = words (map toLower input);
		inputLength = length(inputWords);
		headsAndTails = splitList inputWords
	iorand <- (getRandom 1 inputLength)
	let r = iorand
	putStrLn ("\n\t--  " ++ (recombine headsAndTails r))
