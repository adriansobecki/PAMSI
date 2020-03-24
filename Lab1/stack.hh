#include "list.hh"


template < typename T>
class Stack
{
private:
	List<T> list;
public:
	void push(const T& newElement) { list.pushFront(newElement); }
	T pop() { return list.popFront(); }
	void show() { for (T i : list) cout << i << endl; }  //dla sprawdzenia poprawnosci implementacji
};
