#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
bool vis[1005][1005];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int sx, int sy)
{
    queue<pair<int,int>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            {
                if (!vis[nx][ny] && grid[nx][ny] == '.')
                {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    grid.resize(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    memset(vis, false, sizeof(vis));

    int apartment = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                bfs(i, j);
                apartment++;
            }
        }
    }

    cout << apartment;

    return 0;
}