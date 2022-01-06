#pragma once
#include <iostream>
using namespace std;

template <typename T>
class ABQ
{
	T* data;				
	int capacity;			
	int size;
	float scale_factor;		
public:
	//Contructors
	ABQ();
	ABQ(int capacity_);

	//Big three
	ABQ(const ABQ& d);
	ABQ& operator=(const ABQ& d);
	~ABQ();

	//Fuctions
	void enqueue(T entry);
	T dequeue();
	T peek();
	unsigned int getSize();
	unsigned int getMaxCapacity();
	T* getData();
};

//Constructors
template <typename T>
ABQ<T>::ABQ()
{
	data = new T[1];
	capacity = 1;
	size = 0;
	scale_factor = 2.0f;
}
template <typename T>
ABQ<T>::ABQ(int capacity_)
{
	data = new T[capacity_];
	capacity = capacity_;
	size = 0;
	scale_factor = 2.0f;
}

//Copy Constructor
template <typename T>
ABQ<T>::ABQ(const ABQ& old)
{
	if (data != nullptr)
		delete[] data;
	capacity = old.capacity;
	size = old.size;
	scale_factor = old.scale_factor;
	data = new T[capacity];
	if (size <= capacity)
	{
		for (int i = 0; i < size; i++)
			data[i] = old.data[i];
	}

}
//Assignment Operator
template <typename T>
ABQ<T>& ABQ<T>::operator=(const ABQ& old)
{
	if (data != nullptr)
		delete[] data;
	capacity = old.capacity;
	size = old.size;
	scale_factor = old.scale_factor;
	data = new T[capacity];
	if (size <= capacity)
	{
		for (int i = 0; i < size; i++)
			data[i] = old.data[i];
	}
	return *this;
}

template <typename T>
ABQ<T>::~ABQ()
{
	if (data != nullptr)
	{
		delete[] data;
	}

}

template <typename T>
void ABQ<T>::enqueue(T entry)
{
	//Doesn't need resize, just add it
	if (size < capacity)
	{
		data[size] = entry;

	}
	//Need Resize
	else if (size == capacity)
	{
		this->capacity = static_cast<int>(capacity * scale_factor);
		T* tempArr = new T[capacity];
		if (size <= capacity)
		{
			for (int i = 0; i < size; i++)
				tempArr[i] = data[i];
			tempArr[size] = entry;
		}
		if (data != nullptr)
		{
			delete[] data;
		}
		data = tempArr;
	}
	size += 1; //size gets incremented by 1 no matter what happens
}

//remove the item at the top of the stack, resize if necessary, return the value removed
//throw runtime_error if stack is empty
template <typename T>
T ABQ<T>::dequeue()
{
	T item;
	if (size == 0)
		throw runtime_error("Error: Cannot pop from an empty stack.");
	else
	{
		item = data[0];
		size -= 1;
		T* tempArr = new T[capacity];
		if (size <= capacity)
		{
			for (int i = 0; i < size; i++)
				tempArr[i] = data[i + 1];
		}
		if (data != nullptr)
		{
			delete[] data;
		}
		data = tempArr;
	}

	if ((static_cast<float>(size) / capacity) < (1 / scale_factor))
	{
		this->capacity = static_cast<int>((1 / scale_factor) * capacity);
		T* tempArr = new T[capacity];
		if (size <= capacity)
		{
			for (int i = 0; i < size; i++)
				tempArr[i] = data[i];
		}
		if (data != nullptr)
		{
			delete[] data;
		}
		data = tempArr;
	}
	return item;
}

template <typename T>
T ABQ<T>::peek()
{
	T item;
	if (size == 0)
	{
		throw runtime_error("Error: No entries in an empty stack to peek at.");
	}
	else
	{
		item = data[0];
	}
	return item;
}

template <typename T>
unsigned int ABQ<T>::getSize()
{
	return size;
}

template <typename T>
unsigned int ABQ<T>::getMaxCapacity()
{
	return capacity;
}

template <typename T>
T* ABQ<T>::getData()
{
	return data;
}
