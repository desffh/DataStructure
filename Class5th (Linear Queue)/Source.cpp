#include <iostream>
#include <queue>

#define SIZE 5                         

using namespace std;

template <typename T>

class LinearQueue
{
private:
    int rear;
    int front;
    int size;

    // 배열 선언
    T container[SIZE];

public:
    LinearQueue() // 생성자에 변수 초기화
    {
        rear = 0;
        front = 0;
        size = 0;

        for (int i = 0; i < SIZE; i++) // 배열안의 데이터 null로 초기화
        {
            container[i] = NULL;
        }
    }

    bool Empty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Push(T data)
    {
        if (rear >= SIZE)
        {
            cout << "Queue Overflow" << endl;

        }
        else
        {
            container[rear++] = data; // 후위증가

            size++;
        }
    }

    void Pop()
    {
        if (Empty())
        {
            cout << "Linear Queue is Empty " << endl;
        }
        else
        {
            container[front++] = NULL;

            size--;

        }
    }

    T& Front()
    {
        if (Empty()) // 값이없다
        {
            exit(1); // 강제종료
        }
        else
        {
            return container[front];
        }
    }
    T& Back()
    {
        if (Empty()) // 값이없다
        {
            exit(1); // 강제종료
        }
        else
        {
            return container[rear - 1];
        }
    }
    int& Size()
    {
        return size;
    }
};



int main()
{
    LinearQueue<int> linearqueue;

    // 사이즈는 5
    linearqueue.Push(10);
    linearqueue.Push(20);
    linearqueue.Push(30);
    linearqueue.Push(40);
    linearqueue.Push(50);

    //cout << linearqueue.Back() << endl;; //가장 뒤에 꺼 50

    while (linearqueue.Empty() == false) //비지 않았다면 실행
    {
        cout << linearqueue.Front() << endl;

        linearqueue.Pop();
    }
    // Empty상태(rear == front)로 Push 한번 더 했는데 over Queue가 뜸 (문제점!!)
    linearqueue.Push(99);




    return 0;
}