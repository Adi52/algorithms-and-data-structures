#include <iostream>

using namespace std;


int max(int a, int b)
{
    return (a > b)? a : b;
}


int wybierzPaczki(int C, int W[], int P[], int n)
{
    if (n == 0 || C == 0)
        return 0;

    if (W[n-1] > C)
        return wybierzPaczki(C, W, P, n-1);

    else
        return max( P[n-1] + wybierzPaczki(C-W[n-1], W, P, n-1),
                    wybierzPaczki(C, W, P, n-1));
}


int main()
{
    int iloscAut;
    int P[15];
    int W[15];
    int C;
    int n;

    cin >> iloscAut;

    for (int i=0; i < iloscAut; i++)
    {
        cin >> n;
        for (int przedmiot = 0; przedmiot < n; przedmiot++)
        {
            cin >> P[przedmiot];
        }
        for (int przedmiot = 0; przedmiot < n; przedmiot++) {
            cin >> W[przedmiot];
            if (W[przedmiot] > 100)
                P[przedmiot] -= 5;
        }
        cin >> C;
        int max_zarobek = wybierzPaczki(C, W, P, n) - 20;

        if (max_zarobek > 0)
            cout << max_zarobek << endl;
        else
            cout << "0"<< endl;
    }

    return 0;
}