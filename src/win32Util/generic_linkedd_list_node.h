#ifndef TLINKED_LIST_NODE_H
#define TLINKED_LIST_NODE_H

template <class T>
class generic_linked_list_node final
{
public:
	generic_linked_list_node<T>* _next_node;
	T*                           _pointer;
};

#endif