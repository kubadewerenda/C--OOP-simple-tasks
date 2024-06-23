#include <iostream>
#include <string>

using namespace std;

class Produkt 
{
	private:
	    string nazwa;
	    double cena;
	    string rozmiar;

	public:
	    Produkt():nazwa(""),cena(0.0),rozmiar(""){}
	
	    Produkt(string nazwa, double cena, string rozmiar):nazwa(nazwa),cena(cena),rozmiar(rozmiar){}
	
	    Produkt(const Produkt &other):nazwa(other.nazwa),cena(other.cena),rozmiar(other.rozmiar){}
	
	    string getNazwa() 
		{
	        return nazwa;
	    }
	
	    double getCena() 
		{
	        return cena;
	    }
	
	    string getRozmiar() 
		{
	        return rozmiar;
	    }
	
	    void setNazwa(string nowaNazwa) 
		{
	        nazwa = nowaNazwa;
	    }
	
	    void setCena(double nowaCena) 
		{
	        cena = nowaCena;
	    }
	
	    void setRozmiar(string nowyRozmiar) 
		{
	        rozmiar = nowyRozmiar;
	    }
	
	    void czytajDane() 
		{
	        cout<<"Podaj nazwe produktu: ";
	        cin>>nazwa;
	        cout<<"Podaj cene produktu: ";
	        cin>>cena;
	        cout<<"Podaj rozmiar produktu: ";
	        cin>>rozmiar;
	    }
	
	    double przetwarzajDane() 
		{
	        return cena;
	    }
	
	    void wyswietlWynik() 
		{
	        cout<<"Nazwa produktu: "<<nazwa<<endl;
	        cout<<"Cena produktu: "<<cena<<" PLN"<<endl;
	        cout<<"Rozmiar produktu: "<<rozmiar<<endl;
	    }
};

class SklepOdziezowy 
{
	private:
	    Produkt damski;
	    Produkt meski;

	public:
	    SklepOdziezowy(){}
	
	    SklepOdziezowy(Produkt damski, Produkt meski):damski(damski), meski(meski){}
	
	    void czytajDane() 
		{
	        cout<<"Damska odziez:"<<endl;
	        damski.czytajDane();
	        cout<<"Meska odziez:"<<endl;
	        meski.czytajDane();
	    }
	
	    void wyswietlWynik() 
		{
	        cout<<"Sklep odziezowy:"<<endl;
	        cout<< "Damska odziez:"<<endl;
	        damski.wyswietlWynik();
	        cout<<"Meska odziez:"<<endl;
	        meski.wyswietlWynik();
	    }
};

int main() 
{
    Produkt bluzka("Bluzka damska", 49.99, "M");
    Produkt koszula("Koszula meska", 79.99, "L");
    
	bluzka.wyswietlWynik();
	koszula.wyswietlWynik();
	
	
    SklepOdziezowy sklep(bluzka, koszula);

    cout<<"Wprowadz dane do sklepu odziezowego:"<<endl;
    
    sklep.czytajDane();
    sklep.wyswietlWynik();

    return 0;
}

