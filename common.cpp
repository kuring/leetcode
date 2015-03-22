#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *create_binary_tree(int arr[], int size)
{
    if (size <= 0)
    {
        return NULL;
    }

    TreeNode **node = new TreeNode*[size];
    for (int i=0; i<size; i++)
    {
        if (arr[i] == '#')
        {
            node[i] = NULL;
        }
        else
        {
            node[i] = new TreeNode(arr[i]);
        }
    }

    int pos = 1;
    for (int i=0; i<size && pos < size; i++)
    {
        if (node[i])
        {
            node[i]->left = node[pos++];
            if (pos < size)
            {
                node[i]->right = node[pos++];
            }
        }
    }

    return node[0];
}

/**
 * 采用广度优先搜索的方式对二叉树进行打印
 */
void print_binary_tree(TreeNode *root)
{
    if (root == NULL)
    {
        std::cout <<  "# ";
        return ;
    }

    std::queue<TreeNode *> travel_queue;
    travel_queue.push(root);
    while (travel_queue.size() > 0)
    {
        TreeNode *node = travel_queue.front();
        travel_queue.pop();
        std::cout << node->val << " ";
        if (node->left != NULL)
        {
            travel_queue.push(node->left);
        }
        if (node->right != NULL)
        {
            travel_queue.push(node->right);
        }
    }
}

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
}

int main()
{
    // init tree
    int arr[] = {1, 2, 3, 4, 5, 6};
    TreeNode *root = create_binary_tree(arr, 6);
    print_binary_tree(root);

    // init list
    ListNode *head = create_list(arr, 6);
    print_list(head);

    // init vector
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    return 1;
}
