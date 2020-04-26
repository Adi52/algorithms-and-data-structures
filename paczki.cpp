/*
Paczki
Twoim zadaniem jest zapakowanie samochodu przedmiotami. Masz do wyboru n przedmiotów
Za przewóz i-tego przedmiotu możesz uzyskać Pi złotych (i=1,2,..,n).
Waga i-tego przedmiotu wynosi Wi (i=1,2,..,n).
Masa towaru w samochodzie nie może przekroczyć wartości C.
Upakuj samochód optymalnie, tj. tak by suma wag nie przekroczyła C oraz suma złotych była największa.
Możesz nie przyjąć zlecenia jeśli narazi Cię to na koszty. Niestety Pan, który przenosi przedmioty do samochodu pobiera stałą opłatę 20 zł za samochód.
Dodatkowo, koszt przeniesienia każdego załadowanego przedmiotu o wadze większej niż 100 kg wynosi 5 zł.

Dodatkowe informacje
Maksymalna ilość przedmiotów: 15.
Minimalny element w P i W: 0
Maksymalny element w P i W: 1000
Liczba testów (liczba uruchomień twojego programu): 10.
Wejście
W pierwszej linii liczba zapytań (samochodów do zapakowania) w danym teście.
W kolejnych liniach.
Ilość przedmiotów n.
Wypłaty za przedmioty Pi.
Wagi przedmiotów Wi.
Ładowność wozu C.
Wyjście
W kolejnych liniach.
Optymalny profit.
Przykład
Wejście
2
5
588 40 307 367 206
211 30 974 943 622
1766
1
596
997
550

Wyjście
965
0
 */


#include <iostream>


int max(int a, int b)
{
    // Wybieranie większej spośród 2 liczb.
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int iloscAut;
    int P[15];
    int W[15];
    int C;
    int n;


    scanf("%d", &iloscAut);

    for (int i=0; i < iloscAut; i++)
    {
        int max_zarobek = 0;
        int suma = 0;

        scanf("%d", &n);
        for (int przedmiot = 0; przedmiot < n; przedmiot++)
        {
            scanf("%d", &P[przedmiot]);
        }
        for (int przedmiot = 0; przedmiot < n; przedmiot++)
        {
            scanf("%d", &W[przedmiot]);
            if (W[przedmiot] > 100)
                P[przedmiot] -= 5;
        }
        scanf("%d", &C);

        // Sumowanie wag wszystkich przedmiotów.
        for (int j=0; j<n; j++) suma += W[j];

        // Sprwadzenie czy suma wszystkich przedmiotów jest mniejsza niż C.
        if (suma <= C)
        {
            for (int j=0; j<n; j++)
            {
                // Podczas wczytywania danych jest odliczana opłata za przedmioty cięższe niż 100 kg (5zł).
                // Tutaj sprwadzamy czy jest dla nas opłacalne branie tego przedmiotu (np. jeżeli przedmiot waży 101 kg
                // a jego wartość wynosi 3 zł - tracimy na tym 2 zł).
                if (P[j] >= 0)
                    max_zarobek += P[j];
            }
            // Opłata za samochód.
            max_zarobek -= 20;
        }
        // Jeżeli suma wag przedmiotów jest więszka niż C samochodu - wykonywana jest funkcja rekurencyjna. Ten sposób
        // znacznie skraca czas wykonywania programu.
        else max_zarobek = wybierzPaczki(C, W, P, n) - 20;

        if (max_zarobek > 0)
            printf("%d\n", max_zarobek);
        else
            printf("0\n");
    }

    return 0;
}
