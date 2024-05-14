#include <iostream>
#include <vector>
#include <list>
#include <chrono>

int main() {
    // Пример сравнения std::vector и std::list по объему занимаемой памяти
    std::vector<int> vec; // Создание вектора
    std::list<int> lst; // Создание списка

    int n = 1000000; // Количество элементов

    // Заполнение вектора и списка элементами
    for (int i = 0; i < n; ++i) {
        vec.push_back(i); // Добавление элемента в вектор
        lst.push_back(i); // Добавление элемента в список
    }

    // Вывод информации о памяти, занимаемой каждым контейнером
    std::cout << "Memory used by vector: " << sizeof(vec) + sizeof(int) * vec.capacity() << " bytes\n";
    std::cout << "Memory used by list: " << sizeof(lst) + sizeof(int) * lst.size() << " bytes\n";

    // Пример сравнения скорости работы std::vector и std::list
    auto start = std::chrono::high_resolution_clock::now(); // Засекаем время

    // Доступ к элементам вектора по индексу
    for (int i = 0; i < n; ++i) {
        vec[i];
    }

    auto end = std::chrono::high_resolution_clock::now(); // Засекаем время окончания операции
    std::chrono::duration<double> vector_time = end - start; // Вычисляем время выполнения операции
    std::cout << "Time taken by vector: " << vector_time.count() << " seconds\n"; // Выводим время работы вектора

    start = std::chrono::high_resolution_clock::now(); // Засекаем время для списка

    // Доступ к элементам списка через итератор
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        *it;
    }

    end = std::chrono::high_resolution_clock::now(); // Засекаем время окончания операции для списка
    std::chrono::duration<double> list_time = end - start; // Вычисляем время выполнения операции для списка
    std::cout << "Time taken by list: " << list_time.count() << " seconds\n"; // Выводим время работы списка

    return 0;
}
