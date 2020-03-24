#include "list.hh"


template < typename T>
class PriorityQueue
{
private:
	struct p_data
	{
		T data;
		int priority;
	};
	List<p_data> list;
public:
	void enqueue(const T& newElement, int priority);
	T dequeue() { return (list.popFront()).data; }
    void show() { for (p_data i : list) cout << i.data << "--" << i.priority << endl; }   //dla sprawdzenia poprawnosci implementacji
};


template < typename T>
void PriorityQueue<T>::enqueue(const T& newElement, int priority)
{
	p_data node; 
	node.data = newElement; 
	node.priority = priority; 
	list.priority_insert(node, priority);
}