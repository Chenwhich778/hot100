#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(string&s:strs){
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());// 它直接对字符串的字符进行排序，例如 "eat" -> "aet"
            m[sorted_s].push_back(s);
        }

        vector<vector<string>> ans;
        ans.reserve(m.size());

        for (auto& [_, value] : m){
            ans.push_back(value);
        }
        return ans;
    }
};