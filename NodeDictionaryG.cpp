//NodeDictionaryG class programmed by Badtothebunny

#include "NodeDictionaryG.h"

#include "IteratorG.h"
#include "Range.h"

//constructor
template <typename K, typename V>
NodeDictionaryG<K,V>::NodeDictionaryG()
{
	_uniqueKeys = 0;
	_size = 0; // initially empty
	header = new DNodeG<K,V>; // create sentinels
	trailer = new DNodeG<K,V>;
	header->next = trailer; // have them point to each other
	trailer->prev = header;
}

//destructor
template <typename K, typename V>
NodeDictionaryG<K,V>::~NodeDictionaryG() 
{
}

//size function
template <typename K, typename V>
int NodeDictionaryG<K,V>::size()const
{
	return _size;
}

//uniqueKeys function
template <typename K, typename V>
int NodeDictionaryG<K,V>::uniqueKeys()const
{
	return _uniqueKeys;
}

//Is list empty?
template <typename K, typename V>
bool NodeDictionaryG<K,V>::empty() const
{
	return _size == 0;
}

//Beginning position 
template <typename K, typename V>
IteratorG<K,V> NodeDictionaryG<K,V>::begin() const
{
	return IteratorG<K, V>(header->next);
}

//Ending position 
template <typename K, typename V>
IteratorG<K,V> NodeDictionaryG<K,V>::end() const
{
	return IteratorG<K, V>(trailer);
}

//Find key function
template <typename K, typename V>
IteratorG<K,V> NodeDictionaryG<K,V>::find(K k) const
{
	IteratorG<K,V> temp(begin());
	for (; temp != end(); ++temp)
		if(temp.v->elm.getK() == k)
			return temp;
	return end();
}

//Put function
template <typename K, typename V>
IteratorG<K,V> NodeDictionaryG<K,V>::put(K k, V v)
{
	IteratorG<K,V> temp = find(k);
	DNodeG<K,V> *next = temp.v; //temp's node
	DNodeG<K,V> *behind = next->prev; //temp's predecessor
	DNodeG<K,V> *nNode = new DNodeG<K,V>; //a new node is inserted regardless of whether a key is found
	nNode->elm.setK(k);
	nNode->elm.setV(v);
	nNode->next = next; 
	next->prev = nNode;
	nNode->prev = behind; 
	behind->next = nNode;	
	_size++; //Size is increased no matter what.
	if (temp == end())//No key was found
	{	
		_uniqueKeys++; //uniqueKeys is incremented
	}
	return temp;
}

//erase the first element with the key
template <typename K, typename V>
void NodeDictionaryG<K,V>::erase (K &k)
{
	IteratorG<K,V> temp(begin());
	for (; temp != end(); ++temp)
		if(temp.v->elm.getK() == k)
		{			
			erase(temp);
			break;
		}
}

//Erasing the element at the iterator
template <typename K, typename V>
void NodeDictionaryG<K,V>::erase(IteratorG<K,V> temp) //Erase entry at Iterator
{	
	IteratorG<K,V> unique;
	DNodeG<K,V> *p = unique.v;
	if(p->elm.getK() != p->next->elm.getK()) //if there isn't another element with the same key
		_uniqueKeys--; //the amount of uniqueKeys is reduced.
	DNodeG<K,V>* v = temp.v; // node to remove
	DNodeG<K,V>* w = v->next; // successor
	DNodeG<K,V>* u = v->prev; // predecessor
	u->next = w; 
	w->prev = u; // unlink temp
	delete v; // delete this node
	_size--; // one fewer element
}

//Erasing the element at a specific range
template <typename K, typename V>
void NodeDictionaryG<K,V>::erase(Range<K,V> r)
{
	IteratorG<K,V> cursor = r._begin;
	while (cursor != r._end)
	{
		erase(cursor);
		++cursor;
	}
}

//Finds all elements with the same key
template <typename K, typename V>
Range<K,V> NodeDictionaryG<K,V>::findAll(K k)
{
	IteratorG<K,V> b = find(k);
	IteratorG<K,V> e = b;
//while loop stops at the end or when there are no more elements of the same key
	while (e != end() && e.v->elm.getK() == k)
		++e;
	return Range<K,V>(b,e);//returns range from beginning to end elements with key K.
}

//Printing all elements from range
template <typename K, typename V>
void NodeDictionaryG<K,V>::print(Range<K,V> r)
{
    IteratorG<K, V> cursor = r._begin;
    DNodeG<K, V> *p = cursor.v;
    while (cursor != r._end) 
	{
        cout << p->elm.getK() << " " << p->elm.getV() << endl;
        ++cursor;
        p = cursor.v;
    }
}

template <typename K, typename V>
K NodeDictionaryG<K,V>::theKey(IteratorG<K,V> keyy)
{
	DNodeG<K,V> *p = keyy.v;
	return p->elm.getK();
}

template <typename K, typename V>
V NodeDictionaryG<K,V>::theValue(IteratorG<K,V> valuee)
{
	DNodeG<K,V> *p = valuee.v;
	return p->elm.getV();
}

template <typename K, typename V>
int NodeDictionaryG<K,V>::findNumber(K k)
{
	int n;
	IteratorG<K,V> b = find(k);
//while loop stops at the end or when there are no more elements of the same key
	while (b != end() && b.v->elm.getK() == k)
	{
		++b;
		n++;
	}
	return n;//returns range from beginning to end elements with key K.
}

//template classes
template class NodeDictionaryG<string,string>;

