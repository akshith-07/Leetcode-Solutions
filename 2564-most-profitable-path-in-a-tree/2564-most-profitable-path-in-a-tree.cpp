class Solution
{
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount)
    {
        int n = amount.size();
        vector<vector<int>> tree(n);
        for (auto& e : edges)
        {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        vector<int> bobTime(n, -1);

        // Step 1: Track Bob’s path using DFS
        findBobPath(bob, 0, tree, bobTime, 0);

        // Step 2: DFS for Alice's maximum profit
        return dfs(0, -1, tree, amount, 0, bobTime);
    }

private:
    bool findBobPath(int node, int time, vector<vector<int>>& tree, vector<int>& bobTime, int bob)
    {
        bobTime[node] = time;
        if (node == 0)
        {
            return true;
        } 

        for (int neighbor : tree[node])
        {
            if (bobTime[neighbor] == -1 && findBobPath(neighbor, time + 1, tree, bobTime, bob))
            {
                return true;
            }
        }
        
        bobTime[node] = -1;
        return false;
    }

    int dfs(int node, int parent, vector<vector<int>>& tree, vector<int>& amount, int time, vector<int>& bobTime)
    {
        int income = amount[node];

        // Step 3: Adjust Alice's profit based on Bob's arrival time
        if (bobTime[node] != -1)
        {
            if (bobTime[node] > time)
            {
                // Alice arrives first, full reward
            } 
            else if (bobTime[node] == time)
            {
                // Both reach at the same time, split amount
                income /= 2;
            }
            else
            {
                // Bob arrives earlier, Alice gets nothing
                income = 0;
            }
        }

        int maxProfit = INT_MIN;
        bool isLeaf = true;

        for (int neighbor : tree[node])
        {
            if (neighbor != parent)
            {
                isLeaf = false;
                maxProfit = max(maxProfit, dfs(neighbor, node, tree, amount, time + 1, bobTime));
            }
        }

        // Step 4: If leaf node, return income, else return maxProfit + income
        return income + (isLeaf ? 0 : maxProfit);
    }
};