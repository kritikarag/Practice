#include <bits/stdc++.h>
using namespace std;

int dp[(1 << 16) + 1];
unordered_map<int, unordered_set<int>> mpp; // book -> skill
vector<vector<int>> books;
vector<int> req_skill;
int n, m;

int helper(int mask, int currBook)
{
    if (mask == (1 << n) - 1)
    { // if every skill is acquired
        return 0;
    }

    if (currBook == m)
    {
        return INT_MAX / 2;
    }

    if (dp[mask] != -1)
    {
        return dp[mask];
    }

    int IGNORE = helper(mask, currBook + 1); // IGNORE CURRENT SKILL BOOK

    int ACCEPT = INT_MAX / 2; // ACCEPT CURRENT SKILL BOOK
    bool newSkillAcquired = false;
    int newMask = mask;
    for (int skill = 0; skill < n; skill++)
    {
        if (newMask & (1 << skill))
        { // already this skill is acquired
            continue;
        }
        if (mpp[currBook].find(req_skill[skill] - 1) == mpp[currBook].end())
        { // skill not present in book
            continue;
        }
        newMask = newMask | (1 << skill);
        newSkillAcquired = true;
    }
    if (newSkillAcquired == true)
    {
        ACCEPT = books[currBook][0] + helper(newMask, currBook + 1);
    }

    return dp[mask] = min(IGNORE, ACCEPT);
}

int minCost(vector<int> &req_skills, vector<int> &alice, vector<vector<int>> &book)
{
    n = req_skills.size();
    m = book.size();

    books = book;
    req_skill = req_skills;

    int mask = 0;
    for (int bk = 0; bk < book.size(); bk++)
    {
        for (int skill = 1; skill < book[bk].size(); skill++)
        {
            mpp[bk].insert(books[bk][skill] - 1);
        }
    }

    unordered_set<int> rsk;
    for (auto req : req_skills)
    {
        rsk.insert(req - 1);
    }

    for (auto alice_skill : alice)
    {
        if (rsk.find(alice_skill - 1) != rsk.end())
        { // alice has the required skill
            mask = mask | (1 << (alice_skill - 1));
        }
    }

    memset(dp, -1, sizeof(dp));
    int res = helper(mask, 0);
    return res == INT_MAX / 2 ? -1 : res;
}

int main()
{
    vector<int> skill = {1, 2, 3, 4};
    vector<int> alice = {1, 5};
    vector<vector<int>> books = {{40, 2, 3, 5}, {30, 4, 4}, {60, 2, 3, 4}};
    cout << minCost(skill, alice, books);
}