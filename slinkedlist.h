//Version 1 written by Elaine Crisostomo on April 19, 2016
//slinkedlist header class: a singularly linked list template with a front and back pointer
//has all the basic operations (Insert, Remove, Retrieve)
//version 2: will sort the list using insertion sort

#ifndef _SLINKEDLIST_H_
#define _SLINKEDLIST_H_

using namespace std;

//Node class: creates the nodes for the linked list
template <class T>
class Node
{
	public:
	Node<T>*next;
	T data;

	//parameterized constructor
	Node(T value)
	{
		data = value;
		next = NULL;
	}	
};

//SLinkedList class
template <class T>
class SLinkedList
{
	private:
		Node<T>* front;//pointer to the front of the node
		Node<T>* back;//pointer to the back of the node
		int size;//size of the list

		//Copy Constructor Helper:performs a deep copy of the list
		void CopyList(const SLinkedList& ll);

		//Destructor Helper: deallocates the list
		void DeleteList();

	public:

		//|| CONSTRUCTORS ||

		//|| DEFAULT CONSTRUCTOR ||
		//initializes the private member parameters
		SLinkedList(); 

		//|| COPY CONSTRUCTOR ||
		//performs a deep copy of the list
		SLinkedList(const SLinkedList& ll);

		// || DESTRUCTOR ||
		//deallocates the memory ofthe list
		~SLinkedList();

		//|| MUTATORS ||

		//|| INSERT FRONT ||
		//inserts an item at the front of the list
		//if the item is in the list, return true
		//if not, return false
		bool InsertFront(T item);

		//|| INSERT BACK ||
		//inserts an item at the back of the list
		//if the item is in the list, return true
		//if the item is not in the list, return false
		bool InsertBack(T item);

		//|| REMOVE ||
		//removes an item in the list
		//if the item is in the list and can be removed, return true
		//if the item is not in the list, return false
		bool Remove(T item);

		//|| ACCESSORS ||

		//|| SEARCH ||
		//search the item in the list and return true if it's in the list
		//returns false if the item isn't in the list
		bool Search(T item) const;

		// || ISEMPTY ||
		//return true if the list is empty
		bool IsEmpty() const;

		// || RETRIEVE ||
		// find the item in the list and return the pointer to the item
		// if the item isn't there, return NULL
		T* Retrieve(T item);

		// || GETSIZE ||
		//size of the list
		int GetSize() const;

		//|| OVERLOADED OPERATORS ||

		// || ASSIGNMENT OPERATOR ||
		//perform a deep copy if the object to be assigned exists
		//else perform a shallow copy
		SLinkedList& operator=(const SLinkedList& ll);
	
};

#include "slinkedlist.cpp"

#endif