
class Solution {
  ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return last;
    }
public:
    int getDecimalValue(ListNode* head) {
        head = reverseList(head);
        int result = 0 ;
        int power = 0;
        while(head){
            if(head-> val == 1){
            result += pow(2,power);

        }
        power ++;
        head = head->next;
        }

    
    return result;
    }


        
    
};
