#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        set<int> exists;
        if (!head) {
            return head;
        }
        
        ListNode *curNode = head->next;
        ListNode *preNode = head;
        exists.insert(preNode->val);

        while (curNode) {
            ListNode *temp = curNode;
            while (curNode && exists.find(curNode->val) != exists.end()) {                
                curNode = curNode->next;
            }
                        
            if (curNode != temp) {                
                preNode->next = curNode;                    
            }
            
            if (curNode) {
                exists.insert(curNode->val);
                preNode = curNode;
                curNode = curNode->next;
            }
        }        

        return head;
    }
};

int main() {
    Solution sln;
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);    
    ListNode* head2 = sln.deleteDuplicates(head);

    while (head2) {
        cout << head2->val << endl;
        head2 = head2->next;
    }

    return 0;
}