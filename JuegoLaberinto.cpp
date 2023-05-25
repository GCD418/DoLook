#include <bits/stdc++.h>

#define ffor(i, o, n) for(int i = o; i < n; i ++)

using namespace std;

int nx, ny, tx = 12, ty = 23, c, c2, movements = 0, dif, blind_radio, visual_radio;
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
char mat [12][23] = {{char(219), char(219), '*', '*', '*', '*', '*', char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219)},
    {'-', '*', '*', char(219), char(219), char(219), '*', '*', '*', char(219), '*', '*', '*', char(219), '*', '*', '*', char(219), char(219), char(219), char(219), char(219), char(219)},
    {char(219), char(219), '*', '*', '*', '*', '*', char(219), '*', '*', '*', char(219), '*', '*', '*', char(219), '*', char(219), char(219), char(219), char(219), char(219), char(219)},
    {char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), '*', '*', '*', char(219), '*', '*', char(197), char(219), char(219), char(219), char(219)},
    {'*', '*', '*', char(219), '*', '*', '*', '*', '*', '*', '*', '*', char(219), char(219), '*', char(219), '*', char(219), '*', char(219), char(219), char(219), char(219)},
    {'*', char(219), '*', char(219), '*', char(219), char(219), '*', '*', char(219), char(219), '*', '*', '*', '*', char(219), '*', '*', '*', '*', '*', '*', char(219) },
    {'*', '*', '*', '*', '*', char(219), '*', '*', '*', char(219), char(219), '*', char(219), char(219), char(219), char(219), char(219), char(219), '*', char(219), char(219), '*', char(219)},
    { char(219), '*', char(219), char(219), '*', '*', '*', char(219), '*', '*', '*', '*', char(219), char(219), '*', '*', '*', '*', '*', '*', '*', '*', char(219)},
    { char(219), '*', char(219), char(219), '*', char(219), '*', char(219), char(219), '*', char(219), char(219), char(219), char(219), '*', char(219), char(219), char(219), '*', char(219), char(219), char(219), char(219)},
    { char(219), char(197), '*', '*', '*', char(219), '*', '*', '*', '*', char(219), char(219), char(219), char(219), '*', '*', '*', '*', '*', char(219), char(219), char(219), char(219)},
    { char(219), '*', char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), char(219), '*', char(219), char(219), char(219), char(219)},
    {char(219), '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '/', char(219), char(219), char(219), char(219) }
};
pair<int, int> nm[12]= {{3, 18}, {4, 18}, {5, 18}, {6, 18}, {7, 18}, {8, 18}, {9, 18}, {8, 18}, {7, 18}, {6, 18}, {5, 18}, {4, 18}};
pair<int, int> nm2[36]= {{9, 1}, {8, 1}, {7, 1}, {6, 1}, {6, 2}, {6, 3}, {6, 4}, {7, 4}, {7, 5}, {7, 6}, {8, 6}, {9, 6}, {9, 7}, {9, 8}, {9, 9}, {8, 9}, {7, 9}, {7, 10}, {7, 11}, {6, 11}, {5, 11}, {4, 11}, {4, 10}, {4, 9}, {4, 8}, {5, 8}, {5, 7}, {6, 7}, {6, 6}, {7, 6}, {7, 5}, {7, 4}, {8, 4}, {9, 4}, {9, 3}, {9, 2}};

void print() {
    cout<<"Numero de movimientos actuales: "<<movements<<" \n";
    ffor(i, 0, 12) {
            ffor(j, 0, 23) {
                if(( abs(i-nm[c].first)<blind_radio && abs(j-nm[c].second)<blind_radio )||( abs(i-nm2[c2].first)<blind_radio && abs(j-nm2[c2].second)<blind_radio )){cout<<char(254);}
                else if( abs(i-pos.first)>visual_radio || abs(j-pos.second)>visual_radio ){cout<<char(250);}
                else{ cout << mat[i][j]; }
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
    if(dif==1){
        visual_radio=23;
        blind_radio=-1;
        movements=10;
    }
    else if(dif==2){
        movements=5;
        visual_radio=23;
        blind_radio=-1;
        mat[nm[1].first][nm[1].second] = char(197) ;
        mat[nm[2].first][nm[2].second] = char(197) ;
        mat[nm2[1].first][nm2[1].second] = char(197) ;
        mat[nm2[2].first][nm2[2].second] = char(197) ;
        mat[nm2[3].first][nm2[3].second] = char(197) ;
    }
    else{
        movements=0;
        visual_radio=3;
        blind_radio=2;
    }
    while(1)
    {
        print();
        cin >> s;
        movements ++;
        nx = pos.first + mov[s].first;
        ny = pos.second + mov[s].second;
        if(dif==1 || dif==3){
            mat[nm[c].first][nm[c].second] = '*' ;
            mat[nm2[c2].first][nm2[c2].second] = '*' ;
            c=(c+1)%12;
            c2=(c2+1)%36;
            mat[nm[c].first][nm[c].second] = char(197) ;
            mat[nm2[c2].first][nm2[c2].second] = char(197) ;
        }
        else if(dif==2){
            mat[nm[c].first][nm[c].second] = '*' ;
            mat[nm2[c2].first][nm2[c2].second] = '*' ;
            if(c==5 || c==11){ mat[nm[c].first][nm[c].second] = char(197) ; }
            c=(c+1)%12;
            c2=(c2+1)%36;
            mat[nm[(c+2)%12].first][nm[(c+1)%12].second] = char(197) ;
            mat[nm2[(c2+3)%36].first][nm2[(c2+3)%36].second] = char(197) ;
        }
        if( nx >= 0 && nx < tx && ny >= 0 && ny < ty ) {
            if(mat[nx][ny] == char(197)) {
                mat[pos.first][pos.second] = '*';
                mat[nx][ny] = char(157);
                system("cls");
                print();
                cout << "ESTAS MUERTO\n";
                return;
            }
            else if(mat[nx][ny] == '/') {
                mat[pos.first][pos.second] = '*';
                mat[nx][ny] = char(184);
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
            if(mat[pos.first][pos.second] == char(197)) {
                cout << "ESTAS MUERTO\n";
                return;
            }
        }
        system("cls");
    }

}

void menu(){
    cout<<"1.- Facil \n";
    cout<<"2.- Normal \n";
    cout<<"3.- Dificil \n";
  //  cout<<"4.- Retroceder \n";
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
    cout<<"Ingrese la dificultad en la que le gustaria jugar la proxima partida(La dificultad afectara el modo de juego y tendra un apenalizacion en movimientos)\n";
    while(dif!=1 && dif!=3 && dif!=2 ){
        menu();
        cin>>dif;
        if(dif!=1 && dif!=3 && dif!=2 ){cout<<"Esa opcion no existe, por favor vuelva a ingresar el numero\n";}
    }
    jugar();
    return 0;
}
