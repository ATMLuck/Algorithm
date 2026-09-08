#include "iostream"
using namespace std;
class Node
{
public:
    int id;
    int value;
};
int main()
{
    int n;
    cin >> n;
    Node *arr = new Node[1<<n];
    for(int i = 0;i<(1<<n);i++)
    {
        cin >> arr[i].value;
        arr[i].id = i+1;
    }
    while(n!=1)
    {
        
        Node *fast = arr+1,*low = arr;
        while(fast-arr<1<<n)
        {
            *low = ((fast-1)->value>fast->value)?*(fast-1):*fast;
            fast+=2;
            low++;
        }
        n--;
    }
    cout << ((arr[0].value < arr[1].value)?arr[0].id:arr[1].id) << endl;
    delete[] arr;
    
}