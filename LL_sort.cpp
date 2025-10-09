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

// TC O(logN*(N+N/2))
// SC O(1)
Node* mergeTwoSortedLL(Node* head1, Node* head2){
    Node* t1=head1;
    Node* t2=head2;
    // new linkedList will start from here
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode; // used to create new linkedList 
    while(t1!=NULL && t2!=NULL){
        if(t1->data<t2->data){
            temp->next=t1;
            temp=t1;
            t1=t1->next;
        } else {
            temp->next=t2;
            temp=t2;
            t2=t2->next;
        }
    }

    if(t1) temp->next=t1;
    if(t2) temp->next=t2;
    return dummyNode->next; 
}

Node* getMiddle(Node* head) {
    if(head==NULL || head->next==NULL) return head;
    Node* s=head;
    Node* f=head->next;
    while( f!=NULL && f->next!=NULL ){
        s=s->next; 
        f=f->next->next; 
    }
    return s;

}

Node* sortLL(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* middle=getMiddle(head);
    Node* right=middle->next;
    middle->next=NULL;
    Node* left=head;
    left=sortLL(left);
    right=sortLL(right);
    return mergeTwoSortedLL(left,right);
}

int main(){
    vector<int>nums={6,7,8,2,1,4,5,2,8,9};
    Node* head=convertArr2LL(nums);
    print(sortLL(head));
}