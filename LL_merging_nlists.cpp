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

// TC O(KlogK+N*K*logK)
// SC O(K)
Node* nergeNLLs(vector<Node*>list){
    // priority_queue is ds that give min emement always at the top
    // min heap definition
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    // initially we will push all the heads of the list and start constructing list with the help of the dummy node.
    for(int i=0; i<list.size(); i++){
        if(list[i])pq.push({list[i]->data,list[i]});
    }
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;
    // we will extract min each time from pq untill tere are elements in pq
    while(!pq.empty()){
        auto it=pq.top();
        // we will push one element to pq every time from which LL contribute to ans LL 
        pq.pop();
        if(it.second->next) pq.push({it.second->next->data,it.second->next});
        // after extracting pop() the element and node utilised
        temp->next=it.second;
        temp=temp->next;
    }
    return dummyNode->next;
}


int main(){

}