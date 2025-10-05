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
bool detectLoop(Node* head) {
        // code here
        Node* temp=head;
        map<Node*,int>mpp;
        while(temp!=NULL){
            if(mpp.find(temp)!=mpp.end()) return true;
            mpp[temp]=1;
            temp=temp->next;
        }
        return false;
}

// TC O(N)
// SC O(1)
bool DetectLoop(Node* head){
    Node* s=head;
    Node* f=head;
    while(f!=NULL && f->next!=NULL){
        s=s->next;
        f=f->next->next;
        if(s==f) return true;
    }
    return false;
}

// finding length of loop
int lengthOfLoop(Node* s, Node* f){
    f=f->next;
    int cnt=1;
    while(f!=s){
        cnt++;
        f=f->next;
    }
    return cnt;
}

int lengthOfLoopImplimentaion(Node *head) {
    Node* s=head;
    Node* f=head;
    int cnt=0;
    while(f!=NULL && f->next!=NULL){
        s=s->next;
        f=f->next->next;
        cnt++;
        if(s==f) return lengthOfLoop(s,f); // if loop detected fint its length
    }
    return 0;
}

int main(){
    // test your code
}