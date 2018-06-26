#include <vector>
#include <iostream>

using namespace std;
class spiralOrder {
public:
    vector<int> solve(vector<vector<int>>& matrix) {
        int height = matrix.size();
        if (height == 0) {
            return vector<int>();
        }
        int weight = matrix[0].size();
        if (weight == 0) {
            return vector<int>();
        }
        vector<int> res(height*weight);
        int i=0,j=0;
        int si=0,sj=0;
        int hd=height,wd=weight;
        
        auto itr = res.begin();
        while(wd>0 && hd>0) {
            // cout<<hd<<" "<<wd<<endl;
            for(i=0;i<wd;i++) {
                *itr = matrix[sj][si+i];
                // cout<<sj<<" "<<si+i<<" "<<*itr<<endl;
                itr++;
            }
            si = si+i-1;
            for(j=1;j<hd;j++) {
                *itr = matrix[j+sj][si];
                // cout<<j+sj<<" "<<si<<" "<<*itr<<endl;
                itr++;
            }
            sj = sj+j-1;
            hd-=1;
            for(i=1;i<wd && hd>0;i++) {
                *itr = matrix[sj][si-i];
                // cout<<sj<<" "<<si-i<<" "<<*itr<<endl;
                itr++;
            }
            si = si-i+1;
            wd-=1;
            for(j=1;j<hd && wd>0;j++) {
                *itr = matrix[sj-j][si];
                // cout<<sj-j<<" "<<si<<" "<<*itr<<endl;
                itr++;
            }
            sj = sj-j+1;
            si = si+1;
            wd -= 1;
            hd -= 1;
        }
        return res;
    }
};