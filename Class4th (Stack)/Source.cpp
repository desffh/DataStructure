#include <iostream>
#include <stack>

#define SIZE 10                           

using namespace std;

template <typename T>

class Stack
{
private:
    int top;
    T container[SIZE]; //자료형T


public:
    Stack()
    {
        top = -1;
        for (int i = 0; i < SIZE; i++)
        {
            container[i] = 0;
        }
    }

    void Push(T data)
    {
        if (top >= SIZE - 1)
        {
            cout << "스택 오버플로우" << endl;
        }
        else
        {
            container[++top] = data;
        }

    }

    void Pop()
    {
        if (Empty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            top--;
        }
    }

    bool Empty()
    {
        if (top <= -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    T& Top()
    {
        return container[top];
    }

    int& Size()
    {
        return top;
    }

};

bool CheckBracket(std::string content)
{
    if (content.length() <= 0)
    {
        return false;
    }

    Stack<char> stack;

    for (int i = 0; i < content.length(); i++)
    {
        char character = content[i];

        if (character == '(' || character == '{' || character == '[')
        {
            stack.Push(character);
        }
        else if (character == ')' || character == '}' || character == ']')
        {
            char bracket = stack.Top();

            stack.Pop();

            if (bracket == '(' && character != ')')
            {
                return false;
            }
            if (bracket == '{' && character != '}')
            {
                return false;
            }
            if (bracket == '[' && character != ']')
            {
                return false;
            }
        }
    }

    if (stack.Empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{

    Stack<int> stack;

    //stack.Push(10);
    //stack.Push(20);
    //stack.Push(30);
    //stack.Push(40);
    //stack.Push(50);
    //
    //while (stack.Empty() == false)
    //{
    //    cout<< stack.Top() << endl;
    //    stack.Pop();
    //}

    bool flag = CheckBracket("({[]})");

    cout << "flag 변수의 값: " << flag << endl; // 정답이어서 1이 뜸 / 틀리면 0

    return 0;
}