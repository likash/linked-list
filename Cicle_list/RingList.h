#pragma once
class RingList
{
public:
	RingList();
	~RingList();

	struct Node {
		int data;
		Node *next;
	};

	Node *getCurrentNode() const {
		return current;
	}

	void addNode(int data);	
	void deleteNodeByData(int data);
	void deleteAll();
	void printNodes();
	void moveCurrentPointerToHead();
	void moveCurrentPointerToTail();
	bool operator! () const;
	RingList operator++ (int);
	RingList& operator++ ();
	void sort();
private:
	Node *head;
	Node *tail;
	Node *current;

	void deleteNode(Node *prev, Node *target);
	void deleteHead();
};
