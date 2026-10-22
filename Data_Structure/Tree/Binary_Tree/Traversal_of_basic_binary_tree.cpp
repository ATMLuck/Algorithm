#include "./include/ExampleBinaryTree.hpp"
#include <stack>
#include <iostream>
#include <queue>

using namespace std;
//============DFS============
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
//=======后序遍历=======
void postorder_use_stack(const ExampleBinaryTree &tree)
{
    Node *p = tree.root;
    stack<Node*> tmp;
    while(p!=nullptr)
    {
        tmp.push(p);
        p = p->Lchild;
    }
    Node* last = nullptr;
    while(!tmp.empty())
    {
        p = tmp.top();
        if(p->Rchild==nullptr||last == p->Rchild)
        {
            cout << p->data << ' ';
            last = p;
            tmp.pop();
        }
        else
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
void tmp_postorder(Node *vir)
{
    if(vir == nullptr) return;
    if(vir->Lchild!=nullptr) tmp_postorder(vir->Lchild);
    if(vir->Rchild!=nullptr) tmp_postorder(vir->Rchild);
    cout << vir->data << ' ';
}
void postorder(const ExampleBinaryTree &tree)
{
    tmp_postorder(tree.root);
    cout << endl;
}
//============BFS============
void BFS_order(const ExampleBinaryTree &tree)
{
    queue<Node*> que;
    que.push(tree.root);
    while(!que.empty())
    {
        Node* p = que.front();
        que.pop();
        if(p->Lchild!=nullptr) que.push(p->Lchild);
        if(p->Rchild!=nullptr) que.push(p->Rchild);
        cout << p->data << ' ';
    }
    cout << endl;
}


int main()
{
    ExampleBinaryTree tree;
    cout << "====preorder use stack====\n";
    preorder_use_stack(tree);
    cout << "====preorder====\n";
    preorder(tree);
    cout << "====inorder====\n";
    inorder(tree);
    cout << "====inorder use stack====\n";
    inorder_use_stack(tree);
    cout << "====postorder use stack====\n";
    postorder_use_stack(tree);
    cout << "====postorder====\n";
    postorder(tree);
    cout << "====BFS====\n";
    BFS_order(tree);


    return 0;
}