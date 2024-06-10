#include <iostream>
using namespace std;


template <typename T>
class SingleLinkedList
{
private:
	int size;

	struct Node
	{
		T data;
		Node* next;
	};

	Node* head;

public:
	SingleLinkedList()
	{
		size = 0;
		head = nullptr;

	}
	void PushFront(T data)
	{
		if (head == nullptr)
		{
			head = new Node; //동적할당
			head->data = data; //매개변수 넣어주기
			head->next = nullptr;
		}
		else
		{
			Node* newNode = new Node;
			newNode->data = data;
			newNode->next = head;

			head = newNode;
		}

		size++;
	}
	void Show()
	{
		Node* currentNode = head;


		while (currentNode != nullptr)
		{
			cout << currentNode->data << endl;
			currentNode = currentNode->next;
		}
	}


};


int main()
{
	SingleLinkedList<int> singlelinkedlist;
}
