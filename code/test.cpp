#include"LRC.hpp"
#include<cstdio>
#include<iostream>
#define Matrix array<array<int , 9> , 9>
#define MatrixMap array<array<vector<int> , 9> , 9>

using std::cin;
using std::cout;
using std::endl;

Matrix input;

void test(MatrixMap (*f)(Matrix))
{
    Matrix mat = input;
    while(true)
    {
        int flag = 0;
        MatrixMap ret = f(mat);
        for(int i = 0;i < 9;i ++)
            for(int j = 0;j < 9;j ++)
                if(ret[i][j].size() == 1)
                    mat[i][j] = *ret[i][j].begin() , flag = 1;
        if(!flag) break; 
    }

    bool isfull = 1;
    for(int i = 0;i < 9;i ++)
        for(int j = 0;j < 9;j ++)
            if(mat[i][j] == 0) {isfull = 0;break;}

    if(isfull)
    {
        cout << "puzzle completed" << endl;
        for(int i = 0;i < 9;i ++ , cout << endl)
            for(int j = 0;j < 9;j ++)
                cout << mat[i][j] << ' ';
    }
    else
    {
        cout << "puzzle incompleted" << endl;
        for(int i = 0;i < 9;i ++ , cout << endl)
            for(int j = 0;j < 9;j ++)
                cout << mat[i][j] << ' ';
        cout << "last output" << endl;
        MatrixMap ret = f(mat);
        for(int i = 0;i < 9;i ++ , cout << endl)
            for(int j = 0;j < 9;j ++)
            {
                cout << '[';
                for(auto v:ret[i][j]) cout << v << ' ';
                cout << ']';
            }
    }
}

int main()
{
    freopen("../input/test1.in","r",stdin);
    
    for(int i = 0;i < 9;i ++)
        for(int j = 0;j < 9;j ++) 
            cin >> input[i][j];

    test(PossibleNumberInference);
    return 0;
}