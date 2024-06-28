#include <iostream>
#define SIZE 8
using namespace std;

template <typename T>
class Heap
{
private:

    int index;

    T Container[SIZE];

public:
    Heap()
    {
        for (int i = 0; i < SIZE; i++)
        {
            Container[i] = NULL;
        }

        index = 0;
    }
    void Insert(T data)
    {
        if (index >= SIZE)
        {
            cout << "Heap Overflow" << endl;
        }
        else
        {
            Container[++index] = data;

            int child = index;
            int parent = child / 2;

            while (child > 1)
            {
                if (Container[parent] < Container[child])
                {
                    std::swap(Container[parent], Container[child]);
                }

                child = parent;

                parent = child / 2;
            }
        }
    }

    T Remove()
    {
        if (index <= 0)
        {
            cout << "Heap is Empty" << endl;

            exit(1);
        }
        else
        {
            //임시변수에 1번째 데이터 저장
            T result = Container[1];

            Container[1] = Container[index];

            Container[index] = NULL;

            index--;


            int parent = 1;

            while (parent * 2 <= index)
            {
                int child = parent * 2;

                if (Container[child] > Container[child + 1])
                {
                    child++;
                }

                if (Container[child] < Container[parent])
                {
                    break;
                }
                else
                {
                    std::swap(Container[parent], Container[child]);
                    parent = child;
                }
            }
            return result;
        }
    }

    void Show()
    {
        for (int i = 1; i <= index; i++) //index 0 사용안하기 때문
        {
            cout << Container[i] << " ";
        }
    }
};


int main()
{
    Heap<int> heap;

    heap.Insert(6);
    heap.Insert(7);
    heap.Insert(2);
    heap.Insert(10);

    cout << "Heap의 최대값: " << heap.Remove() << endl;

    heap.Show();

    return 0;
}