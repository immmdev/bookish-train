#include<bits/stdc++.h>
using namespace std;

// doubly LL initiation
class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1,Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};

// printing doubly linked list
void print(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

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

// brute
// TC O(2N)
// SC O(N)
Node* reverseDLL(Node* head){
    Node* temp=head;
    stack<int>st; // Intitialising stack
    // Pushing into the stack
    while(temp!=NULL){ 
        st.push(temp->data); 
        temp=temp->next;
    }

    // Entering data in the DLL agin in reverse order
    temp=head;
    while(temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}

// optimal
// TC O(N)
// SC O(1)
Node* OptimalReverseDLL(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* current=head;
    Node* last=NULL;
    while(current!=NULL){
        // swapping next and back
        last=current->back; 
        current->back=current->next;
        current->next=last;
        current=current->back;
    }
    
    return last->back; // new head
}

int main(){
    vector<int>nums={2,3,4,5,7,8,9,54,2};
    Node* head=array2DoublyLL(nums);
    print(OptimalReverseDLL(head));
}