#include <iostream>
#include <string>

using namespace std;

class Sklep
{
	private:
	    string* pola;  
	    int liczbaPol;  
	
	public:
	    Sklep():pola(NULL),liczbaPol(0)
		{
			dodaj("Bluza");
	        dodaj("Koszula");
	        dodaj("Spodnie");
	        dodaj("Sukienka");
		}
	
	    ~Sklep() 
		{
	        delete[] pola;
	    }

	    void dodaj(const string& pole) 
		{
	        string* nowePola=new string[liczbaPol + 1];

	        for(int i=0;i<liczbaPol;++i) 
			{
	            nowePola[i]=pola[i];
	        }

	        nowePola[liczbaPol]=pole;

	        delete[] pola;

	        pola=nowePola;

	        ++liczbaPol;
    }

    bool czyPoleIstnieje(const string& pole) 
	{
        for(int i=0;i<liczbaPol;++i)
		{
            if(pola[i]==pole) 
			{
                return true;
            }
        }
        return false;
    }

    void zamienPole(const string& pole1, const string& pole2) {
        for (int i = 0; i < liczbaPol; ++i) {
            if (pola[i] == pole1) {
                pola[i] = pole2;
            } else if (pola[i] == pole2) {
                pola[i] = pole1;
            }
        }
    }

    void wyswietl() 
	{
        cout<<"Pola w kolekcji: ";
        cout<<endl;
        for(int i=0;i<liczbaPol;++i) 
		{
            cout<<pola[i]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
};

int main() 
{
    Sklep sklep;

    sklep.wyswietl();

    cout << "Dodaj pole do kolekcji: ";
    string nowePole;
    getline(cin, nowePole);

    sklep.dodaj(nowePole);

    cout << "Sprawdz istnienie pola w kolekcji: ";
    string sprawdzPole;
    getline(cin, sprawdzPole);

    cout << "Czy istnieje " << sprawdzPole << "? " << (sklep.czyPoleIstnieje(sprawdzPole) ? "Tak" : "Nie") << endl;

    cout << "Podaj dwa pola do zamiany miejscami: ";
    string zamianaPole1, zamianaPole2;
    cin >> zamianaPole1 >> zamianaPole2;

    sklep.zamienPole(zamianaPole1, zamianaPole2);

    cout << "Zamieniono miejsca dla " << zamianaPole1 << " i " << zamianaPole2 << endl;
    sklep.wyswietl();

    return 0;
}

