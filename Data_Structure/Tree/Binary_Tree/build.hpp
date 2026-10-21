#pragma once
/*
            A
          /   \
         B     C
       /   \  /  \
      D    E F    G
     / \    / \    \
    H   I  J   K    L
       / \      \
      M   N      O
     /
    P
*/
struct Node 
{
    char data;
    Node* Lchild = nullptr;
    Node* Rchild = nullptr;
    Node* parent = nullptr;
    Node(char str)
    {
        this->data = str;
    }
    Node(){}
};
class ExampleBinaryTree
{
public:
    Node *root;
    ExampleBinaryTree()
    {
        Init();
    }
    ~ExampleBinaryTree()
    {
        Distroy(root);
    }
private:
    void Init()
    {
        root = new Node();
        root->data = 'A';
        root->Lchild = new Node('B');
        root->Lchild->parent = root;
        root->Rchild = new Node('C');
        root->Rchild->parent = root;
        root->Lchild->Lchild = new Node('D');
        root->Lchild->Lchild->parent = root->Lchild;
        root->Lchild->Rchild = new Node('E');
        root->Lchild->Rchild->parent = root->Lchild;
        root->Rchild->Lchild = new Node('F');
        root->Rchild->Lchild->parent = root->Rchild;
        root->Rchild->Rchild = new Node('G');
        root->Rchild->Rchild->parent = root->Rchild;
        root->Lchild->Lchild->Lchild = new Node('H');
        root->Lchild->Lchild->Lchild->parent = root->Lchild->Lchild;
        root->Lchild->Lchild->Rchild = new Node('I');
        root->Lchild->Lchild->Rchild->parent = root->Lchild->Lchild;
        root->Rchild->Lchild->Lchild = new Node('J');
        root->Rchild->Lchild->Lchild->parent = root->Rchild->Lchild;
        root->Rchild->Lchild->Rchild = new Node('K');
        root->Rchild->Lchild->Rchild->parent = root->Rchild->Lchild;
        root->Rchild->Rchild->Rchild = new Node('L');
        root->Rchild->Rchild->Rchild->parent = root->Rchild->Rchild;
        root->Lchild->Lchild->Rchild->Lchild = new Node('M');
        root->Lchild->Lchild->Rchild->Lchild->parent = root->Lchild->Lchild->Rchild;
        root->Lchild->Lchild->Rchild->Rchild = new Node('N');
        root->Lchild->Lchild->Rchild->Rchild->parent = root->Lchild->Lchild->Rchild;
        root->Rchild->Lchild->Rchild->Rchild = new Node('O');
        root->Rchild->Lchild->Rchild->Rchild->parent = root->Rchild->Lchild->Rchild;
        root->Lchild->Lchild->Rchild->Lchild->Lchild = new Node('P');
        root->Lchild->Lchild->Rchild->Lchild->Lchild->parent = root->Lchild->Lchild->Rchild->Lchild;
    }
    void Distroy(Node *vir)
    {
        if(vir == nullptr) return;
        Distroy(vir->Lchild);
        Distroy(vir->Rchild);
        delete vir;
    }
};