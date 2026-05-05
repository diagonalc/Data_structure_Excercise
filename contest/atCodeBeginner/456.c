#include <stdio.h>

typedef struct gp
{
    int d1, d2, d3;
} gpn;

int main()
{
    int ad1[6], ad2[6], ad3[6];
    for (int i = 0; i < 6; i++)
        scanf(" %d", &ad1[i]);
    for (int i = 0; i < 6; i++)
        scanf(" %d", &ad2[i]);
    for (int i = 0; i < 6; i++)
        scanf(" %d", &ad3[i]);

    gpn gp[256];
    int n = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                gp[n].d1 = ad1[i];
                gp[n].d2 = ad2[j];
                gp[n].d3 = ad3[k];

                n++;
            }
        }
    }
    int ct = 0;

    for (int i = 0; i < n; i++)
    {
        if ((gp[i].d1 == 4 && gp[i].d2 == 5 && gp[i].d3 == 6) || (gp[i].d1 == 4 && gp[i].d3 == 5 && gp[i].d2 == 6) || (gp[i].d2 == 4 && gp[i].d1 == 5 && gp[i].d3 == 6) || (gp[i].d2 == 4 && gp[i].d3 == 5 && gp[i].d1 == 6) || (gp[i].d3 == 4 && gp[i].d2 == 5 && gp[i].d1 == 6) || (gp[i].d3 == 4 && gp[i].d1 == 5 && gp[i].d2 == 6))
        {
            ct++;
            
        }
    }
    printf("%.10f", (double)ct / (double)n);

    return 0;
}