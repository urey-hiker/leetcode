#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class findMedianSortedArrays {
public:

    double solve(vector<int>& nums1, vector<int>& nums2) {
        double tmp = ((double)nums1.size() + (double)nums2.size()) / 2 - 1;
        int mid = ceil(tmp);
        int mid1 = floor(tmp+1);
        int minus = 0;
        auto start1 = nums1.begin();
        auto start2 = nums2.begin();
        auto end1 = nums1.end();
        auto end2 = nums2.end();
        
        while (mid > 0) {
            
            if (start1 == end1) {
                return (double)(*(start2+mid) + *(start2+mid1)) / 2.0;
            }
            if (start2 == end2) {
                return (double)(*(start1+mid) + *(start1+mid1)) / 2.0;
            }
            auto half1 = min(start1 + mid / 2, (end1 - 1 - start1) / 2 + start1);
            auto half2 = min(start2 + mid / 2, (end2 - 1 - start2) / 2 + start2);
            
            // cout<<*start1<<" "<<*half1<<" "<<*start2<<" "<<*half2<<" "<<mid<<" "<<mid1<<endl;
            // cout<<half1 - start1<<" "<<half2 - start2<<endl;
            if (half1 - start1 >= mid - 2 || half2 - start2 >= mid - 2 || half1 == start1 || half2 == start2) {
                if (*start1 < *start2) {
                    start1++;
                    mid -= 1;
                    mid1 -= 1;
                } else if (*start1 > *start2) {
                    start2++;
                    mid -= 1;
                    mid1 -= 1;
                } else {
                    if (start1+1 == end1) {
                        start1++;
                        mid -= 1;
                        mid1 -= 1;
                    } else if (start2+1 == end2) {
                        start2++;
                        mid -= 1;
                        mid1 -= 1;
                    } else if (*(start1+1) < *(start2+1)) {
                        start1++;
                        mid-=1;
                        mid1 -= 1;
                    } else {
                        start2++;
                        mid-=1;
                        mid1 -= 1;
                    }
                }
                continue;
            }
            if (*half1 < *half2) {
                minus = half1 - start1;
                mid -= minus;
                mid1 -= minus;
                end2 = min(start2 + mid + 2 ,end2);
                start1 = half1;
            } else {
                minus = half2 - start2;
                mid -= minus;
                mid1 -= minus;
                end1 = min(start1 + mid + 2, end1);
                start2 = half2;
            }
        }
        // cout<<*start1<<" "<<*start2<<" "<<mid<<" "<<mid1<<endl;
        if (start1 == end1) {
            return (*(start2+mid) + *(start2+mid1)) / 2.0;
        }
        if (start2 == end2) {
            return (*(start1+mid) + *(start1+mid1)) / 2.0;
        }
        if (mid == mid1) {
            return *start1 < *start2?*start1:*start2;
        }
        if (*start1 == *start2) {
            return (double)(*start1+*start2)/2.0;
        }
        if (*start1 < *start2) {
            if (start1+1 != end1 && *(start1 + 1) < *start2) {
                return (double)(*start1+*(start1+1))/2.0;
            }
            return (double)(*start1+*start2)/2.0;
        }
        if (start2+1 != end2 && *(start2 + 1) < *start1) {
            return (double)(*start2+*(start2+1))/2.0;
        }
        return (double)(*start1+*start2)/2.0;
    };
};