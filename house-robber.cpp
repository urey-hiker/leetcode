#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef struct
{
    int inuse;
    int now;
} rob_node;

class rob
{
  public:
    int solve(vector<int> &nums)
    {
        int len = nums.size();
        auto vec = new rob_node[len + 2];
        int now = 0, max = 0;
        memset(vec, 0, sizeof(rob_node) * (len + 2));
        auto p = vec + 2;

        for (auto i = 0; i < len; i++)
        {
            now = p[i-2].now + nums[i];
            if (p[i - 1].inuse == 0 || p[i-1].now < now)
            {
                p[i].now = now;
                p[i].inuse = 1;
            } else {
                p[i].now = p[i-1].now;
            }
            if (p[i].now > max) {
                max = p[i].now;
                cout<<max<<" "<<i<<endl;
            }
        }
        return max;
    }
};