//
// Created by patos on 5/22/2023.
//
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main()
{
    cout << "No hace nada" << endl;
    ifstream fich;
    fich.open("E:\\Documents\\UCB\\Intro a progra\\Juegoo\\DoLook\\puntuaciones.dat");
    /*for(int i = 0; i < 60; i ++)
    {
        fich << i << endl;
    }*/
    //fich.close();
    if(!fich.is_open())
    {
        cout << "NO DAAAAAAAA" << endl;
        exit(EXIT_FAILURE);
    }
    string valor;
    int numero;
    for(int i = 0; i < 2; i ++)
    {
        fich >> valor;
        fich >> numero;
        cout << valor << endl << numero << endl << numero + 5 << endl;
    }
    return 0;
}