#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * 比较简单，注意边界条件的判断，时间复杂度为o(n)
 */
ListNode *swapPairs(ListNode *head)
{
    if (!head)
    {
        return NULL;
    }
    ListNode *node = head;
    ListNode *first = NULL, *second = NULL;
    while (node)
    {
        if (second == NULL)
        {
            second = node;
            node = node->next;
        }
        else
        {
            second->next = node->next;
            node->next = second;
            if (first != NULL)
            {
                first->next = node;
            }
            else
            {
                head = node;
            }
            first = second;
            second = NULL;
            node = first->next;
        }
    }
    return head;
}

ListNode *create_list(int arr[], int size)
{
    if (size == 0)
    {
        return NULL;
    }
    ListNode *head = new ListNode(arr[0]);
    ListNode *node = head;
    for (int i=1; i<size; i++)
    {
        ListNode *tmp = new ListNode(arr[i]);
        node->next = tmp;
        node = node->next;
    }
    return head;
}

void print_list(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4}; 
    ListNode *head = create_list(arr, sizeof(arr) / sizeof(int));
    head = swapPairs(head);
    print_list(head);
    return 1;
}
