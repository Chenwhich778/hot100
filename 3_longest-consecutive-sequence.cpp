#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for(int& num : nums){
            num_set.insert(num);
        }
        int longestStreak = 0;
        for(const int&num : num_set){
            if(!num_set.count(num-1)){//num_set.count(x)是用来检查数字 x是否存在于集合 num_set中
                int currentNum=num;
                int currentStreak =1;

                while (num_set.count(currentNum+1)){
                    currentNum+=1;
                    currentStreak+=1;
                }
                longestStreak=max(longestStreak,currentStreak);
            }
        }
        return longestStreak;
    }
};