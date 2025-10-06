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

Node* reverseLL3(Node* head){
    Node* temp=head;
    Node* back=NULL;
    while(temp!=NULL){
        Node* front=temp->next;
        temp->next=back;
        back=temp;
        temp=front;
    }
    return back;
}
Node* getKthNode(Node* temp, int k){
    int n=1;
    while(n<k && temp!=NULL){
        temp=temp->next;
        n++;
    }
    return temp;
}
Node* reverseInGroupOfk(Node* head,int k){
    Node* temp=head;
    Node* prevNode;
    while(temp!=NULL){
        Node* kthNode=getKthNode(temp,k);

        if(kthNode==NULL) {
            if(prevNode) prevNode->next=temp;
            break;
        }
        Node* nextTriHead=kthNode->next;
        kthNode->next=NULL;
        reverseLL3(temp);
        if(temp==head) {
            head=kthNode;
        } else {
            prevNode->next=kthNode;
        }
        prevNode=temp;
        temp=nextTriHead;
    }
    return head;
}

int main(){
    // test your code
}
