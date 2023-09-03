#include <vector>
#include <math.h>

using namespace std;

const int NINF = -1e9;

vector<vector<int>> memo;

// Hay que setear todo memo en -1 antes de llamar a la funcion. 
int astroVoid(vector<int>& price_per_day, int asteroids, int day)
{
    // Se compraron mas asteroides que dias transcurridos o se vendieron mas de los que habia
    if(asteroids < 0 or asteroids > day)
    {
        return NINF;
    }

    // Caso base
    if (day == 0)
    {
        return 0;
    }
    
    // Recursion

    // Si el valor ya esta calculado lo devuelvo
    if (memo[asteroids][day] != -1)
    {
        return memo[asteroids][day];
    }

    // Si no lo calculo y lo devuelvo
    else
    {
        memo[asteroids][day] = max(astroVoid(price_per_day, asteroids, day - 1), // No hago nada
                                    max(astroVoid(price_per_day,asteroids - 1, day - 1) + price_per_day[day - 1], // Vendo 
                                    astroVoid(price_per_day,asteroids + 1,day - 1))); // Compro 
    }
    return memo[asteroids][day];
}