#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <chrono>
#include <vector>

void zadanie1()
{
    int liczba;
    std::cout << "Podaj liczbe " << std::endl;
    std::cin >> liczba;
    int rozmiar = 1000;

    int * tab = new int[rozmiar]();
    float suma = 0;
    int max = 0;
    srand(time(NULL));


    for (int j = 0; j < 20; j++)
    {
        for (int i = 1; i < rozmiar; i++)
        {
            tab[i] = (rand() % rozmiar) + 1;
        }

        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 1; i < rozmiar; i++)
        {
            if (tab[i] == liczba)
                break;
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto czas = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

        suma += czas.count();

        if (max < czas.count())
            max = czas.count();

    }

    std::cout << "Sredni czas dzialania algorytmu wynosi: " << suma/20 << "ns" << std::endl;

    std::cout << "Najgorszy czas algorytmu wynosi: " << max << "ns" << std::endl;
}

void zadanie2()
{
    int liczba;
    std::cout << "Podaj liczbe: ";
    std::cin >> liczba;

    int rozmiar = 1000;
    int * tab = new int[rozmiar]();
    float suma = 0;
    int max = 0;
    srand(time(NULL));

    for(int i = 0; i < 20; i++)
    {
        for (int i = 1; i < rozmiar; i++)
        {
            tab[i] = (rand() % rozmiar) + 1;
        }
        std::sort (tab, tab + rozmiar);
        int idx_max = rozmiar - 1;
        int idx_min = 0;
        int idx = floor(idx_max / 2);
        auto start = std::chrono::high_resolution_clock::now();
        while(tab[idx] != liczba && idx_max != idx_min && idx != 0)
        {
            if(liczba > tab[idx])
                idx_min = idx + 1;
            else
                idx_max = idx - 1;

            idx = floor(idx_min + (idx_max - idx_min) / 2);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto czas = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);

        suma += czas.count();

        if (max < czas.count())
            max = czas.count();
    }

    std::cout << "Sredni czas dzialania algorytmu wynosi: " << suma/20 << "ns" << std::endl;

    std::cout << "Najgorszy czas algorytmu wynosi: " << max  << "ns" << std::endl;
}
void zadanie4()
{
    std::vector<int> ciag = {3, 4, 3, 3, 5, 6, 3, 3, 3, 3};
    int i = 0;
    int licz = 0;

    srand(time(NULL));

    int rozmiar = 1000;
    int wypelnianie = rozmiar/2;
    int * tab = new int[rozmiar]();

    for (int i = 1; i < rozmiar; i++)
    {
        if(rozmiar<wypelnianie)
            tab[i] = i;

        else
            tab[i] = 1;
    }

    for(int liczba : ciag)
    {
        if(licz == 0)
        {
            i = liczba;
            licz == 0;
        }
        else if (liczba = 1)
        {
            licz++;
        }
        else
        {
            licz--;
        }
    }

    std::cout << "Przywodca ciagu jest liczba: " << i << std::endl;
}

int zad5(const std::vector<int>& vec)
{
    int max_temp = vec[0];
    int max_ov = vec[0];
    for (int i=1; i<vec.size(); i++) {
        max_temp = std::max(vec[i], max_temp + vec[i]);
        max_ov = std::max(max_ov, max_temp);
    }
    return max_ov;
}
int bezKadane(const std::vector<int>& vec)
{
    int r = vec.size();
    int suma_max = vec[0];
    for (int i=0; i<r; i++) {
        int suma_temp = 0;
        for(int k=i;k<r;k++){
            suma_temp = suma_temp + vec[k];
            suma_max = std::max(suma_max, suma_temp);
        }
    }
    return suma_max;
}
void zadanie5a(const std::vector<int>& vec)
{
    auto start = std::chrono::high_resolution_clock::now();
    zad5(vec);
    auto stop = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Czas algorytmu = " << elapsed.count()*0.000001 << " s" << std::endl;
}
void zadanie5b(const std::vector<int>& vec) {
    auto start = std::chrono::high_resolution_clock::now();
    bezKadane(vec);
    auto stop = std::chrono::high_resolution_clock::now();
    auto czas = std::chrono::duration_cast<std::chrono::seconds>(stop - start);
    double suma = 0;
    suma += czas.count();
    std::cout << "Czas algorytmu bezKadane = " << suma << " s" << std::endl;
}

void generator_permutacji(std::vector<int>& vec, int start, int stop){
//    if (start == end)
//    {
//        for(int i=0;i<=end;++i){
//            //cout<< elements[i] << " ";
//
//        }
//        //cout<<'\n';
//        return;
//    }

    for(int i = start; i <= stop; i++){
        std::swap(vec[start], vec[i]);
        generator_permutacji(vec,start+1,stop);
        std::swap(vec[start], vec[i]);
    }
}
void zadanie6(std::vector<int>& elements, int start, int end){
    auto start1 = std::chrono::high_resolution_clock::now();
    generator_permutacji(elements,start,end);

    auto stop = std::chrono::high_resolution_clock::now();
    auto czas = std::chrono::duration_cast<std::chrono::nanoseconds >(stop - start1);
    double suma = 0;
    suma+=czas.count();
    std::cout << "Czas dzialania algorytmu  = " << suma * 1e-9 << " ns" << std::endl;
}

int main() {
    std::vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4, 2, 3, 4, 5, 6, 7,9,8,9,10,11,12,13,14};
    std::vector<int> vec6 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    //zadanie1();
    //zadanie2();
    zadanie4();
    //zadanie5a(vec);
    //zadanie5b(vec);
    //zadanie6(vec6, 0, vec6.size() - 1);

    return 0;
}