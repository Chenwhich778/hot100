#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if (n < 2) return 0;
        int left = 0, right = n - 1;
        int max_area = 0;
        while (left < right) {
            int min_height = min(height[left], height[right]);
            int width = right - left;
            int area = min_height * width;
            max_area = max(max_area, area);
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }
        return max_area;
    }
};