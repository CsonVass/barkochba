#ifndef PBINFA_H_INCLUDED
#define PBINFA_H_INCLUDED

#include "BinFa.h"
#include "Serlializable.h"
#include <iostream>

template <class T>
class PBinFa: public BinFa<T>, public Serializable{
    T szeparator, nullp;
public:
    PBinFa(T sz = "\n", T n = "#"): BinFa<T>(), szeparator(sz), nullp(n) {};
    void kiment(std::ostream&, BinFaElem<T> *);
    bool betolt(std::istream&, BinFaElem<T> *);
    void kiment(std::ostream& os) {this->kiment(os, this->getGyoker());}
    void betolt(std::istream& is) {this->betolt(is, this->getGyoker());}
};

template <class T>
void PBinFa<T>::kiment(std::ostream& os, BinFaElem<T> *gyoker){
        if(gyoker == NULL){
        os<<this->nullp<<this->szeparator;
        return;
    }
    os<<gyoker->adat<<this->szeparator;
    kiment(os, gyoker->bal);
    kiment(os, gyoker->jobb);
    }

template <class T>
bool PBinFa<T>::betolt(std::istream& is, BinFaElem<T>* gyoker){
    T s;
    is>>s;
    if(s == ""){
        delete gyoker;
        return true;
    }
    if(s == this->nullp){
        delete gyoker;
        return true;
    }

    gyoker->adat = s;

    this->beszurBalra(s, gyoker);
    this->beszurJobbra(s, gyoker);

    if(this->betolt(is, gyoker->bal)) gyoker->bal = NULL;
    if(this->betolt(is, gyoker->jobb)) gyoker->jobb = NULL;
    return false;
}

#endif // PBINFA_H_INCLUDED
