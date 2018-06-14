#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

class longestPalindrome
{
  public:
    string solve(string s)
    {
        auto len = s.size();
        auto vec = new int[len * (len+1)];
        auto p = vec;
        int start = 0, end = 0, max = 1, last = 0, now = 0;
        memset(vec, 0, sizeof(int)*len * (len+1));
        for (auto i = 0; i != len; i++)
        {
            vec[i * len + i] = 1;
            // vec[i * len + i+1] = 0;
        }

        for (auto i = 1; i != len; i++)
        {
            // now = 0;
            for (auto j = 0; j + i != len; j++)
            {
                if (s[j] == s[j + i])
                {
                    now = vec[(j + 1) * len + j + i - 1] + 2;
                }
                else
                {
                    now = 1;
                }
                if (now <= i)
                {
                    now = 1;
                }
                vec[j * len + j + i] = now;
                if (now > max)
                {
                    start = j;
                    end = j + i;
                    max = now;
                    // cout << max << j<<" "<<j+i<<endl;
                    // cout<<(new string)->assign(s, start, end - start + 1)<<endl;
                }
            }
        }
        string res;
        return res.assign(s, start, end - start + 1);
    }
};
