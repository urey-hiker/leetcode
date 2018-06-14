#include <string>
#include <cstring>
using namespace std;

class lengthOfLongestSubstring {
public:
    int solve(string s) {
        int m[256] = {0};
        int max = 0, now = 0, idx = 0, pos = 0;
        for(auto itr = s.begin(); itr != s.end(); itr++) {
            idx = *itr;
            pos = itr - s.begin() + 1;
            if (m[idx] + now < pos) {
                now += 1;
                m[idx] = pos;
            } else {
                now = pos - m[idx];
                m[idx] = pos;
            }
            if (now > max) {
                max = now;
            }
        }
        return max;
    };
};