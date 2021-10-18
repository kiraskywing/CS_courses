#include <stdio.h>
#include <stdbool.h>

int m, n, res, x_start, y_start, x_end, y_end;
int shift[2][4] = {{0, 1, -1, 0}, {1, 0, 0, -1}};
void dfs(int map[m][n], int visited[m][n], int x, int y, int cur);
bool valid_pos(int map[m][n], int visited[m][n], int x, int y);

int main(void)
{
    scanf("%d %d", &m, &n);
    int map[m][n], visited[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
            visited[i][j] = 0;
            if (map[i][j] == -2)
            {
                x_start = i;
                y_start = j;
                visited[i][j] = 1;
            }
            if (map[i][j] == -3)
            {
                x_end = i;
                y_end = j;
            }
        }
    }

    dfs(map, visited, x_start, y_start, 0);
    printf("%d", res);
    return 0;
}

void dfs(int map[m][n], int visited[m][n], int x, int y, int cur)
{
    if (x == x_end && y == y_end)
    {
        if (res == 0 || cur < res)
            res = cur;
        return;
    }

    int x2, y2;
    for (int i = 0; i < 4; i++)
    {
        x2 = x + shift[0][i];
        y2 = y + shift[1][i];
        if (valid_pos(map, visited, x2, y2))
        {
            visited[x2][y2] = 1;
            dfs(map, visited, x2, y2, cur + 1);
            visited[x2][y2] = 0;
        }
    }
}

bool valid_pos(int map[m][n], int visited[m][n], int x, int y)
{
    if (x < 0 || x >= m || y < 0 || y >= n)
        return false;
    if ((map[x][y] == 0 || map[x][y] == -3) && visited[x][y] != 1)
        return true;
    return false;
}