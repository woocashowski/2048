#include<iostream>
#include<ctime>
#include<unistd.h>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<conio.h>

using namespace std;

int tab[4][4];
void tablica();
void generuj();
void ruch();
void sprawdz();

int main()
{
    srand(time(NULL));
    //Inicjacja tablicy
    for (int i = 0; i<4; i++)
    {
        for (int j = 0; j<4; j++)
        {
            tab[j][i] = 0;
        }
    }


    tablica();
}

void tablica()
{
    int a, b, c, d;

    d = 0;

    for (;d == 0;)
    {
        a = rand()%4;
        b = rand()%4;
        c = rand()%2;
        if(tab[a][b]==0)
        {
            tab[a][b] = (c+1)*2;

            d = 1;
        }
    }
    generuj();
}


void generuj()
{
    int a, b;
    system ("cls");

    cout << " Gra 2048 \n ";


    int biggest = 0;
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if(tab[x][y] > biggest)
                {
                    biggest = tab[x][y];
                }
        }
    }
    int l = 0;
    for(;  biggest >= 1; l++)
       biggest=biggest/10;


    for (int y = 0; y < 4; y++)
    {
        for (int i=0; i<=2; i++)
            cout << endl;
        cout << "     ";
        for (int x = 0; x < 4; x++)
        {
            cout << tab[x][y];

            b = tab[x][y];
            for(a = 0;  b >= 1; a++)
                b=b/10;

            //cout << a;

            for (int i=0; i<=5-a; i++)
                cout <<" ";
            if (tab[x][y] != 0)
                cout <<" ";
        }
    }
    cout << endl << endl;
    sprawdz();
    cout <<" Sterowanie: \n W - gora \n S - dol \n A - lewo \n D - prawo \n R - reset \n";
    ruch();
}

void ruch()
{
    char znak = getch();
    int k = 0;
    switch (znak)
    {
    case 'w':
        for (int x = 0; x < 4 ; x++) //wszystkie X
        {
            for (int y = 0; y < 3; y++) //Y bez dolnego rzêdu s¹ sprawdzane
            {
                if(tab[x][y] == 0)
                {
                    if (tab[x][y+1] != 0)
                        {
                            tab[x][y] = tab[x][y+1];
                            tab[x][y+1] = 0;
                            k++;
                        }
                    else if( tab[x][y+2] != 0 && y < 2)
                        {
                            tab[x][y] = tab[x][y+2];
                            tab[x][y+2] = 0;
                            k++;
                        }
                    else if( tab[x][y+3] != 0 && y < 1)
                    {
                        tab[x][y] = tab[x][y+3];
                        tab[x][y+3] = 0;
                        k++;
                    }
                }

                if (tab[x][y] != 0)
                {
                    if (tab[x][y] == tab[x][y+1]) //Sprawdzenie czy mo¿na po³¹czyæ s¹siaduj¹ce
                    {
                        tab[x][y] = 2 * tab[x][y];
                        tab[x][y+1] = 0;
                        k++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 2
                    else if(tab[x][y] == tab[x][y+2] && tab[x][y+1] == 0 && tab[x][y+2] != 0 && y < 2)
                    {
                        tab[x][y] = 2 * tab[x][y];
                        tab[x][y+2] = 0;
                        k++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 3
                    else if(tab[x][y] == tab[x][y+3] && tab[x][y+1] == 0 && tab[x][y+2] == 0 && tab[x][y+3] != 0 && y < 1)
                    {
                        tab[x][y] = 2 * tab[x][y];
                        tab[x][y+3] = 0;
                        k++;
                    }
                }

                // Jeœli pole jest równe 0 to sprawdŸ czy da siê coœ "wstawiæ"
                else if(tab[x][y] == 0)
                {
                    if (tab[x][y+1] != 0)
                        {
                            tab[x][y] = tab[x][y+1];
                            tab[x][y+1] = 0;
                            k++;
                        }
                    else if( tab[x][y+2] != 0 && y < 2)
                        {
                            tab[x][y] = tab[x][y+2];
                            tab[x][y+2] = 0;
                            k++;
                        }
                    else if( tab[x][y+3] != 0 && y < 1)
                    {
                        tab[x][y] = tab[x][y+3];
                        tab[x][y+3] = 0;
                        k++;
                    }
                    else
                    {
                        //cout << "Brak ruchu";
                    }
                }
            }
        }

        if (k >= 1)
        {
            //cout << " Bylo " << k;
            //getchar();
            //getchar();
        }
        else
        {
            //cout << " Nie bylo "<<k;
            //getchar();
            //getchar();
            generuj();
        }

        break;


    case 's':
        for (int x = 0; x < 4 ; x++) //wszystkie X
            for (int y = 3; y > 0; y--) //Y bez dolnego rzêdu s¹ sprawdzane
            {
                if(tab[x][y] == 0)
                {
                    if (tab[x][y-1] != 0)
                        {
                            tab[x][y] = tab[x][y-1];
                            tab[x][y-1] = 0;
                            k++;
                        }
                    else if( tab[x][y-2] != 0 && y > 1)
                        {
                            tab[x][y] = tab[x][y-2];
                            tab[x][y-2] = 0;
                            k++;
                        }
                    else if( tab[x][y-3] != 0 && y > 2)
                    {
                        tab[x][y] = tab[x][y-3];
                        tab[x][y-3] = 0;
                        k++;
                    }
                }

                if (tab[x][y] != 0)
                {
                    if (tab[x][y] == tab[x][y-1]) //Sprawdzenie czy mo¿na po³¹czyæ s¹siaduj¹ce
                    {
                        tab[x][y] = 2 * tab[x][y];
                        tab[x][y-1] = 0;
                        k++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 2
                    else if(tab[x][y] == tab[x][y-2] && tab[x][y-1] == 0 && y > 1)
                    {
                        tab[x][y] = 2 * tab[x][y];
                        tab[x][y-2] = 0;
                        k++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 3
                    else if(tab[x][y] == tab[x][y-3] && tab[x][y-1] == 0 && tab[x][y-2] == 0 && y > 2)
                    {
                        tab[x][y] = 2 * tab[x][y];
                        tab[x][y-3] = 0;
                        k++;
                    }
                }

                // Jeœli pole jest równe 0 to sprawdŸ czy da siê coœ "wstawiæ"
                else if(tab[x][y] == 0)
                {
                    if (tab[x][y-1] != 0)
                        {
                            tab[x][y] = tab[x][y-1];
                            tab[x][y-1] = 0;
                            k++;
                        }
                    else if( tab[x][y-2] != 0 && y > 1)
                        {
                            tab[x][y] = tab[x][y-2];
                            tab[x][y-2] = 0;
                            k++;
                        }
                    else if( tab[x][y-3] != 0 && y > 2)
                    {
                        tab[x][y] = tab[x][y-3];
                        tab[x][y-3] = 0;
                        k++;
                    }
                }
            }
            if (k >= 1)
        {
            //cout << " Bylo " << k;
            //getchar();
            //getchar();
        }
        else
        {
            //cout << " Nie bylo "<<k;
            //getchar();
            //getchar();
            generuj();
        }

        break;


    case 'a':
        for (int x = 0; x < 3 ; x++)
            for (int y = 0; y < 4; y++)
            {
                if(tab[x][y] == 0)
                {
                    if (tab[x+1][y] != 0)
                        {
                            tab[x][y] = tab[x+1][y];
                            tab[x+1][y] = 0;
                            k++;
                        }
                    else if( tab[x+2][y] != 0 && x < 2)
                        {
                            tab[x][y] = tab[x+2][y];
                            tab[x+2][y] = 0;
                            k++;
                        }
                    else if( tab[x+3][y] != 0 && x < 1)
                    {
                        tab[x][y] = tab[x+3][y];
                        tab[x+3][y] = 0;
                        k++;
                    }
                }

                if (tab[x][y] != 0)
                {
                    if (tab[x][y] == tab[x+1][y]) //Sprawdzenie czy mo¿na po³¹czyæ s¹siaduj¹ce
                    {
                        tab[x][y] = 2 * tab[x][y];
                        tab[x+1][y] = 0;
                        k++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 2
                    else if(tab[x][y] == tab[x+2][y] && tab[x+1][y] == 0 && tab[x+2][y] != 0 && x < 2)
                    {
                        tab[x][y] = 2 * tab[x][y];
                        tab[x+2][y] = 0;
                        k++;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 3
                    else if(tab[x][y] == tab[x+3][y] && tab[x+1][y] == 0 && tab[x+2][y] == 0 && tab[x+3][y] != 0 && x < 1)
                    {
                        tab[x][y] = 2 * tab[x][y];
                        tab[x+3][y] = 0;
                        k++;
                    }
                }

                // Jeœli pole jest równe 0 to sprawdŸ czy da siê coœ "wstawiæ"
                else if(tab[x][y] == 0)
                {
                    if (tab[x+1][y] != 0)
                        {
                            tab[x][y] = tab[x+1][y];
                            tab[x+1][y] = 0;
                            k++;
                        }
                    else if( tab[x+2][y] != 0 && x < 2)
                        {
                            tab[x][y] = tab[x+2][y];
                            tab[x+2][y] = 0;
                            k++;
                        }
                    else if( tab[x+3][y] != 0 && x < 1)
                    {
                        tab[x][y] = tab[x+3][y];
                        tab[x+3][y] = 0;
                        k++;
                    }
                }
            }
            if (k >= 1)
        {
            //cout << " Bylo " << k;
            //getchar();
            //getchar();
        }
        else
        {
            //cout << " Nie bylo "<<k;
            //getchar();
            //getchar();
            generuj();
        }
        break;


    case 'd':
        for (int x = 3; x > 0 ; x--)
            for (int y = 0; y < 4; y++)
            {
                if(tab[x][y] == 0)
                {
                    if (tab[x-1][y] != 0)
                        {
                            tab[x][y] = tab[x-1][y];
                            tab[x-1][y] = 0;
                        }
                    else if( tab[x-2][y] != 0 && x > 1)
                        {
                            tab[x][y] = tab[x-2][y];
                            tab[x-2][y] = 0;
                        }
                    else if( tab[x-3][y] != 0 && x > 2)
                    {
                        tab[x][y] = tab[x-3][y];
                        tab[x-3][y] = 0;
                    }
                }

                if (tab[x][y] != 0)
                {
                    if (tab[x][y] == tab[x-1][y]) //Sprawdzenie czy mo¿na po³¹czyæ s¹siaduj¹ce
                    {
                        tab[x][y] = 2 * tab[x][y];
                        tab[x-1][y] = 0;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 2
                    else if(tab[x][y] == tab[x-2][y] && tab[x-1][y] == 0 && x > 1)
                    {
                        tab[x][y] = 2 * tab[x][y];
                        tab[x-2][y] = 0;
                    }

                    // Czy mo¿na po³¹czyæ z odleg³ym o 3
                    else if(tab[x][y] == tab[x-3][y] && tab[x-1][y] == 0 && tab[x-2][y] == 0 && x > 2)
                    {
                        tab[x][y] = 2 * tab[x][y];
                        tab[x-3][y] = 0;
                    }
                }

                // Jeœli pole jest równe 0 to sprawdŸ czy da siê coœ "wstawiæ"
                else if(tab[x][y] == 0)
                {
                    if (tab[x-1][y] != 0)
                        {
                            tab[x][y] = tab[x-1][y];
                            tab[x-1][y] = 0;
                        }
                    else if( tab[x-2][y] != 0 && x > 1)
                        {
                            tab[x][y] = tab[x-2][y];
                            tab[x-2][y] = 0;
                        }
                    else if( tab[x-3][y] != 0 && x > 2)
                    {
                        tab[x][y] = tab[x-3][y];
                        tab[x-3][y] = 0;
                    }
                }

            }
            if (k >= 1)
        {
            //cout << " Bylo " << k;
            //getchar();
            //getchar();
        }
        else
        {
            //cout << " Nie bylo "<<k;
            //getchar();
            //getchar();
            generuj();
        }
        break;

    case 'r':
        cout << "Jezeli na pewno chcesz zresetowac wcisnij T: ";
        char reset;
        reset = getch();
        if (reset == 't' || reset == 'T')
        {
            for (int i = 0; i<4; i++)
            {
                for (int j = 0; j<4; j++)
                {
                    tab[j][i] = 0;
                }
            }
        tablica();
        }
        else
        {
            generuj();
        }
        break;


    default:
        cout << "Zly znak, podaj jeszcze raz " << endl;
        ruch();
    }
    tablica();
}

void sprawdz()
{
    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
            if (tab[x][y] == 0)
                goto Koniec;
    }

    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (tab[x][y] == tab[x+1][y] && x < 3)
                goto Koniec;
            else if (tab[x][y] == tab[x][y+1] && y < 3)
                goto Koniec;
        }
    }

    cout << "Koniec gry" << endl << "Aby zgrac jeszcze raz wcisnij T ";
    char znak;// = getch();
    znak = getch();
    switch (znak)
    {
    case 't' || 'T':
        srand(time(NULL));
        //Inicjacja tablicy
        for (int i = 0; i<4; i++)
        {
            for (int j = 0; j<4; j++)
            {
                tab[j][i] = 0;
            }
        }
    tablica();
        break;

    default:
        exit(0);
    }

    Koniec:
        cout<<"";
}
