#pragma once
#include <iostream>

struct list
{
	list* next;
	int data;
};

class List
{
protected:
	list* current = new list;
	list* head = new list;
public:
	List() : head(NULL), current(head)
	{
	}

	List(list* hd, int data /*= 0*/) : head(hd), current(head)
	{
	}

	int Next()
	{
		if (current != NULL)
		{
			current = current->next;
			//return 0;
		}
		else
			//return 2;
			throw 2;
	}

	list* getHead()
	{
		return head;
	}

	list* getCurrent()
	{
		return current;
	}

	int& getData()
	{
		return current->data;
	}
};

class Stack : public List
{
public:
	Stack(list* head = NULL, int data = 0) : List(head, data)
	{
	}

	void push_front(list* elem)
	{
		elem->next = head;
		head = elem;
		current = elem;
	}

	int pop_front()
	{
		if (head == NULL)
			//return 1;
			throw 1;
		list* tmp = head;
		head = head->next;
		if (head == NULL)
			current = head;
		free(tmp);
	}
};

class Queue : public List
{
protected:
	list* tail;
public:
	Queue(list* head = NULL, int data = 0) : List(head, data), tail(head)
	{
	}

	list* getTail()
	{
		return tail;
	}

	int pop_front()
	{
		if (head == NULL)
			//return 1;
			throw 1;
		list* tmp = head;
		head = head->next;
		if (head == NULL)
			current = head;
		free(tmp);
	}

	void push_back(list* elem)
	{
		elem->next = NULL;
		if (head != NULL)
			tail->next = elem;
		else
		{
			head = elem;
			current = head;
		}
		tail = elem;
	}
};

