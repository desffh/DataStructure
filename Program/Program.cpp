#include <iostream>
#define SIZE 26
using namespace std;
// 문자열 트라이 자료구죠
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
    // 문자 삽입
    void Insert(const char* content)
    {
        if (*content == '\0')
        {
            final = true;
        }
        else
        {
            int index = 0;

            if ('A' <= *content && 'Z' >= *content)
            {
                index = *content - 'A';
            }
            else if ('a' <= *content && 'z' >= *content)
            {
                int index = *content - 'a';
            }
            if (alphabet[index] == nullptr)
            {
                alphabet[index] = new Trie();
            }
            alphabet[index]->Insert(content + 1); // +1하면 다음위치로 이동
        }

    }

    bool Find(const char* content)
    {
        if (*content == NULL)
        {
            if (final == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            int index = 0;

            if ('A' <= *content && 'Z' >= *content)
            {
                index = *content - 'A';
            }
            else if ('a' <= *content && 'z' >= *content)
            {
                int index = *content - 'a';
            }
            if (alphabet[index] == nullptr)
            {
                return false;
            }
            else
            {
                return alphabet[index]->Find(content + 1);
            }
        }
    }

    ~Trie()
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (alphabet[i] != nullptr)
            {
                delete alphabet[i];
            }
        }
    }
};


int main()
{
    Trie trie;

    trie.Insert("HELLO");
    trie.Insert("APPLE");
    trie.Insert("Health");
    trie.Insert("GAME");

    cout <<trie.Find("HELLO") << endl;
    cout << trie.Find("League") << endl;
    cout << trie.Find("APPLE") << endl;
    cout << trie.Find("Health") << endl; // 1 0 1 1  

    return 0;
}