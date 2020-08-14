#include <iostream>
#include <array>
#include <string>
using namespace std;
int carta1 = 0, carta2 = 0, carta3 = 0, carta4 = 0, carta5 = 0;

class Jugador
{
    string nombre;
    int cartas[5];
    int puntuacion;

public:
    void setCartas()
    {
        cartas[1] = rand() % 11 + 1;
        cartas[2] = rand() % 11 + 1;
        cartas[3] = rand() % 11 + 1;
    }
    string getNombre()
    {
        return nombre;
    }
    void setNombre(string n)
    {
        nombre = n;
    }
    int getPuntuacion()
    {
        return puntuacion;
    }
    void setPuntuacion(int p)
    {
        puntuacion = p;
    }
};

class Juego
{
public:
    void Jugar(int n, string nombre)
    {
        carta1 = rand() % 11 + 1;
        carta2 = rand() % 11 + 1;
        carta3 = rand() % 11 + 1;
        Jugador usuario;
        usuario.setNombre(nombre);
        usuario.setCartas();
        cout << usuario.getNombre() << ": [" << carta1 << "|" << carta2 << "|" << carta3 << "|"
             << "]" << endl;
        cout << "-> Tomar otra carta?[1-Si|2-No]: ";
        int resp;
        cin >> resp;
        int p_user = 0;
        if (resp == 1)
        {
            carta4 = rand() % 11 + 1;
            cout << usuario.getNombre() << ": [" << carta1 << "|" << carta2 << "|" << carta3 << "|" << carta4
                 << "]" << endl;
            cout << "-> Tomar otra carta?[1-Si|2-No]: ";
            cin >> resp;
            if (resp == 1)
            {
                carta5 = rand() % 11 + 1;
                cout << usuario.getNombre() << ": [" << carta1 << "|" << carta2 << "|" << carta3 << "|" << carta4 << "|" << carta5 << "|"
                     << "]" << endl;
                cout << "-> Tomar otra carta?[1-Si|2-No]: ";
                cin >> resp;
                p_user = carta1 + carta2 + carta3 + carta4 + carta5;
            }
            else
            {
                p_user = carta1 + carta2 + carta3 + carta4;
            }
        }
        else
        {
            p_user = carta1 + carta2 + carta3;
        }
        cout << usuario.getNombre() << " | Puntuacion: " << p_user << endl;
        int punt_bot, cont = 0;
        bool flag;
        Jugador b;
        while (cont < n - 1)
        {
            carta1 = rand() % 11 + 1;
            carta2 = rand() % 11 + 1;
            carta3 = rand() % 11 + 1;
            punt_bot = carta1 + carta2 + carta3;
            while (flag)
            {
                if (punt_bot < 18)
                {
                    punt_bot += rand() % 11 + 1;
                }
                else if (punt_bot < 25)
                {
                    if (rand() % 9 + 1 >= 5)
                    {
                        punt_bot += rand() % 11 + 1;
                    }
                    else
                    {
                        b.setNombre("bot-1");
                        b.setPuntuacion(punt_bot);
                        flag = false;
                    }
                }
                else
                {
                    b.setNombre("bot-1");
                    b.setPuntuacion(punt_bot);
                    flag = false;
                }
            }
            cout << "bot-" << cont + 1 << " | Puntuacion: " << punt_bot << endl;
            cont++;
        }
    }
};

int main()
{
    cout << "Ingrese el numero de jugadores: ";
    int n_jugadores;
    cin >> n_jugadores;
    cout << "Ingrese su nombre: ";
    string nombre;
    cin >> nombre;
    Juego j;
    j.Jugar(n_jugadores, nombre);

    return 0;
}