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

// finding pairs brute
vector<pair<int,int>> pairsWithSumK(Node* head,int k){
    Node* temp1=head;
    vector<pair<int,int>>sumk;
    while(temp1!=NULL){
        Node* temp2=temp1->next;
        while(temp2!=NULL && temp1->data + temp2->data <= k){
            if(temp1->data + temp2->data == k){
                sumk.push_back({temp1->data,temp2->data});
            }
            temp2=temp2->next;
        }
      temp1=temp1->next;
    }
    return sumk;     
}
 
// finding pairs optimal
 vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
    Node* t1=head;
    Node* t2=head;
    vector<pair<int,int>>result; // finding tail linked list
    while(t2->next!=NULL){
        t2=t2->next;
    }
    while(t1 != t2 && t2->next != t1){ // travesing to find pairs
        int d1=t1->data;
        int d2=t2->data;
        if(d1+d2==target){ // if target matched move both pointer towards each other
            result.push_back({d1,d2});
            t1=t1->next;
            t2=t2->prev;

        }

        else if(d1+d2>target) t2=t2->prev; // if sum>target reduce sum by shifting t2 left
        else t1=t1->next; // if sum<target increase sum by shifting t1 right
    }
    return result;
    }


int main(){
    // test your code here
}
