class Solution {
public:
ListNode* reverseLL(ListNode* head){
    if(head==NULL || head->next==NULL) return head ;
    ListNode* newHead = reverseLL(head->next);
    head->next->next= head;
    head->next= NULL;
    return newHead;
}
    vector<int> nextLargerNodes(ListNode* head) {
        head= reverseLL(head);
        ListNode* temp = head;
        int n=0;
        while(temp){
            n++;
            temp= temp->next;
        }
        vector<int>ans(n,0);
        stack<int>st;
        int i=0;
        while(head){
            while(st.size()>0 && st.top()<= head->val){
                st.pop();
            }
            if(st.size()!=0) ans[i]= st.top();
            st.push(head->val);
            head= head->next;
            i++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};