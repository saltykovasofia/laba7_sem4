#include <iostream>
#include <vector>
#include <list>
#include <chrono>

int main() {
    // ������ ��������� std::vector � std::list �� ������ ���������� ������
    std::vector<int> vec; // �������� �������
    std::list<int> lst; // �������� ������

    int n = 1000000; // ���������� ���������

    // ���������� ������� � ������ ����������
    for (int i = 0; i < n; ++i) {
        vec.push_back(i); // ���������� �������� � ������
        lst.push_back(i); // ���������� �������� � ������
    }

    // ����� ���������� � ������, ���������� ������ �����������
    std::cout << "Memory used by vector: " << sizeof(vec) + sizeof(int) * vec.capacity() << " bytes\n";
    std::cout << "Memory used by list: " << sizeof(lst) + sizeof(int) * lst.size() << " bytes\n";

    // ������ ��������� �������� ������ std::vector � std::list
    auto start = std::chrono::high_resolution_clock::now(); // �������� �����

    // ������ � ��������� ������� �� �������
    for (int i = 0; i < n; ++i) {
        vec[i];
    }

    auto end = std::chrono::high_resolution_clock::now(); // �������� ����� ��������� ��������
    std::chrono::duration<double> vector_time = end - start; // ��������� ����� ���������� ��������
    std::cout << "Time taken by vector: " << vector_time.count() << " seconds\n"; // ������� ����� ������ �������

    start = std::chrono::high_resolution_clock::now(); // �������� ����� ��� ������

    // ������ � ��������� ������ ����� ��������
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        *it;
    }

    end = std::chrono::high_resolution_clock::now(); // �������� ����� ��������� �������� ��� ������
    std::chrono::duration<double> list_time = end - start; // ��������� ����� ���������� �������� ��� ������
    std::cout << "Time taken by list: " << list_time.count() << " seconds\n"; // ������� ����� ������ ������

    return 0;
}
