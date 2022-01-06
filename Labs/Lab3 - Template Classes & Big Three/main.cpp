#include "ABS.h"
#include "ABQ.h"
#include <iostream>
using namespace std;

void ABSTest();
void ABQTest();

int main() {
	/*
	ABS<int> intABS;
	ABS<int> intABS2(20);
	cout << intABS.getSize() << endl;
	cout << intABS.getMaxCapacity() << endl;

	cout << intABS2.getSize() << endl;
	cout << intABS2.getMaxCapacity() << endl;

	ABS<float> fABS;
	ABS<float> fABS2(20);
	cout << fABS.getSize() << endl;
	cout << fABS.getMaxCapacity() << endl;

	cout << fABS2.getSize() << endl;
	cout << fABS2.getMaxCapacity() << endl;
	
	cout << "Copy constructor test" << endl;
	ABS<float> cABS = fABS;
	cout << cABS.getSize() << endl;
	cout << cABS.getMaxCapacity() << endl;

	cout << "Copy assignment operator test" << endl;

	cABS = fABS2;
	cout << cABS.getSize() << endl;
	cout << cABS.getMaxCapacity() << endl;

	cout << "\nPush test" << endl;
	cABS.push(1.5);
	cout << cABS.getSize() << endl;
	cout << cABS.getMaxCapacity() << endl;
	cABS.push(2.5);
	cout << cABS.getSize() << endl;
	cout << cABS.getMaxCapacity() << endl;
	cABS.push(3.5);
	cout << cABS.getSize() << endl;
	cout << cABS.getMaxCapacity() << endl;
	cABS.push(4.5);
	cout << cABS.getSize() << endl;
	cout << cABS.getMaxCapacity() << endl;
	for (int i = 0; i < 4;i++)
		cout << "Entry: " << cABS.getData()[i] << endl << endl;
	*/
	
	int choice;

	cin >> choice;

	if (choice == 1)
		ABSTest();
	else if (choice == 2)
		ABQTest();
	return 0;
}

void ABSTest() {
	cout << "Making integer ABS...\n";
	ABS<int> intABS;
	cout << "Size: " << intABS.getSize() << endl;
	cout << "Max Capacity: " << intABS.getMaxCapacity() << endl;
	cout << "\nPushing items...\n";
	for (int i = 1; i < 10; i++) {
		intABS.push(i);
		cout << "\nPushed " << intABS.peek() << endl;
		cout << "New Size: " << intABS.getSize() << endl;
		cout << "New Max Capacity: " << intABS.getMaxCapacity() << endl;
	}

	cout << "\nPopping items...\n";
	for (int i = 1; i < 10; i++) {
		cout << "\nPopped " << intABS.pop() << endl;
		cout << "New Size: " << intABS.getSize() << endl;
		cout << "New Max Capacity: " << intABS.getMaxCapacity() << endl;
	}


	cout << "\nMaking float ABS...\n";
	ABS<float> floatABS(10);
	cout << "Size: " << floatABS.getSize() << endl;
	cout << "Max Capacity: " << floatABS.getMaxCapacity() << endl;
	cout << "\nPushing items...\n";
	for (float i = 1; i < 5; i += 0.5f) {
		floatABS.push(i);
		cout << "\nPushed " << floatABS.peek() << endl;
		cout << "New Size: " << floatABS.getSize() << endl;
		cout << "New Max Capacity: " << floatABS.getMaxCapacity() << endl;
	}

	cout << "\nPopping items...\n";
	for (float i = 1; i < 5; i += 0.5f) {
		cout << "\nPopped " << floatABS.pop() << endl;
		cout << "New Size: " << floatABS.getSize() << endl;
		cout << "New Max Capacity: " << floatABS.getMaxCapacity() << endl;
	}
}

void ABQTest() {
	cout << "Making integer ABQ...\n";
	ABQ<int> intABQ;
	cout << "Size: " << intABQ.getSize() << endl;
	cout << "Max Capacity: " << intABQ.getMaxCapacity() << endl;
	cout << "\nEnqueueing items...\n";
	for (int i = 1; i < 10; i++) {
		intABQ.enqueue(i);
		cout << "\nEnqueued " << i << endl;
		cout << "New Size: " << intABQ.getSize() << endl;
		cout << "New Max Capacity: " << intABQ.getMaxCapacity() << endl;
	}

	cout << "\nDequeueing items...\n";
	for (int i = 1; i < 10; i++) {
		cout << "\nDequeued " << intABQ.dequeue() << endl;
		cout << "New Size: " << intABQ.getSize() << endl;
		cout << "New Max Capacity: " << intABQ.getMaxCapacity() << endl;
	}


	cout << "\nMaking float ABQ...\n";
	ABQ<float> floatABQ(10);
	cout << "Size: " << floatABQ.getSize() << endl;
	cout << "Max Capacity: " << floatABQ.getMaxCapacity() << endl;
	cout << "\nEnqueueing items...\n";
	for (float i = 1; i < 5; i += 0.5f) {
		floatABQ.enqueue(i);
		cout << "\nEnqueued " << i << endl;
		cout << "New Size: " << floatABQ.getSize() << endl;
		cout << "New Max Capacity: " << floatABQ.getMaxCapacity() << endl;
	}

	cout << "\nDequeueing items...\n";
	for (float i = 1; i < 5; i += 0.5f) {
		cout << "\nDequeued " << floatABQ.dequeue() << endl;
		cout << "New Size: " << floatABQ.getSize() << endl;
		cout << "New Max Capacity: " << floatABQ.getMaxCapacity() << endl;
	}
}
