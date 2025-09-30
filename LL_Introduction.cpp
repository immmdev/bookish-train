// Linked list
// it is a dynamic data structure, that is used to store data in flexible size and in non contiguous manner.
// it has a (data,next)


#include<bits/stdc++.h>
using namespace std;

// defining of a linked list
// self defined data type Node 
class Node{ // with struct u dont get benifit of OOPs so we use class intead of struct as both provide the same functionality but class have a upper hand.
        public:
        int data; // The data 
        Node* next; // The next item will also of Node data type so for storing it you need a Node pointer.

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


// Length of the linked list
int lengthofLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    
    return cnt;
}

// searching in linked list
int isval(Node* head,int val){
    Node* temp=head;
    while(temp){
        if(temp->data==val) return 1;
        temp=temp->next;
    }
    return 0;
}

int main(){
    
    
    vector<int> nums={2,3,5,8,9,4};
    // Node* x=new Node(nums[1],nullptr);
    // Node* y=new Node(nums[0],x); // used to store memory address of new in y =(0x55f784c932d0)
    // cout<<x->data<<endl; // -> this is used to access the data from memo in an obj;
    Node* head=convertArr2LL(nums);
    
    // travering through linked list
    Node* temp=head;
    while(temp){
        // cout<<temp->data<<" ";
        temp=temp->next;
    }
    
    // length LL
    // cout<<lengthofLL(head)<<endl;
    cout<<isval(head,5)<<endl;

}

