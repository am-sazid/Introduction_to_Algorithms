#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    queue<pair<int,int>> q;
    bool vis[n][m];

    memset(vis, false, sizeof(vis));

    int startX, startY;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                startX = i;
                startY = j;
            }
        }
    }

    q.push({startX, startY});
    vis[startX][startY] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();


        if (grid[x][y] == 'B')
        {
            cout << "YES";
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (!vis[nx][ny] && grid[nx][ny] != '#')
                {
                    q.push({nx, ny});
                    vis[nx][ny] = true;
                }
            }
        }
    }

    cout << "NO";

    return 0;
}