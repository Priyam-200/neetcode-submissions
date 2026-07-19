class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!="*" && s[i]!="/" && s[i]!="+" && s[i]!="-"){
                int p=stoi(s[i]);
                st.push(p);
            }
            else{
                if(s[i]=="+"){
                    int ans=0;
                    ans+=st.top();
                    st.pop();
                    ans+=st.top();
                    st.pop();
                    st.push(ans);
                }
                else if(s[i]=="-"){
                    int ans=0;
                    ans-=st.top();
                    st.pop();
                    ans+=st.top();
                    st.pop();
                    st.push(ans);
                }
                else if(s[i]=="*"){
                    int ans=1;
                    ans*=st.top();
                    st.pop();
                    ans*=st.top();
                    st.pop();
                    st.push(ans);
                }
                else{
                    int elem=st.top();
                    st.pop();
                    int ans=(st.top()/elem);
                    st.pop();
                    st.push(ans);
                }
            }
        }
        return st.top();
    }
};
