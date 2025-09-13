//NodeDictionaryG class programmed by Maria Psomas :)

#ifndef NODEDICTIONARYG_H
#define NODEDICTIONARYG_H

#include "DictionaryG.h"
#include "DNodeG.h"
#include "Entry.h"

template <typename K, typename V>
class IteratorG;

template <typename K, typename V>
class Range;

template <typename K, typename V>
class NodeDictionaryG: public DictionaryG<IteratorG<K,V>, Range<K,V>, K, V> 
{
	private:
		int _uniqueKeys; //current number of unique keys in the Dictionary
		int _size; //total number of entries
		DNodeG<K,V> *header; 
		DNodeG<K,V> *trailer;
	public:
		NodeDictionaryG();
		virtual ~NodeDictionaryG();
		int size() const; //Returns number of nodes
		int uniqueKeys() const; //Returns number of unique keys
		bool empty() const; //Is list empty?
		IteratorG<K,V> begin() const; //Beginning position
		IteratorG<K,V> end() const; //Ending position
		IteratorG<K,V> find(K) const;//Returns iterator pointing to the first entry with key
		IteratorG<K,V> put(K,V);//Insert pair (K,V)
		void erase (K&); //Removes the first entry with key K
		void erase (IteratorG<K,V>); //Erase entry at Iterator
		void erase (Range<K,V>); // Erases entry at range
		Range<K,V> findAll(K); //Returns the range for a key
		void print(Range<K,V>); //Prints all Entries in range
		K theKey(IteratorG<K,V>); //returns the key
		V theValue(IteratorG<K,V>);//returns the value
		int findNumber(K); //returns the number of elements with the same key
};

#endif 
