#include "stdafx.h"
#include "RingList.h"

#include <iostream>	

using namespace std;

int main()
{
	RingList * myRingList = new RingList();
	//myRingList->addNode(7);
	//myRingList->addNode(3);
	//bool test1 = !myRingList;
	myRingList->addNode(1);
	myRingList->addNode(2);
	myRingList->addNode(3);
	//bool test2 = !myRingList;
	//myRingList->deleteNodeByData(3);
	//myRingList->printNodes();	
	myRingList++;
	myRingList->deleteAll();
	myRingList->printNodes();
	//myRingList->getCurrentNode();
	cin.ignore().get();
    return 0;
}

