#pragma once

#include <iostream>
#include <vector>
using namespace std;

class clsString
{
private:
	string _Value;
public:
	clsString() { this->_Value = ""; }
	clsString(string Value) { this->_Value = Value;	}

	enum enLetterType { LowerLetter, CapitalLetter, All };

	string getValue() { return _Value; }
	void setValue(string Value) { this->_Value = Value; }

	__declspec(property(get = getValue, put = setValue)) string Value;

	static vector<char> FirstLetterOfEachWord(string source) {
		vector<char> result;

		bool is_first_letter = true;

		for (int i = 0; i < source.length(); i++) {
			if (source[i] != ' ' && is_first_letter) result.push_back(source[i]);
			is_first_letter = source[i] == ' ' ? true : false;
		}

		return result;
	}
	vector<char> FirstLetterOfEachWord() {
		return FirstLetterOfEachWord(_Value);
	}

	static void UpperFirstLetterOfEachWordByRef(string& source) {
		source = UpperFirstLetterOfEachWord(source);
	}
	static string UpperFirstLetterOfEachWord(string source) {
		bool is_first_letter = true;

		for (int i = 0; i < source.length(); i++) {
			if (source[i] != ' ' && is_first_letter) source[i] = toupper(source[i]);
			is_first_letter = source[i] == ' ' ? true : false;
		}
		return source;
	}
	void UpperFirstLetterOfEachWord() {
		UpperFirstLetterOfEachWordByRef(_Value);
	}

	static void LowerFirstLetterOfEachWordByRef(string& source) {
		source = LowerFirstLetterOfEachWord(source);
	}
	static string LowerFirstLetterOfEachWord(string source) {
		bool is_first_letter = true;

		for (int i = 0; i < source.length(); i++) {
			if (source[i] != ' ' && is_first_letter) source[i] = tolower(source[i]);
			is_first_letter = source[i] == ' ' ? true : false;
		}
		return source;
	}
	void LowerFirstLetterOfEachWord() {
		LowerFirstLetterOfEachWordByRef(_Value);
	}

	static void LowerStringByRef(string& source) {
		source = LowerString(source);
	}
	static string LowerString(string source) {
		for (int i = 0; i < source.length(); i++) {
			source[i] = tolower(source[i]);
		}
		return source;
	}
	void LowerString() {
		LowerStringByRef(_Value);
	}

	static void UpperStringByRef(string& source) {
		source = UpperString(source);
	}
	static string UpperString(string source) {
		for (int i = 0; i < source.length(); i++) {
			source[i] = toupper(source[i]);
		}
		return source;
	}
	void UpperString() {
		UpperStringByRef(_Value);
	}

	static void InvertCharByRef(char& c) {
		c = InvertChar(c);
	}
	static char InvertChar(char c) {
		if (isupper(c)) c = tolower(c);
		else c = toupper(c);
		return c;
	}

	static void InvertStringCharsByRef(string& source) {
		source = InvertStringChars(source);
	}
	static string InvertStringChars(string source) {
		for (int i = 0; i < source.length(); i++) InvertCharByRef(source[i]);
		return source;
	}
	void InvertStringChars() {
		InvertStringCharsByRef(_Value);
	}

	static int CountCapitalLetters(string source) {
		int count = 0;
		for (int i = 0; i < source.length(); i++) if (isupper(source[i])) count++;
		return count;
	}
	int CountCapitalLetters() {
		return CountCapitalLetters(_Value);
	}

	static int CountLowerLetters(string source) {
		int count = 0;
		for (int i = 0; i < source.length(); i++) if (islower(source[i])) count++;
		return count;
	}
	int CountLowerLetters() {
		return CountLowerLetters(_Value);
	}

	static int CountLetters(string source, enLetterType letter_type = enLetterType::All) {

		if (letter_type == enLetterType::All) return source.length();

		int count = 0;

		if (enLetterType::CapitalLetter == letter_type) {
			for (int i = 0; i < source.length(); i++) if (isupper(source[i])) count++;
		}
		else {
			for (int i = 0; i < source.length(); i++) if (islower(source[i])) count++;
		}

		return count;
	}
	int CountLetters(enLetterType letter_type = enLetterType::All) {
		return CountLetters(_Value, letter_type);
	}

	static int CountLetterInString(string source, char c, bool match_case = true) {
		int counter = 0;
		if (match_case) { for (int i = 0; i < source.length(); i++) if (c == source[i]) counter++; }
		else { for (int i = 0; i < source.length(); i++) if (tolower(c) == tolower(source[i])) counter++; }

		return counter;
	}		
	int CountLetterInString(char c, bool match_case = true) {
		return CountLetterInString(_Value, c, match_case);
	}

	static bool isVowel(char c) {
		c = tolower(c);
		return (c == 'a' || c == 'o' || c == 'u' || c == 'i' || c == 'e');
	}

	static int CountVowels(string source) {
		int count = 0;
		for (int i = 0; i < source.length(); i++) {
			if (isVowel(source[i])) count++;
		}

		return count;
	}
	int CountVowels() {
		return CountVowels(_Value);
	}

	static vector<char> GetVowels(string source) {
		vector<char> vowels;

		for (int i = 0; i < source.length(); i++) {
			if (isVowel(source[i])) vowels.push_back(source[i]);
		}

		return vowels;
	}
	vector<char> GetVowels() {
		return GetVowels(_Value);
	}

	static int CountWords(string source, string word_spliter) {
		int pos = 0;
		int counter = 0;

		while ((pos = source.find(word_spliter)) != std::string::npos) {
			if (pos != 0) counter++;
			source.erase(0, pos + word_spliter.length());
		}
		if (source.length() != 0) counter++;

		return counter;
	}
	int CountWords(string word_spliter) {
		return CountWords(_Value, word_spliter);
	}

	// this is exactly similar to SplitString
	static vector<string> Split(string source, string delimiter) {
		vector<string> strings;
		int pos = 0;
		string word;

		while ((pos = source.find(delimiter)) != std::string::npos) {
			word = source.substr(0, pos);
			if (word != "") {
				strings.push_back(word);
			}
			source.erase(0, pos + delimiter.length());
		}
		if (source.length() != 0) strings.push_back(source);

		return strings;
	}
	vector<string> Split(string delimiter) {
		return Split(_Value, delimiter);
	}

	static string TrimLeft(string source) {
		for (int i = 0; i < source.length(); i++) {
			if (source[i] != ' ') return source.substr(i, source.length() - i);
		}
		return "";
	}
	void TrimLeft() {
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string source) {
		for (int i = source.length() - 1; i >= 0; i--) {
			if (source[i] != ' ') {
				return source.substr(0, i + 1);
			}
		}
		return "";
	}
	void TrimRight() {
		_Value = TrimRight(_Value);
	}

	static string Trim(string source) {
		return TrimLeft(TrimRight(source));
	}
	void Trim() {
		_Value = Trim(_Value);
	}

	static string JoinString(vector<string> strings, string separator) {
		string result = "";

		if (strings.empty()) return result;

		result += strings.at(0);

		for (int i = 1; i < strings.size(); i++) {
			result += separator;
			result += strings.at(i);
		}

		return result;
	}

	// same as above
	// one with array, and the other with vector
	static string JoinString(string* strings, int size, string separator) {
		string result = "";

		if (size == 0) return result;

		result += *strings;

		for (int i = 1; i < size; i++) {
			result += separator;
			result += *(strings + i);
		}

		return result;
	}

	// "yasin hamad" => "hamad yasin"
	static string ReversStringWords(string source, string separator) {
		vector<string> strings = Split(source, separator);
		string result = "";

		vector<string>::iterator itor = strings.end();

		while (itor != strings.begin()) {
			itor--;
			result += *itor;
			result += separator;
		}

		return result.substr(0, result.length() - separator.length());
	};
	// "yasin hamad" => "hamad yasin"
	void ReversStringWords(string separator) {
		_Value = ReversStringWords(_Value, separator);
	};

	static string ReplaceWordInString(string source, string old_word, string new_word) {
		int pos = 0;

		pos = source.find(old_word);

		while (pos != std::string::npos) {
			source.replace(pos, old_word.length(), new_word);
			pos = source.find(old_word);
		}

		return source;
	}
	void ReplaceWordInString(string old_word, string new_word) {
		_Value = ReplaceWordInString(_Value, old_word, new_word);
	}

	static string RemovePunctuations(string source) {
		string result = "";
		for (int i = 0; i < source.length(); i++) {
			if (!ispunct(source[i])) result += source[i];
		}

		return result;
	}
	void RemovePunctuations() {
		_Value = RemovePunctuations(_Value);
	}
};

