//DictionaryG ADT written by Badtothebunny

#ifndef _INTERFACE_DICTIONARYG_H
#define _INTERFACE_DICTIONARYG_H

template <typename I, typename R, typename K, typename V>
class DictionaryG
{ 
	public:
		virtual ~DictionaryG() = default;
		virtual int size() const = 0; //Returns number of nodes
		virtual int uniqueKeys() const = 0; //Returns number of unique keys
		virtual bool empty() const = 0; //Is list empty?
		virtual I begin() const = 0; //Beginning position
		virtual I end() const = 0; //Ending position
		virtual I find(K) const = 0;//Returns iterator pointing to the first entry with key
		virtual I put(K,V) = 0;//Insert pair (K,V)
		virtual void erase (K&) = 0; //Removes the first entry with key K
		virtual void erase (I) = 0; //Erase entry at Iterator
		virtual void erase (R) = 0; // Erases entry at range
		virtual R findAll(K) = 0; //Returns the range for a key
		virtual void print(R) = 0; //Prints all Entries in range
};




#endif 

