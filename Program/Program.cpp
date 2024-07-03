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
    
    void Remove(T data)
    {

        if (root == nullptr)
        {
            cout << "Binary Search Tree is Empty" << endl;
        }
        else
        {
            Node* parentNode = nullptr;
            Node* currentNode = root;
            
            while (currentNode != nullptr && currentNode->data != data)
            {
                if (data < currentNode->data)
                {
                    parentNode = currentNode;
                    currentNode = currentNode->left;

                }
                else
                {
                    parentNode = currentNode;
                    currentNode = currentNode->right;
                }
            }
            if (currentNode == nullptr)
            {
                cout << "Data Not Found in the Binary Search Tree" << endl;
            }
            //자식이 없을때
            else if (currentNode->left == nullptr && currentNode->right == nullptr)
            {
                if (parentNode != nullptr)
                {
                    if (parentNode->left == currentNode)
                    {
                        parentNode->left = nullptr;
                    }
                    else
                    {
                        parentNode->right = nullptr;
                    }
                }
                else
                {
                    root = nullptr;
                }

            }
            //자식이 하나일때
            else if (currentNode->left == nullptr || currentNode->right == nullptr)
            {
                Node* childNode = nullptr;
                
                if (currentNode->left != nullptr)
                {
                    childNode = currentNode->left;
                }
                else
                {
                    childNode = currentNode->right;
                }

                if (parentNode != nullptr)
                {
                    if (parentNode->left == currentNode)
                    {
                        parentNode->left = childNode;
                    }
                    else
                    {
                        parentNode->right = childNode;
                    }
                }
                 
            }
            else
            {
                Node* childNode = currentNode->right;
                Node* traceNode = childNode;

                while (childNode->left != nullptr)
                {
                    traceNode = childNode;
                    childNode = childNode->left;
                }
                currentNode->data = childNode->data;

                traceNode->left = childNode->right;

                delete childNode;

                return;
            }
            delete currentNode;
        }
    }

};




int main()
{
    BinarySearchTree<int> binarysearchtree;

    binarysearchtree.Insert(10);
    binarysearchtree.Insert(7);
    binarysearchtree.Insert(15);
    binarysearchtree.Insert(5);
    binarysearchtree.Insert(3);


    cout << binarysearchtree.Find(5) << endl;
    cout << binarysearchtree.Find(0) << endl;
    
    
    binarysearchtree.Remove(5); // 없는값을 찾아봄
    binarysearchtree.Remove(7); // 없는값을 찾아봄

    binarysearchtree.Inorder(binarysearchtree.Root());
    //cout << endl;

    return 0;
}