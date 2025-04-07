#include<cstdio>
#include<array>
#include<vector>
#include<cstring>
using std::array;

using std::vector;

array<array<vector<int> , 9> , 9> LastRemainingCellInference(array<array<int , 9> , 9> mat)
{
    bool vis[9][9][10];
    memset(vis , 0 , sizeof vis);

    for(int i = 0;i < 9;i ++)
    {
        for(int j = 0;j < 9;j ++)
            if(mat[i][j] != 0)
            {
                int id = mat[i][j];
                for(int k = 0;k < 9;k ++)
                    vis[i][k][id] = vis[k][j][id] = 1;
                
                int L = i  / 3 , R = j / 3;
                for(int k = 0;k < 3;k ++)
                    for(int l = 0;l < 3;l ++) 
                        vis[L * 3 + k][R * 3 + l][id] = 1; 

                for(int k = 1;k <= 9;k ++) vis[i][j][k] = 1;
            }
    }

    array<array<vector<int> , 9> , 9> ret;
    
    for(int i = 0;i < 9;i ++)
        for(int j = 0;j < 9;j ++)
            if(mat[i][j] == 0)
            {
                for(int k = 1;k <= 9;k ++)
                    if(vis[i][j][k] == 0)
                    {
                        bool flag = 1;
                        for(int l = 0;l < 9;l ++)
                            if(l != j && vis[i][l][k] == 0) flag = 0;
                        if(flag == 1)
                        {
                            ret[i][j].push_back(k); 
                            break;
                        }

                        flag = 1;
                        for(int l = 0;l < 9;l ++)
                            if(l != i && vis[l][j][k] == 0) flag = 0;
                        if(flag == 1)
                        {
                            ret[i][j].push_back(k); 
                            break;
                        }

                        flag = 1;
                        int L = i / 3 , R = j / 3;

                        for(int a = 0;a < 3;a ++)
                            for(int b = 0;b < 3;b ++)
                            {
                                int dx = L * 3 + a , dy = R * 3 + b;
                                if(dx == i && dy == j) continue;
                                if(vis[dx][dy][k] == 0) flag = 0;
                            }
                        if(flag == 1)
                        {
                            ret[i][j].push_back(k);
                            break;
                        }
                    }        
            }

    return ret;
}

array<array<vector<int> , 9> , 9> PossibleNumberInference(array<array<int , 9> , 9> mat)
{
    bool vis[9][9][10];
    memset(vis , 0 , sizeof vis);

    for(int i = 0;i < 9;i ++)
    {
        for(int j = 0;j < 9;j ++)
            if(mat[i][j] != 0)
            {
                int id = mat[i][j];
                for(int k = 0;k < 9;k ++)
                    vis[i][k][id] = vis[k][j][id] = 1;
                
                int L = i  / 3 , R = j / 3;
                for(int k = 0;k < 3;k ++)
                    for(int l = 0;l < 3;l ++) 
                        vis[L * 3 + k][R * 3 + l][id] = 1; 

                for(int k = 1;k <= 9;k ++) vis[i][j][k] = 1;
            }
    }

    array<array<vector<int> , 9> , 9> ret;
    
    for(int i = 0;i < 9;i ++)
        for(int j = 0;j < 9;j ++)
            if(mat[i][j] == 0)
            {
                for(int k = 1;k <= 9;k ++)
                    if(vis[i][j][k] == 0)
                        ret[i][j].push_back(k);
            }
    return ret;
}
