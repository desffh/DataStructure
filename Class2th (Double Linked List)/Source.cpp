#include <iostream>
using namespace std;

template <typename T>
class DoubleLinkedList
{
private:
	int size;

	struct Node; // 프로토 타입
	//{
	//	T data;
	//	Node * next;
	//	Node * previous;
	//};
	Node* head;
	Node* tail;

public:
	struct Node
	{
		T data;
		Node* next;
		Node* previous;
	};

	DoubleLinkedList()
	{
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	void PushBack(T data)
	{
		Node* newNode = new Node; // 동적할당

		newNode->data = data;
		newNode->next = nullptr; // 초기화
		newNode->previous = nullptr; // 초기화

		if (tail == nullptr) // 하나도 없을때
		{
			tail = newNode;
			head = tail;
		}
		else
		{
			tail->next = newNode;
			newNode->previous = tail;

			tail = newNode;
		}
		size++;
	}

	void PushFront(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;
		newNode->next = nullptr;
		newNode->previous = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
			//tail = head; // 같은 곳 참조(이것도 사용가능)
		}
		else
		{
			//== head->previous = newNode;
			tail->previous = newNode;
			newNode->next = head;

			head = newNode;
		}
		size++;
	}

	void PopFront()
	{
		if (head == nullptr) // 하나도 없는 경우
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node* deleteNode = head;

			if (head == tail) // 하나만 있는 경우
			{
				head = nullptr;
				tail = nullptr;
			}
			else // 여러개 있는 경우
			{
				deleteNode->next->previous = nullptr;
				head = head->next;
			}
			delete deleteNode;

			size--;
		}
	}

	void PopBack()
	{

		if (tail == nullptr) // 아무 데이터도 없다
		{
			cout << "Linked List is Empty" << endl;
		}
		else
		{
			Node* deleteNode = tail;

			if (head == tail)
			{
				head = nullptr;
				tail = nullptr;

				delete deleteNode;
			}
			else
			{
				tail->previous->next = nullptr;
				tail = tail->previous;

				delete deleteNode;
			}
			size--;
		}
	}

	int& Size()
	{
		return size;
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


	Node* Begin()
	{
		return head;
	}

	void InSert(Node* position, T data)
	{

		if (head == nullptr)
		{
			PushBack(data);
		}
		else
		{
			Node* previousNode = position;
			Node* nextNode = position->next;
			Node* newNode = head->next;

			if (nextNode == nullptr)
			{
				PushBack(data);
			}
			else if (previousNode->previous == nullptr)
			{
				PushFront(data);
			}
			else
			{
				Node* newNode = new Node;
				newNode->data = data;

				previousNode->next = newNode;
				nextNode->previous = newNode;

				newNode->next = nullptr;
				newNode->previous = previousNode;
				newNode->next = nextNode;

				size++;
			}
		}

	}
	~DoubleLinkedList()
	{
		while (head != nullptr)
		{
			PopFront();
		}
	}

};

int main()
{
	DoubleLinkedList<int> doubleLinkedList;

	doubleLinkedList.PushBack(10);
	doubleLinkedList.PushBack(20);
	doubleLinkedList.PushBack(30);
	//doubleLinkedList.PopBack();
	//doubleLinkedList.PushFront(50);
	doubleLinkedList.PopFront(); // 젤 앞에꺼 사라짐

	doubleLinkedList.InSert(doubleLinkedList.Begin()->next, 99); // 젤 앞에꺼 사라짐


	cout << "Size: " << doubleLinkedList.Begin()->next << endl;

	doubleLinkedList.Show();


	return 0;

}
