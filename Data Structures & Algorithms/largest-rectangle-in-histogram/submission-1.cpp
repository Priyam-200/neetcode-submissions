class Solution {
public:
    void solve1(vector<int>&next,vector<int>& heights){
        stack<int>st;
        st.push(-1);
        int n=heights.size();
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            next[i]=st.top();
            st.push(i);
        }
    }
    void solve2(vector<int>&prev,vector<int>& heights){
        stack<int>st;
        st.push(-1);
        int n=heights.size();
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            prev[i]=st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next(n);
        vector<int>prev(n);
        solve1(next,heights);
        solve2(prev,heights);
        for(int i=0;i<n;i++){
            if(next[i]==-1){
                next[i]=n;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,heights[i]*(next[i]-prev[i]-1));
        }
        return ans;
    }
};
