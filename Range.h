#ifndef RANGE_H
#define RANGE_H

template <typename K, typename V>
class Range 
{
	private:
		IteratorG<K,V> _begin;
		IteratorG<K,V> _end;
	public:
		Range(const IteratorG<K,V>& b, const IteratorG<K,V>& e):_begin(b),_end(e)
		{};
		IteratorG<K,V>& begin()
		{
			return _begin;
		};
		IteratorG<K,V>& end()
		{
			return _end;
		};
		
		friend class NodeDictionaryG<K,V>; // give NodeDictionaryG access
};
#endif
