class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int num=-1;
    KthLargest(int k, vector<int>& nums) {
        num=k;
        for(auto it:nums){
            pq.push(it);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>num){
            pq.pop();
        }
        return pq.top();
    }
};
