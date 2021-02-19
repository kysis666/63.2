#include <iostream>
#include <vector>
#include <fstream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

int ciag,add;

class klasa {
    vector <string> ciag;
    public:
    	void intro();
        void wypisz();
        bool boolcheck(string ciag);
        int zapiszDoPliku(const char *);             
};

void klasa::intro() {
	fstream plik;  
    string check;
    
    plik.open("ciagi.txt", ios::in); 
    if(plik.good()) 
    while(!plik.eof()) {
        plik >> check;
        ciag.push_back(check);
    }
    plik.close();          			
}


void klasa::wypisz() {
	for (int i = 0; i < ciag.size(); i++) {
		if(boolcheck(ciag[i]) == true) {
			add++;
		}	
	}
}


bool klasa::boolcheck(string ciag) {
	int add;
	for (int i = 0; i < ciag.length()-1; i++) {
		if (ciag[i] == '1' && ciag[i+1] == '1') {
			return false;
		}
	}
	return true;
}

klasa::zapiszDoPliku(const char *nazwa) {	
    ofstream plik;
    plik.open(nazwa);
    cout << add;
    plik << add;
    plik.close();
}

int main(int argc, char** argv) {
	klasa start;
	
    start.intro();
    start.wypisz();
    start.zapiszDoPliku("wynik.txt");
    
    return 0;
}
