#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class maxArea {
    int calcArea(int a, int ai, int b, int bi) {
        return abs(bi - ai) * min(a, b);
    }

   public:
    // 解题思路，每一个点都可以画一条平行于X轴的直线，
    // 直线与不低于于该点的最远点构成的容器是该包含点构成容器的最大容量。
    typedef struct info_s {
        int x;
        int y;
    } info_t;
    static bool compare(info_t &a, info_t &b) { return a.y > b.y; }
    int solve(vector<int> &height) {
        vector<info_t> vec;
        for (int i = 0; i < height.size(); i++) {
            vec.push_back(info_t{i, height[i]});
        }
        sort(vec.begin(), vec.end(), compare);
        // for (int i = 0; i < vec.size(); i++) {
        //     cout << vec[i].y << vec[i].x << endl;
        // }

        int leftMax = 0, rightMax = 0, tmpy = 0, tmpx = 0;
        int tmpArea = 0, leftArea = 0, rightArea = 0, areaMax = 0;
        leftMax = rightMax = vec[0].x;
        for (int i = 1; i < vec.size(); i++) {
            tmpy = vec[i].y;
            tmpx = vec[i].x;
            leftArea = 0;
            rightArea = 0;
            if (leftMax < tmpx) {
                leftArea = calcArea(tmpy, tmpx, height[leftMax], leftMax);
                // cout<<leftMax<<" "<<tmpx<<" "<<leftArea<<"\n";
            } else {
                leftMax = tmpx;
            }
            if (rightMax > tmpx) {
                rightArea = calcArea(tmpy, tmpx, height[rightMax], rightMax);
                // cout<<rightMax<<" "<<tmpx<<" "<<rightArea<<"\n";
            } else {
                rightMax = tmpx;
            }
            tmpArea = max(leftArea, rightArea);
            if (areaMax < tmpArea) {
                areaMax = tmpArea;
            }
        }

        return areaMax;
    }

    int solve2(vector<int> &height) {
        int max = 0, area = 0;
        for (auto i = 0; i < height.size(); i++) {
            for (auto j = i; j < height.size(); j++) {
                area = calcArea(height[i], i, height[j], j);
                if (area > max) {
                    max = area;
                }
            }
        }
        return max;
    }
};