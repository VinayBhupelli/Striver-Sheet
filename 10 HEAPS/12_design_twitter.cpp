#include <bits/stdc++.h>
using namespace std;

class Twitter
{
private:
    unordered_map<int, set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int time;

public:
    Twitter()
    {
        time = 0;
    }

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId)
    {
        priority_queue<pair<int, int>> maxHeap;
        // get the userId tweets first
        for (auto x : tweets[userId])
            maxHeap.push(x);

        // Also get his following tweets
        for (auto x : following[userId])
            for (auto y : tweets[x])
                maxHeap.push(y);
        // Take the recent 10 tweets
        vector<int> res;
        while (!maxHeap.empty())
        {
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
            if (res.size() == 10)
                break;
        }
        return res;
    }

    void follow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
            following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */