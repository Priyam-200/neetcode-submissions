//Brute force
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(nums[i]+nums[j]==target){
//                     return {i,j};
//                 }
//             }
//         }
//     }
// };


//optimised approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp.find(target-nums[i])!=mp.end() && mp[target-nums[i]]!=i){
                return {mp[target-nums[i]],i};
            }
            else{
                mp[nums[i]]=i;
            }
        }
    }
};

