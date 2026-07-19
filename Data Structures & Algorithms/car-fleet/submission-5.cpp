class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        vector<pair<int,int>>ans(n);
        for(int i=0;i<n;i++){
            ans[i]={position[i],speed[i]};
        }

        sort(ans.begin(),ans.end());
        stack<float>st;
        for(int i=0;i<n;i++){
            float time=((target-ans[i].first)/(float)ans[i].second);
            while(!st.empty() && st.top()<=time){
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};
