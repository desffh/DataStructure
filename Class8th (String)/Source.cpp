#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;


class String
{
private:
    char* container;
    int size;

public:
    String()
    {
        size = 0;
        container = nullptr;
    }
    void operator = (const char* content)
    {
        int arraySize = strlen(content) + 1;
        size = strlen(content);

        if (container == nullptr)
        {
            container = new char[arraySize];

            for (int i = 0; i < arraySize; i++)
            {
                container[i] = content[i];
            }

        }
        else
        {
            char* newcontainer = new char[arraySize];

            for (int i = 0; i < arraySize; i++)
            {
                newcontainer[i] = content[i];
            }
            delete container;

            container = newcontainer;
        }

    }
    int& Size()
    {
        return size;
    }

    int Compare(const char* content)
    {
        int count = 0;

        for (int i = 0; i < strlen(content); i++)
        {
            if (container[i] != content[i])
            {
                break;
            }
            else
            {
                count++;
            }
        }
        if (strlen(content) == count)
        {
            return 0;
        }

        int classString = 0;
        int otherString = 0;

        for (int i = 0; i < strlen(container); i++)
        {
            classString += container[i];
        }
        for (int i = 0; i < strlen(content); i++)
        {
            otherString += content[i];
        }
        if (classString > otherString)
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    void Append(const char* content)
    {
        int newSize = strlen(container) + strlen(content);

        char* newContainer = new char[newSize]; // 새로운 배열 만들기

        // 새로운 배열에 기존꺼 넣어주기
        for (int i = 0; i < strlen(container); i++)
        {
            newContainer[i] = container[i];
        }
        // 추가된 문자열 넣기. 추가된 문자열 만큼만 반복
        for (int i = 0; i < strlen(content); i++)
        {
            newContainer[strlen(container) + i] = content[i];
        }
        size = newSize;

        delete[] container;

        container = newContainer;
    }


    char& operator [] (int index)
    {
        return container[index];
    }

    ~String()
    {
        if (container != nullptr)
        {
            delete[] container;
        }
    }
};



int main()
{
    String string;

    string = "Janna";
    // null문자 제외한 크기
    cout << "string의 크기: " << string.Size() << endl;

    string = "Alista";

    cout << string.Compare("Alistar") << endl;

    string.Append("Ko");

    for (int i = 0; i < string.Size(); i++)
    {
        cout << string[i];
    }




    return 0;
}