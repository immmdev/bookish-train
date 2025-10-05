#include<bits/stdc++.h>
using namespace std;
class Node{ 
        public:
        int data;  
        Node* next; 

        // constructor_1; used to initialise value of an obj
        public:
        Node(int data1,Node* next1){
            data=data1;
            next=next;
        }
        // contructor_2
        public:
        Node(int data1){
            data=data1;
            next=nullptr;
        }
};



// coverting array to linkedlist
Node* convertArr2LL(vector<int>&arr){
    Node* head=new Node(arr[0]); // head pointing to first el always
    Node* mover=head;
    for(int i=1; i<arr.size(); i++){
        Node* temp=new Node(arr[i]); //  creating new node pointing to null
        mover->next=temp; // storing address of new node in prev node
        mover=temp; // mover moving to next node after storing memo address of currently created node in prev.
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

// deleting middle node
Node* deleteMiddle(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* f=head;
    Node* s=head;
    f=f->next->next; // skipping slow for one step so that it slow point one step before mid
    while(f!=NULL && f->next!=NULL){
        s=s->next;
        f=f->next->next;
    }
    Node* toDelete=s->next;
    s->next=s->next->next;
    delete toDelete;
    return head;
}

int main(){
    vector<int>nums={1,2,3};
    Node* head=convertArr2LL(nums);
    print(deleteMiddle(head));
}