class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here
        if(head==NULL) return head;
        Node *curr=head;
        while(curr!=NULL){
            Node *prev=NULL;
            for(int i=0;i<m && curr!=NULL;i++){
                prev=curr;
                curr=curr->next;
            }
            for(int i=0;i<n && curr!=NULL;i++){
                curr=curr->next;
            }
            prev->next=curr;
        }
        return head;
    }
};