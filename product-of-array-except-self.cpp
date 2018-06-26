#include <vector>
#include <iostream>

using namespace std;

class productExceptSelf
{
  public:
    vector<int> solve(vector<int> &nums)
    {
        int tmp, length = nums.size();
        vector<int> res(length);
        res[0] = 1;
        for (int i = 1; i != length; i++)
        {
            res[i] = res[i - 1] * nums[i - 1];
        }
        tmp = 1;
        for (int i = length - 2; i >= 0; i--)
        {
            tmp = tmp * nums[i+1];
            res[i] *= tmp;
        }
        return res;
    }

    vector<int> old_solve(vector<int> &nums)
    {
        int length = nums.size();
        int product;
        vector<int> res(length, 1);
        for (int i = 0; i != length; i++)
        {
            product = 1;
            for (int j = 0; j != length; j++)
            {
                if (i != j)
                {
                    product *= nums[j];
                }
            }
            res[i] = product;
        }
        return res;
    }
};