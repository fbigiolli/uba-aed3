#include <vector>
#include <iostream>
using namespace std;

vector<int> res;
int max_sum = -1;

vector<int> matrix_max_subset_sum(vector<vector<int>>& mat, int k, int i, vector<int>&subset, int sum)
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
    else if (i < n)
    {
        // Agrego i al subset
        subset.push_back(i);
        int new_element_sum = 0;

        // Calculo la suma de las posibles combinaciones de i con los elementos del subset
        for (int j = 0; j < subset.size(); j++)
        {
            new_element_sum += mat[i][subset[j]] * 2; // la matriz es simetrica, no hace falta acceder a la posicion espejo
        }
        
        // Recursion + backtracking
        matrix_max_subset_sum(mat,k-1,i+1,subset,sum+new_element_sum);
        subset.pop_back();
        matrix_max_subset_sum(mat,k,i+1,subset,sum);
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
    for (int i = 0; i < subset.size(); i++)
    {
        cout << subset[i] ;
    }
    

    return 0;
}
