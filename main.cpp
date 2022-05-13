//
//  main.cpp
//  dzielniki liczby
//
//  Created by Łukasz Michalak on 11/03/2019.
//  Copyright © 2019 Łukasz Michalak. All rights reserved.
//

#include <iostream>
using namespace std;

int* powiekszenie(int* tab,int& dlugosc);
int* redukcja(int* tab,int dlugosc);
int wyznaczanie(int liczba,int** dzielenie,int wiersz,int wielkosc);
void wypisanie_wiersz(int liczba_do_dzielenia,int** tab,int wiersz,int wielkosc);


int main() {
    cout<<"Prosze podać najwyższą liczbę, dla której zostaną wypisane wszystkie dzielniki: ";
    int liczba_do_dzielenia;
    cin>>liczba_do_dzielenia;
    int wielkosc=5;
    int **tab=new int* [liczba_do_dzielenia];
    for(int i=0;i<liczba_do_dzielenia;i++){
        tab[i]=new int [wielkosc];
    }
    cout<<"Dzielniki wygladaja nastepujaco"<<endl;
    for(int i=0;i<liczba_do_dzielenia;i++){
        cout<<"Dla "<<i+1<<"\t->\t";
        wypisanie_wiersz(i+1, tab, i, wielkosc);
        cout<<endl;
    }
    for(int i=0;i<liczba_do_dzielenia;i++){
        delete[] tab[i];
    }
    delete[] tab;
    return 0;
}

int* powiekszenie(int* tab,int& wielkosc){
    wielkosc+=4; //zwiekszanie
    int* nowaTablica=new int[wielkosc];
    for(int i=0;i<wielkosc;i++){
        nowaTablica[i]=tab[i];
    }
    delete[] tab;
    return nowaTablica;
}

int* redukcja(int* tab,int dlugosc){
    int* nowaTablica=new int[dlugosc];
    for(int i=0;i<dlugosc;i++){
        nowaTablica[i]=tab[i];
    }
    delete[] tab;
    return nowaTablica;
}

int wyznaczanie(int liczba,int** tablica,int wiersz,int wielkosc){
    int j=0;
    for(int i=1;i<=liczba;i++){
        if(liczba%i==0){
            if(j<wielkosc){
                tablica[wiersz][j]=i;
                j++;
            }
            else{
                tablica[wiersz]=powiekszenie(tablica[wiersz],wielkosc);
            }
        }
    }
    tablica[wiersz]=redukcja(tablica[wiersz], j);
    return j;
}

void wypisanie_wiersz(int liczba_do_dzielenia,int** tab,int wiersz,int wielkosc){
    int dlugosc=wyznaczanie(liczba_do_dzielenia,tab,wiersz,wielkosc);
    for(int i=0;i<dlugosc;i++){
        cout<<tab[wiersz][i]<<"\t";
    }
}
