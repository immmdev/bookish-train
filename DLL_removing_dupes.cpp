#include<bits/stdc++.h>
using namespace std;

// doubly LL initiation
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1,Node* next1,Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};


// creating doubly linked list from an array
Node* array2DoublyLL(vector<int>nums){
    Node* head=new Node(nums[0]);
    Node* prev=head;
    int n=nums.size();
    for(int i=1; i<n; i++){
        Node* temp=new Node(nums[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

// printing doubly linked list
void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


// removing duplicates 
// TC O(N)
Node* removeDuplicatesDLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        Node* nextNode=temp->next; // finding the nextNode at each new temp
        while( nextNode!=NULL && nextNode->data==temp->data){ // finding non unique elelment to connect with
            Node* toDelete=nextNode;
            nextNode=nextNode->next;
            delete toDelete;
        }
        temp->next=nextNode; // skipped middle one
        if(nextNode)nextNode->prev=temp;
        temp=nextNode; // move temp to new unique node  
    }
    return head;
}
int main(){

}