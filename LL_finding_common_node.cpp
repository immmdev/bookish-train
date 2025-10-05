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

// finding common node brute
Node* commonNode(Node* head1,Node* head2){
    Node* temp1=head1;
    map<Node*,int>mpp;
    while(temp1!=NULL){ // storing all the nodes in hashMap LL1
        mpp[temp1]=1;
        temp1=temp1->next;
    }
    Node* temp2=head2;
    while(temp2!=NULL){ // checking for common node LL2
        if(mpp.find(temp2)!=mpp.end()){
            return temp2;
        }
        temp2=temp2->next;
    }
    return NULL; 
}

// collison point
Node* collisonpoint(Node* lghead,Node* smhead, int tomove){
    Node* t1=lghead;
    Node* t2=smhead;
    // both LL at same point
    for(int i=0; i<tomove; i++){
        t1=t1->next;
    }

    // compare node by node
    while(t1!=NULL && t2!=NULL){
        if(t1==t2){
            return t1;
        }
        t1=t1->next;
        t2=t2->next;
    }
    return NULL;
}

// better solution
// TC O(N1+2N2)
// SC O(1)
Node* commonNodeBetter(Node* head1,Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;
    int len1=0,len2=0;
    while(temp1!=NULL){
        len1++;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        len2++;
        temp2=temp2->next;
    }
    Node* temp1=head1;
    Node* temp2=head2;
    if(len1>len2){
        int tomove=len1-len2;
        return collisonpoint(temp1,temp2,tomove);
    } else {
        return collisonpoint(temp2,temp1,len2-len1);
    }
}

// optimal solution 
// TC O(N1+N2)
// SC O(1)
// move both t1 and t2 till they become equal at some point when they reaches null move them to diff head positions t1=h2, t2=h1, this will help both t1 and t2 to align with each other then from their compare them
Node* intersetionNode(Node* head1,Node* head2){
    // base case
    if(head1==NULL || head2==NULL) return NULL;
    Node* temp1=head1;
    Node* temp2=head2;
    // they will ultimately colloid at some point either at any node or at NULL
    while(temp1!=temp2){
        temp1=temp1->next;
        temp2=temp2->next;
        if(temp1==temp2) return temp1;
        // it will help aligning the nodes of Y LL
        if(temp1==NULL) temp1=head2;
        if(temp2==NULL) temp2=head1;
    }
    return temp1;
}

int main(){
    // test here the algo
}