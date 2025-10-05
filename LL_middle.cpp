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

// finding middle rabbit turtle algo
// TC O(N/2)
// SC O(1)
// intution:- when p1 is moving with x and p2 is moving with x/2 then at time t when p1 will be at d then p2 will be at d/2
int getMiddle(Node* head) {
    // code here
    if(head==NULL || head->next==NULL) return head->data;
    Node* s=head;
    Node* f=head;
    while(f->next!=NULL && f!=NULL){
        s=s->next; // moving x
        f=f->next->next; // moving 2x
    }
    return s->data;

}

int main(){
    // test here the algo
}

