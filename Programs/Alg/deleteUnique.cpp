#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteUnique(ListNode* head) {
    if (head == nullptr) 
        return head;

    if (head->next == nullptr)
        return nullptr;

    ListNode *curr = head, *tmp = head;

    while (head->next != nullptr) {
        if (head->val != head->next->val) {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        else {
            break;
        }
    }

    if (head == nullptr || head->next == nullptr)
        return nullptr;

    
    curr = head;

    while (curr->next->next != nullptr) {
        if (curr->val != curr->next->val) {
            if (curr->next->val != curr->next->next->val) {
                tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
            } else {
                curr = curr->next;
            }
        } else {
            curr = curr->next;
        }
    }

    if (curr->val != curr->next->val) {
        tmp = curr->next;
        curr->next = nullptr;
        delete tmp;
    }

    return head;
}

int main() {
    ListNode *p1 = new ListNode(5);
    ListNode *p2 = new ListNode(4);
    ListNode *p3 = new ListNode(4);
    ListNode *p4 = new ListNode(3);
    ListNode *p5 = new ListNode(3);
    ListNode *p6 = new ListNode(2);
    ListNode *p7 = new ListNode(1);

    p7->next = p6;
    p6->next = p5;
    p5->next = p4;
    p4->next = p3;
    p3->next = p2;
    p2->next = p1;

    ListNode *curr = deleteUnique(p7);

    while (curr != nullptr) {
        std::cout << curr->val << std::endl;
        curr = curr->next;
    }

    return 0;
}