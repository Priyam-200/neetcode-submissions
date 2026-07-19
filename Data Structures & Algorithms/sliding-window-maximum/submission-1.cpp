class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int n=nums.size();
        vector<int>ans;
        for(int right=0;right<k;right++){
            while(!dq.empty() && nums[dq.back()]<nums[right]){
                dq.pop_back();
            }
            dq.push_back(right);
        }
        ans.push_back(nums[dq.front()]);

        for(int right=k;right<n;right++){
            while(!dq.empty() && nums[dq.back()]<nums[right]){
                dq.pop_back();
            }
            while(!dq.empty() && right-dq.front()>=k){
                dq.pop_front();
            }
            dq.push_back(right);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
