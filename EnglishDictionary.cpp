//EnglishDictionary class programmed by Maria Psomas :)

#include "EnglishDictionary.h"
#include "IteratorG.h"
#include "Range.h"
#include "Entry.h"

//constructor
EnglishDictionary::EnglishDictionary(string n)
{
	name = n;
}

//destructor
EnglishDictionary::~EnglishDictionary()
{
	//body is empty
}

//number of words
int EnglishDictionary::words()const 
{
	return dictionary.size();
}

//number of unique words 
int EnglishDictionary::uniqueWords()const
{
	return dictionary.uniqueKeys();
}

//empty?
bool EnglishDictionary::empty()const
{
	return dictionary.empty();
}

//add function
void EnglishDictionary::add(Entry<string,string> eEntry)
{
	dictionary.put(eEntry.getK(), eEntry.getV());
}

//delete first function
void EnglishDictionary::deleteFirst(string given)
{
	dictionary.erase(given);
}
void EnglishDictionary::deletes(string given)
{
	dictionary.erase(dictionary.findAll(given)); //erases all keys at the returned range
}

//Printing dictionary using a recursive function
void EnglishDictionary::printDictionary(bool direction, int n)
{
//Base check
	 if (n == 0)
        return;
    IteratorG<string, string> base;
    if (direction == true) // print from beginning to end
    {
        base = dictionary.begin();
        if (n == uniqueWords()) //If true, it will print the first key's elements.
            dictionary.print(dictionary.findAll(dictionary.theKey(dictionary.begin())));
        else
        {
            int para = uniqueWords() - n;
            int numKeys = 0;
            string lastKey = dictionary.theKey(dictionary.begin()); //beginning key
            while (para != 0) //while loop increments through the base to find the next unique key
            {
                string currentKey = dictionary.theKey(base); //base key
                if (currentKey != lastKey) 
                {
                    lastKey = currentKey;
                    para--;
                }
                ++base;
            }
            dictionary.print(dictionary.findAll(lastKey));
        }
        printDictionary(direction, --n); //Recursion function call
    }
    else //printing from end to the begining
    {
		base = dictionary.end();
        --base; // Move iterator to the last element
        if (n == uniqueWords())
            dictionary.print(dictionary.findAll(dictionary.theKey(base)));
        else
        {
            int para = uniqueWords() - n;
            int numKeys = 0;
            string lastKey = dictionary.theKey(base); // end key
            while (para != 0)
            {
                string currentKey = dictionary.theKey(base); // base key
                if (currentKey != lastKey)
                {
                    lastKey = currentKey;
                    para--;
                }
                --base;
            }
            dictionary.print(dictionary.findAll(lastKey));
        }
        printDictionary(direction, --n); // Recursion function call
    }
}

//Printing all definitions for a given word.
void EnglishDictionary::printDictionary(string given)
{
	dictionary.print(dictionary.findAll(given));
}

//returns the first word and its definition equal to the given word
Entry<string,string> EnglishDictionary::find(string given)
{
	string vV= dictionary.theValue(dictionary.find(given));
	Entry<string,string> eE;
	eE.setK(given);
	eE.setV(vV);
	return eE;
}
