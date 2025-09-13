//Entry Class Programmed by Badtothebunny

#ifndef ENTRY_H_
#define ENTRY_H_

#include <iostream>
using namespace std;

template <typename K, typename V>
class Entry 
{	
	private: // private data
		K key; // key
		V value; // value
	public: // public functions
		Entry();
		Entry(const K&, const V&);// constructor
		const K& getK() const; // get key
		const V& getV() const; // get value
		void setK(const K&);  // set key
		void setV(const V&); // set value


	friend ostream& operator<<(ostream& os, Entry& p)
	{
		os<<endl<<"{"<<p.key<<" ; "<<p.value<<"}";
		return os;
	}


};

#endif /* ENTRY_H_ */

