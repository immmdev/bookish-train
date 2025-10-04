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

// Length of LL
int lengthofLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

// deleting kth element from LL extreme naive
Node* deletekthFromBack(Node* head, int k){
    Node* temp=head;
    if(k==0) {
        head=head->next;
        free(temp);
        return head;
    }
    while(temp!=NULL){
        k--;
        if(k==0){
            Node* deleteNode=temp->next;
            temp->next=temp->next->next;
            free(deleteNode);
            return head;
        }
        temp=temp->next;
    }
    return head;
}


Node* removeNthFromEnd(Node* head, int n) {
    Node* fast = head;
    Node* slow = head;

    // Step 1: Move `fast` pointer n steps ahead
    // After this loop, `fast` is n nodes ahead of `slow`
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // Step 2: If `fast` becomes NULL here,
    // it means n == length of the list.
    // So we need to delete the head node itself.
    if (fast == NULL) {
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
        return head;
    }

    // Step 3: Move `fast` and `slow` together until `fast` reaches the last node.
    // When `fast->next` becomes NULL, `slow` will be just before the target node.
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Step 4: Delete the target node (Nth from end)
    Node* deleteNode = slow->next;          // Node to be deleted
    slow->next = slow->next->next;          // Bypass the target node
    delete deleteNode;                       // Free memory

    // Step 5: Return updated head of the list
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
    vector<int>nums={2,3,4,6,8,5,3};
    Node* head=convertArr2LL(nums);
    int k;
    cin>>k;
    // int k=lengthofLL(head)-bn;
    // print(deletekthFromBack(head,k));
    print(deletekthFromBack(head,k));

}