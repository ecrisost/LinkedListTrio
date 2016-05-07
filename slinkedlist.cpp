#ifdef _SLINKEDLIST_H_

//PRIVATE MEMBER FUNCTIONS

//copy helper
template <class T>
void SLinkedList<T>::CopyList(const SLinkedList& ll)
{
	front = NULL;
	size = ll.size;

	//copies the front of the list
	if(front != NULL)
	{

		Node<T>* temp_ptr = ll.front;//temporary pointer to hold the object's front
		Node<T>* copy_ptr = NULL;//pointer to be copied

		//create a copy of the front node 
		copy_ptr = new Node<T>(temp_ptr->data);
		front = copy_ptr;
		temp_ptr = temp_ptr->next;

		//copy the rest of the nodes
		while(temp_ptr != NULL)
		{
			copy_ptr->next = new Node<T>(temp_ptr->data);
			copy_ptr = copy_ptr->next;
			temp_ptr = temp_ptr->next;
		}
	}
}

//destructor helper
template <class T>
void SLinkedList<T>::DeleteList()
{
	Node<T>*temp = front;
	//deallocates the list
	while(front != NULL)
	{
		temp = front->next;
		delete front;
		front = temp;
	}
}

//PUBLIC MEMBER FUNCTIONS

//|| CONSTRUCTORS ||

//default constructor
template <class T>
SLinkedList<T>::SLinkedList()
{
	front = NULL;
	back = NULL;
	size = 0;
}

//copy constructor
template <class T>
SLinkedList<T>::SLinkedList(const SLinkedList& ll)
{
	//copy helper
	CopyList(ll);
}

//destructor
template <class T>
SLinkedList<T>::~SLinkedList()
{
	//destructor helper
	DeleteList();
}
//||ACCESSORS||
template <class T>
bool SLinkedList<T>::IsEmpty() const
{
	if (front == NULL)
	{
		//return true if empty
		return true;
	}
	return false;
}

template <class T>
int SLinkedList<T>::GetSize() const
{
	return size;
}

template <class T>
bool SLinkedList<T>::Search(T item) const
{
	Node<T>* temp = front;

	while(temp != NULL)
	{
		//find the item in the list
		if(temp->data == item)
		{
			//if the item is in the list return true
			return true;
		}
		temp = temp->next;
	}

	return false;
}

//retrieve
template <class T>
T* SLinkedList<T>::Retrieve(T item)
{
	Node<T>*temp = front;

	while(temp != NULL)
	{
		//find the item in the list 
		//return pointer
		if(temp->data == item)
		{
			return &(temp->data);
		}
		temp = temp->next;
	}

	return &(temp->data);

}

// || MUTATORS ||

//insert front
template <class T>
bool SLinkedList<T>::InsertFront(T item)
{
	
	Node<T>*new_node = new Node<T>(item);//node to be inserted
	bool is_inserted = false;//bool to determine if the node has been inserted

	if(front == NULL)
	{
		//check if the list is empty
		new_node->next = NULL;//point next to null
		front = new_node;
		is_inserted = true;
		size++;
	}
	else
	{
		//if it's not empty
		new_node->next = front;//point next to the front
		front = new_node;
		is_inserted = true;
		size++
	}

	return is_inserted;
}

//insert at the back of the list
template<class T>
bool SLinkedList<T>::InsertBack(T item)
{
	Node<T>*new_node = new Node<T>(item);//node to be inserted
	Node<T>*cur_ptr = front;//current pointer
	Node<T>*prev_ptr = front;//previos pointer
	bool is_inserted = false;//bool to determine if node has been inserted

	if(front == NULL)
	{
		//empty list
		new_node->next = NULL;//point next to NULL
		front = new_node;
		is_inserted = true;
		size++;
	}
	else
	{
		while(cur_ptr != NULL)
		{
			//find where the position of the new back node is going to be
			prev_ptr = cur_ptr;
			cur_ptr = cur_ptr->next;
		}

		prev_ptr->next = new_node;//assign the previous node's next pointer to the new back
		new_node->next = NULL;//assign new node's next pointer to NULL
		back = new_node;
		is_inserted = true;
		size++;
	}

	return is_inserted;
}

// || REMOVE ||
template <class T>
bool SLinkedList<T>::Remove(T item)
{
	Node<T>* cur_ptr = front;//current pointer
	Node<T>* prev_ptr = front;//previous pointer
	bool is_removed = false;//bool to check if node has been removed

	if(front == NULL)
	{
		//list is empty don't remove
		is_removed = false;
	}
	else 
	{
		if(front->data == item)
		{
			//check if the item is in the front
			front = cur_ptr->next;//assign front to the next pointer
			delete cur_ptr;
			size--;
			is_removed = true;
		}
		else 
		{
			//check if the item is in the middle

			cur_ptr = front->next;//move the current pointer to the node after front

			while(cur_ptr != NULL)
			{
				//search through the list
				if(cur_ptr->data == item)
				{
					//if item is found
					//set the previous node's next to node after current pointer
					prev_ptr->next = cur_ptr->next;

					if(cur_ptr == back)
					{//check if the current pointer is back
						//set prev_ptr's next to NULL and assign it as the new back pointer
						prev_ptr->next = NULL;
						back = prev_ptr;
					}

					delete cur_ptr;//delete the current poinetr
					size--;
					is_removed = true;
					break;
				}

				prev_ptr = cur_ptr; //assign the current pointer to the prev pointer before traversing
				cur_ptr = cur_ptr->next;

			}

		}

	}

	return is_removed;
}

//sort using selection sort
template <class T>
void SLinkedList<T>::SortList()
{
	Node<T>*min_ptr = NULL;//pointer to the smallest data
	Node<T>* temp_ptr = front;//first iterator to divide the list between unsorted and sorted
	Node<T>* temp_ptr2 = front;//second iterator to find the smallest data
	T temp_data;//holds the data for swapping

	for(temp_ptr = front; temp_ptr->next != NULL; temp_ptr = temp_ptr->next)
	{
		//sets where the sorted and unsorted halves are
		min_ptr = temp_ptr;

		for(temp_ptr2 = temp_ptr->next; temp_ptr2 != NULL; temp_ptr2 = temp_ptr2->next)
		{
			if(temp_ptr2->data < min_ptr->data)
			{
				//finds the smalles data
				min_ptr = temp_ptr2;
			}

		}
		if(min_ptr != temp_ptr)
		{
			//swap
			temp_data = min_ptr->data;
			min_ptr->data = temp_ptr->data;
			temp_ptr->data  = temp_data;
		}
	}

}
//|| OVERLOADED ASSIGNMENT OPERATORS ||
template <class T>
SLinkedList<T>& SLinkedList<T>::operator =(const SLinkedList<T>& ll)
{
	if(this != &ll)
	{
		//object pointer is NULL
		CopyList(ll);
	}
	return *this;

}


#endif
