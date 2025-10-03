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

// segregation odd-even nodes (brute force approach)
Node* oddEven(Node* head){
    // if list is empty or has only 1 node → return as it is
    if(head==NULL || head->next==NULL) return head;

    Node* temp=head;
    vector<int>oddevenList;

    // inserting odd-indexed elements
    // move in steps of 2 (head, head->next->next, ...)
    // condition (temp!=NULL && temp->next!=NULL) ensures safe traversal
    while(temp!=NULL && temp->next!=NULL){
        oddevenList.push_back(temp->data);
        temp=temp->next->next;
    }
    // if last node exists at odd position, push it too
    if(temp) oddevenList.push_back(temp->data);

    // inserting even-indexed elements
    temp=head->next;
    while(temp!=NULL && temp->next!=NULL){
        oddevenList.push_back(temp->data);
        // this check is redundant because of while condition, 
        // but kept for safety
        if (!temp->next) break; 
        temp=temp->next->next;
    }
    // if last node exists at even position, push it too
    if(temp) oddevenList.push_back(temp->data);

    // overwriting linked list values with arranged order
    temp=head;
    for(int i=0; i<oddevenList.size(); i++){
        temp->data=oddevenList[i];
        temp=temp->next;
    }

    // return modified head
    return head;
}


// optimal segregation of odd and even nodes in a linked list
// TC O(N/2)*2 = O(N)
// SC O(1)
Node* optimalOddEven(Node* head){
    if(head==NULL || head->next==NULL) return head;
    // pointers for odd and even traversal
    Node* odd=head;            // starting at 1st node (odd index)
    Node* even=head->next;     // starting at 2nd node (even index)
    Node* evenHead=head->next; // store even head to connect later

    // iterate while there are more even nodes available
    while(even!=NULL && even->next!=NULL){
        odd->next=odd->next->next;   // link current odd to next odd node
        even->next=even->next->next; // link current even to next even node

        odd=odd->next;   // move odd pointer forward
        even=even->next; // move even pointer forward
    }

    // attach even list after all odd nodes
    odd->next=evenHead;

    // return modified head of list
    return head;  
}

// TC O(N)
// SC O(1)
// segrigating odd even on the basis of their node->data
Node* divide(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* temp=head;
    Node* odd=new Node(-1);
    Node* even=new Node(-1);
    Node* t1=even;
    Node* t2=odd;
    while(temp!=NULL){
        if((temp->data)%2==0){
            t1->next=temp;
            t1=temp;
        }
        else if((temp->data)%2==1){
            t2->next=temp;
            t2=temp;
        }
        temp=temp->next;
    }
    t1->next=odd->next;
    t2->next=NULL;
    Node* newHead=even->next;
    delete odd;
    delete even;
    return newHead;
}

int main(){
    vector<int>nums={1,2,3,4,5,6,7,8,9,10,11};
    Node* head=convertArr2LL(nums);
    // print(oddEven(head));
    print(divide(head));
}