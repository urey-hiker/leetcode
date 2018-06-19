#include <iostream>

using namespace std;

class reverseInteger
{
  public:
    int solve(int x)
    {
        bool sign = (x > 0);
        
        int res = 0, low = 0;
        int max = INT32_MAX / 10;
        int max_low = INT32_MAX % 10;
        int min = -(INT32_MIN / 10);
        int min_low = (10 - (INT32_MIN % 10)) % 10;
        while (x != 0)
        {
            if (sign)
            {
                low = x % 10;
                if (res > max)
                {
                    return 0;
                }
                else if (res == max && low > max_low)
                {
                    // cout<<x<<" "<<low<<" "<<res<<endl;
                    return 0;
                }
                res = res * 10 + low;
                x = x / 10;
            }
            else
            {
                low = (10-(x % 10))%10;
                if (res > min)
                {
                    return 0;
                }
                else if (res == min && low > min_low)
                {
                    return 0;
                }
                res = res * 10 + low;
                x = x / 10;
            }
            // cout<<x<<" "<<low<<" "<<res<<endl;
        }
        if (!sign) {
            res = -res;
        }
        return res;
    }
};