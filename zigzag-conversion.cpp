#include <string>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class zigzagConvert
{
  public:
    string solve(string s, int numRows)
    {
        int size = s.size();
        if (size < 3 ||numRows < 2) {
            return s;
        }
        int numCols = numRows - 1;
        int totCols = ceil(numCols*(double(size) / double(numCols+numRows-1)));
        cout<<size<<" "<<numCols+numRows-1<<endl;
        cout<<totCols<<" "<<totCols * numRows<<endl;
        auto vec = new int[totCols * numRows];
        memset(vec, 0, sizeof(int) * totCols * numRows);
        int c = 0, r = 0;
        for (auto itr = s.begin(); itr != s.end(); itr++)
        {
            vec[c * totCols + r] = *itr;
            // cout<<c<<" "<<r<<endl;
            if (r % numCols == 0)
            {
                c++;
                if (c == numRows)
                {
                    c -= 2;
                    r += 1;
                }
            }
            else
            {
                c--;
                r++;
            }
        }
        string res;
        for(auto i=0;i<totCols*numRows;i++) {
            if (vec[i]!= 0){
                res.push_back(vec[i]);
            }
        }

        return res;
    }
    string solve2(string s, int numRows)
    {
        int size = s.size();
        if (size < 3 ||numRows < 2) {
            return s;
        }
        int numCols = numRows - 1;
        int interval =numRows+numCols-1;
        string res;
        for(auto i=0;i<numRows;i++) {
            if (i == 0 || i == numRows-1) {
                auto t = i;
                while (t<size) {
                    
                    res.push_back(s[t]);
                    t+=interval;
                    // cout<<s[t]<<endl;
                }
                continue;
            }
            auto t1 = i, t2 = interval-i;
            while(t1<size || t2<size) {
                if (t1<size) {
                    res.push_back(s[t1]);
                    // cout<<s[t]<<endl;
                    t1+=interval;
                }
                if (t2<size) {
                    res.push_back(s[t2]);
                    t2+=interval;
                }
            }
        }
        return res;
    }
};