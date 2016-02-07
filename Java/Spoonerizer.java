import java.io.*;
import java.util.StringTokenizer;
import java.util.ArrayList;
import java.util.Random;

class Spoonerizer {
	private ArrayList<String> inputList;
	private ArrayList<String> headList;
	private ArrayList<String> tailList;
	
	private boolean isVowel(char c) {
		if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') {
			return true;
		} else {
			return false;
		}
	}
	
	private void TokenizeInput(String S) {
		inputList = new ArrayList();
		StringTokenizer st = new StringTokenizer(S);
		
		while (st.hasMoreTokens()) {
			inputList.add(st.nextToken());
		}
		inputList.trimToSize();
	}
	
	private void SplitInput() {
		String head, tail = "";
		headList = new ArrayList();
		tailList = new ArrayList();
		
		for (int i = 0; i < inputList.size(); i++) {
			head = tail = "";
			String s = inputList.get(i);
			int j = 0;
			for (; j < s.length(); j++) {
				if (!isVowel(s.charAt(j))) {
					head += s.charAt(j);
				} else {
					break;
				}
			}
			for (; j < s.length(); j++) {
				tail += s.charAt(j);
			}
			headList.add(head);
			tailList.add(tail);
		}
		headList.trimToSize();
		tailList.trimToSize();
	}
	
	private String Recombine() {
		Random R = new Random();
		int rand = R.nextInt(inputList.size() - 1) + 1;
		String output = "";
		
		for (int i = 0; i < tailList.size(); i++, rand++) {
			output += headList.get(rand % headList.size());
			output += tailList.get(i);
			if (i != tailList.size() - 1) {
				output += " ";
			}
		}
		return output;
	}
	
	public String spoon(String s) {
		TokenizeInput(s.toLowerCase());
		if (inputList.size() == 1) {
			return inputList.get(0);
		} else if (inputList.size() == 0) {
			return "";
		}
		SplitInput();
		String output = Recombine();
		return output;
	}
}
