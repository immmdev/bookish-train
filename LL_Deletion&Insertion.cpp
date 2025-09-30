#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }

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

// deleting head
Node* removeHead(Node* head){
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    delete temp; // freeing the memo 
    return head;
};

// deleting tail

Node* removeTail(Node* head){
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next; // moving to next if not null
    }
    delete temp->next; // freeing memo at temp->next
    temp->next=nullptr; // updating address at 2nd last node
    return head;
}

// deleting kth element from LL
Node* deletek(Node* head, int k){
    Node* temp=head;
    if(head==NULL) return head;
    if(k==1){
        head=head->next;
        delete temp;
        return head;
    }

    int cnt=0; Node* prev=NULL;
    while(temp!=NULL){
        cnt++; // increaing cnt to nodes
        if(cnt==k){
            prev->next=prev->next->next; // skipping the desired node
            delete temp; // removing space of the skipped node
            return head; 
        }
        prev=temp; // storing prev address before moving to next node
        temp=temp->next; // moving to the next node
    }
    return head;
}

// removal of node by value
Node* deletek(Node* head, int el){
    Node* temp=head;
    if(head==NULL) return head;
    if(head->data==el){ // checking if saying remove head
        head=head->next;
        delete temp;
        return head;
    }

    Node* prev=NULL;
    while(temp!=NULL){
        if(temp->data==el){
            prev->next=prev->next->next; // skipping the desired node
            delete temp; // removing space of the skipped node
            return head; 
        }
        prev=temp; // storing prev address before moving to next node
        temp=temp->next; // moving to the next node
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



int main(){
    vector<int>arr={1,2,3,4,5,5};
    Node* head=convertArr2LL(arr);
    // print(removeHead(head));
    // print(removeTail(head));
    int k;
    cin>>k;
    print(deletek(head,k));
}

