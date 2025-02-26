// https://leetcode.com/problems/path-with-minimum-effort/description/

#include <bits/stdc++.h>

using namespace std;

// Normal DFS with TLE
class Solution
{
    bool visit[101][101];
    int minAns, m, n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(vector<vector<int>> &heights, int currX, int currY, int maxDiff)
    {
        if (currX == m - 1 && currY == n - 1)
        {
            minAns = min(minAns, maxDiff);
            return;
        }

        visit[currX][currY] = true;
        for (int i = 0; i < 4; ++i)
        {
            int x = currX + dx[i];
            int y = currY + dy[i];

            if (x < 0 || y < 0 || x >= m || y >= n || visit[x][y])
                continue;

            // maxDiff = max(maxDiff, abs(heights[currX][currY] - heights[x][y]));
            dfs(heights, x, y, max(maxDiff, abs(heights[currX][currY] - heights[x][y])));
        }

        visit[currX][currY] = false;
    }

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        memset(visit, 0x0, sizeof(visit));
        minAns = INT_MAX;
        m = heights.size(), n = heights[0].size();

        if (m == 1 && n == 1)
            return 0;

        dfs(heights, 0, 0, INT_MIN);

        return minAns;
    }
};

// Using Bianry search with DFS
class Solution
{
    bool visit[101][101];
    int minAns, m, n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool dfs(vector<vector<int>> &heights, int currX, int currY, int &maxDiff)
    {
        if (currX == m - 1 && currY == n - 1)
        {
            return true;
        }

        visit[currX][currY] = true;
        for (int i = 0; i < 4; ++i)
        {
            int x = currX + dx[i];
            int y = currY + dy[i];

            if (x < 0 || y < 0 || x >= m || y >= n || visit[x][y])
                continue;

            if (maxDiff >= abs(heights[currX][currY] - heights[x][y]))
            {
                if (dfs(heights, x, y, maxDiff))
                    return true;
            }
        }

        return false;
    }

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        minAns = INT_MAX;
        m = heights.size(), n = heights[0].size();

        int minDiff = 0, maxDiff = 1000000;

        while (minDiff <= maxDiff)
        {
            int mid = (minDiff + maxDiff) / 2;
            memset(visit, 0x0, sizeof(visit));
            if (dfs(heights, 0, 0, mid))
            {
                minAns = mid;
                maxDiff = mid - 1;
            }
            else
            {
                minDiff = mid + 1;
            }
        }

        return minAns;
    }
};

// Djikshtra Algorithm
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        vector<vector<int>> minCost(heights.size(), vector<int>(heights[0].size(), INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});
        minCost[0][0] = 0;

        while (!pq.empty())
        {
            vector<int> temp = pq.top();
            int currCost = temp[0];
            int x = temp[1];
            int y = temp[2];

            pq.pop();

            if (x == heights.size() - 1 && y == heights[0].size() - 1)
                return currCost;

            for (int i = 0; i < 4; ++i)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newX < heights.size() && newY >= 0 && newY < heights[0].size())
                {
                    int newCost = max(currCost, abs(heights[x][y] - heights[newX][newY]));
                    if (newCost < minCost[newX][newY])
                    {
                        minCost[newX][newY] = newCost;
                        pq.push({newCost, newX, newY});
                    }
                }
            }
        }
        return 0;
    }
};