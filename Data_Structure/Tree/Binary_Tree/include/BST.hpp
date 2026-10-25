#pragma once
#include <new>
#include <iostream>
namespace BST
{    
    struct Node
    {
        int data;
        int cnt;
        Node *Lchild;
        Node *Rchild;
        Node *Parent;
        Node()
        {
            data = 0;
            cnt = 0;
            Lchild = nullptr;
            Rchild = nullptr;
            Parent = nullptr;
        }
        Node(int _data)
        {
            Node();
            data = _data;
            cnt = 1;
        }
    };
    class BST
    {
    public:
        BST()
        {
            root = nullptr;
            size = 0;
        }
        ~BST()
        {
            Destroy(root);
        }
        BST(const BST& target)
        {

        }
        BST& operator=(const BST&) = delete;
        Node* GetRoot(){return root;}
        unsigned long long Size()
        {
            return size;
        }
        bool Insert(int _data)
        {
            if(insert(_data,root))
            {
                size++;
                return true;
            }
            else
            {
                std::cerr << "Space application failed!" << std::endl;
                return false;
            }
        }
        Node* Find(int _data)
        {
            return find(_data,root);
        }
        
    private:
        Node* root;
        unsigned long long size;

        void Destroy(Node* _vir)
        {
            if(_vir->Lchild!=nullptr) Destroy(_vir->Lchild);
            if(_vir->Rchild!=nullptr) Destroy(_vir->Rchild);
            delete _vir;
        }
        bool copy(Node* &self,Node* target,Node* parent = nullptr)
        {
            self = new Node(target->data);
            self->cnt = target->cnt;
            self->Parent = parent;
            bool iscopy = true;
            if(target->Lchild!=nullptr) 
            {
                copy(self->Lchild,target->Lchild,self);
                
            }
            if(target->Rchild!=nullptr) 
            {
                copy(self->Rchild,target->Rchild,self);
            }
            return iscopy;
        }
        bool insert(const int _data,Node* &_vir,Node* _parent = nullptr)
        {
            if(_vir == nullptr)
            {
                try
                {
                    _vir = new Node(_data);
                    _vir->Parent = _parent;
                    return true;
                }
                catch(const std::bad_alloc& e)
                {
                    return false;
                }
            }
            if(_data<_vir->data)
            {
                return insert(_data,_vir->Lchild,_vir);
            }
            else if(_data>_vir->data)
            {
                return insert(_data,_vir->Rchild,_vir);
            }
            else
            {
                _vir->cnt++;
                return true;
            }
        }
        Node* find(const int _data,Node* _vir)
        {
            if(_vir == nullptr) return nullptr;
            if(_data<_vir->data) 
                return find(_data,_vir->Lchild);
            else if(_data>_vir->data)
                return find(_data,_vir->Rchild);
            else 
                return _vir;
        }
    };
}