#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;


class String
{
private:
    char * container;
    int size;

public:
    String()
    {
        size = 0;
        container = nullptr;
    }
    void operator = (const char * content)
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

    char& operator [] (int index)
    {
        return container[index];
    }
};



int main()
{   
    //String string;
    //
    //string = "Janna";
    //// null문자 제외한 크기
    //cout << "string의 크기: " << string.Size() << endl;
    //
    //string = "Alista";
    //
    //for (int i = 0; i < string.Size(); i++)
    //{
    //    cout << string[i];
    //}


    String name;

    name = "ab";


    return 0;
}