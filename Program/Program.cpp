﻿#include <iostream>
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
	void PopFront()
	{
		if (head != nullptr)
		{
			Node * deleteNode = head;
			head = deleteNode->next;
			delete deleteNode;
			size--;

		}
		else
		{
			cout << "Linked List is Empty" << endl;
		}
		

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

	void PushBack(T data)
	{
		if (head == nullptr)
		{
			head = new Node;
			head->data = data;
			head->next = nullptr;
		}
		else
		{
			Node * currentNode = head;
			
			

			while (currentNode->next != nullptr)
			{
				currentNode = currentNode->next;
			}
			Node * newNode = new Node;
			
			currentNode->next = newNode;
		
			newNode->data = data;
			newNode->next = nullptr;
		}

		size++;
	}

	void PopBack()
	{
		if (head == nullptr)
		{
			cout << "Linked List is Empty" << endl;
		}

		else
		{
			Node * deleteNode = head;
			Node * previousNode = nullptr;
			
			if (size == 1)
			{
				head = deleteNode->next;

				delete deleteNode;
			}
			else
			{
				while (deleteNode->next != nullptr)
				{
					previousNode = deleteNode;
					deleteNode = deleteNode->next;
				}

			}
			previousNode->next = deleteNode->next;

			delete deleteNode;	
		}
		size--;
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

	//singlelinkedlist.PushFront(30);
	//singlelinkedlist.PushFront(20);
	//singlelinkedlist.PushFront(10);

	//singlelinkedlist.PopFront();
	//singlelinkedlist.PopFront();

	singlelinkedlist.PushBack(10);
	singlelinkedlist.PushBack(20);
	singlelinkedlist.PushBack(30);

	singlelinkedlist.PopBack();


	singlelinkedlist.Show();

	return 0;

}
