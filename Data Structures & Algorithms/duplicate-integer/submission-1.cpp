class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,bool>mp;
        for(int i=0;i<n;i++){
            if(mp[nums[i]]==true){
                return true;
            }
            else{
                mp[nums[i]]=true;
            }
        }
        return false;
    }
};