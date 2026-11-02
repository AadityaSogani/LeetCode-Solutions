
#include <iostream>
using namespace std;

// Linked List Node
struct ListNode
{
    int val;
    ListNode* next;

    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

// Add Two Numbers
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = carry;

        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;
        int digit = sum % 10;

        current->next = new ListNode(digit);
        current = current->next;
    }

    return dummy->next;
}

// Create Linked List
ListNode* createList(int n)
{
    int value;

    if (n <= 0)
        return NULL;

    cin >> value;

    ListNode* head = new ListNode(value);
    ListNode* temp = head;

    for (int i = 1; i < n; i++)
    {
        cin >> value;

        temp->next = new ListNode(value);
        temp = temp->next;
    }

    return head;
}

// Display Linked List
void displayList(ListNode* head)
{
    while (head != NULL)
    {
        cout << head->val;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

// Main Function
int main()
{
    int n1, n2;

    cout << "Enter number of nodes in first list: ";
    cin >> n1;

    cout << "Enter digits of first list: ";
    ListNode* l1 = createList(n1);

    cout << "Enter number of nodes in second list: ";
    cin >> n2;

    cout << "Enter digits of second list: ";
    ListNode* l2 = createList(n2);

    ListNode* result = addTwoNumbers(l1, l2);

    cout << "\nResult: ";
    displayList(result);

    return 0;
}
