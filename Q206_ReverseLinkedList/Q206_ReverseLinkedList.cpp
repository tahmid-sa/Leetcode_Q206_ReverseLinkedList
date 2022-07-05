#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next = curr->next;

    while (curr != nullptr) {
        curr->next = prev;

        prev = curr;
        curr = next;

        if (next != nullptr) {
            next = next->next;
        }
    }

    return prev;
}

int main()
{
    ListNode n3(3, nullptr);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);

    ListNode* head = reverseList(&n1);

    for (ListNode* tmp = head; tmp != nullptr; tmp = tmp->next) {
        cout << tmp->val << endl;
    }

    return 0;
}
