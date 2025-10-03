#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor_1; used to initialise value of an obj
public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next;
    }
    // contructor_2
public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]); // head pointing to first el always
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]); //  creating new node pointing to null
        mover->next = temp;            // storing address of new node in prev node
        mover = temp;                  // mover moving to next node after storing memo address of currently created node in prev.
    }

    return head;
}

// printing linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// sorting LL with only (1,2,3)s
// TC O(2N)
// SC O(1)
Node *sortingLL123Brute(Node *head)
{
    // code here
    if (head == NULL || head->next == NULL)
        return head;
    Node *temp = head;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    while (temp != NULL)
    {
        if (temp->data == 0)
            cnt0++;
        else if (temp->data == 1)
            cnt1++;
        else
            cnt2++;
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (cnt0)
        {
            temp->data = 0;
            temp = temp->next;
            cnt0--;
        }
        else if (cnt1)
        {
            temp->data = 1;
            temp = temp->next;
            cnt1--;
        }
        else
        {
            temp->data = 2;
            temp = temp->next;
            cnt2--;
        }
    }
    return head;
}
// sorting LL with only (1,2,3)s
// TC O(N)
// SC O(1)
Node *sortingLL123(Node *head)
{
// Base case: if list is empty or has only one node, return head as it is already sorted
    if (head == NULL || head->next == NULL)
        return head;

    Node *temp = head;

    // Create dummy nodes for three separate linked lists for 0s, 1s, and 2s
    Node *dummyZero = new Node(-1);
    Node *dummyOne = new Node(-1);
    Node *dummyTwo = new Node(-1);

    // Temporary pointers to build the three lists
    Node *t0 = dummyZero;
    Node *t1 = dummyOne;
    Node *t2 = dummyTwo;

    // Traverse the original list and separate nodes into 0s, 1s, and 2s lists
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            t0->next = temp;   // Append node to 0s list
            t0 = temp;         // Move tail pointer of 0s list forward
        }
        else if (temp->data == 1)
        {
            t1->next = temp;   // Append node to 1s list
            t1 = temp;         // Move tail pointer of 1s list forward
        }
        else
        {
            t2->next = temp;   // Append node to 2s list
            t2 = temp;         // Move tail pointer of 2s list forward
        }
        temp = temp->next;     // Move to next node in original list
    }
    Node *newHead = NULL;

    // -1->0->0->0
    // -1->1->1->1->1
    // -1->2->2->2->2->2
    t0->next = (dummyOne->next)? dummyOne->next : dummyTwo->next; // if there is no dummyone->next then point to dummytwo->next if their will neither of them t0->next(means tail t0 of 1's) will point to null as dummyOne->next=NULL & dummyTwo->next=NULL.

    t1->next = dummyTwo->next; // if there will be no dummytwo->next then t1->next=NULL as (dummyTwo->next=NULL)

    t2->next = NULL; // t2->next always be null doesnt matter whats the condition is.

    newHead = dummyZero->next; // if there will be no dummyzero then dummyzero->next=dummyOne->next becoz head and tail will be same if no cnt o 0s, that is your required head.
    // if there will be no dummyone->next as well then point to dummyTwo->next that will your required head

    delete dummyZero;
    delete dummyOne;
    delete dummyTwo;
    return newHead;
}

int main()
{
    vector<int> nums = {1, 1, 2};
    Node *head = convertArr2LL(nums);
    print(sortingLL123(head));
}

// take aways-look at the logic and dry run properly becoz one line can ruin your solution.