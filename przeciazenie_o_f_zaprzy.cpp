#include <iostream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class SklepOdziezowy 
{
	private:
	    string nazwa;
	    int iloscRozmiarow; 
	    string kategoria; 
	
	public:
	    SklepOdziezowy():nazwa(""),iloscRozmiarow(0),kategoria(""){}
	    SklepOdziezowy(string n, int s, string c):nazwa(n),iloscRozmiarow(s),kategoria(c){}
	    ~SklepOdziezowy(){}
	
	    SklepOdziezowy& operator-=(int wartosc)
		{
	        iloscRozmiarow-=wartosc;
	        return *this;
	    }
	
	    SklepOdziezowy& operator+=(int wartosc) 
		{
	        iloscRozmiarow+=wartosc;
	        return *this;
	    }
	
	    SklepOdziezowy& operator=(const SklepOdziezowy& inny) 
		{
	        if(this != &inny) 
			{
	            nazwa=inny.nazwa;
	            iloscRozmiarow=inny.iloscRozmiarow;
	            kategoria=inny.kategoria;
	        }
	        return *this;
	    }
	
	    bool operator==(const SklepOdziezowy& inny)const 
		{
	        return nazwa==inny.nazwa&&iloscRozmiarow==inny.iloscRozmiarow&&kategoria==inny.kategoria;
	    }
	
	    friend ostream& operator<<(ostream& os, const SklepOdziezowy& sklep);
	    friend istream& operator>>(istream& is, SklepOdziezowy& sklep);
};

ostream& operator<<(ostream& os, const SklepOdziezowy& sklep) 
{
    os<<"Nazwa: "<<sklep.nazwa<<", Ilosc Rozmiarow: "<<sklep.iloscRozmiarow<<", Kategoria: "<<sklep.kategoria;
    return os;
}

istream& operator>>(istream& is, SklepOdziezowy& sklep) 
{
    cout<<"Podaj nazwe: ";
    is>>sklep.nazwa;
    cout<<"Podaj ilosc rozmiarow: ";
    is>>sklep.iloscRozmiarow;
    cout<<"Podaj kategorie: ";
    is>>sklep.kategoria;
    return is;
}

int main() 
{
    SklepOdziezowy sklep1("Skrpety", 50, "damska");
    SklepOdziezowy sklep2("Koszulka", 30, "meska");
    SklepOdziezowy sklep3;

    cout<<"===Oryginalny sklep 1=== "<<endl<<sklep1<<endl;
    cout<<"===Oryginalny sklep 2=== "<<endl<<sklep2<<endl;

    sklep1 += 10;
    sklep2 -= 5;

    cout<<"===Zaktualizowany sklep 1=== "<<endl<<sklep1<<endl;
    cout<<"===Zaktualizowany sklep 2=== "<<endl<<sklep2<<endl;

    sklep3=sklep1;

    if(sklep1 == sklep3) 
	{
        cout<<"Sklep 1 i sklep 3 sa identyczne."<<endl;
    }else 
	{
        cout<<"Sklep 1 i sklep 3 sa rozne."<<endl;
    }

    SklepOdziezowy nowySklep;
    cin>>nowySklep;
    cout<<"===Nowy Sklep=== "<<endl<<nowySklep<<endl;

    return 0;
}


