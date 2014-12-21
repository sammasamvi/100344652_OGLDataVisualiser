#ifndef TLINKED_LIST_H
#define TLINKED_LIST_H

#include "generic_linkedd_list_node.h"

template <class T>
class generic_linked_list
{
    private:
		generic_linked_list_node<T>* _curr_node;
		generic_linked_list_node<T>* _root_node;
		generic_linked_list_node<T>* _tail_node;

    public:
		generic_linked_list();
		~generic_linked_list();

		void add(T* pointer);
		T*   get_next_pointer();
		void remove(T*pointer);
		void reset_pointer_next();
};

template <class T>
generic_linked_list<T>::generic_linked_list()
{
	_root_node = nullptr;
	_tail_node = nullptr;
}

template <class T>
generic_linked_list<T>::~generic_linked_list()
{
	delete _root_node;
}

template <class T>
void generic_linked_list<T>::add(T* pointer)
{
	generic_linked_list_node<T>* node = new generic_linked_list_node<T>;
	node->_pointer                    = pointer;
	node->_next_node                  = nullptr;

	if (!_root_node)
	{
		_root_node = node;
		_tail_node = _root_node;
		_curr_node = _root_node;
	}
	else
	{
		_tail_node->_next_node = node;
		_tail_node             = node;
	}
}

template <class T>
T* generic_linked_list<T>::get_next_pointer()
{
	if (_curr_node)
	{
		generic_linked_list_node<T>* node = _curr_node;
		_curr_node                        = _curr_node->_next_node;

		return node->_pointer;
	}

	return nullptr;
}

template <class T>
void generic_linked_list<T>::remove(T* pointer)
{
	generic_linked_list_node<T>* c_node = _root_node;

	if (pointer == _root_node->_pointer)
	{
		_root_node = c_node->_next_node;
		delete c_node;
	}
	else
	{
		while (c_node)
		{
			if (c_node->_next_node->_pointer == pointer)
			{
				generic_linked_list_node<T>* t_node = c_node->_next_node;
				c_node->_next_node                  = t_node->_next_node;

				delete t_node;
				break;
			}

			c_node = c_node->_next_node;
		}
	}
}

template <class T>
void generic_linked_list<T>::reset_pointer_next()
{
	_curr_node = _root_node;
}

#endif