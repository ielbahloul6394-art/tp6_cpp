#include <iostream>
#include <string>
using namespace std;

class Employe {
protected:
    string nom;
    int id;
    float salaireDeBase;

public:
    Employe(string n, int i, float s) {
        nom = n;
        id = i;
        salaireDeBase = s;
    }

    virtual void afficherInfos() {
        cout << "Nom : " << nom << endl;
        cout << "ID : " << id << endl;
        cout << "Salaire de base : " << salaireDeBase << " DH" << endl;
    }

    virtual ~Employe() {
        cout << "Destruction de l'employe " << nom << endl;
    }
};

class Permanent : public Employe {
private:
    float primeAnnuelle;

public:
    Permanent(string n, int i, float s, float prime)
        : Employe(n, i, s) {
        primeAnnuelle = prime;
    }

    void afficherInfos() override {
        cout << "\n--- Employe permanent ---" << endl;
        Employe::afficherInfos();
        cout << "Prime annuelle : " << primeAnnuelle << " DH" << endl;
    }
};

class Contractuel : public Employe {
private:
    int dureeContrat;
    float tauxHoraire;

public:
    Contractuel(string n, int i, float s, int duree, float taux)
        : Employe(n, i, s) {
        dureeContrat = duree;
        tauxHoraire = taux;
    }

    float calculerSalaireMensuel(int heures) {
        return heures * tauxHoraire;
    }

    void afficherInfos() override {
        cout << "\n--- Employe contractuel ---" << endl;
        Employe::afficherInfos();
        cout << "Duree du contrat : " << dureeContrat << " mois" << endl;
        cout << "Taux horaire : " << tauxHoraire << " DH" << endl;
    }
};

int main() {
    Employe** employes = new Employe*[3];

    employes[0] = new Permanent("Imane", 101, 6000, 5000);
    employes[1] = new Contractuel("Sara", 102, 3000, 6, 50);
    employes[2] = new Permanent("Salma", 103, 7000, 6000);

    for (int i = 0; i < 3; i++) {
        employes[i]->afficherInfos();
    }

    cout << "\n--- Calcul du salaire mensuel ---" << endl;

    Contractuel* c = dynamic_cast<Contractuel*>(employes[1]);

    if (c != nullptr) {
        cout << "Salaire pour 160 heures : "
             << c->calculerSalaireMensuel(160) << " DH" << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete employes[i];
    }

    delete[] employes;

    return 0;
}