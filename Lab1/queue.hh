#include "list.hh"


template < typename T>
class Queue
{
private:
	List<T> list;
public:
	void enqueue(const T& newElement) { list.pushBack(newElement); }
	T dequeue() { return list.popFront(); }
	void show() { for (T i : list) cout << i << endl; }  //dla sprawdzenia poprawnosci implementacji
}; 

