#pragma once
class RingList
{
public:
	RingList();
	~RingList();
	RingList(const RingList& list);

	struct Node {
		int data;
		Node *next;
	};

	Node *getCurrentNode() const {
		return current;
	}

	/*Node *getHead() const {
		return head;
	}

	Node *getCurrentNode() const {
		return current;
	}*/

	void addNode(int data);	
	void deleteNodeByData(int data);
	void deleteAll();
	void printNodes();
	void moveCurrentPointerToHead();
	void moveCurrentPointerToTail();
	bool operator! () const;
	void operator=(RingList const&);
	RingList operator++ (int);
	RingList& operator++ ();
	void sort();
private:
	Node *head;
	Node *tail;
	Node *current;

	void deleteNode(Node *prev, Node *target);
	void deleteHead();
	void copy(RingList const&);
};
