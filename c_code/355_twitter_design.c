// ˼·��
// ���� �� ������ɢ��
// tweetһ������
// userһ������
// �ο����ӣ�https://leetcode-cn.com/problems/design-twitter/solution/cyu-yan-dan-lian-biao-shu-zu-san-lie-biao-by-dingj/

#define MAX_SIZE 1024

typedef struct StruUser {
    int userId;
    int followee[MAX_SIZE];
    struct StruUser *next;
} User;

typedef struct StruTweet {
    int userId;
    int tweetId;
    struct StruTweet *next;
} Tweet;

typedef struct {
    User *user;
    Tweet *tweet;
} Twitter;

/** Initialize your data structure here. */

Twitter* twitterCreate() {
    Twitter *obj = (Twitter *)malloc(sizeof(Twitter));
    if (obj == NULL) {
        return NULL;
    }
    User *user = (User *)malloc(sizeof(User));
    memset(user->followee, sizeof(int) * MAX_SIZE, 0);
    Tweet *tweet = (Tweet *)malloc(sizeof(Tweet));
    user->next = NULL;
    tweet->next = NULL;
    obj->user = user;
    obj->tweet = tweet;
    return obj;
}

/** Compose a new tweet. */
void twitterPostTweet(Twitter* obj, int userId, int tweetId) {
    Tweet *tweet = (Tweet *)malloc(sizeof(Tweet));
    tweet->userId = userId;
    tweet->tweetId = tweetId;
    tweet->next = obj->tweet->next; // ��ͷ�ڵ����һ���ڵ�
    obj->tweet->next = tweet;
    twitterFollow(obj, userId, 0);  // �ж�userId�Ƿ���ϵͳ������������ϵͳ��0��ʾ��ע�Լ�
}

/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
int* twitterGetNewsFeed(Twitter* obj, int userId, int* retSize) {
    int *res = (int*)malloc(10 * sizeof(int));

    User *user = obj->user;
    while (user != NULL) { // �ҵ���ǰuser��Ϣ
        if (user->userId == userId) {
            break;
        }
        user = user->next;
    }
    if (user == NULL) {
        return NULL; // error, ��ǰ�û���������ϵͳ��
    }

    int i = 0;
    Tweet *tweet = obj->tweet->next; // ��ͷ�ڵ����һ���ڵ㿪ʼ
    while (tweet != NULL && i < 10) { // �ҵ���ǰuser�����ע�ߵ�ǰ10������
        if (tweet->userId == userId || user->followee[tweet->userId] == 1) { // ��ǰ�û������������ע��
            // printf("tweet->tweetId: %d\n", tweet->tweetId);
            res[i] = tweet->tweetId;
            i++;
        }
        tweet = tweet->next;
    }
    *retSize = i; // ʵ��չʾ���������� <=10

    return res;
}

/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
void twitterFollow(Twitter* obj, int followerId, int followeeId) {
    User *user = obj->user;
    while (user != NULL) { // �ҵ���ǰuser��Ϣ
        if (user->userId == followerId) {
            break;
        }
        user = user->next;
    }
    if (user == NULL) { // ��ǰ�û���������ϵͳ��
        user = (User *)malloc(sizeof(User));
        memset(user->followee, sizeof(int) * MAX_SIZE, 0);
        user->userId = followerId;
        user->next = obj->user->next;
        obj->user->next = user;        
    }
    user->followee[followeeId] = 1; // ��ע
    return;
}

/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
void twitterUnfollow(Twitter* obj, int followerId, int followeeId) {
    User *user = obj->user;
    while (user != NULL) { // �ҵ���ǰuser��Ϣ
        if (user->userId == followerId) {
            break;
        }
        user = user->next;
    }
    if (user == NULL) {
        return; // error, ��ǰ�û���������ϵͳ��
    }

    user->followee[followeeId] = 0; // ��ע
    return;
}

void twitterFree(Twitter* obj) {
    if (obj != NULL && obj->tweet != NULL) {
        free(obj->tweet);
        obj->tweet = NULL;
    }
    if (obj != NULL && obj->user != NULL) {
        free(obj->user);
        obj->user = NULL;
    }
    if (obj != NULL) {
        free(obj);
        obj = NULL;
    }
    return;
}

/**
 * Your Twitter struct will be instantiated and called as such:
 * Twitter* obj = twitterCreate();
 * twitterPostTweet(obj, userId, tweetId);
 
 * int* param_2 = twitterGetNewsFeed(obj, userId, retSize);
 
 * twitterFollow(obj, followerId, followeeId);
 
 * twitterUnfollow(obj, followerId, followeeId);
 
 * twitterFree(obj);
*/