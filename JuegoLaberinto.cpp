#include <bits/stdc++.h>

#define ffor(i, o, n) for(int i = o; i < n; i ++)

using namespace std;

int nx, ny, tx = 9, ty = 19;
map < char, pair < int, int > > mov;
char s;
pair < int, int > pos = {1, 0};
char mat[9][19] = {{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                {'-', '*', '*', '*', '*', '*', '*', '*', '*', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                {'#', '#', '#', '#', '#', '#', '#', '#', '*', '*', '*', '*', '*', '#', '#', '#', '#', '#', '#'},
                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '*', '*', '*', '#', '#', '#', '#'},
                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '*', '#', '#', '#', '#'},
                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '*', '#', '#', '#', '#'},
                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '*', '*', '*', '*', '#'},
                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '*', '#'},
                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '/', '#'}};

void enemy()
{
    
}

int main()
{
    mov['d'] = {0, 1};
    mov['w'] = {-1, 0};
    mov['a'] = {0, -1};
    mov['s'] = {1, 0};
    while(1)
    {
        ffor(i, 0, 9)
        {
            ffor(j, 0, 19)
            {
                cout << mat[i][j];
            }
            cout << endl;
        }
        cin >> s;
        nx = pos.first + mov[s].first;
        ny = pos.second + mov[s].second;
        if(nx >= 0 && nx < tx && ny >= 0 && ny < ty && (mat[nx][ny] == '*' || mat[nx][ny] == '/'))
        {
            mat[pos.first][pos.second] = '*';
            if(mat[nx][ny] == '/')
            {
                cout << "GANASTEEEEEEE" << endl;
                return 0;
            }
            mat[nx][ny] = '-';
            pos = {nx, ny};
        }
        system("cls");

    }
    return 0;
}
