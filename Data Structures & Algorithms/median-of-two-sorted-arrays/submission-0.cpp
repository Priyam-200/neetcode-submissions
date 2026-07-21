class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums;
        int l=nums1.size();
        int m=nums2.size();
        for(int i=0;i<l;i++){
            nums.push_back(nums1[i]);
        }
        for(int i=0;i<m;i++){
            nums.push_back(nums2[i]);
        }

        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n%2==1){
            return double(nums[n/2]);
        }
        else {
            double ans=((nums[n/2]+nums[(n/2)-1])/(double)2.0);
            return ans;
        }
    }

};
