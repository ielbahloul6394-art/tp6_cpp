#include <iostream>
using namespace std;

class Compte {
protected:
    int numero;
    double solde;

public:
    Compte(int num, double s) {
        numero = num;
        solde = s;
    }

    void deposer(double montant) {
        if (montant > 0) {
            solde += montant;
            cout << "Depot effectue avec succes." << endl;
        }
    }

    void retirer(double montant) {
        if (montant > 0 && montant <= solde) {
            solde -= montant;
            cout << "Retrait effectue avec succes." << endl;
        } else {
            cout << "Retrait impossible." << endl;
        }
    }

    void afficher() {
        cout << "Numero du compte : " << numero << endl;
        cout << "Solde : " << solde << " DH" << endl;
    }
};

class CompteEpargne : public Compte {
private:
    double tauxInteret;

public:
    CompteEpargne(int num, double s, double taux)
        : Compte(num, s) {
        tauxInteret = taux;
    }

    double calculerInteret() {
        return solde * tauxInteret / 100;
    }
};

int main() {
    CompteEpargne c(1234, 1000, 5);

    c.afficher();

    c.deposer(500);
    c.retirer(200);

    cout << "\nApres les operations :" << endl;
    c.afficher();

    cout << "Interet : " << c.calculerInteret() << " DH" << endl;

    return 0;
}