struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* merge(Node* first, Node* second){
        if(first==NULL) return second;
        if(second==NULL) return first;
        
        if(first->data>second->data){
            second->next=merge(first, second->next);
        
            return second;
        }
        else{
            first->next= merge(first->next, second);
            
            return first;
        }
    }
    
    Node* splitList(Node* head){
        if(head==NULL) return head;
        
        Node* fast=head;
        Node* slow=head;
        
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            if (fast != NULL) {
                slow = slow->next;
            }
        }
        
        Node* secondHead= slow->next;
        slow->next=NULL;
        return secondHead;
    }
    
    
    Node* mergeSort(Node* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        Node* second = splitList(head);
        
        head=mergeSort(head);
        second= mergeSort(second);
        
        return merge(head, second);
        
    }
};
