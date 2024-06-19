#include <iostream>
#include <queue>

#define SIZE 5                         

using namespace std;

template <typename T>

class CircleQueue
{
private:
    int rear;
    int front;
    int size;

    // 배열 선언
    T container[SIZE];

public:
    CircleQueue() // 생성자에 변수 초기화
    {
        rear = SIZE - 1;
        front = SIZE - 1;
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
        if (front == (rear + 1) % SIZE)
        {
            cout << "CircleQueue Overflow" << endl;
        }
        else
        {
            rear = (rear + 1) % SIZE;
            container[rear] = data;

            size++;
        }
    }
    void Pop()
    {
        if (Empty())
        {
            cout << "CircleQueue is Empty" << endl;
        }
        else
        {
            front = (front + 1) % SIZE;
            container[front] = NULL;

            size--;
        }
    }
    T& Front()
    {
        return container[(front + 1) % SIZE];
    }

    T& Back()
    {
        return container[(rear + 1) % SIZE];
    }

    int& Size()
    {
        return size;
    }


};

int main()
{
    CircleQueue<char> circlequeue;

    circlequeue.Push('A');
    circlequeue.Push('B');
    circlequeue.Push('C');
    circlequeue.Push('D');
    //circlequeue.Push('E'); // 선형큐는 한칸 비워놔야함


    while (circlequeue.Empty() == false) //비지 않았다면 실행
    {
        cout << circlequeue.Front() << endl;
        circlequeue.Pop();
    }
    // pop으로 다 비워둔 상태에서 push

    circlequeue.Push('E');
    circlequeue.Push('F'); // 원형큐는 가능

    while (circlequeue.Empty() == false)
    {
        cout << circlequeue.Front() << endl;
        circlequeue.Pop();
    }


    return 0;
}