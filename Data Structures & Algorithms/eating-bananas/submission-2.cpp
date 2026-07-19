class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        long long s=1;
        long long e=*max_element(piles.begin(),piles.end());
        long long ans=LLONG_MAX;
        while(s<=e){
            long long mid=s+(e-s)/2;
            long long time=0;
            for(int i=0;i<n;i++){
                time+=(ceil((double)piles[i]/mid));
            }
            if(time<=h){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};
