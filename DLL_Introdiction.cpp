#include<bits/stdc++.h>
using namespace std;

// Definition
// A Doubly Linked List (DLL) is a type of linked data structure in which:
// Each node contains three parts:
// Data – the actual information stored in the node.
// Pointer to the next node (called next).
// Pointer to the previous node (called prev).
// The nodes are connected both forward and backward, unlike a singly linked list where movement is only in one direction.
// The head pointer points to the first node, and the tail pointer usually points to the last node (whose next = NULL).

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

// deleting head of DLL
Node* deleteHeadDLL(Node* head){
    if(head==NULL && head->next==NULL) return NULL;
    Node* prev=head; // preserving head
    head=head->next; // moving head to next
    head->back=nullptr; // break new head link with previous
    prev->next=nullptr; // braking previous link with new head
    delete prev; // deleting the previous head
    return head; // returning head
}

// deleting tail of DLL
Node* deleteTailDLL(Node* head){
    if(head==NULL && head->next==NULL) return NULL;
    Node* tail=head;
    while(tail->next!=NULL){
        tail=tail->next;
    }
    Node* prev=tail->back;
    tail->back=nullptr;
    prev->next=nullptr;
    delete tail;
    return head;
}

// delting from kth postion
Node* deletekthDLL(Node* head,int k){
    Node* temp=head;
    int cnt=0;
    //  loop to get kth node
    while(temp!=NULL){
        cnt++;
        if(cnt==k) break; // get kth node break
        temp=temp->next; 
    }

    Node* front=temp->next; // getiing front of the kth node
    Node* prev=temp->back; // getting back of the kth node
    if(front==NULL && prev==NULL){ // if single node
        delete temp;
        return NULL;
    }
    else if(front==NULL){ // if tail
        return deleteTailDLL(temp);
    }
    else if(prev==NULL){ // if head
        return deleteHeadDLL(temp);
    }
    
    prev->next=front; // skipping kth node
    front->back=prev;
    temp->next=nullptr; // freeing kth node
    temp->back=nullptr;
    delete temp; // deleting kth node
    return head;
}

// deleting given node
Node* deleteNode(Node* temp){
    Node* front=temp->next; 
    Node* prev=temp->back;
    if(front==NULL){ // checking tail condition
        return deleteTailDLL(temp); // deleting tail
    }
    prev->next=front; // skipping the temp
    front->back=prev; 
    temp->next=nullptr; // detching the temp from the LL
    temp->back=nullptr;
    delete temp; // freeing the space
}

// Insertion 
// Insertion before head
Node* insertionBeforeHead(Node* head, int val){
    Node* newHead=new Node(val,head,nullptr);
    head->back=newHead;
    return newHead;
}

// insert before the tail
Node* insertBeforeTail(Node* head, int val){
    if(head->next==NULL) return insertionBeforeHead(head,val);
    Node* tail=head; // prev <--> tail
    // searching tail
    while(tail->next!=NULL){
        tail=tail->next;
    }
    // back of the tail
    Node* prev=tail->back;
    Node* newNode= new Node(val,tail,prev); // prev <-- newNode --> tail
    prev->next=newNode; // prev --> newNode
    tail->back=newNode; // newNode <-- tail
    return head; // prev <--> newNode <--> tail
}

// insertion at kth Node
Node* insertKthNode(Node* head, int k, int val){
    Node* NodeK=head;
    int cnt=0;

    if(k==1){
        return insertionBeforeHead(head,val);
    }

    // finding node before we have to insert
    while(NodeK!=NULL){
        cnt++;
        if(cnt==k) {
            break;
        }
        NodeK=NodeK->next;
    }
    Node* prev=NodeK->back; 

    Node* newNode=new Node(val,NodeK,prev);
    prev->next=newNode;
    NodeK->back=newNode;
    return head;
}

// inserting before node (never head)
Node* insertbeforeNode(Node* node, int k, int val){
    Node* prev=node->back; 
    Node* newNode=new Node(val,node,prev);
    prev->next=newNode;
    node->back=newNode;
}

int main(){
    vector<int>nums={2,3,4,5,6,7,1,3};
    Node* head=array2DoublyLL(nums);
    // print(deleteTailDLL(head));
    int val;
    cin>>val;
    // print(deletekthDLL(head,k));
    // deleteNode(head->next->next);
    // print(head);
    // print(insertionBeforeHead(head,k));
    //  print(insertBeforeTail(head,k));
    print(insertKthNode(head,8,val));
    return 0;
}