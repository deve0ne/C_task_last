#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct AstronomObject {
    int type;
    string name;
    int radius;
    bool hasAtmosphere = false;
};

int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);

    vector<AstronomObject> objects;

//    AstronomObject sun;
//    sun.type = 0;
//    sun.name = "Солнце";
//    sun.radius = 696000;
//    sun.hasAtmosphere = true;
//    sun.Object.Star.brightness = 39800;
//    sun.Object.Star.temperature = 20000000;
//
//    AstronomObject betelgeuse;
//    betelgeuse.type = 0;
//    betelgeuse.name = "Бетельгейзе";
//    betelgeuse.radius = 52750000;
//    betelgeuse.hasAtmosphere = true;
//    betelgeuse.Object.Star.brightness = 581000;
//    betelgeuse.Object.Star.temperature = 740000000;
//
//    AstronomObject earth;
//    earth.type = 1;
//    earth.name = "Земля";
//    earth.radius = 6378;
//    earth.hasAtmosphere = true;
//    earth.Object.Planet.isHabitable = true;
//    earth.Object.Planet.isInhabited = true;
//
//    AstronomObject asteroid;
//    asteroid.type = 2;
//    asteroid.name = "Астероид 41582";
//    asteroid.radius = 24;
//    asteroid.hasAtmosphere = false;
//
//    objects.push_back(sun);
//    objects.push_back(betelgeuse);
//    objects.push_back(earth);
//    objects.push_back(asteroid);

    cout << "0 - Добавить элемент" << "\n";
    cout << "1 - Удалить элемент" << "\n";
    cout << "2 - Вывести элемент" << "\n";
    cout << "3 - Вывести количество элементов" << "\n\n";

    while (true) {
        int choose = -1;

        cout << "Выберите действие: ";
        cin >> choose;

        switch (choose) {
            case 0: {
                int type = -1;
                cout << "Выберите тип нового объекта (0 - звезда, 1 - планета, 2 - астероид): ";
                cin >> type;

                AstronomObject newObj = *new AstronomObject();
                objects.push_back(newObj);
                break;
            }
            case 1: {
                int index = -1;
                cout << "Введите номер элемента для удаления: ";
                cin >> index;
                index--;

                if (index > objects.size() - 1 || index < 0) {
                    cout << "Такого элемента не существует\n";
                    break;
                }

                if (objects.size() == 0) {
                    cout << "Вектор объектов пуст\n";
                    break;
                }

                objects.erase(objects.begin() + index);
                break;
            }
            case 2: {
                int index = -1;
                cout << "Введите номер элемента: ";
                cin >> index;
                index--;

                if (index > objects.size() - 1 || index < 0) {
                    cout << "Такого элемента не существует\n";
                    break;
                }

                if (objects.size() == 0) {
                    cout << "Вектор объектов пуст\n";
                    break;
                }

//                printObject(objects.at(index));
                break;
            }
            case 3: {
                cout << "Количество элементов: " << objects.size() << "\n";
                break;
            }
        }

        cout << "\n";
    }
}
