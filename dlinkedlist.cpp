#ifdef _DLINKEDLIST_H_


// || PRIVATE HELPER FUNCTIONS ||

template <class T>
void DLinkedList<T>::CopyList(const DLinkedList& ll)
{
	front = NULL;
	size = ll.size;
	if(front != NULL)
	{
		//copy front
		Node<T>* temp_ptr = ll.front;
		Node<T>* copy_ptr = NULL;
		copy_ptr = new Node<T>(temp_ptr->data);
		temp_ptr = temp_ptr->next;

		//copy the rest of the list
		while(temp_ptr != NULL)
		{
			copy_ptr->next = new Node(temp_ptr->data);
			copy_ptr = copy_ptr->next;
			temp_ptr = temp_ptr->next;
		}
	}
}

//destructor helper
template <class T>
void DLinkedList<T>::DeleteList()
{
	Node<T>* temp = front;
	while(front != NULL)
	{
		temp = front->next;
		delete front;
		front = temp;
	}
}

/*//quicksort helper
template <class T>
Node<T>* DLinkedList<T>::QSPartition(Node<T>* head, Node<T>* tail)
{
	T pivot_element = tail->data;
	Node<T>* i = head;
	int swaps = 0;
	Node<T>* pivot_ptr = NULL;
	for(Node<T>* j = head; j != tail; j = j->next)
	{
		if(j->data < pivot_element)
		{	
			if(swaps == 0)
			{
				Swap(i->data, j->data);
			}
			else
			{
				if(i)
				{
					i = i->next;
					Swap(i->data, j->data);
				}
			}
			swaps++;
		}
		
	}
	pivot_ptr = i->next;
	Swap(pivot_ptr->data, pivot_element);

	return pivot_ptr;

}

//swap helper
template <class T>
void DLinkedList<T>::Swap(T a, T b)
{
	T temp_data;
	temp_data = a;
	a = b;
	b = temp_data;
}
*/
// || CONSTRUCTORS ||]

//default constructor
template <class T>
DLinkedList<T>::DLinkedList()
{
	size = 0;
	front = NULL;
	back = NULL;
}

//copy constructor
template <class T>
DLinkedList<T>::DLinkedList(const DLinkedList& ll)
{
	CopyList(ll);
}

//destructor
template <class T>
DLinkedList<T>::~DLinkedList()
{
	DeleteList();
}

// || ACCESSORS ||

template <class T>
int DLinkedList<T>::GetSize() const
{
	return size;
}

//check if the list is empty
template <class T>
bool DLinkedList<T>::IsEmpty() const
{
	if (front==NULL)
	{
		return true;
	}

	return false;
}

//search item
template <class T>
bool DLinkedList<T>::Search(T item)
{
	Node<T>* temp = front;

	while(temp != NULL)
	{
		if(temp->data == item)
		{
			return true;
		}

		temp = temp->next;
	}

	return false;
}

//retrieve pointer to an item
template <class T>
T* DLinkedList<T>::Retrieve(T item)
{
	T* node_return = NULL;
	while(front != NULL)
	{
		if(front->data == item)
		{
			node_return = &(front->data);
		}
		front = front->next;
	}

	return node_return;
}

//get the front of the list
template <class T>
Node<T>* DLinkedList<T>::GetFront() const
{
	return this->front;
}

//get the back of the list
template <class T>
Node<T>* DLinkedList<T>::GetBack() const
{
	return this->back;
}

//print the list
template <class T>
void DLinkedList<T>::PrintList()
{
	Node<T>* temp = front;
	while(temp != NULL)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
}
//|| MUTATORS ||

//insert at the front
template <class T>
bool DLinkedList<T>::InsertFront(T item)
{
	Node<T>* new_node = new Node<T>(item);
	bool is_front = false;

	if(front == NULL)
	{
		new_node->next = NULL;
		front = new_node;
		is_front = true;
		size++;
	}
	else
	{
		new_node->next = front;
		front->prev = new_node;
		front = new_node;
		is_front = true;
		size++;
	}

	return is_front;
}

//insert at the back
template<class T>
bool DLinkedList<T>::InsertBack(T item)
{
	Node<T>*new_node = new Node<T>(item);
	Node<T>* find_null = front;
	Node<T>* current = NULL;
	bool is_back = false;

	if(front == NULL)
	{
		new_node->next = NULL;
		front = new_node;
		is_back = true;
		size++;
	}
	else if(back == NULL)
	{
		while(find_null != NULL)
		{
			current = find_null;
			find_null = find_null->next;
		}

		current->next = new_node;
		new_node->prev = current;
		new_node->next = NULL;
		back = new_node;
		is_back = true;
		size++;
	}
	else
	{
		new_node->prev = back;
		new_node->next = NULL;
		back = new_node;
		is_back = true;
		size++;

	}

	return is_back;
}

template <class T>
T* DLinkedList<T>::Remove(T item)
{
	T* item_removed = NULL;
	Node<T>* removed_ptr = front;
	Node<T>* temp_ptr = NULL;
	if(front == NULL)
	{
		//empty list return nothing
		return item_removed;
	}

	if(front->data == item)
	{
		//remove from the front
		item_removed = &(front->data);
		front = removed_ptr->next;
		delete removed_ptr;
		size--;
	}
	else
	{
		//remove from the middle
		removed_ptr = front->next;
		while(removed_ptr != NULL)
		{
			if(removed_ptr->data==item && removed_ptr != back)
			{
				item_removed = &(removed_ptr->data);
				removed_ptr->prev->next = removed_ptr->next;
				removed_ptr->next->prev = removed_ptr->prev;
				delete removed_ptr;
				size--;
				break;
			}
			else if(removed_ptr == back)
			{
				//remove from the back
				item_removed = &(removed_ptr->data);
				removed_ptr->prev->next = NULL;
				back = removed_ptr->prev;
				delete removed_ptr;
				size--;
				break;
				
			}
			removed_ptr = removed_ptr->next;
		}

	}

	return item_removed;
}

template <class T>
void DLinkedList<T>::SortList(Node<T>* head, Node<T>* tail)
{
	
	return;
	
}


//OVERLOADED OPERATORS
//assignment operator
template <class T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList<T> &ll)
{
	if(this != ll)
	{
		CopyList(ll);
	}

	return *this;
}



#endif