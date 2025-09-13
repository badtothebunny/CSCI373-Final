//Entry class programmed by Badtothebunny

#include "Entry.h"

#include <iostream>

using namespace std;

template<typename K, typename V>
Entry<K, V>::Entry()
{
}

template<typename K, typename V>
Entry<K, V>::Entry(const K &k, const V &v):key(k),value(v)  
{
}

template<typename K, typename V>
const K& Entry<K, V>::getK() const 
{
	return key;
}

template<typename K, typename V>
const V& Entry<K, V>::getV() const 
{
	return value;
}

template<typename K, typename V>
void Entry<K, V>::setK(const K &k) 
{
	 key = k;
}

template<typename K, typename V>
void Entry<K, V>::setV(const V &v) 
{
	value = v;
}

template class Entry<string,string>;

