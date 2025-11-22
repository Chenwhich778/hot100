#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return{};
    }
};

int main(){
    Solution solution;
    
    // Test case
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    
    vector<int> result = solution.twoSum(nums, target);
    
    cout << "Index: [" << result[0] << ", " << result[1] << "]" << endl;
    cout << "Values: [" << nums[result[0]] << ", " << nums[result[1]] << "]" << endl;
    
    return 0;
}