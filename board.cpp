#include <iostream>
using namespace std;

class Joueur
{
private:
    char symbole;
    string name;

public:
    // Constructor
    Joueur(char symbole = 'X', string name = "Player X") : symbole(symbole), name(name) {}

    // Getter methods
    char getSymbole() const { return symbole; }
    string getName() const { return name; }
};

class Board
{
private:
    // Tableau pour stocker l'état du jeu
    char grille[3][3];
    int compteurCaseRemplie = 0; // compteur de case remplie

public:
    // Initialisation de la grille
    // Constructor to initialize the board
    Board() : filledCells(0)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                grid[i][j] = ' ';
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

            // Ligne avec espaces
            for (int j = 0; j < taille; ++j)
            {
                cout << "|   ";
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

    bool verifierVictoire()
    {
        // Check rows
        for (int i = 0; i < 3; i++)
        {
            if (grille[i][0] == symbole && grille[i][1] == symbole && grille[i][2] == symbole)
            {
                return true;
            }
        }

        // Check columns
        for (int i = 0; i < 3; i++)
        {
            if (grille[0][i] == symbole && grille[1][i] == symbole && grille[2][i] == symbole)
            {
                return true;
            }
        }

        // Check diagonals
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

    bool isFull() const
    {
        return compteurCaseRemplie == 9;
    }
};

// Game class to manage the game logic
class Morpion
{
private:
    Board board;
    Joueur joueurs[2];
    int currentPlayerIndex;

public:
    // Constructor
    Morpion() : currentPlayerIndex(0)
    {
        joueurs[0] = Joueur('X', "Joueur 1");
        joueurs[1] = Joueur('O', "Joueur 2");
    }

    // Method to get the current player
    Joueur getCurrentPlayer()
    {
        return joueurs[currentPlayerIndex];
    }

    // Method to switch turns
    void changerTour()
    {
        currentPlayerIndex = (currentPlayerIndex + 1) % 2;
    }

    // Method to play the game
    void play()
    {
        int row, col;
        cout << "Welcome to Tic-Tac-Toe!" << endl;

        while (!board.isFull())
        {
            // Display the board
            board.dessinerGrille();

            Joueur &joueurs = getCurrentPlayer();

            // Get valid input
            while (true)
            {
                cout << currentPlayer.getName() << " (" << currentPlayer.getSymbol()
                     << "), enter row (1-3) and column (1-3): ";
                cin >> row >> col;
                row--;
                col--; // Convert to 0-indexed

                if (board.isValidMove(row, col))
                {
                    break;
                }
                else
                {
                    cout << "Invalid move. Try again." << endl;
                }
            }

            // Make move
            board.makeMove(row, col, currentPlayer.getSymbol());

            // Check for win
            if (board.checkWin(currentPlayer.getSymbol()))
            {
                board.drawBoard();
                cout << currentPlayer.getName() << " wins!" << endl;
                return;
            }

            // Switch turns
            switchTurn();
        }

        // Game ended in a draw
        board.drawBoard();
        cout << "It's a draw!" << endl;
    }
};

int main()
{
}