#include <iostream>
#include <vector>

using namespace std;

/**
 *  注意需要进位时的处理和最后一位进位时需要增加元素
 */
vector<int> plusOne(vector<int> &digits)
{
    for (int i=digits.size() - 1; i >= 0;)
    {
        digits[i] += 1;
        if (digits[i] == 10)
        {
            digits[i] = 0;
            i--;
        }
        else
        {
            return digits;
        }
    }
    digits.insert(digits.begin(), 1); 
    return digits;
}

int main()
{
    int arr[] = {129};
    vector<int> digits(arr, arr + sizeof(arr) / sizeof(int));
    vector<int> result = plusOne(digits);
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
    cout << endl;
}

