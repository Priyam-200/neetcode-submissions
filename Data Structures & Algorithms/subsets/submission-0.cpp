class Solution {
public:
    void solve(vector<int>& nums,vector<int>&ans,int i,set<vector<int>>&st){
        if(i>=nums.size()){
            st.insert(ans);
            return;
        }
        ans.push_back(nums[i]);
        solve(nums,ans,i+1,st);
        ans.pop_back();

        solve(nums,ans,i+1,st);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>>st;
        vector<int>ans;
        solve(nums,ans,0,st);

        vector<vector<int>>p;
        for(auto it:st){
            p.push_back(it);
        }
        return p;
    }
};
