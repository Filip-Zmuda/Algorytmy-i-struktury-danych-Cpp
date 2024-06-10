#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>


std::vector<std::vector<int>> macierzOdleglosci(int n) {
    std::vector<std::vector<int>> odleglosci(n, std::vector<int>(n));
    switch(n) {
        case 5:
            odleglosci = {
                    {0, 25, 41, 66, 30},
                    {25, 0, 25, 41, 66},
                    {41, 25, 0, 25, 41},
                    {66, 41, 25, 0, 25},
                    {30, 66, 41, 25, 0}
            };
            break;
        case 7:
            odleglosci = {
                    {0, 25, 41, 66, 30, 37, 72},
                    {25, 0, 25, 41, 66, 30, 37},
                    {41, 25, 0, 25, 41, 66, 30},
                    {66, 41, 25, 0, 25, 41, 66},
                    {30, 66, 41, 25, 0, 25, 41},
                    {37, 30, 66, 41, 25, 0, 25},
                    {72, 37, 30, 66, 41, 25, 0}
            };
            break;
        case 9:
            odleglosci = {
                    {0, 25, 41, 66, 30, 37, 72, 81, 54},
                    {25, 0, 25, 41, 66, 30, 37, 72, 81},
                    {41, 25, 0, 25, 41, 66, 30, 37, 72},
                    {66, 41, 25, 0, 25, 41, 66, 30, 37},
                    {30, 66, 41, 25, 0, 25, 41, 66, 30},
                    {37, 30, 66, 41, 25, 0, 25, 41, 66},
                    {72, 37, 30, 66, 41, 25, 0, 25, 41},
                    {81, 72, 37, 30, 66, 41, 25, 0, 25},
                    {54, 81, 72, 37, 30, 66, 41, 25, 0}
            };
            break;
        case 10:
            odleglosci = {
                    {0, 25, 41, 66, 30, 37, 72, 81, 54, 12},
                    {25, 0, 25, 41, 66, 30, 37, 72, 81, 54},
                    {41, 25, 0, 25, 41, 66, 30, 37, 72, 81},
                    {66, 41, 25, 0, 25, 41, 66, 30, 37, 72},
                    {30, 66, 41, 25, 0, 25, 41, 66, 30, 37},
                    {37, 30, 66, 41, 25, 0, 25, 41, 66, 30},
                    {72, 37, 30, 66, 41, 25, 0, 25, 41, 66},
                    {81, 72, 37, 30, 66, 41, 25, 0, 25, 41},
                    {54, 81, 72, 37, 30, 66, 41, 25, 0, 25},
                    {12, 54, 81, 72, 37, 30, 66, 41, 25, 0}
            };
            break;
        case 11:
            odleglosci = {
                    {0, 25, 41, 66, 30, 37, 72, 81, 54, 12, 93},
                    {25, 0, 25, 41, 66, 30, 37, 72, 81, 54, 12},
                    {41, 25, 0, 25, 41, 66, 30, 37, 72, 81, 54},
                    {66, 41, 25, 0, 25, 41, 66, 30, 37, 72, 81},
                    {30, 66, 41, 25, 0, 25, 41, 66, 30, 37, 72},
                    {37, 30, 66, 41, 25, 0, 25, 41, 66, 30, 37},
                    {72, 37, 30, 66, 41, 25, 0, 25, 41, 66, 30},
                    {81, 72, 37, 30, 66, 41, 25, 0, 25, 41, 66},
                    {54, 81, 72, 37, 30, 66, 41, 25, 0, 25, 41},
                    {12, 54, 81, 72, 37, 30, 66, 41, 25, 0, 25},
                    {93, 12, 54, 81, 72, 37, 30, 66, 41, 25, 0}
            };
            break;

    }
    return odleglosci;
}

std::vector<std::vector<int>> generujPermutacje(std::vector<int> vec, int poz = 0) {
    std::vector<std::vector<int>> permutatacje;
    if (poz != vec.size()) {
        for (int i = poz; i < vec.size(); ++i) {
            std::swap(vec[i], vec[poz]);
            std::vector<std::vector<int>> podpermutacje = generujPermutacje(vec, poz + 1);
            permutatacje.insert(permutatacje.end(), podpermutacje.begin(), podpermutacje.end());
            std::swap(vec[i], vec[poz]);
        }
    } else {
        permutatacje.push_back(vec);
    }
    return permutatacje;
}

int obliczDlugosc(const std::vector<int>& permutatacja, const std::vector<std::vector<int>>& odleglosci) {
    int dlugosc = 0;
    for (int i = 0; i < permutatacja.size() - 1; ++i) {
        dlugosc += odleglosci[permutatacja[i]][permutatacja[i + 1]];
    }
    dlugosc += odleglosci[permutatacja.back()][permutatacja.front()];
    return dlugosc;
}

int main() {
    std::vector<int> liczbaMiast = {5, 7, 9, 10, 11};
    for (int n : liczbaMiast) {
        int najkrotszaDroga = 1000000;
        std::vector<std::vector<int>> odleglosci = macierzOdleglosci(n);

        std::chrono::microseconds totalElapsedTime(0);
        std::chrono::microseconds maxElapsedTime(0);

        for (int i = 0; i < 5; ++i) {
            auto startTime = std::chrono::high_resolution_clock::now();

            std::vector<int> permutatacja(n);
            for (int i = 0; i < n; ++i) {
                permutatacja[i] = i;
            }
            std::vector<std::vector<int>> podpermutacja = generujPermutacje(permutatacja);

            for (const auto& perm : podpermutacja) {
                int dlugosc = obliczDlugosc(perm, odleglosci);
                if (dlugosc < najkrotszaDroga) {
                    najkrotszaDroga = dlugosc;
                }
            }
            auto endTime = std::chrono::high_resolution_clock::now();
            auto elapsedTime = duration_cast<std::chrono::microseconds>(endTime - startTime);
            totalElapsedTime += elapsedTime;
            if (elapsedTime > maxElapsedTime) {
                maxElapsedTime = elapsedTime;
            }
        }

        std::cout << "Instancja dla " << n << " miast:" << std::endl;
        std::cout << "Sredni czas generowania permutacji: " << totalElapsedTime.count() / 5.0 << " us" << std::endl;
        std::cout << "Maksymalny czas generowania permutacji: " << maxElapsedTime.count() << " us" << std::endl;
        std::cout << "Najkrotsza dlugosc trasy: " << najkrotszaDroga << std::endl << std::endl;
    }

    return 0;
}
