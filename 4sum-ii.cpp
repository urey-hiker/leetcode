#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

typedef struct info_s {
    int num;
    int count;
}info;
class fourSumCount
{
  public:
    int solve(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        vector<vector<info>> ab;
        vector<vector<info>> cd;
        int slots = max(C.size()+D.size(), A.size()+B.size())+1;
        ab.assign(slots, vector<info>());
        cd.assign(slots, vector<info>());
        int sum = 0,slot = 0;
        for (auto aitr = A.begin(); aitr != A.end(); aitr++)
        {
            for (auto bitr = B.begin(); bitr != B.end(); bitr++)
            {
                sum = *aitr+*bitr;
                slot = sum%slots;
                if (slot < 0)
                {
                    slot = slot + slots;
                }
                auto st = &ab[slot];
                auto sitr = st->begin();
                for (; sitr != st->end(); sitr++) {
                    if ((*sitr).num == sum) {
                        (*sitr).count++;
                        // cout<<"ab "<<(*sitr).num<<" "<<(*sitr).count<<endl;
                        break;
                    }
                }
                if (sitr == st->end()) {
                    st->push_back(info{sum,1});
                    // cout<<slot<<" ab "<<st[0].num<<" "<<st[0].count<<endl;
                }
            }
        }

        for (auto citr = C.begin(); citr != C.end(); citr++)
        {
            for (auto ditr = D.begin(); ditr != D.end(); ditr++)
            {
                sum = *citr + *ditr;
                slot = sum % slots;
                if (slot < 0)
                {
                    slot = slot + slots;
                }
                auto st = &cd[slot];
                auto sitr = st->begin();
                for (; sitr != st->end(); sitr++)
                {
                    if ((*sitr).num == sum)
                    {
                        (*sitr).count++;
                        // cout<<"cd "<<(*sitr).num<<" "<<(*sitr).count<<endl;
                        break;
                    }
                }
                if (sitr == st->end())
                {
                    st->push_back(info{sum, 1});
                }
            }
        }

        int count = 0, tmpc = 0;
        for (auto aitr = ab.begin(); aitr != ab.end(); aitr++)
        {
            for (auto bitr = (*aitr).begin(); bitr != (*aitr).end(); bitr++) {
                sum = -(*bitr).num;
                tmpc = (*bitr).count;
                slot = sum % slots;
                if (slot < 0)
                {
                    slot = slot + slots;
                }
                auto st = &cd[slot];
                auto sitr = st->begin();
                for (; sitr != st->end(); sitr++) {
                    if ((*sitr).num == sum) {
                        count += (tmpc*(*sitr).count);
                    }
                }
            }
        }
        return count;
    }


    int solve2(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        unordered_map<int,int> ab;
        unordered_map<int,int> cd;
        int count = 0;
        for (auto aitr = A.begin(); aitr != A.end(); aitr++)
        {
            for (auto bitr = B.begin(); bitr != B.end(); bitr++)
            {
                ab[*aitr + *bitr]++;
            }
        }
        
        for (auto citr = C.begin(); citr != C.end(); citr++)
        {
            for (auto ditr = D.begin(); ditr != D.end(); ditr++)
            {
                count += ab[-(*citr+*ditr)];
            }
        }
        return count;
    }
};