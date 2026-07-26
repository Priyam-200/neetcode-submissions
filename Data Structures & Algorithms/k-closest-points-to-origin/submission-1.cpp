class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<vector<int>>pq;

        int n=points.size();
        for(int i=0;i<n;i++){
            int dist=((points[i][0]*points[i][0])+(points[i][1]*points[i][1]));
            pq.push({dist,points[i][0],points[i][1]});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(k){
            auto front=pq.top();
            pq.pop();
            ans.push_back({front[1],front[2]});
            k--;
        }
        return ans;
    }
};
