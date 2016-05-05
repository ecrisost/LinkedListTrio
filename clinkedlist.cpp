#ifdef _CLINKEDLIST_H_

//|| HELPER ||
template <class T>
void CLinkedList<T>::CopyHelper(const CLinkedList &ll)
{
	size = ll.size;

	if(ll.front != NULL)
	{
		//copy front
		Node<T>* temp_ptr = ll.front;
		Node<T>* copy_ptr = NULL;
		copy_ptr = new Node<T>(temp_ptr->data);
		temp_ptr = temp_ptr->next;

		//the rest of the data
		while(temp_ptr != ll.back)
		{
			copy_ptr->next = new Node<T>(temp_ptr->data);
			copy_ptr = copy_ptr->next;
			temp_ptr = temp_ptr->next;
		}

		//copy back
		temp_ptr = ll.back;
		copy_ptr = new Node<T>(temp_ptr->data);
		temp_ptr->next = front;
		
	}
}

//destructor helper
template <class T>
void CLinkedList<T>::DeleteList()
{
	Node<T>* temp = front;
	while(front != back)
	{
		temp = front->next;
		delete front;
		front  = temp;
	}

}
//|| CONSTRUCTORS ||
//default constructor
template <class T>
CLinkedList<T>::CLinkedList()
{
	front = NULL;
	back = NULL;
	size = 0;
}

//parameterized copy constructor
template <class T>
CLinkedList<T>::CLinkedList(const CLinkedList &ll)
{
	CopyHelper(ll);
}

//destructor
template <class T>
CLinkedList<T>::~CLinkedList()
{
	DeleteList();
}

//|| MUTATORS ||
template <class T>
bool CLinkedList<T>::InsertFront(T item)
{
	Node<T>* new_node = new Node<T>(item);
	bool is_ins = false;
	if(front == NULL)
	{
		//empty list
		new_node->next = back;
		front = new_node;
		is_ins = true;
		size++;
	}
	else
	{
		new_node->next = front;
		front->prev = new_node;
		new_node->prev = back;
		front = new_node;
		is_ins = true;
		size++;

	}
	
	return is_ins;
	
}

template <class T>
bool CLinkedList<T>::InsertBack(T item)
{
	Node<T>* new_node = new Node<T>(item);
	bool is_ins = false;

	if(front == NULL)
	{
		//empty list
		new_node->next = back;
		new_node->prev = back;
		front = new_node;
		is_ins = true;
		size++;
	}
	else if(back == NULL)
	{
		//back is empty
		Node<T>*temp = front;
		Node<T>* temp2 = front;
		while(temp != back)
		{
			//find the position of the item
			temp2 = temp;
			temp = temp->next;
		}
		temp = new_node;
		new_node->prev = temp2;
		temp2->next = new_node;
		new_node->next = front;
		back = new_node;
		is_ins = true;
		size++;
	}
	else
	{
		back->next = new_node;
		new_node->prev = back;
		new_node->next = front;
		front->prev = new_node;
		back = new_node;
		is_ins = true;
		size++;
	}
	return is_ins;
}

template <class T>
bool CLinkedList<T>::InsertAt(T item, int p)
{
	Node<T>* new_node = new Node<T>(item);
	Node<T>* temp = front;
	Node<T>* temp2 = front;
	bool is_ins = false;
	int i = 0;

	if(front == NULL)
	{
		//empty list
		new_node->next = back;
		new_node->prev = back;
		front = new_node;
		is_ins = true;
		size++;
	}
	else if(p == 0)
	{
		//front is not NULL
		new_node->next = front;
		front->prev = new_node;
		new_node->prev = back;
		front = new_node;
		is_ins = true;
		size++;
	}
	else if(back == NULL && p == (size-1))
	{
		//back is empty
		Node<T>*temp = front;
		while(temp != back)
		{
			//find the position of the item
			temp = temp->next;
		}
		temp = new_node;
		new_node->prev = temp->prev;
		new_node->next = front;
		back = new_node;
		is_ins = true;
		size++;
	}
	else if(p == (size-1))
	{
		//back is not null but p is the last
		back->next = new_node;
		new_node->prev = back;
		new_node->next = front;
		front->prev = new_node;
		back = new_node;
		is_ins = true;
		size++;
	}
	else
	{
		//middle
		while(i != p && i < (size-1) && temp != back)
		{
			//find the position of the item
			i++;
			temp = temp->next;
		}
		temp->prev->next = new_node;
		new_node->prev = temp->prev->next;
		new_node->next = temp;
		temp->prev = new_node;
		is_ins = true;
		size++;
	}

	return is_ins;
}

//remove 
template <class T>
bool CLinkedList<T>::Remove(T item)
{
	bool is_removed = false;
	Node<T>* removed_ptr = front;
	if(front == NULL)
	{
		return is_removed;
	}

	if(front->data == item)
	{
		front = removed_ptr->next;
		back->next = front;
		delete removed_ptr;
		is_removed = true;
		size--;
	}
	else
	{
		//check in the middle
		removed_ptr = front->next;
		while(removed_ptr != back)
		{
			//search the list until item to remove is found
			if(removed_ptr->data == item)
			{
				removed_ptr->prev->next = removed_ptr->next;
				removed_ptr->next->prev = removed_ptr->prev;
				delete removed_ptr;
				is_removed = true;
				size--;
				break;
			}
			removed_ptr = removed_ptr->next;
		}

		//check if item is at the back
		if(removed_ptr->data == item)
		{
			back = removed_ptr->prev;
			back->next = front;
			delete removed_ptr;
			is_removed = true;
			size--;
		}
	}

	return is_removed;
}

// || ACCESSORS ||
//size of the list
template <class T>
int CLinkedList<T>::GetSize() const
{
	return size;
}

//check if the list is empty
template <class T>
bool CLinkedList<T>::IsEmpty() const
{
	if(front == NULL)
	{
		return true;
	}

	return false;
}

//search item
template <class T>
bool CLinkedList<T>::Search(T item) 
{
	Node<T>* temp = front;
	bool is_found = false;
	//search item
	while(temp != back)
	{
		if(temp->data == item)
		{
			return true;
		}
		temp = temp->next;
		
	}

	//check for the back
	if(temp->data == item)
	{
		return true;
	}

	return false;
}

//retrieve item and return
template <class T>
T CLinkedList<T>::Retrieve(T item)
{
	T item_returned;
	Node<T>* temp = front;

	if(front == NULL)
	{
		//list is empty
		return item_returned;
	}
	
	while(temp != back)
	{
		if(temp->data == item)
		{
			item_returned = temp->data;
			return item_returned;
		}
		temp = temp->next;
	}

	//for the back
	if(temp->data == item)
	{
		item_returned = temp->data;
	}

	return item_returned;
}
#endif