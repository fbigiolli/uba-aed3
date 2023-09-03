#include <math.h>
#include <vector>
#include <limits>

using namespace std;

const int INF = 1e11;

/*El algoritmo toma como entrada un vector de posibles valores de billetes, el parametro j 
que indica cuanto nos resta por pagar y el parametro i que nos indica cual es el indice del vector
que vamos a tomar, o sea, con que billete estamos pagando*/

pair<int,int> c_machine_backtracking(vector<int>& billetes, int i, int j)
{
    // Si no hay mas que pagar
    if (j <= 0)
    {
        return make_pair(0,0);
    }
    
    // Si me quede sin billetes para agregar
    if (i == billetes.size())
    {
        return make_pair(INF,INF);
    }

    pair<int,int> bt_con_billete = c_machine_backtracking(billetes, i++, j - billetes[i]); // Le resto a lo que falta pagar el valor del billete agregado
    pair<int,int> bt_sin_billete = c_machine_backtracking(billetes, i++, j); // No le resto el valor del billete agregado a j

    // No funciona porque min no tiene el overload para comparar pairs, pero es lo que tendria que devolver
    return min({bt_con_billete.first + billetes[i] , 1 + bt_con_billete.second},{bt_sin_billete});
}

vector<vector<pair<float, float>>> top_down_memo;

// En el main hay que inicializar top down memo con -1 en todas las posiciones
pair<float, float> c_machine_topdown(vector<int> &B, int i, int j) {
    if (i <= 0 && j > 0) 
    {
        return {INF, INF};
    }

     else if (j <= 0)
    {
        return {0, 0};
    }

    else 
    {
        // Si el valor no esta calculado hago la recursion para calcularlo
        if (top_down_memo[i - 1][j].first == -1) 
        {
            pair<float, float> r = c_machine_topdown(B, i - 1, j - B[i - 1]);
            top_down_memo[i - 1][j] = min(
                {B[i - 1] + r.first, 1.0 + r.second},
                c_machine_topdown(B, i - 1, j)
            );
        }

        // Si no, devuelvo lo que esta precalculado
        return top_down_memo[i - 1][j];
    }
}
