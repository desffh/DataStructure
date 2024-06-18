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
        rear = SIZE-1;
        front = SIZE-1;
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
        if (rear > SIZE)
        {
            rear = SIZE % rear;
            container[rear] = data;

            size++;
        }
    }
    void Pop()
    {
        if (front > SIZE)
        {
            front = SIZE % front; 
            container[front] = NULL;

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
    CircleQueue<int> circlequeue;

    circlequeue.Push(10);
    circlequeue.Push(20);
    circlequeue.Push(30);
    circlequeue.Push(40);

    while (circlequeue.Empty() == false) //비지 않았다면 실행
    {
        cout << circlequeue.Front() << endl;

    }


    return 0;
}