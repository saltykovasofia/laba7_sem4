#include <iostream>
#include <vector>
#include <list>
#include <chrono>

int main() {
    // Ïðèìåð ñðàâíåíèÿ std::vector è std::list ïî îáúåìó çàíèìàåìîé ïàìÿòè
    std::vector<int> vec; // Ñîçäàíèå âåêòîða
    std::list<int> lst; // Ñîçäàíèå ñïèñêà

    int n = 1000000; // Êîëè÷åñòâî ýëåìåíòîâ

    // Çàïîëíåíèå âåêòîðà è ñïèñêà ýëåìåíòàìè
    for (int i = 0; i < n; ++i) {
        vec.push_back(i); // Äîáàâëåíèå ýëåìåíòà â âåêòîð
        lst.push_back(i); // Äîáàâëåíèå ýëåìåíòà â ñïèñîê
    }

    // Âûâîä èíôîðìàöèè î ïàìÿòè, çàíèìàåìîé êàæäûì êîíòåéíåðîì
    std::cout << "Memory used by vector: " << sizeof(vec) + sizeof(int) * vec.capacity() << " bytes\n";
    std::cout << "Memory used by list: " << sizeof(lst) + sizeof(int) * lst.size() << " bytes\n";

    // Ïðèìåð ñðàâíåíèÿ ñêîðîñòè ðàáîòû std::vector è std::list
    auto start = std::chrono::high_resolution_clock::now(); // Çàñåêàåì âðåìÿ

    // Äîñòóï ê ýëåìåíòàì âåêòîðà ïî èíäåêñó
    for (int i = 0; i < n; ++i) {
        vec[i];
    }

    auto end = std::chrono::high_resolution_clock::now(); // Çàñåêàåì âðåìÿ îêîí÷àíèÿ îïåðàöèè
    std::chrono::duration<double> vector_time = end - start; // Âû÷èñëÿåì âðåìÿ âûïîëíåíèÿ îïåðàöèè
    std::cout << "Time taken by vector: " << vector_time.count() << " seconds\n"; // Âûâîäèì âðåìÿ ðàáîòû âåêòîðà

    start = std::chrono::high_resolution_clock::now(); // Çàñåêàåì âðåìÿ äëÿ ñïèñêà

    // Äîñòóï ê ýëåìåíòàì ñïèñêà ÷åðåç èòåðàòîð
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        *it;
    }

    end = std::chrono::high_resolution_clock::now(); // Çàñåêàåì âðåìÿ îêîí÷àíèÿ îïåðàöèè äëÿ ñïèñêà
    std::chrono::duration<double> list_time = end - start; // Âû÷èñëÿåì âðåìÿ âûïîëíåíèÿ îïåðàöèè äëÿ ñïèñêà
    std::cout << "Time taken by list: " << list_time.count() << " seconds\n"; // Âûâîäèì âðåìÿ ðàáîòû ñïèñêà

    return 0;
}
