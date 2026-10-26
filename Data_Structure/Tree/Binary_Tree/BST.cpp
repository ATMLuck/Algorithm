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
            // data = 0;
            // cnt = 0;
            Lchild = nullptr;
            Rchild = nullptr;
            Parent = nullptr;
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
            type = 0;
        }
        ~BST()
        {
            Destroy(root);
        }
        BST(const BST& target)
        {
            if(!copy(root,target.root,nullptr)) 
                std::cerr << "Copy Error!\n";
            
            this->type = target.type;
            this->size = target.size; 
            
        }
        BST& operator=(const BST&) = delete;
        const Node* GetRoot() const {return root;}
        unsigned long long Size() const
        {
            return size;
        }
        unsigned long long Type() const
        {
            return type;
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
                return false;
            }
        }
        const Node* Find(int _data)
        {
            return find(_data,root);
        }
        bool Erase(const int _data)
        {
            return erase(_data,false);
        }
        bool Erase_one(const int _data)
        {
            return erase(_data,true);
        }       
    private:
        Node* root;
        unsigned long long size;
        unsigned long long type;

        void Destroy(Node* _vir)
        {
            if(_vir==nullptr) return;
            if(_vir->Lchild!=nullptr) Destroy(_vir->Lchild);
            if(_vir->Rchild!=nullptr) Destroy(_vir->Rchild);
            delete _vir;
        }
        bool copy(Node* &self,Node* target,Node* parent = nullptr)
        {
            if(target==nullptr){ self=nullptr; return true;}
            bool iscopy = true;
            try
            {
                {
                    self = new Node(target->data);
                    self->cnt = target->cnt;
                    self->Parent = parent;
                }
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                return false;
            }
            if(target->Lchild!=nullptr) 
            {
                if(!copy(self->Lchild,target->Lchild,self))
                    iscopy = false;  
            }
            if(target->Rchild!=nullptr) 
            {
                if(!copy(self->Rchild,target->Rchild,self))
                    iscopy = false;
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
                    type++;
                    _vir->Parent = _parent;
                    return true;
                }
                catch(const std::bad_alloc& e)
                {
                    std::cerr << e.what() << std::endl;
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
        bool erase(const int _data,bool _once)
        {
            Node* target = find(_data,root);
            if(target==nullptr) 
                return false;
            if(_once&&target->cnt > 1) 
            {
                target->cnt--;
                this->size--;
                return true;
            }
            this->size-=target->cnt;
            this->type--;
            if(target->Lchild!=nullptr&&target->Rchild!=nullptr)
            {
                Node* succeed = target->Rchild;
                while(succeed->Lchild!=nullptr) succeed = succeed->Lchild;
                node_data_swap(target,succeed);
                return erase_less_two_child(succeed);
            }
            else
            {
                return erase_less_two_child(target);
            }


        }
        bool erase_less_two_child(Node* target)
        {
            if(target == root)
            {
                if(target->Lchild!=nullptr)
                {
                    target->Lchild->Parent = nullptr;
                    root = target->Lchild;
                }
                else if(target->Rchild!=nullptr)
                {
                    target->Rchild->Parent = nullptr;
                    root = target->Rchild;
                }
                else
                {
                    root = nullptr;
                }
                delete target;
                return true;
            }
            if(target->Lchild==nullptr&&target->Rchild==nullptr)
            {
                if(target->Parent->Lchild==target)
                    target->Parent->Lchild = nullptr;
                else
                    target->Parent->Rchild = nullptr;
            }
            else if(target->Lchild!=nullptr)
            {
                target->Lchild->Parent = target->Parent;
                if(target->Parent->Lchild==target)
                    target->Parent->Lchild = target->Lchild;
                else
                    target->Parent->Rchild = target->Lchild;
            }
            else
            {
                target->Rchild->Parent = target->Parent;
                if(target->Parent->Lchild==target)
                    target->Parent->Lchild = target->Rchild;
                else
                    target->Parent->Rchild = target->Rchild;
            }
            delete target;
            return true;
        }
        void node_data_swap(Node* a,Node* b)
        {
            std::swap(a->data,b->data);
            std::swap(a->cnt,b->cnt);
        }
    };
};