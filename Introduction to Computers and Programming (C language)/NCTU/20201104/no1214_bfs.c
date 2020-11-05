#include <stdio.h>
#include <stdbool.h>

int m, n, res, x_start, y_start, x_end, y_end;
int shift[2][4] = {{0, 1, -1, 0}, {1, 0, 0, -1}};
void bfs(int map[m][n], int visited[m][n], int queue[3][m * n], int start, int end);
bool valid_pos(int map[m][n], int visited[m][n], int x, int y);

int main(void)
{
    scanf("%d %d", &m, &n);
    int map[m][n], visited[m][n], queue[3][m * n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &map[i][j]);
            visited[i][j] = 0;
            if (map[i][j] == -2)
            {
                queue[0][0] = i;
                queue[1][0] = j;
                queue[2][0] = 0;
                visited[i][j] = 1;
            }
        }
    }

    bfs(map, visited, queue, 0, 1);
    printf("%d", res);
    return 0;
}

void bfs(int map[m][n], int visited[m][n], int queue[3][m * n], int start, int end)
{
    if (start == end)
        return;

    int count = 0;
    for (int i = start; i < end; i++)
    {
        int x = queue[0][i];
        int y = queue[1][i];
        if (map[x][y] == -3)
        {
            res = queue[2][i];
            return;
        }
        
        int x2, y2;
        for (int j = 0; j < 4; j++)
        {
            x2 = x + shift[0][j];
            y2 = y + shift[1][j];
            if (valid_pos(map, visited, x2, y2))
            {
                visited[x2][y2] = 1;
                queue[0][end + count] = x2;
                queue[1][end + count] = y2;
                queue[2][end + count] = queue[2][i] + 1;
                count += 1;
            }
        }
    }
    
    bfs(map, visited, queue, end, end + count);
}

bool valid_pos(int map[m][n], int visited[m][n], int x, int y)
{
    if (x < 0 || x >= m || y < 0 || y >= n)
        return false;
    if ((map[x][y] == 0 || map[x][y] == -3) && visited[x][y] != 1)
        return true;
    return false;
}