#include "stdafx.h"
#include "RingList.h"

#include <iostream>	

using namespace std;

int main()
{
	RingList myRingList;
	//myRingList->addNode(7);
	//myRingList->addNode(3);
	//bool test1 = !myRingList;
	bool test1 = myRingList.operator!();
	myRingList.addNode(1);
	myRingList.addNode(2);
	myRingList.addNode(3);
	bool test2 = myRingList.operator!();
	//myRingList->deleteNodeByData(3);
	//myRingList->printNodes();	
	myRingList++;
	myRingList.operator++();
	//myRingList->operator++;
	myRingList.deleteAll();
	myRingList.printNodes();
	//myRingList->getCurrentNode();
	cin.ignore().get();
    return 0;
}

