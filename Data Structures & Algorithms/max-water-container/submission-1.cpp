class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0,j=n-1;
        int maxi=0;
        while(i<j){
            if(heights[i]<heights[j]){
                int ans=min(heights[i],heights[j]);
                maxi=max(maxi,ans*(j-i));
                i++;
            }
            else{
                int ans=min(heights[i],heights[j]);
                maxi=max(maxi,ans*(j-i));
                j--;
            }
        }
        return maxi;
    }
};
