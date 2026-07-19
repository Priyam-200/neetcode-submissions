class Solution {
public:
    void solve(vector<int>& temperatures,vector<int>&next){
        stack<int>st;
        st.push(-1);
        int n=next.size();
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            next[i]=st.top();
            st.push(i);
        }
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>next(n);
        solve(temperatures,next);

        vector<int>ans;
        for(int i=0;i<n;i++){
            if(next[i]==-1){
                ans.push_back(0);
            }
            else{
                ans.push_back(next[i]-i);
            }
        }
        return ans;
    }
};
