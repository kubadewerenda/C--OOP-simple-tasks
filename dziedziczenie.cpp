#include <iostream>
#include <string>

using namespace std;

class Pracownik{
protected:
    static const int STAWKA=20;
    int id;
    static int licznik;
    string imie;
    string nazwisko;

public:
    Pracownik():id(++licznik),imie("Andrzej"),nazwisko("Kapral"){}
    Pracownik(const string& imie,const string& nazwisko)
        :id(++licznik),imie(imie),nazwisko(nazwisko){}

    virtual ~Pracownik() 
	{
        cout<<"Destruktor Pracownik: "<<imie<<" "<<nazwisko<<endl;
    }

    string getImie() const 
	{
        return imie;
    }

    void setImie(const string& noweImie) 
	{
        imie=noweImie;
    }

    string getNazwisko() const 
	{
        return nazwisko;
    }

    void setNazwisko(const string& noweNazwisko) 
	{
        nazwisko=noweNazwisko;
    }
};

int Pracownik::licznik=0;

class Kierownik:public Pracownik 
{
private:
    string nazwa_zespolu;

public:
    Kierownik(const string& nazwa_zespolu)
        : Pracownik(), nazwa_zespolu(nazwa_zespolu) {}

    ~Kierownik() 
	{
        cout<<"Destruktor Kierownik: "<<getImie()<<" "<<getNazwisko()<<endl;
    }

    string getNazwaZespolu() const 
	{
        return nazwa_zespolu;
    }

    void setNazwaZespolu(const string& nowaNazwaZespolu) 
	{
        nazwa_zespolu=nowaNazwaZespolu;
    }
};

class Informatyk : public Pracownik 
{
public:
    Informatyk():Pracownik(){}
    Informatyk(const Pracownik& pracownik):Pracownik(pracownik) 
	{
        cout<<"Konstruktor kopiujacy Informatyk: "<<getImie()<<" "<<getNazwisko()<<endl;
    }

    ~Informatyk() 
	{
        cout<<"Destruktor Informatyk: "<<getImie()<<" "<<getNazwisko()<<endl;
    }
};

int main() 
{
    Pracownik pracownikDomyslny;
    cout<<"Utworzono pracownika domyslnego: "<<pracownikDomyslny.getImie()<<" "<<pracownikDomyslny.getNazwisko()<<endl;

    string imie, nazwisko;
    cout<<"Imie: ";
    cin>>imie;
    cout<<"Naazwisko: ";
    cin>>nazwisko;
    Pracownik pracownikSparametryzowany(imie, nazwisko);
    cout<<"Utworzono pracownika sparametryzowanego: "<<pracownikSparametryzowany.getImie()<<" "<<pracownikSparametryzowany.getNazwisko()<<endl;

    Informatyk informatykDomyslny;
    cout<<"Utworzono informatyka domyslnego: "<<informatykDomyslny.getImie()<<" "<<informatykDomyslny.getNazwisko()<<endl;

    Informatyk kopiaInformatyka(pracownikDomyslny);
    cout<<"Utworzono kopie informatyka: "<<kopiaInformatyka.getImie()<<" "<<kopiaInformatyka.getNazwisko()<<endl;

    Kierownik kierownik("Zespol IT");
    cout<<"Utworzono kierownika: "<<kierownik.getImie()<<" "<<kierownik.getNazwisko()<<" - Zespol: "<<kierownik.getNazwaZespolu()<<endl;

    Pracownik* zespol[3];
    zespol[0]=new Kierownik("Zespol Kierownika");
    zespol[1]=new Informatyk();
    zespol[2]=new Pracownik("Kowal", "Kowalski");

    for(int i=0;i<3;++i) 
	{
        cout<<"ID "<<i+1<<": "<<zespol[i]->getImie()<<" "<<zespol[i]->getNazwisko()<<endl;
    }

    for(int i=0;i<3;++i) 
	{
        delete zespol[i];
    }

    return 0;
}

