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
	Entry<string,string> t1("Kutrolli","An awesome professor");
	Entry<string,string> t2("Kutrolli", "Will give Maria an A");
	Entry<string,string> t3("Kutrolli", "Smart about C++");
	test.add(t1);
	test.add(t2);
	test.add(t3);
	//4 repetitions
	Entry<string,string> t4("Maria","Will recieve an A in CSCI 373");
	Entry<string,string> t5("Maria","Learning to program");
	Entry<string,string> t6("Maria","Gets a 100 on the final project");
	Entry<string,string> t7("Maria","Tries her hardest :)");
	test.add(t4);
	test.add(t5);
	test.add(t6);
	test.add(t7);
	////1 repetition
	Entry<string,string> t8("False","Maria getting an F");
	test.add(t8);
	//2 repetitions
	Entry<string,string> t9("Fact","Maria got an A!");
	Entry<string,string> t10("Fact","Maria is happy.");
	test.add(t9);
	test.add(t10);
	cout<<"Printing all the words from the beginning."<<endl;
	test.printDictionary(true,test.uniqueWords());
	cout<<"Printing all the words from the end."<<endl;
	test.printDictionary(false,test.uniqueWords());
	cout<<"Printing the word with 2 definitions."<<endl;
	test.printDictionary("Fact",true);
	test.deleteFirst("Kutrolli");
	test.printDictionary("Maria");
	test.deleteFirst("Maria");
	test.deletes("Kutrolli");
	test.deletes("Fact");
	test.printDictionary(true,test.uniqueWords());
	test.printDictionary(false,test.uniqueWords());
	return 0;
}

