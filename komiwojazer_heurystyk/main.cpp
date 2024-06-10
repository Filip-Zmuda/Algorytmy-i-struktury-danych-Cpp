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

        case 29:
            odleglosci = {
                    {0, 107, 241, 190, 124, 80, 316, 76, 152, 157, 283, 133, 113, 297, 228, 129, 348, 276, 188, 150, 65, 341, 184, 67, 221, 169, 108, 45, 167},
                    {107, 0, 148, 137, 88, 127, 336, 183, 134, 95, 254, 180, 101, 234, 175, 176, 265, 199, 182, 67, 42, 278, 271, 146, 251, 105, 191, 139, 79},
                    {241, 148, 0, 374, 171, 259, 509, 317, 217, 232, 491, 312, 280, 391, 412, 349, 422, 356, 355, 204, 182, 435, 417, 292, 424, 116, 337, 273, 77},
                    {190, 137, 374, 0, 202, 234, 222, 192, 248, 42, 117, 287, 79, 107, 38, 121, 152, 86, 68, 70, 137, 151, 239, 135, 137, 242, 165, 228, 205},
                    {124, 88, 171, 202, 0, 61, 392, 202, 46, 160, 319, 112, 163, 322, 240, 232, 314, 287, 238, 155, 65, 366, 300, 175, 307, 57, 220, 121, 97},
                    {80, 127, 259, 234, 61, 0, 386, 141, 72, 167, 351, 55, 157, 331, 272, 226, 362, 296, 232, 164, 85, 375, 249, 147, 301, 118, 188, 60, 185},
                    {316, 336, 509, 222, 392, 386, 0, 233, 438, 254, 202, 439, 235, 254, 210, 187, 313, 266, 154, 282, 321, 298, 168, 249, 95, 437, 190, 314, 435},
                    {76, 183, 317, 192, 202, 141, 233, 0, 213, 188, 272, 193, 131, 302, 233, 98, 344, 289, 177, 216, 141, 346, 108, 57, 190, 245, 43, 81, 243},
                    {152, 134, 217, 248, 46, 72, 438, 213, 0, 206, 365, 89, 209, 368, 286, 278, 360, 333, 284, 201, 111, 412, 321, 221, 353, 72, 266, 132, 111},
                    {157, 95, 232, 42, 160, 167, 254, 188, 206, 0, 159, 220, 57, 149, 80, 132, 193, 127, 100, 28, 95, 193, 241, 131, 169, 200, 161, 189, 163},
                    {283, 254, 491, 117, 319, 351, 202, 272, 365, 159, 0, 404, 176, 106, 79, 161, 165, 141, 95, 187, 254, 103, 279, 215, 117, 359, 216, 308, 322},
                    {133, 180, 312, 287, 112, 55, 439, 193, 89, 220, 404, 0, 210, 384, 325, 279, 415, 349, 285, 217, 138, 428, 310, 200, 354, 169, 241, 112, 238},
                    {113, 101, 280, 79, 163, 157, 235, 131, 209, 57, 176, 210, 0, 186, 117, 75, 231, 165, 81, 85, 92, 230, 184, 74, 150, 208, 104, 158, 206},
                    {297, 234, 391, 107, 322, 331, 254, 302, 368, 149, 106, 384, 186, 0, 69, 191, 59, 35, 125, 167, 255, 44, 309, 245, 169, 327, 246, 335, 288},
                    {228, 175, 412, 38, 240, 272, 210, 233, 286, 80, 79, 325, 117, 69, 0, 122, 122, 56, 56, 108, 175, 113, 240, 176, 125, 280, 177, 266, 243},
                    {129, 176, 349, 121, 232, 226, 187, 98, 278, 132, 161, 279, 75, 191, 122, 0, 244, 178, 66, 160, 161, 235, 118, 62, 92, 277, 55, 155, 275},
                    {348, 265, 422, 152, 314, 362, 313, 344, 360, 193, 165, 415, 231, 59, 122, 244, 0, 66, 178, 198, 286, 77, 362, 287, 228, 358, 299, 380, 319},
                    {276, 199, 356, 86, 287, 296, 266, 289, 333, 127, 141, 349, 165, 35, 56, 178, 66, 0, 112, 132, 220, 79, 296, 232, 181, 292, 233, 314, 253},
                    {188, 182, 355, 68, 238, 232, 154, 177, 284, 100, 95, 285, 81, 125, 56, 66, 178, 112, 0, 128, 167, 169, 179, 120, 69, 283, 121, 213, 281},
                    {150, 67, 204, 70, 155, 164, 282, 216, 201, 28, 187, 217, 85, 167, 108, 160, 198, 132, 128, 0, 88, 211, 269, 159, 197, 172, 189, 182, 135},
                    {65, 42, 182, 137, 65, 85, 321, 141, 111, 95, 254, 138, 92, 255, 175, 161, 286, 220, 167, 88, 0, 299, 229, 104, 236, 110, 149, 97, 108},
                    {341, 278, 435, 151, 366, 375, 298, 346, 412, 193, 103, 428, 230, 44, 113, 235, 77, 79, 169, 211, 299, 0, 353, 289, 213, 371, 290, 379, 332},
                    {184, 271, 417, 239, 300, 249, 168, 108, 321, 241, 279, 310, 184, 309, 240, 118, 362, 296, 179, 269, 229, 353, 0, 121, 162, 345, 80, 189, 342},
                    {67, 146, 292, 135, 175, 147, 249, 57, 221, 131, 215, 200, 74, 245, 176, 62, 287, 232, 120, 159, 104, 289, 121, 0, 154, 220, 41, 93, 218},
                    {221, 251, 424, 137, 307, 301, 95, 190, 353, 169, 117, 354, 150, 169, 125, 92, 228, 181, 69, 197, 236, 213, 162, 154, 0, 352, 147, 247, 350},
                    {169, 105, 116, 242, 57, 118, 437, 245, 72, 200, 359, 169, 208, 327, 280, 277, 358, 292, 283, 172, 110, 371, 345, 220, 352, 39, 263, 178, 39},
                    {108, 191, 337, 165, 220, 188, 190, 43, 266, 161, 216, 241, 104, 246, 177, 55, 299, 233, 121, 189, 149, 290, 80, 41, 147, 265, 0, 124, 263},
                    {45, 139, 273, 228, 121, 60, 314, 81, 132, 189, 308, 112, 158, 335, 266, 155, 380, 314, 213, 182, 97, 379, 189, 93, 247, 178, 124, 0, 199},
                    {167, 79, 77, 205, 97, 185, 435, 243, 111, 163, 322, 238, 206, 288, 243, 275, 319, 253, 281, 135, 108, 332, 342, 218, 350, 39, 263, 199, 0}
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

std::vector<int> najblizszegoSasiada(const std::vector<std::vector<int>>& odleglosci) {
    int liczbaMiast = odleglosci.size();
    std::vector<int> permutacja(liczbaMiast);
    std::vector<bool> odwiedzone(liczbaMiast, false);

    // Wybieramy losowe miasto jako startowe
    int aktualneMiasto = rand() % liczbaMiast;
    permutacja[0] = aktualneMiasto;
    odwiedzone[aktualneMiasto] = true;

    for (int i = 1; i < liczbaMiast; ++i) {
        int najlepszeMiasto;
        int najkrotszaOdleglosc = std::numeric_limits<int>::max();

        for (int j = 0; j < liczbaMiast; ++j) {
            if (!odwiedzone[j] && odleglosci[aktualneMiasto][j] < najkrotszaOdleglosc) {
                najlepszeMiasto = j;
                najkrotszaOdleglosc = odleglosci[aktualneMiasto][j];
            }
        }

        permutacja[i] = najlepszeMiasto;
        odwiedzone[najlepszeMiasto] = true;
        aktualneMiasto = najlepszeMiasto;
    }

    return permutacja;
}

int main() {
    std::vector<int> liczbaMiast = {5, 7, 9, 10, 11, 29};
    for (int n : liczbaMiast) {
        int najkrotszaDroga = 1000000;
        std::vector<std::vector<int>> odleglosci = macierzOdleglosci(n);

        std::chrono::microseconds totalElapsedTime(0);
        std::chrono::microseconds maxElapsedTime(0);

        for (int i = 0; i < 5; ++i) {
            auto startTime = std::chrono::high_resolution_clock::now();

            // Zastosowanie algorytmu najbliższego sąsiada
            std::vector<int> permutacja = najblizszegoSasiada(odleglosci);

            int dlugosc = obliczDlugosc(permutacja, odleglosci);
            if (dlugosc < najkrotszaDroga) {
                najkrotszaDroga = dlugosc;
            }

            auto endTime = std::chrono::high_resolution_clock::now();
            auto elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
            totalElapsedTime += elapsedTime;
            if (elapsedTime > maxElapsedTime) {
                maxElapsedTime = elapsedTime;
            }
        }

        std::cout << "Instancja dla " << n << " miast:" << std::endl;
        std::cout << "Sredni czas generowania permutacji: " << totalElapsedTime.count() / 5.0 << " us" << std::endl;
        std::cout << "Maksymalny czas generowania permutacji: " << maxElapsedTime.count() << " us" << std::endl;
        std::cout << "Najkrotsza dlugosc trasy (najblizszy sasiad): " << najkrotszaDroga << std::endl << std::endl;
    }

    return 0;
}