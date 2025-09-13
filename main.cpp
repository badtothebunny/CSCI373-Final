//This class tests the utility of the EnglishDictionary class I programmed.
//Programmed by Badtothebunny

//necessary #include statements 
#include "EnglishDictionary.h"
#include "Entry.h"
#include <string>

#include <iostream>
using namespace std;

int main(int argc, char** argv) 
{
	cout<<"Welcome. This program tests the utility of an EnglishDictionary class."<<endl;
	cout<<"First I create an instance of the EnglishDictionary class and title the dictionary 'Test'."<<endl;
	EnglishDictionary test("Test");
	cout<<"Next I create an Entry instance that has words with definitions, repititions being 3, 4, 1, and then 2."<<endl;
	//3 repetitions	
	Entry<string,string> t1("Professor","An awesome professor");
	Entry<string,string> t2("Professor", "Will give Bunny an A");
	Entry<string,string> t3("Professor", "Smart about C++");
	test.add(t1);
	test.add(t2);
	test.add(t3);
	//4 repetitions
	Entry<string,string> t4("Bunny","Will recieve an A in CSCI 373");
	Entry<string,string> t5("Bunny","Learning to program");
	Entry<string,string> t6("Bunny","Gets a 100 on the final project");
	Entry<string,string> t7("Bunny","Tries their hardest :)");
	test.add(t4);
	test.add(t5);
	test.add(t6);
	test.add(t7);
	////1 repetition
	Entry<string,string> t8("False","Bunny getting an F");
	test.add(t8);
	//2 repetitions
	Entry<string,string> t9("Fact","Bunny got an A!");
	Entry<string,string> t10("Fact","Bunny is happy.");
	test.add(t9);
	test.add(t10);
	cout<<"Printing all the words from the beginning."<<endl;
	test.printDictionary(true,test.uniqueWords());
	cout<<"Printing all the words from the end."<<endl;
	test.printDictionary(false,test.uniqueWords());
	cout<<"Printing the word with 2 definitions."<<endl;
	test.printDictionary("Fact",true);
	test.deleteFirst("Professor");
	test.printDictionary("Bunny");
	test.deleteFirst("Bunny");
	test.deletes("Professor");
	test.deletes("Fact");
	test.printDictionary(true,test.uniqueWords());
	test.printDictionary(false,test.uniqueWords());
	return 0;
}


