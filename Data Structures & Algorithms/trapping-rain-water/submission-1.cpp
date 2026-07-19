class Solution {
public:
    int trap(vector<int>& heights) {
        int n=heights.size();
        vector<int>pref(n);
        vector<int>suff(n);
        pref[0]=heights[0];
        for(int i=1;i<n;i++){
            pref[i]=max(heights[i],pref[i-1]);
        }
        suff[n-1]=heights[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=max(suff[i+1],heights[i]);
        }

        vector<int>water(n);
        for(int i=0;i<n;i++){
            water[i]=(min(pref[i],suff[i])-heights[i]);
        }
        int sum=accumulate(water.begin(),water.end(),0);
        return sum;
    }
};
