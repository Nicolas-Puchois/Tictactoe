#include <iostream>
using namespace std;

class Joueur
{
private:
    char symbole;
    string nom;

public:
    // Constructor
    Joueur(char symbole, string nom) : symbole(symbole), nom(nom) {}

    // Getter methods
    char getSymbole() const { return symbole; }
    string getNom() const { return nom; }
};

class Plateau
{
private:
    // Tableau pour stocker l'état du jeu
    char grille[3][3];
    int compteurCaseRemplie = 0; // compteur de case remplie

public:
    // Initialisation de la grille
    // Constructeur pour initialiser le plateau
    Plateau() : compteurCaseRemplie(0)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                grille[i][j] = ' ';
            }
        }
    }

    void dessinerGrille(int taille)
    {
        for (int i = 0; i < taille; ++i)
        {
            // Ligne horizontale
            for (int k = 0; k < taille; ++k)
            {
                cout << "+---";
            }
            cout << "+" << endl;

            // Ligne avec les symboles
            for (int j = 0; j < taille; ++j)
            {
                cout << "| " << grille[i][j] << " ";
            }
            cout << "|" << endl;
        }

        // Dernière ligne horizontale
        for (int k = 0; k < taille; ++k)
        {
            cout << "+---";
        }
        cout << "+" << endl;
    }

    bool verifierVictoire(char symbole)
    {
        // Vérifier les lignes
        for (int i = 0; i < 3; i++)
        {
            if (grille[i][0] == symbole && grille[i][1] == symbole && grille[i][2] == symbole)
            {
                return true;
            }
        }

        // Vérifier les colonnes
        for (int i = 0; i < 3; i++)
        {
            if (grille[0][i] == symbole && grille[1][i] == symbole && grille[2][i] == symbole)
            {
                return true;
            }
        }

        // Vérifier les diagonales
        if (grille[0][0] == symbole && grille[1][1] == symbole && grille[2][2] == symbole)
        {
            return true;
        }
        if (grille[0][2] == symbole && grille[1][1] == symbole && grille[2][0] == symbole)
        {
            return true;
        }

        return false;
    }

    bool estPleine() const
    {
        return compteurCaseRemplie == 9;
    }

    // vérifier si le coup est valide
    bool estValide(int ligne, int colonne)
    {
        // Vérifier les limites
        if (ligne < 0 || ligne >= 3 || colonne < 0 || colonne >= 3)
        {
            return false;
        }
        // Vérifier si la case est libre
        return grille[ligne][colonne] == ' ';
    }

    // méthode pour faire un coup
    void faireUncoup(int ligne, int colonne, Joueur joueurActuel)
    {
        if (estValide(ligne, colonne))
        {
            grille[ligne][colonne] = joueurActuel.getSymbole();
            compteurCaseRemplie++;
        }
    }
};

// Game class to manage the game logic
class Morpion
{
private:
    Plateau plateau;
    Joueur joueurs[2];
    int indexJoueurActuel;

public:
    // Constructeur
    Morpion() : indexJoueurActuel(0),
                joueurs{Joueur('X', "Joueur 1"), Joueur('O', "Joueur 2")}
    {
    }

    // Méthode pour obtenir le joueur actuel
    Joueur obtenirJoueurActuel()
    {
        return joueurs[indexJoueurActuel];
    }

    // Méthode pour changer de tour
    void changerTour()
    {
        indexJoueurActuel = (indexJoueurActuel + 1) % 2;
    }

    // Méthode pour jouer le jeu
    void jouer()
    {
        int ligne, colonne;
        cout << "Bienvenue au Morpion!" << endl;

        while (!plateau.estPleine())
        {
            // Afficher le plateau
            plateau.dessinerGrille(3);

            Joueur joueurActuel = obtenirJoueurActuel();

            // Obtenir une entrée valide
            while (true)
            {
                cout << joueurActuel.getNom() << " (" << joueurActuel.getSymbole()
                     << "), entrez ligne (1-3) et colonne (1-3): ";
                cin >> ligne >> colonne;
                ligne--;
                colonne--; // Convertir en index 0

                if (plateau.estValide(ligne, colonne))
                {
                    break;
                }
                else
                {
                    cout << "Coup invalide ! Essayez une autre case." << endl;
                }
            }

            // Faire le coup
            plateau.faireUncoup(ligne, colonne, joueurActuel);

            // Vérifier la victoire
            if (plateau.verifierVictoire(joueurActuel.getSymbole()))
            {
                plateau.dessinerGrille(3);
                cout << joueurActuel.getNom() << " gagne!" << endl;
                return;
            }

            // Changer de tour
            changerTour();
        }

        // Jeu terminé par match nul
        plateau.dessinerGrille(3);
        cout << "Match nul!" << endl;
    }
};

int main()
{
    Morpion jeu;
    jeu.jouer();
    return 0;
}