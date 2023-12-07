#include <iostream>
#include <cstring>

using namespace std;


struct AEROFLOT {
    char CITY[50];
    int NUM;
    char TYPE[50];
};

void ввідРейсів(AEROFLOT* AIR, int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Введіть місто: ";
        cin >> AIR[i].CITY;
        cout << "Введіть номер рейсу: ";
        cin >> AIR[i].NUM;
        cout << "Введіть тип літака: ";
        cin >> AIR[i].TYPE;
    }
}

void сортуванняРейсів(AEROFLOT* AIR, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (AIR[j].NUM > AIR[j + 1].NUM) {
                swap(AIR[j], AIR[j + 1]);
            }
        }
    }
}

void виведенняРейсівДоПунктуПризначення(AEROFLOT* AIR, int size, const char* destination) {
    bool found = false;
    cout << "Рейси до " << destination << ":" << endl;
    for (int i = 0; i < size; ++i) {
        if (strcmp(AIR[i].CITY, destination) == 0) {
            cout << "Номер рейсу: " << AIR[i].NUM << ", Тип літака: " << AIR[i].TYPE << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Рейсів до " << destination << " не знайдено." << endl;
    }
}

int main() {
    const int size = 3; // Розмір масиву

    AEROFLOT AIR[size];

    // Введення даних з клавіатури
    ввідРейсів(AIR, size);

    // Сортування за зростанням номеру рейсу
    сортуванняРейсів(AIR, size);

    // Виведення на екран номерів рейсів і типів літаків для пункту призначення
    // введеного з клавіатури
    char destination[50];
    cout << "Введіть місто призначення: ";
    cin >> destination;
    виведенняРейсівДоПунктуПризначення(AIR, size, destination);

    return 0;
}
