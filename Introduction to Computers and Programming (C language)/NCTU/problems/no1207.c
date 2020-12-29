#include <stdio.h>
#define IN_MAX 500 * 2
#define VAL_MAX 65536 * 2 + 1

int input_x[2][IN_MAX], input_y[2][IN_MAX];
int x_value[VAL_MAX], y_value[VAL_MAX];
int new_x[IN_MAX], new_y[IN_MAX];
int board[IN_MAX][IN_MAX];
int bias = 65536;
int N;

void init_map(void);
void create_map(void);
long long get_res(void);

int main(void)
{
    int times;
    scanf("%d", &times);

    while (times--)
    {
        init_map();
        create_map();
        printf("%lld\n", get_res());
    }

    return 0;
}

void init_map(void)
{
    for (int i = 0; i < VAL_MAX; i++)
        x_value[i] = y_value[i] = 0;

    for (int i = 0; i < IN_MAX; i++)
    {
        for (int j = 0; j < IN_MAX; j++)
            board[i][j] = 0;
    }
}

void create_map(void)
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d %d", &input_x[0][i], &input_y[0][i], &input_x[1][i], &input_y[1][i]);
        // 0: min_value, 1: max_value
        input_x[0][i] += bias;
        input_x[1][i] += bias;
        input_y[0][i] += bias;
        input_y[1][i] += bias;

        // record used value
        x_value[input_x[0][i]] = 1;
        x_value[input_x[1][i]] = 1;
        y_value[input_y[0][i]] = 1;
        y_value[input_y[1][i]] = 1;
    }

    int count_x = 0, count_y = 0;
    for (int i = 0; i < VAL_MAX; i++)
    {
        if (x_value[i] == 1)
        {
            new_x[count_x] = i;
            x_value[i] = count_x++;
        }
        if (y_value[i] == 1)
        {
            new_y[count_y] = i;
            y_value[i] = count_y++;
        }
    }
}

long long get_res(void)
{
    long long res = 0;
    for (int i = 0; i < N; i++)
    {
        int x_low = x_value[input_x[0][i]];
        int x_high = x_value[input_x[1][i]];
        int y_low = y_value[input_y[0][i]];
        int y_high = y_value[input_y[1][i]];

        for (int x = x_low; x < x_high; x++)
        {
            for (int y = y_low; y < y_high; y++)
                board[x][y] = 1;
        }
    }

    for (int i = 0; i < IN_MAX; i++)
    {
        for (int j = 0; j < IN_MAX; j++)
        {
            if (board[i][j] == 1)
                res += (new_x[i + 1] - new_x[i]) * (new_y[j + 1] - new_y[j]);
                // 上行計算可能造成overflow，因此res要用long long type
        }
    }
    
    return res;
}