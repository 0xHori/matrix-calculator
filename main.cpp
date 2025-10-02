#include <iostream>

using namespace std;

int main() {
    int rows, cols;
    cout << "Введите размер матрицы через пробел" << endl;
    cin>>rows>>cols;
    if (rows <= 0 || cols <= 0) {
        cout << "Неправильный размер матрицы" << endl;
        return 0;
    }
    if (rows > 3 || cols > 3) {
        cout << "В данный момент матрицы с такими размерами не поддерживаются программой." << endl;
        return 0;
    }
    double **matrix = new double*[rows];

    // Выделение памяти
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[cols];
    }


    cout << "Введите числа для заполнения матрицы " << rows << "*" << cols << endl;
    // Заполнение массива
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Ваша матрица: " << endl;
    // Вывод двумерного массива
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    while (true) {
        cout << endl;
        cout << "Список доступных действий:" << endl;
        cout << "1. Вычисление определителя" << endl;
        // cout << "2. Транспонирование матрицы" << endl;
        cout << "0. Выход из программы" << endl;
        cout << "Введите номер действия (Например, 1)" << endl;
        char action;
        cin >> action;
        switch (action) {
            case '1':
                if (rows != cols) {
                    cout << "Невозможно вычислить определитель. Матрица должна быть квадратной." << endl;
                } else {
                    if (rows == 2) {
                        double res;
                        res = matrix[0][0]* matrix[1][1] - matrix[1][0] * matrix[0][1];
                        cout << "Определитель матрицы 2x2 равен: " << res << endl;
                    } else if (rows == 3) {
                        double res;
                        res = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[1][0] * matrix[2][1] * matrix[0][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] - matrix[2][0] * matrix[1][1] * matrix[0][2] - matrix[1][0] * matrix[0][1] * matrix[2][2] - matrix[2][1] * matrix[1][2] * matrix[0][0];
                        cout << "Определитель матрицы 3x3 равен: " << res << endl;
                    } else {
                        cout << "В данный момент недоступно." << endl;
                    }
                }
                break;
            // case '2':
            //     cout << "Скоро" << endl;
            //     break;
            case '0':
                cout << "Выход из программы..." << endl;
                // Освобождение памяти
                for (int i = 0; i < rows; i++) {
                    delete[] matrix[i];
                }
                delete[] matrix;
                return 0;
            default:
                cout << "Неправильное действие" << endl;
                break;
        }
    }
}