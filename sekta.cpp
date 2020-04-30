/*
 Sekta

Znaleźliście się w nieodpowiednim miejscu i w nieodpowiednim czasie. Wśród n (np. n=20)
osób (numerujemy od 1) wszyscy oprócz Ciebie chcą popełnić samobójstwo (niestety nie masz czasu na agitację).

Guru wymyślił(a) następującą metodę: ustawiacie się w kółku i co 2-ga osoba zostaje
zamordowana (nie pierwsza, a druga, nie trzecia, a czwarta, nie piąta, a szósta, itd.).

W którym miejscu staniesz (wybieraj od 1 do 20)? Czas start masz 10 sekund.
Który z kolei zginiesz? Kto jest następny? Kto zginie jako k-ty?

Niech n=10. Wówczas porządek jest następujący 2,4,6,8,10,3,7,1,9.
Przetrwała 5-tka. Jest to równoważne z n=10 i k=10. Niech n=10 i k=6.
Wówczas jako szósta zginie osoba na miejscu 3.

Przyjmujemy oznaczenia -1, -2, -3 itd. - oznaczają ostatnią osobę,
przedostatnią osobę itd. Wówczas
n=11 i k=11 daje ten sam wynik co n=11 i k=-1,
n=7 i k=5 daje ten sam wynik co n=7 i k=-3.

Wejście
W pierwszej linii liczba kolejnych linii.
W następnych liniach po spacjach n i k.

Wyjście
W kolejnych liniach, miejsce w kręgu.


Przykłady
Wejście
10
4 4
5 -2
13 -6
16 -16
16 -13
7 -5
4 2
10 10
8 -1
3 -3

Wyjście
1
5
5
2
8
6
4
5
1
2
 */

//def ocalaly(n, k):
//    if k < 0:
//        k = n + k + 1
//
//    first = 1
//    gap = 1
//    ileUmarlo = 0
//
//    while n >= 0:
//        gap *= 2
//
//        if k <= ileUmarlo + n/2 and k >= ileUmarlo:
//            ileJeszczeUmrze = k - ileUmarlo
//            return first + gap * ileJeszczeUmrze - gap/2
//
//
//        n, odd = divmod(n, 2)
//        ileUmarlo += n
//
//        if odd:
//            first += gap
//            ileUmarlo += 1
//
//    return ''


#include <iostream>



unsigned long long int ktyOcalaly(long long int n, long long int k)
{
    unsigned long long int pierwszyWTurze = 1;
    unsigned long long int odlegloscMiedzyZywymi = 1;
    unsigned long long int iluUmarlo = 0;
    int nieparzysty;


    while (n >= 0)
    {
        if (k <= iluUmarlo + n / 2 && k >= iluUmarlo) {
            long long int iluJeszczeUmrze = k - iluUmarlo;
            return pierwszyWTurze + odlegloscMiedzyZywymi * 2 * iluJeszczeUmrze - odlegloscMiedzyZywymi;
        }
        odlegloscMiedzyZywymi *= 2;

        nieparzysty = n % 2;
        n = n / 2;
        iluUmarlo += n;

        if (nieparzysty)
        {
            pierwszyWTurze += odlegloscMiedzyZywymi;
            iluUmarlo++;
        }
    }
    return 0;
}



int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long liczbaKolejnychLinii;
    long long int n;
    long long int k;
    scanf("%d", &liczbaKolejnychLinii);

    for (long i=0; i < liczbaKolejnychLinii; i++)
    {
        scanf("%lld %lld", &n, &k);
        if (k < 0) k = n + k + 1;
        printf("%lld\n", ktyOcalaly(n, k));

    }
    return 0;
}/*
 Sekta

Znaleźliście się w nieodpowiednim miejscu i w nieodpowiednim czasie. Wśród n (np. n=20)
osób (numerujemy od 1) wszyscy oprócz Ciebie chcą popełnić samobójstwo (niestety nie masz czasu na agitację).

Guru wymyślił(a) następującą metodę: ustawiacie się w kółku i co 2-ga osoba zostaje
zamordowana (nie pierwsza, a druga, nie trzecia, a czwarta, nie piąta, a szósta, itd.).

W którym miejscu staniesz (wybieraj od 1 do 20)? Czas start masz 10 sekund.
Który z kolei zginiesz? Kto jest następny? Kto zginie jako k-ty?

Niech n=10. Wówczas porządek jest następujący 2,4,6,8,10,3,7,1,9.
Przetrwała 5-tka. Jest to równoważne z n=10 i k=10. Niech n=10 i k=6.
Wówczas jako szósta zginie osoba na miejscu 3.

Przyjmujemy oznaczenia -1, -2, -3 itd. - oznaczają ostatnią osobę,
przedostatnią osobę itd. Wówczas
n=11 i k=11 daje ten sam wynik co n=11 i k=-1,
n=7 i k=5 daje ten sam wynik co n=7 i k=-3.

Wejście
W pierwszej linii liczba kolejnych linii.
W następnych liniach po spacjach n i k.

Wyjście
W kolejnych liniach, miejsce w kręgu.


Przykłady
Wejście
10
4 4
5 -2
13 -6
16 -16
16 -13
7 -5
4 2
10 10
8 -1
3 -3

Wyjście
1
5
5
2
8
6
4
5
1
2
 */

//def ocalaly(n, k):
//    if k < 0:
//        k = n + k + 1
//
//    first = 1
//    gap = 1
//    ileUmarlo = 0
//
//    while n >= 0:
//        gap *= 2
//
//        if k <= ileUmarlo + n/2 and k >= ileUmarlo:
//            ileJeszczeUmrze = k - ileUmarlo
//            return first + gap * ileJeszczeUmrze - gap/2
//
//
//        n, odd = divmod(n, 2)
//        ileUmarlo += n
//
//        if odd:
//            first += gap
//            ileUmarlo += 1
//
//    return ''


#include <iostream>



unsigned long long int ktyOcalaly(long long int n, long long int k)
{
    unsigned long long int pierwszyWTurze = 1;
    unsigned long long int odlegloscMiedzyZywymi = 1;
    unsigned long long int iluUmarlo = 0;
    int nieparzysty;


    while (n >= 0)
    {
        if (k <= iluUmarlo + n / 2 && k >= iluUmarlo) {
            long long int iluJeszczeUmrze = k - iluUmarlo;
            return pierwszyWTurze + odlegloscMiedzyZywymi * 2 * iluJeszczeUmrze - odlegloscMiedzyZywymi;
        }
        odlegloscMiedzyZywymi *= 2;

        nieparzysty = n % 2;
        n = n / 2;
        iluUmarlo += n;

        if (nieparzysty)
        {
            pierwszyWTurze += odlegloscMiedzyZywymi;
            iluUmarlo++;
        }
    }
    return 0;
}



int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long liczbaKolejnychLinii;
    long long int n;
    long long int k;
    scanf("%d", &liczbaKolejnychLinii);

    for (long i=0; i < liczbaKolejnychLinii; i++)
    {
        scanf("%lld %lld", &n, &k);
        if (k < 0) k = n + k + 1;
        printf("%lld\n", ktyOcalaly(n, k));

    }
    return 0;
}