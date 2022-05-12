#ifndef BINFA_H_INCLUDED
#define BINFA_H_INCLUDED

#include "string.h"
#include <iostream>

template <class T>
struct BinFaElem{
        T adat;
        BinFaElem *bal;
        BinFaElem *jobb;
        BinFaElem(BinFaElem *b = NULL, BinFaElem *j = NULL): bal(b), jobb(j){}
    };

template <class T>
class BinFa{
    BinFaElem<T> *gyoker, *akt;
public:
    BinFa() {akt = gyoker = new BinFaElem<T>;}
    void setElem(const T& p) {akt->adat = p;}
    void beszurBalra(const T&, BinFaElem<T>*);
    void beszurBalra(const T& dat) {this->beszurBalra(dat, akt);}
    void beszurJobbra(const T&, BinFaElem<T>*);
    void beszurJobbra(const T& dat) {this->beszurJobbra(dat, akt);}
    bool level(){return (akt->bal == NULL && akt->jobb == NULL);}
    void lepBalra(){if(akt->bal != NULL) akt = akt->bal;}
    void lepJobbra(){if(akt->jobb != NULL) akt = akt->jobb;}
    BinFaElem<T>* getGyoker() {return gyoker;}
    T& getAdat() {return akt->adat;}
    void felszabadit(BinFaElem<T> *);
    ~BinFa() {felszabadit(gyoker);}
};

template <class T>
void BinFa<T>::beszurBalra(const T& dat, BinFaElem<T>* mihez){
    BinFaElem<T> *uj = new BinFaElem<T>;
    uj->adat = dat;
    mihez->bal = uj;
}

template <class T>
void BinFa<T>::beszurJobbra(const T& dat, BinFaElem<T>* mihez){
    BinFaElem<T> *uj = new BinFaElem<T>;
    uj->adat = dat;
    mihez->jobb = uj;
}

template <class T>
void BinFa<T>::felszabadit(BinFaElem<T>* gyoker){
    if(gyoker == NULL) return;
    felszabadit(gyoker->bal);
    felszabadit(gyoker->jobb);
    delete gyoker;
}

#endif // BINFA_H_INCLUDED
