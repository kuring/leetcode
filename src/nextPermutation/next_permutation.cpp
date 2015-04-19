#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 从最后一个位置开始搜索
 * 如果最后一位大于倒数第二位，则将两个变换位置。如：1 2 3 4 变换为 1 2 4 3
 * 如果最后一位小于等于倒数第二位，则依次向前查找。如果找到一个比已经遍历集合中小的值，则将遍历集合中比该值大的元素移动到比较的元素位置，并将比较的元素按正序排序。如1 2 4 6 5 3 将转变为 1 2 5 3 4 6。其中4为要比较的元素，5是已经遍历的元素中比4稍大的元素。
 * 如果集合中的顺序已经按照倒序排序完毕，则将集合翻转。
 *
 * 在STL中存在该函数
 */
void nextPermutation(vector<int> &num)
{
    size_t length = num.size();
    if (length < 2)
    {
        return ;
    }
    else if (length == 2)
    {
        swap(num[0], num[1]);
        return ;
    }
    else if (num[length - 1] > num[length -2])
    {
        swap(num[length - 1], num[length - 2]);
        return ;
    }

    bool flag = false;
    for (vector<int>::iterator iter = num.end() - 2; iter >= num.begin(); iter--)
    {
        if (*iter < *(iter + 1))
        {
            // 找到可以替换的元素，可替换的元素为从数组的末尾数第一个比*iter大的元素
            vector<int>::iterator iter2 = num.end() - 1;
            for (; iter2 > iter; iter2--)
            {
                if (*iter2 > *iter)
                {
                    break;
                }
            }

            // 交换位置
            swap(*iter, *iter2);

            // 对num[i]之后的元素进行正序排序
            sort(iter + 1, num.end());

            flag = true;
            break;
        }
    }

    // 整个集合已经倒序有序，按正序排列
    if (flag == false)
    {
        sort(num.begin(), num.end());
    }
}
int main()
{
    int arr[] = {2, 3, 1};
    vector<int> num(arr, arr + sizeof(arr) / sizeof(int));
    nextPermutation(num);
    for (size_t i = 0; i < num.size(); i++)
    {
        cout << num[i] << " ";
    }
    cout << endl;
    return 1;
}
