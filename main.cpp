#include <iostream>

const int N = 3; // размер массива

void findAndReplaceMin(int arr[N][N]) {
    for (int col = 0; col < N; col++) { // перебираем столбцы
        int min = arr[0][col]; // предполагаем, что первый элемент - минимальный
        for (int row = 1; row < N; row++) { // перебираем строки в текущем столбце
            if (arr[row][col] < min) { // если текущий элемент меньше минимального
                min = arr[row][col]; // обновляем минимальный элемент
            }
        }
        for (int row = 0; row < N; row++) { // перебираем строки в текущем столбце еще раз
            if (arr[row][col] == min) { // если текущий элемент равен минимальному
                arr[row][col] = 0; // заменяем его на ноль
                break; // прерываем цикл, так как мы уже заменили минимальный элемент
            }
        }
    }
}

int main() {
    int arr[N][N] = {{3, 5, 1},
                     {2, 4, 7},
                     {6, 0, 9}}; // пример входного массива

    std::cout << "Входной массив:\n";
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            std::cout << arr[row][col] << " ";
        }
        std::cout << "\n";
    }
    
    findAndReplaceMin(arr); // вызов функции для изменения массива

    std::cout << "\nМассив после замены минимальных элементов на ноль:\n";
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            std::cout << arr[row][col] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}