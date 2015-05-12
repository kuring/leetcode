#include <string>
#include <iostream>
#include <vector>

using namespace std;

void combine(int start, int n, int k, vector<int> value, vector<vector<int>> &result)
{
	// ������������������뼯����
	if (k == 0)
	{
		result.push_back(value);
		return ;
	}
	
	// �������������
	if (n - start + 1 < k)
	{
		return ;
	}
	
	for (int i = start; i <= n; i++)
	{
		auto tmp = value;
		tmp.push_back(i);
		combine(i + 1, n, k - 1, tmp, result);
	}
}

/**
 * ���õݹ�ʵ�ֵ�������ȫ��������
 */
vector<vector<int>> combine(int n, int k)
{
	vector<vector<int>> result;
	if (k > 0 && n >= k)
	{
		combine(1, n, k, {}, result);
	}
	return result;
}

int main()
{
    vector<vector<int> > result = combine(1, 1);
    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 1;
}