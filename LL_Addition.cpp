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
void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


// addition to LL
// TC O(max(l1,l2))
// SC O(max(l1,l2))
Node* addTwoLL(Node* head1,Node* head2){
    Node* temp1=head1; // to travese LL1
    Node* temp2=head2; // to travese LL2
    int carry=0;
    Node* dummy=new Node(-1); // first node 
    Node* curr=dummy; // to create ans LL
    // traverse untill both get diminished
    while(temp1!=NULL || temp2!=NULL){
        int sum=carry; 
        if(temp1) sum+=temp1->data; // if el in LL1 add to sum
        if(temp2) sum+=temp2->data; // if el in LL1 add to sum
        Node* newNode=new Node(sum%10); // creating new node with summing unit place el
        carry=sum/10; // storing carry
        curr->next=newNode; // linking newnode in the ans LL
        curr=newNode; // moving curr to nxt in the ans LL
        if(temp1) temp1=temp1->next; // trversing LL1 and LL2
        if(temp2) temp2=temp2->next;
    }
    if(carry){ // adding node od caary if any in the last
            Node* newNode=new Node(carry);
            curr->next=newNode;
        }
    return dummy->next; // dummy wast the first node hence it was pointing to head
}

int main(){
    vector<int>nums1={3,8,7};
    vector<int>nums2={5,2,4,1};
    // its like 1425+783
    Node* head1=convertArr2LL(nums1);
    Node* head2=convertArr2LL(nums2);
    print(addTwoLL(head1,head2));


}

