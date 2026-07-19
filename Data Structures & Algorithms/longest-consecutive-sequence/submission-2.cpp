class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(int num : nums){
            mp[num] = true;
        }

        int best = 0;
        for(auto& [num, exists] : mp){
            if(mp.find(num - 1) == mp.end()){
                int length = 1;
                int cur = num;
                while(mp.find(cur + 1) != mp.end()){
                    cur++;
                    length++;
                }
                best = max(best, length);
            }
        }
        return best;
    }
};