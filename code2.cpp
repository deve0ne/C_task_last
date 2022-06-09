//#include <iostream>
//#include <string>
//#include <vector>
//#include <windows.h>
//
//using namespace std;
//
//struct AstronomObject {
//    int type;
//    string name;
//    int radius;
//    bool hasAtmosphere = false;
//
//    union Object{
//        Object() {}
//        ~Object() {}
//        struct {
//            double brightness = 0.0;
//            int temperature = 0;
//        } Star;
//        struct {
//            bool isInhabited = false;
//            bool isHabitable = false;
//        } Planet;
//    } Object;
//};
//
//void printObject(AstronomObject object) {
//    switch (object.type) {
//    case 0:
//    {
//        cout << "Тип: Звезда" << "\n";
//        cout << "Имя: " << object.name << "\n";
//        cout << "Радиус: " << object.radius << "\n";
//        string hasAtmosphere = object.hasAtmosphere ? "Есть" : "Нет";
//        cout << "Атмосфера: " << hasAtmosphere << "\n";
//        cout << "Яркость: " << object.Object.Star.brightness << "\n";
//        cout << "Температура: " << object.Object.Star.temperature << "\n";
//        break;
//    }
//    case 1:
//    {
//        cout << "Тип: Планета" << "\n";
//        cout << "Имя: " << object.name << "\n";
//        cout << "Радиус: " << object.radius << "\n";
//        string hasAtmosphere = object.hasAtmosphere ? "Есть" : "Нет";
//        cout << "Атмосфера: " << hasAtmosphere << "\n";
//        string isInhabited = object.Object.Planet.isInhabited ? "Да" : "Нет";
//        cout << "Есть жизнь: " << isInhabited << "\n";
//        string isHabitable = object.Object.Planet.isHabitable ? "Да" : "Нет";
//        cout << "Может быть жизнь: " << isHabitable << "\n";
//        break;
//    }
//    case 2:
//    {
//        cout << "Тип: Астероид" << "\n";
//        cout << "Имя: " << object.name << "\n";
//        cout << "Радиус: " << object.radius << "\n";
//        string hasAtmosphere = object.hasAtmosphere ? "Есть" : "Нет";
//        cout << "Атмосфера: " << hasAtmosphere << "\n";
//        break;
//    }
//    }
//}
//
//AstronomObject enterObject(int type) {
//    AstronomObject newObj;
//
//    switch (type) {
//    case 0:
//    {
//        newObj.type = type;
//
//        cout << "Введите имя: ";
//        cin >> newObj.name;
//        cout << "Введите радиус: ";
//        cin >> newObj.radius;
//        cout << "Есть атмосфера? (0 или 1): ";
//        cin >> newObj.hasAtmosphere;
//        cout << "Введите яркость: ";
//        cin >> newObj.Object.Star.brightness;
//        cout << "Введите температуру: ";
//        cin >> newObj.Object.Star.temperature;
//        break;
//    }
//    case 1:
//    {
//        newObj.type = type;
//
//        cout << "Введите имя: ";
//        cin >> newObj.name;
//        cout << "Введите радиус: ";
//        cin >> newObj.radius;
//        cout << "Есть атмосфера? (0 или 1): ";
//        cin >> newObj.hasAtmosphere;
//        cout << "Есть жизнь? (0 или 1): ";
//        cin >> newObj.Object.Planet.isInhabited;
//        cout << "Может быть жизнь? (0 или 1): ";
//        cin >> newObj.Object.Planet.isHabitable;
//        break;
//    }
//    case 2:
//    {
//        newObj.type = type;
//
//        cout << "Введите имя: ";
//        cin >> newObj.name;
//        cout << "Введите радиус: ";
//        cin >> newObj.radius;
//        cout << "Есть атмосфера? (0 или 1): ";
//        cin >> newObj.hasAtmosphere;
//        break;
//    }
//    }
//
//    return newObj;
//}
//
//int main()
//{
//    setlocale(LC_ALL, "Russian");
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    vector<AstronomObject> objects;
//
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
//
//    cout << "0 - Добавить элемент" << "\n";
//    cout << "1 - Удалить элемент" << "\n";
//    cout << "2 - Вывести элемент" << "\n";
//    cout << "3 - Вывести количество элементов" << "\n\n";
//
//    while (true) {
//        int choose = -1;
//
//        cout << "Выберите действие: ";
//        cin >> choose;
//
//        switch (choose) {
//        case 0:
//        {
//            int type = -1;
//            cout << "Выберите тип нового объекта (0 - звезда, 1 - планета, 2 - астероид): ";
//            cin >> type;
//
//            AstronomObject newObj = enterObject(type);
//            objects.push_back(newObj);
//            break;
//        }
//        case 1:
//        {
//            int index = -1;
//            cout << "Введите номер элемента для удаления: ";
//            cin >> index;
//            index--;
//
//            if (index > objects.size() - 1 || index < 0) {
//                cout << "Такого элемента не существует\n";
//                break;
//            }
//
//            if (objects.size() == 0) {
//                cout << "Вектор объектов пуст\n";
//                break;
//            }
//
//            objects.erase(objects.begin() + index);
//            break;
//        }
//        case 2:
//        {
//            int index = -1;
//            cout << "Введите номер элемента: ";
//            cin >> index;
//            index--;
//
//            if (index > objects.size() - 1 || index < 0) {
//                cout << "Такого элемента не существует\n";
//                break;
//            }
//
//            if (objects.size() == 0) {
//                cout << "Вектор объектов пуст\n";
//                break;
//            }
//
//            printObject(objects.at(index));
//            break;
//        }
//        case 3:
//        {
//            cout << "Количество элементов: " << objects.size() << "\n";
//            break;
//        }
//        }
//
//        cout << "\n";
//    }
//}
