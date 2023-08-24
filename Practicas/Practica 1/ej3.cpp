#include <vector>
#include <iostream>
using namespace std;

vector<int> res;
int max_sum = -1;

// Algoritmo top-down backtracking. El algoritmo hace varios recorridos de mas ya que genera todos los subsets posibles entre i y n, mas alla de aquellos que sean mayores al k.
void matrix_max_subset_sum(vector<vector<int>>& mat, int k, int i, vector<int>&subset, int sum)
{
    int n = mat.size();

    // Si k == 0 es porque el size del subset es el maximo posible
    if (k == 0)
    {
        if (sum > max_sum)
        {
            // Entonces, si sumo mas actualizo el vector resultado.
            res = subset;
            max_sum = sum;
        }
    }

    // Ademas, si i es menor al numero de filas/columnas de la matriz
    else
    {
        // No es un else if porque si no el algoritmo recorreria subsets innecesarios en los que hay mas elementos de los que k permite en ciertos casos.
        if (i < n)
        {
             // Agrego i al subset
            subset.push_back(i);
            int new_element_sum = 0;

            // Calculo la suma de las posibles combinaciones de i con los elementos del subset
            for (int j = 0; j < subset.size(); j++)
            {
                new_element_sum += mat[i][subset[j]] + mat[subset[j]][i]; // la matriz es simetrica, no hace falta acceder a la posicion espejo
            }
            
            // Recursion + backtracking
            matrix_max_subset_sum(mat,k-1,i+1,subset,sum+new_element_sum);
            subset.pop_back();
            matrix_max_subset_sum(mat,k,i+1,subset,sum);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n = 4;
    vector<vector<int>> mat = {{  0, 10, 10,  1},
                               { 10,  0,  5,  2},
                               { 10,  5,  0,  1},
                               {  1,  2,  1,  0}};

    int k = 3;

    vector<int> subset;
    matrix_max_subset_sum(mat,k,0,subset,0);

     // Print solution.
    for (int i = 0; i < res.size(); i++)
    {   
        // Aca en realidad habria que sumarle 1 a cada output para cumplir con el enunciado, porque arranca a indexar desde el 0
        cout << res[i] << " " ;
    }
    

    return 0;
}

