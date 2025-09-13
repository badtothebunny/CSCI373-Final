/*
 *      Author: MaksiKutrolli
 */

#ifndef DNODEG_H_
#define DNODEG_H_

#include <iostream>
#include "Entry.h"

using namespace std;

template <typename K, typename V>
class NodeDictionaryG;

template<typename K, typename V >
class IteratorG;

template<typename K, typename V >
class Range;

template <typename K, typename V>
class DNodeG{
private:
	Entry<K,V> elm;
	DNodeG<K,V> *next;
	DNodeG<K,V> *prev;

	friend class NodeDictionaryG<K,V>;
	friend class IteratorG<K,V>;
	friend class Range<K,V>;
};



#endif /* DNODEG_H_ */
