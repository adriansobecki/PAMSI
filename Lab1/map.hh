#include <iostream>
#define N 10

int hash_function(int key);
int hash_function(const std::string& key);

template < typename KeyType, typename ValueType >
class Map // Tablica z haszowaniem
{
private:
	ValueType tab[N];
public:
	void insert(const KeyType& key, const ValueType& value);
	ValueType& operator ()( const KeyType& key );
	void remove(const KeyType& key);
	Map();
};

template < typename KeyType, typename ValueType >
void Map<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value)
{
	tab[hash_function(key)] = value;
}

template < typename KeyType, typename ValueType >
Map<KeyType, ValueType>::Map()
{
	for (ValueType& a : this->tab)
		a = -1;
}

template < typename KeyType, typename ValueType >
void Map<KeyType, ValueType>::remove(const KeyType& key)
{
	tab[hash_function(key)] = -1;
}

template < typename KeyType, typename ValueType >
ValueType& Map<KeyType, ValueType>::operator()(const KeyType& key)
{
	return tab[hash_function(key)];
}

int hash_function(int key)
{
	return key % 10;
}

int hash_function(const std::string& key)
{
	int a = 0;;
	int i = 1;
	for (char b : key)
	{
		a = a + int(b) * i;
		i++;
	}
	a = a % 10;
	return a;
}

