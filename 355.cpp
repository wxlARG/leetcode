#include"common.h"
using namespace std;

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter(): counter(0) {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(user_post[userId].size()>=10) user_post[userId].pop_back();
        user_post[userId].push_front({counter++, tweetId});
        user_follow[userId].insert(userId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto cmp = [&](auto& a, auto& b)  {
            return user_post[a.first][a.second].first<user_post[b.first][b.second].first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for(auto user: user_follow[userId]) {
            if(!user_post[user].empty()) pq.push({user, 0});
        }
        while(!pq.empty() && res.size()<10) {
            auto& item=pq.top();
            res.push_back(user_post[item.first][item.second].second);
            if(item.second+1<user_post[item.first].size()) pq.push({item.first, item.second+1});
            pq.pop();
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        user_follow[followerId].insert(followeeId);
        user_follow[followeeId].insert(followeeId); 
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId) return;
        user_follow[followerId].erase(followeeId); 
    }

private:
    uint64_t counter;
    unordered_map<int, unordered_set<int>> user_follow;
    unordered_map<int, deque<pair<int, int>>> user_post;
};

int main() {
    Twitter twitter;
    twitter.postTweet(1, 5);
    auto res = twitter.getNewsFeed(1);
    for(auto v: res) cout << v << "\t";
    cout << endl;
    twitter.follow(1, 2);
    twitter.postTweet(2, 6);
    res = twitter.getNewsFeed(1);
    for(auto v: res) cout << v << "\t";
    cout << endl;
    twitter.unfollow(1, 2);
    res = twitter.getNewsFeed(1);
    for(auto v: res) cout << v << "\t";
    cout << endl;
}
