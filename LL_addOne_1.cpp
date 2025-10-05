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

// printing linked list
void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// reverse LL
// SC O(N)
// TC O(1)
Node* reverseLL(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        Node* front=temp->next; // for temp movement
        temp->next=prev; // reversing the link
        prev=temp; // preserving and moving prev
        temp=front; // moving temp to front 
    }
    return prev; // new head
}

// add 1 to LL number in forward direction
// Function to add 1 to the number represented by a linked list
// TC(3N)
// SC O(1)
Node* addOne(Node* head){
    // Base case: if list is empty, simply return
    if(head == NULL) return head;

    // Step 1: Reverse the linked list
    // This helps us start addition from the least significant digit (end of list)
    head = reverseLL(head); 

    Node* temp = head; // temp pointer for traversal
    int carry = 1;     // carry starts as 1 since we are adding '1' to the number

    // Step 2: Traverse the reversed list and perform addition
    while(temp != NULL){
        temp->data += carry; // add carry to current node's data

        // If sum is less than 10, no further carry is generated
        if(temp->data < 10){
            carry = 0;       // reset carry
            break;           // addition complete, exit loop
        } 
        else {
            // If sum >= 10, set current digit to 0 and carry remains 1
            carry = 1;
            temp->data = 0;
        }

        // Move to next node to continue addition
        temp = temp->next;
    }

    // Step 3: If carry is still 1 after traversing entire list,
    // we need to add a new node at the beginning
    if(carry == 1){
        Node* newNode = new Node(1); // create new node with data = 1

        // Reverse the list back to restore original order
        head = reverseLL(head);

        // Link new node at the front of reversed list
        newNode->next = head;

        // Return the new node as the new head of the final list
        return newNode;
    } 

    // Step 4: If no carry remains, simply reverse the list back
    head = reverseLL(head);

    // Step 5: Return the updated head
    return head;
}

// optimal addition of one
int helper(Node* temp) {
    // Base case: if we reach the end of the linked list, return 1 
    // (this 1 will act as a 'carry' to add 1 to the last node)
    if (temp == NULL) { 
        return 1; 
    }

    // Recursive call: move to the next node until we hit NULL (end of list)
    // The returned value (carry) will be added to current node's data
    int carry = helper(temp->next); 

    // Add the carry from the deeper recursive call to the current node's data
    temp->data += carry; 

    // If after addition, the current node's data is less than 10,
    // it means no further carry is generated — so return 0
    if (temp->data < 10) {
        return 0; 
    }

    // If data becomes 10, set it to 0 (carry-over condition)
    temp->data = 0; 

    // Return 1 as carry to be added to the previous node
    return 1; 
}

Node* AddOne(Node* head){
    int carry=helper(head);
    if(carry==1){
    Node* newNode=new Node(1);
    newNode->next=head;
    return newNode;
    } 
    return head;
}

int main(){
    vector<int>nums={9,8,7,6,5,4};
    Node* head=convertArr2LL(nums);
    print(AddOne(head));
}