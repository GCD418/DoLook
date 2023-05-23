#include <bits/stdc++.h>

#define ffor(i, o, n) for(int i = o; i < n; i ++)

using namespace std;

int nx, ny, tx = 12, ty = 23, c, movements = 0;
vector < pair < string, long > > clasificador;
map < char, pair < int, int > > mov;
string handle;

struct sort_vii_S {
    bool operator()(pair <string, long> &left, pair <string, long> &right){
        return left.second < right.second;
    }
};

char s;
pair < int, int > pos = {1, 0};
char mat [12][23] = {{'#', '#', '*', '*', '*', '*', '*', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'-', '*', '*', '#', '#', '#', '*', '*', '*', '#', '*', '*', '*', '#', '*', '*', '*', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '*', '*', '*', '*', '*', '#', '*', '*', '*', '#', '*', '*', '*', '#', '*', '#', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '*', '*', '*', '#', '*', '*', '+', '#', '#', '#', '#'},
    {'*', '*', '*', '#', '*', '*', '*', '*', '*', '*', '*', '*', '#', '#', '*', '#', '*', '#', '*', '#', '#', '#', '#'},
    {'*', '#', '*', '#', '*', '#', '#', '*', '*', '#', '#', '*', '*', '*', '*', '#', '*', '*', '*', '*', '*', '*', '#'},
    {'*', '*', '*', '*', '*', '#', '*', '*', '*', '#', '#', '*', '#', '#', '#', '#', '#', '#', '*', '#', '#', '*', '#'},
    {'#', '*', '#', '#', '*', '*', '*', '#', '*', '*', '*', '*', '#', '#', '*', '*', '*', '*', '*', '*', '*', '*', '#'},
    {'#', '*', '#', '#', '*', '#', '*', '#', '#', '*', '#', '#', '#', '#', '*', '#', '#', '#', '*', '#', '#', '#', '#'},
    {'#', '*', '*', '*', '*', '#', '*', '*', '*', '*', '#', '#', '#', '#', '*', '*', '*', '*', '*', '#', '#', '#', '#'},
    {'#', '*', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '*', '#', '#', '#', '#'},
    {'#', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '/', '#', '#', '#', '#'}
};
pair<int, int> nm[13]= {{3, 18}, {4, 18}, {5, 18}, {6, 18}, {7, 18}, {8, 18}, {9, 18}, {8, 18}, {7, 18}, {6, 18}, {5, 18}, {4, 18}, {3, 18}};

void print() {
    ffor(i, 0, 12) {
            ffor(j, 0, 23) {
                cout << mat[i][j];
            }
            cout << endl;
        }
}

void inicializarScore()
{
    string user;
    long puntuacion;
    ifstream leer;
    leer.open("E:\\Documents\\UCB\\Intro a progra\\Juegoo\\DoLook\\puntuaciones.dat");
    ffor(i, 0, 3)
    {
        leer >> user;
        leer >> puntuacion;
        clasificador.push_back({user, puntuacion});
    }
    leer.close();
    cout << "Los 3 mejores puntajes actuales son de" << endl;
    ffor(i, 0, 3)
    {
        cout << i + 1 << ". " << clasificador[i].first << " con " << clasificador[i].second << " puntos" << endl;
    }
}

void guardarScore()
{
    ofstream escribir;
    escribir.open("E:\\Documents\\UCB\\Intro a progra\\Juegoo\\DoLook\\puntuaciones.dat");
    clasificador.push_back({handle, movements});
    sort(clasificador.begin(), clasificador.end(), sort_vii_S());
    ffor(i, 0, 3)
    {
        escribir << clasificador[i].first << endl;
        escribir << clasificador[i].second << endl;
    }
    escribir.close();
    cout << "La tabla de posiciones actualizada es:" << endl;
    ffor(i, 0, 3)
    {
        cout << i + 1 << ". " << clasificador[i].first << " con " << clasificador[i].second << " puntos" << endl;
    }
}

void jugar()
{
    while(1)
    {
        print();
        cin >> s;
        movements ++;
        nx = pos.first + mov[s].first;
        ny = pos.second + mov[s].second;
        mat[nm[c].first][nm[c].second] = '*' ;
        c=(c+1)%13;
        mat[nm[c].first][nm[c].second] = '+' ;
        if( nx >= 0 && nx < tx && ny >= 0 && ny < ty ) {
            if(mat[nx][ny] == '+') {
                mat[pos.first][pos.second] = '*';
                mat[nx][ny] = '@';
                system("cls");
                print();
                cout << "ESTAS MUERTO\n";
                return;
            }
            else if(mat[nx][ny] == '/') {
                mat[pos.first][pos.second] = '*';
                mat[nx][ny] = '$';
                system("cls");
                print();
                cout << "GANASTEEEEEEE" << endl;
                guardarScore();
                return;
            }
            else if( mat[nx][ny] == '*' ) {
                mat[pos.first][pos.second] = '*';
                mat[nx][ny] = '-';
                pos = {nx, ny};
            }
        }
        else{
            if(mat[pos.first][pos.second] == '+') {
                cout << "ESTAS MUERTO\n";
                return;
            }
        }
        system("cls");
    }

}

int main() {
    //cout << char(178) << endl;
    cout << "Ingresa un nombre de usuario, sin espacios ni caracteres raros" << endl;
    cin >> handle;
    inicializarScore();
    mov['d'] = {0, 1};
    mov['w'] = {-1, 0};
    mov['a'] = {0, -1};
    mov['s'] = {1, 0};
    c=0;
    jugar();
    return 0;
}
