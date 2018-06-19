#include <string>

using namespace std;

class myAtoi {
public:
    int solve(string str) {
        int num = 0;
        int next = 0;
        int max = INT32_MAX / 10;
        int max_low = INT32_MAX % 10;
        int min = -(INT32_MIN / 10);
        int min_low = (10 - (INT32_MIN % 10)) % 10;
        bool sign = true;
        bool getting = false;
        for(auto itr = str.begin();itr!=str.end();itr++)
        {
            if (getting) {
                if (*itr >= '0' && *itr <= '9') {
                    next = *itr-'0';
                    if (sign) {
                        if (num > max || (num == max && next > max_low)) {
                            return INT32_MAX;
                        }
                        num = num * 10 + next;
                    } else {
                        if (num > min || (num == min && next > max_low)) {
                            return INT32_MIN;
                        }
                        num = num * 10 + next;   
                    }
                } else {
                    if (sign) {
                        return num;
                    }
                    return -num;
                }
            } else {
                if (*itr >= '0' && *itr <= '9') {
                    getting = true;
                    num = *itr-'0';
                    continue;
                }
                if (*itr == '-') {
                    getting = true;
                    sign = false;
                    continue;
                }
                if (*itr == '+') {
                    getting = true;
                    sign = true;
                    continue;
                }
                if (*itr == ' ') {
                    sign = true;
                    continue;
                }
                return 0;
            }
        }
        if (sign) {
            return num;
        }
        return -num;
    }
};