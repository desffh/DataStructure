#include <iostream>
using namespace std;

template <typename T>

class BinarySearchTree
{
private:
    struct Node
    {
        T data;
        Node* left;
        Node* right;
    };
    
    Node * root;

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    Node * Root()
    {
        return root;
    }

    // 노드생성
    Node* CreateNode(T data)
    {
        Node* newNode = new Node;
        newNode->data = data; 
        newNode->left = nullptr;
        newNode->right = nullptr;

        return newNode;
    }
    
    void Insert(T data)
    {
        if (root == nullptr) //노드가 하나도없으면
        {
            root = CreateNode(data);
        }
        else //노드가 여러개 있다면
        {
            Node * currentNode = root;

            while (currentNode != nullptr)
            {
                if (currentNode->data < data)
                {   
                    if (currentNode->right == nullptr)
                    {
                        currentNode->right = CreateNode(data);
                        break;
                    }
                    else
                    {
                        currentNode = currentNode->left;
                    }

                }
                else if(currentNode->data > data)
                {
                    if (currentNode->left == nullptr)
                    {
                        currentNode->left = CreateNode(data);
                        break;
                    }
                    else
                    {
                        currentNode = currentNode->left;
                    }
                }
                else
                {
                    return;
                }
            }
        }
    }

    bool Find(T data)
    {
        Node * currentNode = root;

        if (currentNode == nullptr)
        {
            return false;
        }
        else
        {
            if (currentNode->data == data)
            {
                return true;
            }
            else
            {
                if (currentNode->data > data)
                {
                    currentNode = currentNode->left;
                }
                else
                {
                    currentNode = currentNode->right;
                }
            }
        }
        return false;
    }

    void Destroy(Node * root)
    {
        if (root != nullptr)
        {
            Destroy(root->left);
            Destroy(root->right);
            delete root;
        }
    }


    // 중위순회 출력
    void Inorder(Node* root)
    {
        if (root != nullptr)
        {
            Inorder(root->left);
            cout << root->data << " ";
            Inorder(root->right);
        }
    }

    ~BinarySearchTree()
    {
        Destroy(root);
    }

};




int main()
{
    BinarySearchTree<int> binarysearchtree;

    binarysearchtree.Insert(10);
    binarysearchtree.Insert(7);
    binarysearchtree.Insert(15);
    binarysearchtree.Insert(5);


    binarysearchtree.Inorder(binarysearchtree.Root());


    cout << binarysearchtree.Find(7) << endl;

    return 0;
}