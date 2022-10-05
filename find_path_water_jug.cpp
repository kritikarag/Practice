#include <bits/stdc++.h>
using namespace std;
 
void printpath(map< pair<int, int>,  pair<int, int>> mp,  pair<int, int> u)
{
    if (u.first == 0 && u.second == 0)
    {
        cout << 0 << " " << 0 << endl;
        return;
    }
    printpath(mp, mp[u]);
    cout << u.first << " " << u.second << endl;
}

void BFS(int a, int b, int target)
{
    // This map data structure will store the visited or not-visited value of a particular state
    map< pair<int, int>, int> m;
    bool isSolvable = false;

    //This map data structure will store the states of node visited through out the traversal with their parent state
    map< pair<int, int>,  pair<int, int>> mp;

    // Implement a queue data structure that will store the current state(water capacity) of both the jugs
    queue< pair<int, int>> q;

    // First of all push the initial state into the queue
    q.push(make_pair(0, 0));
    while (!q.empty())
    {
        // Take out the front element from the queue
        auto u = q.front();
        // cout<<u.first<<" "<<u.second<<endl;
        q.pop();

        // If the state has already been explored then continue
        if (m[u] == 1)
            continue;

        // If the capacity of current states greater than either of the container than continue
        if ((u.first > a || u.second > b || u.first < 0 || u.second < 0))
            continue;
        // cout<<u.first<<" "<<u.second<<endl;

        // Mark the current state as visited
        m[{u.first, u.second}] = 1;

        // If either of the current state is equal to the required target state then print the path
        if (u.first == target || u.second == target)
        {
            isSolvable = true;

            printpath(mp, u);
            if (u.first == target)
            {
                if (u.second != 0)
                    cout << u.first << " " << 0 << endl;
            }
            else
            {
                if (u.first != 0)
                    cout << 0 << " " << u.second << endl;
            }
            return;
        }

        // completely fill the jug 2
        if (m[{u.first, b}] != 1)
        {
            q.push({u.first, b});
            mp[{u.first, b}] = u;
        }

        // completely fill the jug 1
        if (m[{a, u.second}] != 1)
        {
            q.push({a, u.second});
            mp[{a, u.second}] = u;
        }

        // transfer jug 1 -> jug 2
        int d = b - u.second;
        if (u.first >= d)
        {
            int c = u.first - d;
            if (m[{c, b}] != 1)
            {
                q.push({c, b});
                mp[{c, b}] = u;
            }
        }
        else
        {
            int c = u.first + u.second;
            if (m[{0, c}] != 1)
            {
                q.push({0, c});
                mp[{0, c}] = u;
            }
        }
        // transfer jug 2 -> jug 1
        d = a - u.first;
        if (u.second >= d)
        {
            int c = u.second - d;
            if (m[{a, c}] != 1)
            {
                q.push({a, c});
                mp[{a, c}] = u;
            }
        }
        else
        {
            int c = u.first + u.second;
            if (m[{c, 0}] != 1)
            {
                q.push({c, 0});
                mp[{c, 0}] = u;
            }
        }

        // empty the jug 2
        if (m[{u.first, 0}] != 1)
        {
            q.push({u.first, 0});
            mp[{u.first, 0}] = u;
        }

        // empty the jug 1
        if (m[{0, u.second}] != 1)
        {
            q.push({0, u.second});
            mp[{0, u.second}] = u;
        }
    }
    if (!isSolvable)
        cout << "No solution";
}

int main()
{
    int n, m, target;
    // Take the user input for the capacity of Jug 1
    cout << "Enter the capacity of Jug 1 : ";
    cin >> n;
    cout << endl;

    // Take the user input for the capacity of Jug 1
    cout << "Enter the capacity of Jug 2 : ";
    cin >> m;
    cout << endl;

    // Take the user input for the capacity of water needed to be measured
    cout << "Enter the capacity of water you want to measure : ";
    cin >> target;
    cout << endl;

    // Print the final Results
    cout << "Path from initial state "
            "to solution state ::\n";
    BFS(n, m, target);

    return 0;
}