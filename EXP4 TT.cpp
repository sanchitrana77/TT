#include <bits/stdc++.h>
using namespace std;

int main()
{

    list<int> linkedList;

    int choice, element;
    linkedList.push_front(3);
    linkedList.push_front(2);
    linkedList.push_front(1);
    cout << "Initial Linked List: " << endl;
    for (const auto &elem : linkedList)
    {
        cout << elem << " -> ";
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        linkedList.push_front(element);
    }

    cout << "\nFinal Linked List: " << endl;
    for (const auto &elem : linkedList)
    {
        std::cout << elem << " -> ";
    }
    return 0;
}