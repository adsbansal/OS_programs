#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5, m = 3, i, j, k;
    int al_res[5][3] = {{0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2}};
    int max_res[5][3] = {{7, 5, 3}, {3, 2, 2}, {9, 0, 2}, {2, 2, 2}, {4, 3, 3}};
    int avail_res[] = {3, 3, 2};
    int freed[n]={0}, ans[n]={0}, ind = 0,l = 0;

    int need_res[5][3];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need_res[i][j] = max_res[i][j] - al_res[i][j];
        }
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (freed[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need_res[i][j] > avail_res[j])
                    {
            cout<<"in";
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (l = 0; l < m; l++)
                        avail_res[l] += al_res[i][l];
                        freed[i] = 1;
                }
            }
        }
    }
    cout<<"The safe sequence is "<<endl;
    for(i=0;i<n-1;i++){
        cout<<"Process"<<ans[i]<<"->";
    }
        cout<<"Process"<<ans[n-1]<<endl;
}