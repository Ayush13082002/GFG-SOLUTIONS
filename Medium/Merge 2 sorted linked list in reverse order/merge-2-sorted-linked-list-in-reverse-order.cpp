//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    Node* merge(Node* node1, Node* node2){
        if(node1->data > node2->data){
            return merge(node2, node1);
        }
        
        Node* head = node1;
        node1=node1->next;
        Node* temp=head;
        
        while(node1 && node2){
            if(node1->data <=node2->data){
                temp=temp->next;
                node1=node1->next;
            }
            else{
                temp->next=node2;
                temp=temp->next;
                node2 = node2->next;
                temp->next = node1;
            }
        }
        if(node2){
            temp->next=node2;
        }
        
        return head;
    }
    
    Node* reverse(Node* node){
        Node* temp=node;
        Node* prev=NULL;
        Node* next=temp->next;
        
        while(next){
            temp->next = prev;
            prev=temp;
            temp=next;
            next=next->next;
        }
        
        temp->next =prev;
        
        return temp;
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        if(node1==NULL && node2==NULL){
            return NULL;
        }
        if(node1==NULL){
           return reverse(node2); 
        }
        if(node2==NULL){
            return reverse(node1);
        }
        
        //merge the linked list
        Node* head = merge(node1, node2);
        
        //reverse the linked list
        head= reverse(head);
        
        return head;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends