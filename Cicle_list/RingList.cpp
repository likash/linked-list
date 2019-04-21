#include "stdafx.h"
#include "RingList.h"
#include <iostream>

using namespace std;

RingList::RingList()
{
	head = nullptr;
	tail = nullptr;
	current = nullptr;
}


RingList::~RingList()
{
	while (head != nullptr)
	{
		Node *temp = head->next;
		delete head;
		head = temp;
	}
	current = nullptr;
	tail = nullptr;
}

void RingList::addNode(int data) {
	if (head == nullptr) {
		head = new Node;
		head->data = data;
		head->next = head;
		current = head;
		tail = head;
	}
	else {
		Node *temp = head;
		while (temp->next != head) {
			temp = temp->next;
		}
		temp->next = new Node;
		temp->next->data = data;
		temp->next->next = head;
		current = temp->next;
		tail = temp->next;
	}
}

void RingList::deleteHead() {
	Node *temp = head;
	if (head == tail) {
		tail = nullptr;
		head = nullptr;
	}
	else {
		head = head->next;
		tail->next = head;
	}
	delete temp;
	current = head;
}

void RingList::deleteNode(Node *prev, Node *target) {
	if (target == head) {
		deleteHead();
	} else {
		Node *temp;
		temp = target;
		prev->next = target->next;
		if (target == tail) {
			tail = prev;
		}
		delete temp;		
		current = head;
	}
}

void RingList::deleteNodeByData(int data) {
	if (head == nullptr) {
		return;
	}

	Node *temp = tail;
	do {	
		if (temp->next->data == data) {
			deleteNode(temp, temp->next); 
		}
		temp = temp->next;
	} while (temp->next != head);

	if (head->data == data) {
		deleteHead();
	}
}

void RingList::deleteAll() {
	if (head == nullptr) {
		return;
	}

	Node *temp = tail;
	do {
		deleteNode(temp, temp->next);
		temp = temp->next;
	} while (temp->next != head);
	
	deleteHead();	
}

void RingList::printNodes() {
	Node *temp = head;
	if (head == nullptr) {
		cout << "No data";
		return;
	}

	do {
		cout << temp->data;
		temp = temp->next;
	} while (temp != tail);
}

void RingList::moveCurrentPointerToHead()
{
	this->current = this->head;
}

void RingList::moveCurrentPointerToTail()
{
	this->current = this->tail;
}

bool RingList::operator!() const
{
	return this->head != nullptr;
}

RingList& RingList::operator++()
{
	this->current = this->current->next;
	return *this;
}
