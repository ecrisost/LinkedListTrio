#ifndef _CLINKEDLIST_H_
#define _CLINKEDLIST_H_
#include <vector>
template <class T>
class Node
{
	public:
		Node<T>* next;
		Node<T>* prev;
		T data;
		Node(T value)
		{
			data = value;
			next = NULL;
			prev = NULL;
		}
		
};

template <class T>
class CLinkedList
{
	private:
		Node<T>* front;
		Node<T>* back;
		int size;

		void CopyHelper (const CLinkedList &ll);
		void DeleteList();

   public:
		CLinkedList();//default constructor
		CLinkedList(const CLinkedList &ll); //parameterized copy constructor
		~CLinkedList(); //destructor

		//|| MUTATORS ||
		bool InsertFront(T item);
		bool InsertBack(T item);
		bool InsertAt(T item, int p);
		bool Remove(T item);

		//|| ACCESSORS ||
		int GetSize() const;//size of the list
		bool IsEmpty() const;
		bool Search(T item);//search for item

		T Retrieve(T item); //retrieve data

//		vector<T> Dump() const;//dump items in the list into a vector

		//|| OVERLOADED OPERATORS ||
		//overload assignment operator
		CLinkedList& operator =(const CLinkedList &ll);

};

#include "clinkedlist.cpp"
#endif