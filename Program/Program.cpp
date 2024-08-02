#include <iostream>
#define SIZE 26
using namespace std;

class Trie
{
private:
    bool final;
    
    Trie * alphabet[SIZE]; // A~Z 담을 배열

public:
    Trie()
    {
        final = false;

        // 배열 초기화
        for (int i = 0; i < SIZE; i++)
        {
            alphabet[i] = nullptr;
        }
    }
    bool final()
    {

    }

};


int main()
{

    return 0;
}