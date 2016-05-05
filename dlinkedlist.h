#ifndef _DLINKEDLIST_H_
#define _DLINKEDLIST_H_
#include <cstdlib>

template <class T>
class Node
{
	public:
		Node<T>* next;
		Node<T>* prev;
		T data;
		Node(T value)
		{
			prev = NULL;
			next = NULL;
			data = value;
		}
};

template <class T>
class DLinkedList
{
	private:
		Node<T>* front;
		Node<T>* back;
		int size;

		void DeleteList();
		void CopyList(const DLinkedList &ll);
		Node<T>* QSPartition(Node<T>* head, Node<T>*tail);
		void Swap(T a, T b);

	public:
		//||CONSTRUCTORS||

		//default constructors
		DLinkedList();
		//copy constructors
		DLinkedList(const DLinkedList &ll);
		//destructor
		~DLinkedList();

		//||MUTATORS||
		bool InsertFront(T item);
		bool InsertBack(T item);

		//remove the item from the list and return the pointer to the item
		T* Remove(T item);

		//sort the list using quicksort
		void SortList(Node<T>* head, Node<T>* tail);

		//||ACCESORS||

		//retreive the pointer
		T* Retrieve(T item);

		//see if the item is in the list
		bool Search(T item);

		//see if the list is empty
		bool IsEmpty() const;

		//return size
		int GetSize() const;

		//print list
		void PrintList();

		//get front
		Node<T>* GetFront() const;

		//get last
		Node<T>* GetBack() const;

		//||OVERLOADED OPERATORS||
		//overload assignment operators
		DLinkedList& operator=(const DLinkedList& ll);
};

#include "dlinkedlist.cpp"
#endif