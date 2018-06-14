#include <iostream>
#include <string>
using namespace std;

typedef struct
{
    int64_t xnum;
    int64_t num;
} eqn;

class solveEquation
{
    int64_t num = 0, lx = 0;
    void parse(eqn *now)
    {
        // cout<<num<<" "<<lx<<endl;
        if (lx != 0)
        {
            now->xnum += num;
        }
        else
        {
            now->num += num;
        }
        num = 0;
        lx = 0;
    }
  public:
    string solve(string equation)
    {
        eqn left, right, *now;
        left.num = 0;
        left.xnum = 0;
        right.num = 0;
        right.xnum = 0;
        now = &left;
        num = 0;
        lx = 0;

        for (auto itr = equation.begin(); itr != equation.end(); itr++)
        {
            switch (*itr)
            {
            case '-':
                parse(now);
                num = INT64_MIN;
                break;
            case '+':
                parse(now);
                break;
            case '=':
                parse(now);
                now = &right;
                break;
            case 'x':
                if (num == 0)
                {
                    if ((itr-1) >= equation.begin() && *(itr - 1) == '0') {
                        num = 0;
                    } else {
                        num = 1;
                    }
                } else if (num == INT64_MIN){
                    num = -1;
                }
                lx = 1;
                break;
            default:
                if (*itr >= '0' && *itr <= '9')
                {
                    if (num == 0)
                    {
                        num = *itr - '0';
                    }
                    else if (num == INT64_MIN)
                    {
                        num = -(*itr - '0');
                    }
                    else
                    {
                        num = (num / abs(num)) * (abs(num) * 10 + (*itr-'0'));
                    }
                    // cout<<num<<endl;
                }
            }
        }
        parse(now);
        // cout<<"left "<<left.xnum<<" "<<left.num<<endl;
        // cout<<"right "<<right.xnum<<" "<<right.num<<endl;
        lx = left.xnum - right.xnum;
        num = right.num - left.num;
        // cout << lx << "x=" << num << endl;
        if (lx == 0 && num == 0)
        {
            return string("Infinite solutions");
        }
        if (lx == 0)
        {
            return string("No solution");
        }
        string res;
        res.assign("x=");
        res.append(to_string(num / lx));
        return res;
    }
};
