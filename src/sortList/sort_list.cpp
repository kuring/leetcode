#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

/**
 * 使用归并排序方法，核心思想为将数组拆分为两半，分别对两半进行排序，排序完成后再进行一次排序，排序算法就可以采用插入排序的方式。
 * 对两半排序的算法仍然采用归并排序算法，即问题为递归问题
 * 在使用线性存储结果的归并排序算法中，会使用额外的空间来存储临时结果，空间复杂度为O(n)，而在链式存储中，空间复杂度为O(1)
 * 归并排序的时间复杂度为O(nlogn)
 * 如果存储结构为双向链表，可以使用快速排序
 */
ListNode* sortList(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    if (head->next->next == nullptr)
    {
        // 仅有两个元素，对两个元素进行排序后直接返回
        if (head->val < head->next->val)
        {
            return head;
        }
        else
        {
            ListNode *tmp = head->next;
            tmp->next = head;
            tmp->next->next = nullptr;
            return tmp;
        }
    }

    // 为了找到中间节点，这里采用快慢指针的方式，否则需要使用先遍历一次取长度，然后找到中间位置的两次遍历方式
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *slow_prev = nullptr;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow_prev = slow;
        slow = slow->next;
    }
    fast = slow_prev->next;
    slow_prev->next = nullptr;

    // 分别对两段链表进行排序
    slow = sortList(head);
    fast = sortList(fast);

    // 对两段链表进行合并
    ListNode *node = nullptr, *result = nullptr;
    while (slow != nullptr && fast != nullptr)
    {
        if (slow->val < fast->val)
        {
            if (result != nullptr)
            {
                node->next = slow;
                node = node->next;
            }
            else
            {
                node = slow;
                result = slow;
            }
            slow = slow->next;
        }
        else
        {
            if (result != nullptr)
            {
                node->next = fast;
                node = node->next;
            }
            else
            {
                node = fast;
                result = fast;
            }
            fast = fast->next;
        }
    }
    if (slow != nullptr)
    {
        node->next = slow;
    }

    if (fast != nullptr)
    {
        node->next = fast;
    }

    return result;
}

int main()
{
    // init tree
//    int arr[] = {1, 2, 3, 4, 5, 6};
    int arr[] = {8, 5, 9, 3, 7, 2, 3};

    // init list
    ListNode *head = create_list(arr, sizeof(arr) / sizeof(int));
    head = sortList(head);
    cout << "result : ";
    print_list(head);

    return 1;
}
