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

// palindrome test
int isPalindrome(Node* head){
    Node* temp=head;
    stack<int>el;
    while(temp!=NULL){
        el.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if((temp->data)!=el.top()) return 0;
        temp=temp->next;
        el.pop();
    }
    return 1;
}

// optimal palindrome test
// TC(2N)
// SC(1)
bool ispalindrome(Node* head){
    if(head==NULL || head->next==NULL) return true;
    // Step 1: Use rabbit and turtle (fast & slow pointers) to find the middle of the linked list in O(N)
    Node* fast=head;
    Node* slow=head;

    // Example: 1 → 2 → 3 → 2 → 1
    // After loop ends: 
    // slow → 3 (middle element)
    // fast → last node (1)
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next; // moves twice as fast
        slow=slow->next;       // moves once
    }

    // Step 2: Reverse the second half of the linked list for comparison
    // Example:
    // Original LL: 1 → 2 → 3 → 2 → 1
    // After reverse from slow->next: 1 → 2 (reversed part) 3->2 still 
    Node* newHead=reverseLL(slow->next);

    // Step 3: Compare first half and reversed second half node by node
    Node* first=head;
    Node* second=newHead;

    // Example comparison sequence:
    // first: 1,  second: 1  
    // first: 2,  second: 2  
    while(second!=NULL){
        if(first->data!=second->data) {
            // If mismatch found, restore the list before returning
            reverseLL(newHead); 
            return false;
        }
        second=second->next;
        first=first->next;
    }

    // Step 4: Reverse the second half again to restore the original list
    reverseLL(newHead);

    // If all matched → palindrome
    return true;
}


int main(){
    vector<int>nums={1,2,3,3,2,1};
    Node* head=convertArr2LL(nums);
    cout<<ispalindrome(head)<<endl;

}