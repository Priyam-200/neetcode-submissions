
class Twitter{
    struct Tweet{
        int time;
        int tweetId;
        Tweet(int t,int id){
            time=t;
            tweetId=id;
        }
    };
    struct cmp{
    bool operator()(const Tweet &a,const Tweet &b){
        return a.time > b.time;
    }
};
    int time;
    unordered_map<int,vector<Tweet>>post;
    unordered_map<int,unordered_set<int>>following;
public:
    Twitter()
    {
       time=0;
    }

    void postTweet(int userId, int tweetId)
    {
       post[userId].push_back(Tweet(time++,tweetId));
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<Tweet,vector<Tweet>,cmp>pq;
        if(post.find(userId)!=post.end()){
            for(auto it:post[userId]){
                pq.push(it);
                if(pq.size()>10){
                    pq.pop();
                }
            }
        }

        if(following.find(userId)!=following.end()){
            for(auto it:following[userId]){
                int followeeId=it;
                if(post.find(followeeId)!=post.end()){
                    for(auto it:post[followeeId]){
                        pq.push(it);
                        if(pq.size()>10){
                            pq.pop();
                        }
                    }
                }
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            auto [time,tweetId]=pq.top();
            pq.pop();
            ans.push_back(tweetId);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        if(followerId==followeeId){
            return;
        }
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if(following.find(followerId)!=following.end()){
            following[followerId].erase(followeeId);
        }
    }
};