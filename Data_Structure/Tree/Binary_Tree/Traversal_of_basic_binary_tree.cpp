#include "./build.hpp"
#include <stack>
#include <iostream>
#include <queue>

using namespace std;
//=======前序遍历=======
void preorder_use_stack(const ExampleBinaryTree &tree)
{
    stack<Node*> tmp;
    tmp.push(tree.root);
    while(!tmp.empty())
    {
        Node* vir = tmp.top();
        tmp.pop();
        cout << vir->data << ' ';
        if(vir->Rchild!=nullptr) tmp.push(vir->Rchild);
        if(vir->Lchild!=nullptr) tmp.push(vir->Lchild);
    }
    cout << endl;
}
void tmp_preorder(Node *vir)
{
    if(vir == nullptr) return;
    cout << vir->data << ' ';
    tmp_preorder(vir->Lchild);
    tmp_preorder(vir->Rchild);
    
}
void preorder(const ExampleBinaryTree &tree)
{
    tmp_preorder(tree.root);
    cout << endl;
}
//=======中序遍历=======
void inorder_use_stack(const ExampleBinaryTree &tree)
{
    stack<Node*> tmp;
    Node* p = tree.root;
    while(p!=nullptr)
    {
        tmp.push(p);
        p = p->Lchild;
    }
    
    while(!tmp.empty())
    {
        p = tmp.top();
        tmp.pop();
        cout << p->data << ' ';
        if(p->Rchild!=nullptr)
        {
            p = p->Rchild;
            while(p!=nullptr)
            {
                tmp.push(p);
                p = p->Lchild;
            }
        }
    }
    cout << endl;
}
void tmp_inorder(Node *vir)
{
    if(vir == nullptr) return;
    if(vir->Lchild!=nullptr) tmp_inorder(vir->Lchild);
    cout << vir->data << ' ';
    if(vir->Rchild!=nullptr) tmp_inorder(vir->Rchild);
}
void inorder(const ExampleBinaryTree &tree)
{
    tmp_inorder(tree.root);
    cout << endl;
}



int main()
{
    ExampleBinaryTree tree;
    // preorder_use_stack(tree);
    // preorder(tree);
    inorder(tree);
    inorder_use_stack(tree);
    return 0;
}