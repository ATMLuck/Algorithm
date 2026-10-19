#include <iostream>
using namespace std;
struct Node
{
    int value;
    int cnt = 1;
    Node *Lchild = nullptr;
    Node *Rchild = nullptr;
    Node *parent = nullptr;
    Node(int key):value(key){}
    
};
class BST 
{
private:
    Node* _root = nullptr;
    Node* RecursionInsert(Node *vir, int key)
    {
        if(vir==nullptr)
        {
            Node *tmp = new Node(key);
            return tmp;
        }
        else 
        {
            if(key<vir->value) 
            {
                vir->Lchild = RecursionInsert(vir->Lchild, key);
                vir->Lchild->parent = vir;
            }
            else if(key>vir->value)
            {
                vir->Rchild = RecursionInsert(vir->Rchild, key);
                vir->Rchild->parent = vir;
            }
            else 
            {
                vir->cnt++;   
            }
            return vir;
        }
    }
    void Distroy(Node* vir)
    {
        if(vir->Lchild!=nullptr)
            Distroy(vir->Lchild);
        if(vir->Rchild!=nullptr)
            Distroy(vir->Rchild);
        if(vir->parent!=nullptr)
        {
            if(vir->parent->Lchild==vir) 
                vir->parent->Lchild = nullptr;
            else
                vir->parent->Rchild = nullptr;
        } 
        delete vir;
    }
    void RecursionErase(Node *vir)
    {
        if(vir->Lchild==nullptr&&vir->Rchild==nullptr)
        {
            Distroy(vir);
        }
        else if(vir->Rchild==nullptr)
        {
            vir->Lchild->parent = vir->parent;
            if(vir->parent->Rchild==vir) vir->parent->Rchild = vir->Lchild;
            else vir->parent->Lchild = vir->Lchild;
            vir->Lchild = nullptr;
            Distroy(vir);
        }
        else if(vir->Lchild==nullptr)
        {
            vir->Rchild->parent = vir->parent;
            if(vir->parent->Rchild==vir) vir->parent->Rchild = vir->Rchild;
            else vir->parent->Lchild = vir->Rchild;
            vir->Rchild = nullptr;
            Distroy(vir);
        }
    }
public:
    void Insert(int key)
    {
        _root = RecursionInsert(_root, key);
    }
    void Erase(int key)
    {
        Node *vir = _root;
        while(vir!=nullptr)
        {
            if(vir->value<key)
                vir = vir->Rchild;
            else if(vir->value>key)
                vir = vir->Lchild;
            else
                break;
        }
        if(vir == nullptr) {cerr << key << " Not Found" << endl;return;}
        
        if(vir->Lchild!=nullptr&&vir->Rchild!=nullptr)
        {
            Node *UpperBound = vir->Rchild;
            while(UpperBound->Lchild!=nullptr) UpperBound = UpperBound->Lchild;
            vir->value = UpperBound->value;
            RecursionErase(UpperBound);
        }
        else
        {
            RecursionErase(vir);
        }
        

    }

};