#include <iostream>
using namespace std;

void dessinerCarre(int taille)
{
    for (int i = 0; i < taille; ++i)
    {
        for (int j = 0; j < taille; ++j)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int main()
{
    int taille = 3; // Taille du carré
    dessinerCarre(taille);
    return 0;
}