#pragma once
#include <iostream>
#include<vector>
#include <stdexcept>
using namespace std;

template <typename T>
class LinkedList
{
public:
	struct Node
	{
		T data;
		Node* next;
		Node* prev;
	};
	
	//Behaviors
	void PrintForward() const;
	void PrintReverse() const;
	void PrintForwardRecursive(const Node* node) const;
	void PrintReverseRecursive(const Node* node) const;
	
	//Accessors
	unsigned int NodeCount() const;
	void FindAll(vector<Node*>& outData, const T& value) const;
	const Node* Find(const T& data) const;
	Node* Find(const T& data);
	const Node* GetNode(unsigned int index) const;
	Node* GetNode(unsigned int index);
	Node* Head();
	const Node* Head() const;
	Node* Tail();
	const Node* Tail() const;

	//Insertions
	void AddHead(const T& data);
	void AddTail(const T& data);
	void AddNodesHead(const T* data, unsigned int count);
	void AddNodesTail(const T* data, unsigned int count);
	void InsertAfter(Node* node, const T& data);
	void InsertBefore(Node* node, const T& data);
	void InsertAt(const T& data, unsigned int index);

	//Removals
	bool RemoveHead();
	bool RemoveTail();
	unsigned int Remove(const T& data);
	bool RemoveAt(int index);
	void Clear();

	//Operators
	const T &operator[](unsigned int index) const;
	T& operator[](unsigned int index);
	bool operator==(const LinkedList<T>& rhs) const;
	LinkedList<T>& operator=(const LinkedList<T>& rhs);

	//Construction/Destruction
	LinkedList();
	LinkedList(const LinkedList<T>& list);
	~LinkedList();

private:
	Node* head;
	Node* tail;
	unsigned int nodeNum;
};


//Constructors/Destructors
template <typename T>
LinkedList<T>::LinkedList()		
{
	nodeNum = 0;
	head = nullptr;
	tail = nullptr;
}
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) //copy constructor		issue
{
	nodeNum = list.nodeNum;
	Node* current = list.head;
	while (current != nullptr) 
	{
		Node* temp = new Node;
		if (current == list.head)
		{
			temp->data = current->data;
			temp->next = nullptr;
			temp->prev = nullptr;
			current = current->next;
			head = temp;
			tail = temp;

		}
		else
		{
			temp->data = current->data;
			tail->next = temp;
			temp->next = nullptr;
			temp->prev = tail;
			current = current->next;
			tail = temp;
		}
	}
}
template <typename T>
LinkedList<T>::~LinkedList()
{
	Node* current = head;
	while (current != nullptr)
	{
		current = current->next;
		delete head;
		head = current;
	}
}


//Operators
template <typename T>
const T& LinkedList<T>::operator[](unsigned int index) const
{
	return (this->GetNode(index)->data);
}
template <typename T>
T& LinkedList<T>::operator[](unsigned int index)
{
	return (this->GetNode(index)->data);
}
template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const	//issue
{
	bool condition = true;
	if (nodeNum == rhs.nodeNum)
	{
		for (unsigned int i = 0; i < nodeNum; i++)	
		{
			if ((this->GetNode(i)->data) != rhs[i])
			{
				condition = false;
				break;
			}
		}
	}
	else
	{
		condition = false;
	}
	return condition;
}
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) //issue
{
	nodeNum = rhs.nodeNum;
	Node* current = rhs.head;
	while (current != nullptr)
	{
		Node* temp = new Node;
		if (current == rhs.head)
		{
			temp->data = current->data;
			temp->next = nullptr;
			temp->prev = nullptr;
			current = current->next;
			head = temp;
			tail = temp;

		}
		else
		{
			temp->data = current->data;
			tail->next = temp;
			temp->next = nullptr;
			temp->prev = tail;
			current = current->next;
			tail = temp;
		}
	}
	return *this;
}

//Accessors
template <typename T>
unsigned int LinkedList<T>::NodeCount() const
{
	return nodeNum;
}
template <typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const
{
	Node* curr = head;
	while (curr != nullptr)
	{
		if (curr->data == value)
			outData.push_back(curr);
		curr = curr->next;
	}
}
template <typename T>
 const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const
{
	 Node* curr = head;
	 Node* ptr = nullptr;
	 while (curr != nullptr)	
	 {
		 if (*(curr->data) == data)
		 {
			 ptr = curr;
			 break;
		 }
		 curr = curr->next;
	 }
	 return ptr;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data)
{
	Node* curr = head;
	Node* ptr = nullptr;
	while (curr != nullptr)	
	{
		if (curr->data == data)
		{
			ptr = curr;
			break;
		}
		curr = curr->next;
	}
	return ptr;
}
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const
{
	if (index <= (nodeNum - 1))
	{
		unsigned int currIndex = 0;
		Node* currNode = head;
		while (currIndex != index)
		{
			currNode = currNode->next;
			currIndex++;
		}
		return currNode;
	}
	else
	{
		throw runtime_error("Cannot call GetNote(unsigned int index) because of an invalid index.");
	}
}
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index)
{
	if (index <= (nodeNum - 1))
	{
		unsigned int currIndex = 0;
		Node* currNode = head;
		while (currIndex != index)
		{
			currNode = currNode->next;
			currIndex++;
		}
		return currNode;
	}
	else
	{
		throw runtime_error("Cannot call GetNote(unsigned int index) because of an invalid index.");
	}
}
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head()
{
	return head;
}
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const
{
	return head;
}
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail()
{
	return tail;
}
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const
{
	return tail;
}

//Insertions
template <typename T>
void LinkedList<T>::AddHead(const T& data)
{
	Node* temp = new Node;
	temp->data = data;
	if (head == nullptr)
	{
		temp->prev = nullptr;
		temp->next = nullptr;
		this->head = temp;
		this->tail = temp;
	}
	else
	{
		head->prev = temp;
		temp->prev = nullptr;
		temp->next = head;
		this->head = temp;
	}
	nodeNum++;
}
template <typename T>
void LinkedList<T>::AddTail(const T& data)
{
	Node* temp = new Node;
	temp->data = data;
	if (tail == nullptr)
	{
		temp->prev = nullptr;
		temp->next = nullptr;
		this->head = temp;
		this->tail = temp;
	}
	else
	{
		tail->next = temp;
		temp->next = nullptr;
		temp->prev = tail;
		this->tail = temp;
	}
	nodeNum++;
}
template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count)
{
	unsigned int index = 0;
	for (unsigned int i = 1; i <= count; i++)
	{
		index = count - i;
		this->AddHead(data[index]);
	}
}
template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count)
{
	for (unsigned int i = 0; i < count; i++)
	{
		this->AddTail(data[i]);
	}
}
template <typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data)
{
	if (node == this->Tail())
	{
		this->AddTail(data);
	}
	else
	{
		Node* nodeToAdd = new Node;
		nodeToAdd->data = data;
		Node* oldNextNode = node->next;
		node->next = nodeToAdd;
		nodeToAdd->prev = node;
		oldNextNode->prev = nodeToAdd;
		nodeToAdd->next = oldNextNode;
		nodeNum++;
	}
}
template <typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data)
{
	if (node == this->Head())
	{
		this->AddHead(data);
	}
	else
	{
		Node* nodeToAdd = new Node;
		nodeToAdd->data = data;
		Node* oldPrevNode = node->prev;
		node->prev = nodeToAdd;
		nodeToAdd->next = node;
		oldPrevNode->next = nodeToAdd;
		nodeToAdd->prev = oldPrevNode;
		nodeNum++;
	}
}
template <typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index)
{
	if (index > nodeNum)
	{
		throw runtime_error("Invalid index passed to InsertAt(const T& data, unsigned int index).");
	}
	else
	{
		if (index == 0)
		{
			this->AddHead(data);
		}
		else if (index == nodeNum)
		{
			this->AddTail(data);
		}
		else
		{
			Node* nodeToAdd = new Node;
			nodeToAdd->data = data;
			Node* prevNode = this->GetNode(index - 1);
			Node* nextNode = this->GetNode(index);
			//affix to previous
			prevNode->next = nodeToAdd;
			nodeToAdd->prev = prevNode;
			//affix to next
			nextNode->prev = nodeToAdd;
			nodeToAdd->next = nextNode;
			nodeNum++;
		}
	}
}

//Removals
template <typename T>
bool LinkedList<T>::RemoveHead()
{
	Node* current = head;
	if (current != nullptr)	
	{
		current = current->next;
		delete head;
		head = current;
		if (head != nullptr)
		{
			head->prev = nullptr;
		}
		else
		{
			tail = nullptr;	
		}
		nodeNum--;
		return true;
	}
	else
	{
		return false;
	}
}
template <typename T>
bool LinkedList<T>::RemoveTail()
{
	Node* current = tail;
	if (current != nullptr)		
	{
		current = current->prev;
		delete tail;
		tail = current;
		if (tail != nullptr)
		{
			tail->next = nullptr;
		}
		else					
		{
			head = nullptr;
		}
		nodeNum--;
		return true;
	}
	else
	{
		return false;
	}
}
template <typename T>
unsigned int LinkedList<T>::Remove(const T& data)
{
	vector<Node*> toBeDeleted;
	this->FindAll(toBeDeleted, data);
	for (unsigned int i = 0; i < toBeDeleted.size(); i++)
	{
		toBeDeleted[i]->prev->next = toBeDeleted[i]->next;
		toBeDeleted[i]->next->prev = toBeDeleted[i]->prev;
		delete toBeDeleted[i];
		nodeNum--;
	}
	return toBeDeleted.size();
}
template <typename T>
bool LinkedList<T>::RemoveAt(int index)
{
	try
	{
		Node* toBeDeleted = this->GetNode(index);
		toBeDeleted->prev->next = toBeDeleted->next;
		toBeDeleted->next->prev = toBeDeleted->prev;
		delete toBeDeleted;
		nodeNum--;
		return true;
	}
	catch (runtime_error)
	{
		return false;
	}
}
template <typename T>
void LinkedList<T>::Clear()
{
	Node* current = head;
	while (current != nullptr)
	{
		current = current->next;
		delete head;
		head = current;
	}
	head = nullptr;
	tail = nullptr;;
	nodeNum = 0;
}

//Behaviors
template <typename T>
void LinkedList<T>::PrintForward() const
{
	if (nodeNum > 0)
	{
		Node* current = head;
		while (current != nullptr)
		{
			cout << current->data << endl;
			current = current->next;
		}
	}
	else
	{
		cout << "The list is empty." << endl;
	}
}
template <typename T>
void LinkedList<T>::PrintReverse() const
{
	if (nodeNum > 0)
	{
		Node* current = tail;
		while (current != nullptr)
		{
			cout << current->data << endl;
			current = current->prev;
		}
	}
	else
	{
		cout << "The list is empty." << endl;
	}
}
template <typename T>
void LinkedList<T>::PrintForwardRecursive(const Node* node) const
{
	if (node == nullptr)
	{
		return;
	}
	else
	{
		cout << node->data << endl;
		PrintForwardRecursive(node->next);
	}
}
template <typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const
{
	if (node == nullptr)
	{
		return;
	}
	else
	{
		cout << node->data << endl;
		PrintReverseRecursive(node->prev);
	}
}