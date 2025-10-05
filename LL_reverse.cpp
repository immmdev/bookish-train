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

// reverse LL
// SC O(N)
// TC O(1)
Node* reverseLL(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        Node* front=temp->next; // for temp movement
        temp->next=prev; // reversing the link
        prev=temp; // preserving and moving prev
        temp=front; // moving temp to front 
    }
    return prev; // new head
}

// recursive solution
// SC O(N)
// TC O(N) stck space is occupied
Node* reveseRecursive(Node* head){
     if(head==NULL || head->next==NULL) return head;
     Node* newHead=reveseRecursive(head->next); // recursion deriving base case then back tracking
     Node* front=head->next; // finding front of old head
     front->next=head; // reversing the link
     head->next=NULL; // setting the head next to null as it becomes newest tail after reversing
     return newHead; // return nw head
}

int main(){
    vector<int>nums={1,2,3,4,5,6,7,8,9,10,11};
    Node* head=convertArr2LL(nums);
    print(reveseRecursive(head));
}

