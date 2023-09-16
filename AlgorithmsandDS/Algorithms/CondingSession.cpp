struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 ListNode* insertionSortList(ListNode* head) {
        ListNode* curr = head;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        ListNode* tmp = nullptr;
        while(curr) 
        {
            next = curr->next;
…                    tmp = tmp->next;
                }
                curr->next = tmp->next;
                tmp->next = curr;
            }
            curr = next;
        }
        return prev;


    }
 ListNode* partition(ListNode* head, int x) {
        ListNode* lowstart = new ListNode();
        ListNode* bigstart = new ListNode();
        ListNode* lowsers = lowstart;
        ListNode* biggers = bigstart;
        
        while(head) 
        {
            if(head->val < x) 
            {
                lowers->next = head;
                lowers = lowers->next;
            } 
            else 
            {
                biggers->next = head;
                biggers = biggers->next;
            }
            head = head->next
        }
        lowers->next = bigstart->next;
        biggers->next = nullptr;
        delete lowstart;
        lowstart = nullptr;
        delete bigstart;
        bigstart = nullptr;
        return lowers->next;
    }
