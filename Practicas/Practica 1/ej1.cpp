#include <vector>
#include <iostream>
using namespace std;

// La implementacion va a tomar como entrada un vector, ya que no hay un modulo de multiconjunto en la STL.

bool exists_subset_sum(vector<int>& set, int i, int j, vector<int>& subset)
{
    if (j < 0) return false; //  Regla de factibilidad para no considerar aquellos conjuntos que se pasan de la suma

    if(j == 0) // Print del subset valido
    {
        for(auto num : subset)
        {
            cout << num << " ";
        }
        cout << "Fin del subset ";
        return true;
    }

    if (i == 0) return false; // No hay mas posiciones para recorrer

    // Recursion incluyendo el elemento actual al subset
    subset.push_back(set[i-1]);
    bool included = exists_subset_sum(set,i-1,j - set[i-1],subset);
    subset.pop_back();

    // Recursion no incluyendo el elemento actual al subset
    bool not_included = exists_subset_sum(set,i-1,j,subset);

    return included or not_included;
}


// Driver code

int main()
{
    // Inicializar un vector con valores arbitrarios
    vector<int> set;
    for (int i = 0; i < 15; i++)
    {
        set.push_back(i);
    }

    // Inicializar subset vacio y valor solicitado para la suma
    int k = 58;
    vector<int> subset;

    if(!exists_subset_sum(set,set.size(),k,subset)) cout << "No existe un subconjunto que sume " << k << endl;

    return 0;
}