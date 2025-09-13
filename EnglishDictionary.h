//EnglishDictionary class programmed by Badtothebunny

#ifndef ENGLISHDICTIONARY_H
#define ENGLISHDICTIONARY_H

#include<string>
#include "NodeDictionaryG.h"

class EnglishDictionary
{
	private:
		string name; //The name of the dictionary
		NodeDictionaryG<string,string> dictionary; //The words and their definitions
	public:
		EnglishDictionary(string);//constructor
		~EnglishDictionary();//destructor
		int words()const; //number of words in dictionary
		int uniqueWords()const; //number of unique words in dictionary
		bool empty()const;//is dictionary empty?
		void add(Entry<string,string>);//adds a word and its definition
		void deleteFirst(string);//removes the first word equal to a given string
		void deletes(string);//removes all words equal to a given string
		void printDictionary(bool,int n); //prints all words and definitions
		void printDictionary(string);//prints the definitions for a given word
		Entry<string,string> find(string);//returns the first word and its definition equal to string
};

#endif

