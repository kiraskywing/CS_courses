#include <stdio.h>
#include <string.h>

void swap(int *a, int *b);
void card_read_sort(int *color, int *point);
int straight_flush(int *c_A, int *p_A, int *c_B, int *p_B);
int flush(int *color, int *point);
int straight(int *point);
int four_a_kind(int *c_A, int *p_A, int *c_B, int *p_B);

int main(void)
{
    int times;
    scanf("%d", &times);

    while (times--)
    {
        int Acolor[5], Bcolor[5], Apoint[5], Bpoint[5];
        card_read_sort(Acolor, Apoint);
        card_read_sort(Bcolor, Bpoint);

        int temp;

        if (temp = straight_flush(Acolor, Apoint, Bcolor, Bpoint));
        else if (temp = four_a_kind(Acolor, Apoint, Bcolor, Bpoint));

        if (temp > 0) puts("Wins");
        else puts("Lose");
    }
    
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void card_read_sort(int *color, int *point)
{
    char card[3];
    for (int i = 0; i < 5; i++)
    {
        scanf("%s", card);
        if (card[0] == 'A') point[i] = 14;
        else if (card[0] == 'K') point[i] = 13;
        else if (card[0] == 'Q') point[i] = 12;
        else if (card[0] == 'J') point[i] = 11;
        else point[i] = card[0] - '0';

        if (card[1] == 'S') color[i] = 4;
        if (card[1] == 'H') color[i] = 3;
        if (card[1] == 'D') color[i] = 2;
        if (card[1] == 'C') color[i] = 1;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (point[i] < point[j] || (point[i] == point[j] && color[i] < color[j]))
            {
                swap(&point[i], &point[j]);
                swap(&color[i], &color[j]);
            }
        }
    }
}

int straight_flush(int *c_A, int *p_A, int *c_B, int *p_B)
{
    int res_f_a = flush(c_A, p_A), res_s_a = straight(p_A), res_a = 0;
    int res_f_b = flush(c_B, p_B), res_s_b = straight(p_B), res_b = 0;
    if (res_f_a != 0 && res_s_a != 0)
        res_a = res_s_a;
    if (res_f_b != 0 && res_s_b != 0)
        res_b = res_s_b;

    if (res_a != 0 && res_b != 0 && res_a == res_b)
        return c_A[0] - c_B[0];
    return res_a - res_b;
}

int flush(int *color, int *point)
{
    for (int i = 0; i < 4; i++)
    {
        if (color[i] != color[i + 1])
            return 0;
    }
    return point[0] * 100000000 + point[1] * 1000000 + point[2] * 10000 + point[3] * 100 + point[4];
}

int straight(int *point)
{
    if (point[0] == 14 && point[1] == 5 && point[2] == 4 && point[3] == 3 && point[4] == 2)
        return 5;
    for (int i = 0; i < 4; i++)
    {
        if (point[i] - point[i + 1] != 1)
            return 0;
    }
    return point[0];
}

int four_a_kind(int *c_A, int *p_A, int *c_B, int *p_B)
{
    int res_a = 0, res_b = 0, i, j;

    if (p_A[0] == p_A[1] && p_A[1] == p_A[2] && p_A[2] == p_A[3])
    {
        res_a = p_A[0];
        i = 0;
    }
    if (p_A[1] == p_A[2] && p_A[2] == p_A[3] && p_A[3] == p_A[4])
    {
        res_a = p_A[1];
        i = 1;
    }
    
    if (p_B[0] == p_B[1] && p_B[1] == p_B[2] && p_B[2] == p_B[3])
    {
        res_b = p_B[0];
        j = 0;
    }
    if (p_B[1] == p_B[2] && p_B[2] == p_B[3] && p_B[3] == p_B[4])
    {
        res_b = p_B[1];
        j = 1;
    }

    if (res_a != 0 && res_b != 0 && res_a == res_b)
        return c_A[i] - c_B[j];
    return res_a - res_b; 
}