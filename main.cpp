#include <iostream>
#include <limits>

/**
 * Функция создания массива
 * @param size Размер массива
 */
int* createArray(const size_t size);

/**
 * Функция удаления массива
 * @param arr Массив
 */
void deleteArray(int* arr);

/**
 * Функция получения значения элемента
 * @param size Размер массива
 * @param index Индекс элемента
 */
int getElement(const int* arr, const int index); 

/**
 * Функция установки значения элемента
 * @param arr Массив
 * @param index Индекс элемента
 * @param value Вводимое значение
 */
void setElement(int* arr, const int index, const int value);

/**
 * Функция изменения размера массива
 * @param arr Массив
 * @param size Размер массива
 * @param newSize Новый размер массива
 */
int* resizeArray(int* arr, const size_t size, const size_t newSize); 

/**
 * Вывод массива
 * @param arr Массив
 * @param size Размер массива
 */
void printArray(const int* arr, const size_t size);

/**
 * Функция поиска максимального элемента массива
 * @param arr Массив
 * @param size Размер массива
 */
int getMaxElement(const int* arr, const size_t size);

/**
 * Функция поиска минимального элемента массива
 * @param arr Массив
 * @param size Размер массива
 */
int getMinElement(const int* arr, const size_t size);

int main() {
    size_t size = 5;
    int* arr = createArray(size);

    // Добавляем значения в массив
    for (int i = 0; i < size; i++) {
        setElement(arr, i, i + 1);
    }

    // Выводим значения массива
    printArray(arr, size);

    // Изменяем размер массива
    size_t newSize = 10;
    arr = resizeArray(arr, size, newSize);

    // Добавляем новые значения в расширенный массив
    for (int i = size; i < newSize; i++) {
        setElement(arr, i, i + 1);
    }

    std::cout << "\n\n";

    // Выводим значения расширенного массива
     printArray(arr, newSize);

    // Очищаем память
    deleteArray(arr);

    return 0;
}

// Функция создания массива
int* createArray(const size_t size) {
    int* arr = new int[size];
    return arr;
}

// Функция удаления массива
void deleteArray(int* arr) {
    delete[] arr;
}

// Функция получения значения элемента
int getElement(const int* arr, const int index) {
    return arr[index];
}

// Функция установки значения элемента
void setElement(int* arr, const int index, const int value) {
    arr[index] = value;
}

// Функция изменения размера массива
int* resizeArray(int* arr, const size_t size, const size_t newSize) {
    int* newArr = new int[newSize];
    int minSize = (size < newSize) ? size : newSize;

    for (int i = 0; i < minSize; i++) {
        newArr[i] = arr[i];
    }

    delete[] arr;
    return newArr;
}

// Функция вывода массива
void printArray(const int* arr, const size_t size) {
    for (int i = 0; i < size; i++) {
        std::cout << "arr[" << i << "] = " << arr[i] << "\n";
    }
}

// Функция поиска максимального элемента массива
int getMaxElement(const int* arr, const size_t size) {
    int maxEl = std::numeric_limits<int>::min();
  
    for(int i = 0; i < size; i++){
        if(arr[i] > maxEl){
           maxEl = arr[i];
        }
    }
  
    return maxEl;
}

// Функция поиска минимального элемента массива
int getMinElement(const int* arr, const size_t size) {
    int minEl = std::numeric_limits<int>::max();
  
    for(int i = 0; i < size; i++){
        if(arr[i] < minEl){
           minEl = arr[i];
        }
    }
  
    return minEl;
}