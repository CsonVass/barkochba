#include <iostream>
#include <fstream>

#include "BinFa.h"
#include "PBinFa.h"
#include "string.h"


using namespace std;

void teszt_String(){
    cout<<"String osztaly fuggvenyeinek tesztelese\n"<<endl;
    String s0;
    cout<<"Parameter nelkuli konstruktor: "<<s0<<endl;
    String sc('s');
    cout<<"Karakterbol string: "<<sc<<endl;
    String str("teszt string");
    cout<<"C sztringbol String: "<<str<<endl;
    cout<<"String hossza: "<<str.getlen()<<endl;
    String strcopy(str);
    cout<<"Masolo konstruktor: "<<strcopy<<endl;
    cout<<"A masolt hozza: "<<strcopy.getlen()<<endl;
    str = str + strcopy;
    cout<<"Stringek osszefuzese: "<<str<<" Hossza: "<<str.getlen()<<endl;
    sc = sc + 'z';
    cout<<"Stringhez karakter fuzese: "<<sc<<" Hossza: "<<sc.getlen()<<endl;
    str = sc;
    cout<<"Ertekado operator: "<<str<<" Hossza: "<<str.getlen()<<endl;
    cout<<"Beolvasas: ";
    cin>>str;
    cout<<"Beolvasott: "<<str<<" Merete: "<<str.getlen()<<endl;
    cout<<"Egyenloseg operatorok teszelese: "<<endl;
    if(str == "teszt" && !(str != "teszt")) cout<<"A beolvasott szoveg: teszt"<<endl;
    else cout<<"A beolvasott szoveg nem: teszt"<<endl;
    if(str == sc) cout<<"A ket sztring egyezo"<<endl;
    else cout<<"A ket string nem egyezo"<<endl;
}

void teszt_BinFa(){
    cout<<"BinFa osztaly tesztelese:"<<endl;
    BinFa<String> sfa;
    cout<<"String binfa letrehozva"<<endl;
    BinFa<double> dfa;
    cout<<"Double binfa letrehozva"<<endl;
    String str("Teszt");
    sfa.setElem(str);
    cout<<"String beallitva adatnak: "<<sfa.getAdat()<<endl;
    dfa.setElem(3.14);
    cout<<"Double bealltiva adatnak: "<<dfa.getAdat()<<endl;
    String str2("Teszt bal");
    sfa.beszurBalra(str2);
    cout<<"String beszurva balra"<<endl;
    sfa.lepBalra();
    cout<<"A bal oldalt levo string: "<<sfa.getAdat()<<endl;
    cout<<"Felepitunk egy valos szamokat tarolo binfat"<<endl;
    for(int i = 0; i < 10; i++){
        if(i % 3 == 0) {
            dfa.beszurBalra(3.14*i+i);
            dfa.lepBalra();
        }else{
            dfa.beszurJobbra(3.14-i);
            dfa.lepJobbra();
        }
    }
    cout<<"Ezzel teszteltuk a jobbra beszurast is."<<endl;
}

void teszt_PBinFa(){
    PBinFa<String> sfa;
    cout<<"Letrehoztunk egy Stringeket tartalmazo binfat"<<endl;
    String str("teszt");
    sfa.setElem(str);
    sfa.beszurBalra(str+"bal");
    sfa.beszurJobbra(str+"jobb");
    sfa.lepBalra();
    sfa.beszurJobbra(str+"baljobb");

    cout<<"Kimentjuk a BinFat egy fajlba"<<endl;
    ofstream fajlki;
    fajlki.open("teszt.txt");
    sfa.kiment(fajlki);
    fajlki.close();
    cout<<"A kimentett adatok: ";
    sfa.kiment(cout);

    cout<<"Visszatoltjuk a fajlbol egy masik faba"<<endl;
    PBinFa<String> sfa2;
    ifstream fajlbe;
    fajlbe.open("teszt.txt");
    if(fajlbe.is_open())
        sfa2.betolt(fajlbe);
    fajlbe.close();
    cout<<"A beolvasott fa elemei: ";
    sfa2.kiment(cout);

}

void teszt_Jatek(){
    PBinFa<String> fa;

    ifstream fajlbe;
    fajlbe.open("mentes.txt");
    if(fajlbe.is_open())
        fa.betolt(fajlbe);
    fajlbe.close();

    String valasz("start");

    do{
        if(valasz == "N") fa.lepBalra();
        else if(valasz == "I") fa.lepJobbra();
        else if(valasz == "start");
        else cout<<"I-t vagy N-t irj be!"<<endl;
        if(!fa.level()) cout<<fa.getAdat()<<" (I/N)"<<endl;
        else cout<<"Tipp: "<<fa.getAdat()<<" (I/N)"<<endl;
    }while(cin>>valasz && !fa.level());

    int seged = 0;
    do{
        if(seged == 0 && valasz == "I"){
            cout<<"Koszonom a jatekot!"<<endl;
            seged = 4;
        }
        else if(seged > 0 || valasz == "N"){
            if(seged == 0)
                cout<<"Segits fejlodnom! Adj meg egy uj kerdest a tippem helyett es a hozza tartozo valszokat!\nKerdes: ";
            if(seged == 1){
                fa.setElem(valasz);
                cout<<"Igen: ";
            }
            if(seged == 2){
                fa.beszurJobbra(valasz);
                cout<<"Nem: ";
            }
            if(seged == 3){
                fa.beszurBalra(valasz);
                cout<<"Koszonom a segitseget"<<endl;
                ofstream fajlki;
                fajlki.open("mentes.txt");
                fa.kiment(fajlki);
            }
            seged++;
        }
        else cout<<"I-t vagy N-t irj be!"<<endl;

    }while(seged < 4 && cin>>valasz);

}

int main()
{
    teszt_String();
    cout<<"\n------------------\n"<<endl;
    teszt_BinFa();
    cout<<"\n------------------\n"<<endl;
      teszt_PBinFa();
    cout<<"\n------------------\n"<<endl;
    teszt_Jatek();

    return 0;
}
