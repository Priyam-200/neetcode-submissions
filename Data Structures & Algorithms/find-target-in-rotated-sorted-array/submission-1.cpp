class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        int s=0,e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(mid+1<n && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[s]>nums[mid]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return n-1;
    }
    int BinarySearch(vector<int> &nums,int s,int e,int target) {
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int index=findMin(arr);
        int ans1=BinarySearch(arr,0,index,target);
        int ans2=BinarySearch(arr,index+1,n-1,target);
        return ans1==-1?ans2:ans1;
    }
};
