class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            maxi=max(maxi,mp[nums[i]]);
        }

        unordered_map<int,vector<int>>mp1;
        for(auto it:mp){
            mp1[it.second].push_back(it.first);
        }
        vector<int>p;
        for(int i=maxi;i>=1;i--){
            if(k==0){
                break;
            }
            int m=mp1[i].size();
            vector<int>ans=mp1[i];
            for(int j=0;j<m;j++){
                p.push_back(ans[j]);
                k--;
                if(k==0){
                    break;
                }
            }
        }
        return p;
    }
};
