#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/**
 * �Ƚϼ򵥵��߼���Ŀ
 */
int removeDuplicates(vector<int>& nums)
{
	if (nums.size() < 3)
	{
		return nums.size();
	}
	
	bool twice = false;
	for (auto iter = nums.begin() + 1; iter != nums.end();)
	{
		cout << "deal " << *iter << endl;
		if (*iter == *(iter - 1))
		{
			if (twice)
			{
				iter = nums.erase(iter);	// erase���������ʧЧ����erase�᷵�ص�������һ��λ��
			}
			else
			{
				twice = true;
				iter++;
			}
		}
		else
		{
			twice = false;
			iter++;
		}
	}
	return nums.size();
}

int main()
{
	vector<int> nums = {1, 1, 1, 2, 2, 3};
	cout << removeDuplicates(nums) << endl;
    for (auto i : nums)
	{
		cout << i << " ";
	}
	cout << endl;
    return 1;
}