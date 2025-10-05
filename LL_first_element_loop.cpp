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

// Naive approch;
// TC O(N*2log(N))
// SC O(N)
int detectLoopFirstVal(Node* head) {
        // code here
        Node* temp=head;
        map<Node*,int>mpp;
        while(temp!=NULL){
            if(mpp.find(temp)!=mpp.end()) return temp->data;
            mpp[temp]=1;
            temp=temp->next;
        }
        return -1;
}

// after collison the distance between the (firstNodeLoop,head)  and (firstNodeLoop,collisionPoint) will be the same
// when slow will fisrt time at firstNodeLoop let the distance from head to it l1.
// then fast will be at l1 distance from slow is forward dir in loop.
// and let fast will be d distance behind from slow in loop.
// to colloid slow will cover d distance and fast will cover 2d distance, left distance from slow to fisrtNodeLoop will be l1;
// overall loop=l1+d;
// after collision (fistNodeLoop-collison) and (head-firstNodeLoop) will=l1
// TC O(N)
// SC O(1)
int firstOccurance(Node* f, Node* s,Node* head){
    f=head;
    while(f!=head){
        f=f->next;
        s=s->next;
    }
    return f->data;
}

int firstValLoop(Node* head){
    Node* s=head;
    Node* f=head;
    while(f!=NULL && f->next!=NULL){
        s=s->next;
        f=f->next->next;
        if(s==f) return firstOccurance(f,s,head);
    }
    return -1;
}



int main(){
    // test code
}