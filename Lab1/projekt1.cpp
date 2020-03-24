
#include "list.hh"
#include "stack.hh"
#include "queue.hh"
#include "priorityqueue.hh"
#include "map.hh"
#include <list>
#include <stack>
#include <queue>
#include <map> 

void moje_struktury();
void typy_z_stl();

int main()
{ 

    moje_struktury();
    typy_z_stl();
}

void moje_struktury() {
    // ||||||||||||||LISTA||||||||||||||||
    cout << "<<<<<<<<<<<<<<<<< LISTA >>>>>>>>>>>>>>>>>>" << endl;
    List<int> list;
    list.pushBack(3);
    list.pushFront(1);
    list.insert(0, 0);
    list.insert(2, 2);
    list.insert(4, 4);
    cout << "ELEMENTY:" << endl;
    list.show();
    list.remove(0);
    list[3] = 10;
    cout << "ELEMENTY:" << endl;
    list.show();
    cout << "liczba elementow wiekszych od 2 : ";
    cout << std::count_if(list.begin(), list.end(), [](int i) { return i > 2;}) << endl;

    // ||||||||||||||STOS||||||||||||||||
    cout << endl << "<<<<<<<<<<<<<<<<< STOS >>>>>>>>>>>>>>>>>>" << endl;
    Stack<int> stack;
    stack.push(0);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    cout << "ELEMENTY:" << endl;
    stack.show();
    stack.pop();
    cout << "ELEMENTY:" << endl;
    stack.show();

    // ||||||||||||||KOLEJKA||||||||||||||||
    cout << endl << "<<<<<<<<<<<<<<<<< KOLEJKA >>>>>>>>>>>>>>>>>>" << endl;
    Queue<int> queue;
    queue.enqueue(0);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout << "ELEMENTY:" << endl;
    queue.show();
    queue.dequeue();
    cout << "ELEMENTY:" << endl;
    queue.show();

    // ||||||||||||||KOLEJKA PRIORYTETOWA ||||||||||||||||
    cout << endl << "<<<<<<<<<<<<<<<<< KOLEJKA PRIORYTETOWA >>>>>>>>>>>>>>>>>>" << endl;
    PriorityQueue<int> priority_queue;
    priority_queue.enqueue(0, 10);
    priority_queue.enqueue(1, 4);
    priority_queue.enqueue(2, 5);
    priority_queue.enqueue(3, 2);
    cout << "ELEMENTY:" << endl;
    priority_queue.show();
    priority_queue.dequeue();
    cout << "ELEMENTY:" << endl;
    priority_queue.show();

    // ||||||||||||||MAP||||||||||||||||
    cout << endl << "<<<<<<<<<<<<<<<<< MAP >>>>>>>>>>>>>>>>>>" << endl;
    Map<string, int> map;
    cout << "INDEKS DLA KLUCZA ALA: " << hash_function("ALA") << endl;
    cout << "INDEKS DLA KLUCZA MA: " << hash_function("MA") << endl;
    cout << "INDEKS DLA KLUCZA KOTA: " << hash_function("KOTA") << endl;
    map.insert("ALA", 10);
    map.insert("MA", 20);
    map.insert("KOTA", 30);

    cout << "WARTOSC DLA KLUCZA ALA: " << map("ALA") << endl;
    cout << "WARTOSC DLA KLUCZA MA: " << map("MA") << endl;
    cout << "WARTOSC DLA KLUCZA KOTA: " << map("KOTA") << endl;
    map.remove("ALA");
    cout << "USUNIECIE WARTOSCI DLA KLUCZA ALA" << endl;
    cout << "WARTOSC DLA KLUCZA ALA: " << map("ALA") << endl;

    cout << endl << "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl << endl;
}


void typy_z_stl() {
    // ||||||||||||||LISTA||||||||||||||||
    cout << "<<<<<<<<<<<<<<<<< LISTA STL >>>>>>>>>>>>>>>>>>" << endl;
    std::list<int> l;
    l.push_back(3);
    l.push_front(1);
    std::list<int>::iterator it = l.begin();
    l.insert(it, 0);
    advance(it, 1);
    l.insert(it, 2);
    advance(it, 1);
    l.insert(it, 4);
    cout << "ELEMENTY:" << endl;
    for (int i : l)
        cout << i << endl;
    l.remove(0);
    cout << "ELEMENTY:" << endl;
    for (int i : l)
        cout << i << endl;
    cout << "liczba elementow wiekszych od 2 : ";
    cout << std::count_if(l.begin(), l.end(), [](int i) { return i > 2;}) << endl;


    // ||||||||||||||STOS||||||||||||||||
    cout << endl << "<<<<<<<<<<<<<<<<< STOS STL>>>>>>>>>>>>>>>>>>" << endl;
    std::stack<int> s;
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();


    // ||||||||||||||KOLEJKA||||||||||||||||
    cout << endl << "<<<<<<<<<<<<<<<<< KOLEJKA STL >>>>>>>>>>>>>>>>>>" << endl;
    queue<int> q;
    q.push(0);
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << endl;
    q.pop();


    // ||||||||||||||KOLEJKA PRIORYTETOWA ||||||||||||||||
    cout << endl << "<<<<<<<<<<<<<<<<< KOLEJKA PRIORYTETOWA STL >>>>>>>>>>>>>>>>>>" << endl;
    std::priority_queue<int> pq;
    pq.push(0);
    pq.push(1);
    pq.push(2);
    pq.push(3);
    cout << pq.top() << endl;
    pq.pop();


    // ||||||||||||||MAP||||||||||||||||
    cout << endl << "<<<<<<<<<<<<<<<<< MAP STL >>>>>>>>>>>>>>>>>>" << endl;
    std::map<string, int> m;
    m.insert(pair<string, int>("ALA", 10));
    m.insert(pair<string, int>("MA", 20));
    m.insert(pair<string, int>("KOTA", 30));
    for (std::map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
        cout << it->first << " => " << it->second << '\n';
    m.erase("ALA");
    cout << endl;
    for (std::map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
        cout << it->first << " => " << it->second << '\n';
    cout << endl;
    cout << "MA => " << m.find("MA")->second << '\n';
    


}
