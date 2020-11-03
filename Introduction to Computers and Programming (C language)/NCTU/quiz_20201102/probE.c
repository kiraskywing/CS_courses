#include <stdio.h>
#define INPUT_MAX 500
#define VAL_MAX 65536 * 2 + 1

long long input_x[2][INPUT_MAX], input_y[2][INPUT_MAX];
int x_value[VAL_MAX], y_value[VAL_MAX];
long long new_x[INPUT_MAX * 2], new_y[INPUT_MAX * 2];
long long board[INPUT_MAX * 2][INPUT_MAX * 2];
int bias = 65536;
int count_x, count_y;
int N;

void init_arr(void);
void create_map(void);
long long get_res(void);

int main(void)
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        init_arr();
        create_map();
        printf("%lld\n", get_res());
    }

    return 0;
}

void init_arr(void)
{
    count_x = count_y = 0;

    for (int i = 0; i < VAL_MAX; i++)
        x_value[i] = y_value[i] = 0;
    
    for (int i = 0; i < INPUT_MAX * 2; i++)
    {
        for (int j = 0; j < INPUT_MAX * 2; j++)
            board[i][j] = 0;
    }
}

void create_map(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lld %lld %lld %lld", &input_x[0][i], &input_y[0][i], &input_x[1][i], &input_y[1][i]);  
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
    long long x_low, x_high, y_low, y_high;
    for (int i = 0; i < N; i++)
    {
        x_low = x_value[input_x[0][i]];
        x_high = x_value[input_x[1][i]];
        y_low = y_value[input_y[0][i]];
        y_high = y_value[input_y[1][i]];
        for (int x = x_low; x < x_high; x++)
        {
            for (int y = y_low; y < y_high; y++)
                board[x][y] = 1;
        }
    }

    for (int x = 0; x < INPUT_MAX * 2; x++)
    {
        for (int y = 0; y < INPUT_MAX * 2; y++)
        {
            if (board[x][y] == 1)
                res += (new_x[x + 1] - new_x[x]) * (new_y[y + 1] - new_y[y]);
        }
    }
    
    return res;
}