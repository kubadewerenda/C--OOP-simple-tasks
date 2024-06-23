#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Sklep{
	protected:
		int id;
		int licznik;
		string nazwa; //cecha wspolna
	public:
		Sklep():id(++licznik),nazwa("---"){}
		Sklep(string n)
			:id(++licznik),nazwa(n){}
		virtual ~Sklep(){}	
		
		virtual void dodaj()=0;
		virtual void wypiszInformacje(Sklep& s)
		{
			cout<<"---Informacje---"<<endl;
			cout<<"Nazwa: "<<s.nazwa<<endl;	
		}
		
		string getNazwa()
		{
			return nazwa;
		}
		
		void setNazwa(const string& n)
		{
			nazwa=n;
		}
	
};

class Produkt:public Sklep
{
	private:
		string rozmiar;//cecha dodatkowa
	public:
		Produkt()
			:Sklep(),rozmiar("---"){}
		Produkt(Produkt& p)
			:Sklep(p.nazwa),rozmiar(p.rozmiar){}
		Produkt(string n,string r)
			:Sklep(n),rozmiar(r){}	
		//virtual ~Sklep(){}
		
		virtual void dodaj()
		{
			cout<<"---Dodawanie produktu---"<<endl;
			cout<<"Podaj nazwe: ";
			cin>>nazwa;
			cout<<"Podaj rozmiar: ";
			cin>>rozmiar;	
		}
		virtual void wypiszInformacje(Sklep& s)
		{
			Sklep::wypiszInformacje(s);	
			cout<<"Rozmiar: "<<rozmiar<<endl;
		}
		
		string getRozmiar()
		{
			return rozmiar;
		}
		
		void setRozmiar(const string& r)
		{
			rozmiar=r;
		}			
			
};
int main() 
{
	Produkt p1("Bluza","M");
	Produkt p1_kopia(p1);
	
	Produkt* wsk=&p1;
	
	wsk->dodaj();
	
	p1.wypiszInformacje(p1);
	
		
	delete p1;
	delete p1_kopia;
	
	return 0;
}
