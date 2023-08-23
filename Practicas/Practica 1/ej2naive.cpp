#include <vector>
#include <iostream>
using namespace std;

bool is_valid(vector<vector<int>>& square)
{
    int n = square.size();

    // Calcular numero magico

    int magicNumber = 0;
    for (int i = 0; i < n; i++)
    {
        magicNumber += square[i][0];
    }
    
    // Chequear que las filas y columnas cumplan

    for (int i = 0; i < n; i++)
    {
        int row = 0;
        int col = 0;
        for (int j = 0; j < n; j++)
        {
            row += square[i][j];
            col += square[j][i];
        }
        
        if (row != magicNumber || col != magicNumber)
        {
            return false;
        }
    }
    

    // Chequear diagonales

    int diagonal1 = 0;
    int diagonal2 = 0;

    for (int i = 0; i < n; i++)
    {
        diagonal1 += square[i][i];
        diagonal2 += square[i][n-i-1];
    }

    if (diagonal1 != magicNumber || diagonal2 != magicNumber)
    {
        return false;
    }
    
    return true;
}

int magic_squares(vector<vector<int>>& square, int i, int j, vector<int>& candidates)
{
    int n = square.size();
    if (j == n) return magic_squares(square,i+1,0,candidates); // fin de la fila
    if (i == n) return is_valid(square); // el cuadrado esta lleno 
    int res = 0;

    for (int k = 0; k < n*n; k++)
    {
        if (candidates[k] == 0) // Si el candidato no fue usado
        {
            square[i][j] = k + 1;
            candidates[k] = 1;
            res += magic_squares(square,i,j+1,candidates);
            candidates[k] = 0; // backtracking 
        }
    }
    return res;
}