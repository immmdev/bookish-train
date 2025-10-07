#include<bits/stdc++.h>
using namespace std;
using namespace std;

class Node{ 
        public:
        int data;  
        Node* next; 
        Node* bottom;

        // constructor_1; used to initialise value of an obj
        public:
        Node(int data1,Node* next1,Node* bottom1){
            data=data1;
            next=next;
            bottom=bottom1;
        }
        // contructor_2
        public:
        Node(int data1){
            data=data1;
            next=nullptr;
            bottom=nullptr;
        }
};

Node* merge2LL(Node* list1, Node* list2){
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;
    // traversing two LL
    while(list1!=NULL && list2!=NULL){
        if(list1->data>list2->data){
            temp->bottom=list2; 
            temp=list2;
            list2=list2->bottom;
        } 
        else{
            temp->bottom=list1;
            temp=list1;
            list1=list1->bottom;
        }
        temp->next=NULL; // making all next two as the res LL will be vertical LL
    }
    if(list1) temp->bottom=list1;
    if(list2) temp->bottom=list2;
    return dummyNode->bottom;
    }
    

// TC O(2*M*N)
// SC O(N) using satck space
Node *flatten(Node *head) {
    if(head==NULL || head->next==NULL){
        return head;
    } // base case 

    Node* mergedHead=flatten(head->next); // digging till last node
    return merge2LL(head,mergedHead); // after getting last node from base case start merging from last and second last node and then so on.
}
        
int main(){
    // test your code
}