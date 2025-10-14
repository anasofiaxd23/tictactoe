#include <iostream>
using namespace std;

int main() {
    char tablero[9];
    for (int i = 0; i < 9; i++)
        tablero[i] = ' ';

    char jugador;
    cout << "¿Quién empieza el juego? (X o O): ";
    cin >> jugador;

    if (jugador != 'X' && jugador != 'O' && jugador != 'x' && jugador != 'o') {
        cout << "no se puede. Comienza X por defecto." << endl;
        jugador = 'X';
    }

    int movimientos = 0;
    bool terminado = false;

    cout << "triki" << endl;
    cout << "Guia de posiciones" << endl;
    cout << " 1 | 2 | 3 " << endl;
    cout << "---+---+---" << endl;
    cout << " 4 | 5 | 6 " << endl;
    cout << "---+---+---" << endl;
    cout << " 7 | 8 | 9 " << endl;

    while (!terminado) {
        cout << endl << "Tablero actual" << endl;
        cout << " " << tablero[0] << " | " << tablero[1] << " | " << tablero[2] << endl;
        cout << "---+---+---" << endl;
        cout << " " << tablero[3] << " | " << tablero[4] << " | " << tablero[5] << endl;
        cout << "---+---+---" << endl;
        cout << " " << tablero[6] << " | " << tablero[7] << " | " << tablero[8] << endl;

        char entrada; 
        cout << endl << "Jugador " << jugador << ", elige tu casilla : ";
        cin >> entrada;

        if (entrada != '1' && entrada != '2' && entrada != '3' &&
            entrada != '4' && entrada != '5' && entrada != '6' &&
            entrada != '7' && entrada != '8' && entrada != '9') {
            cout << "Error; solo puedes ingresar un numero del 1 al 9." << endl;
            continue;
        }

        int pos = entrada - '0'; 

        if (tablero[pos - 1] == 'X' || tablero[pos - 1] == 'O') {
            cout << "Movimiento invalido, esa casilla ya esta ocupada." << endl;
            continue;
        }

        tablero[pos - 1] = jugador;
        movimientos++;

        if (
            (tablero[0] == jugador && tablero[1] == jugador && tablero[2] == jugador) ||
            (tablero[3] == jugador && tablero[4] == jugador && tablero[5] == jugador) ||
            (tablero[6] == jugador && tablero[7] == jugador && tablero[8] == jugador) ||
            (tablero[0] == jugador && tablero[3] == jugador && tablero[6] == jugador) ||
            (tablero[1] == jugador && tablero[4] == jugador && tablero[7] == jugador) ||
            (tablero[2] == jugador && tablero[5] == jugador && tablero[8] == jugador) ||
            (tablero[0] == jugador && tablero[4] == jugador && tablero[8] == jugador) ||
            (tablero[2] == jugador && tablero[4] == jugador && tablero[6] == jugador)
        ) {
            cout << endl;
            cout << " " << tablero[0] << " | " << tablero[1] << " | " << tablero[2] << endl;
            cout << "---+---+---" << endl;
            cout << " " << tablero[3] << " | " << tablero[4] << " | " << tablero[5] << endl;
            cout << "---+---+---" << endl;
            cout << " " << tablero[6] << " | " << tablero[7] << " | " << tablero[8] << endl;
            cout << endl << "EL JUGADOR " << jugador << " GANO" << endl;
            terminado = true;
        } else if (movimientos == 9) {
            cout << "EMPATE" << endl;
            terminado = true;
        } else {
            if (jugador == 'X' || jugador == 'x') {
                jugador = 'O';
            } else {
                jugador = 'X';
            }
        }
    }
}
