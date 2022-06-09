//#include <iostream>
//#include <string>
//#include <vector>
//#include <windows.h>
//
//using namespace std;
//
//struct Goods {
//
//    int type;
//    string name;
//    int price;
//
//    union Object {
//
//        Object() {}
//        ~Object() {}
//
//        struct {
//
//            double calories = 0.0;
//
//        } Food;
//        struct {
//
//            bool forKitchen = false;
//            bool softUpholstery = false;
//
//        } furniture;
//
//    } Object;
//};
//
//
//struct node {
//    Goods value;
//    node* next;
//
//    node(Goods x) : value(x), next(nullptr) {}
//
//    Goods getValue(){
//        return this->value;
//    }
//    void setValue(Goods newValue){
//        this->value = newValue;
//    }
//};
//
//struct list {
//    node* first;
//    int size = 0;
//
//    list() : first(nullptr) {
//    }
//
//    int getSize(){
//        return size;
//    }
//
//    void addFirst(node* n) {
//        n->next = first;
//        first = n;
//        size++;
//    }
//
//    void addLast(node* n) {
//        if (first == nullptr) {
//            first = n;
//            return;
//        }
//        node* t = first;
//        while (t->next != nullptr) {
//            t = t->next;
//        }
//        t->next = n;
//        size++;
//    }
//
//    void addByIndex(node* n,int index){
//        if(index < 0 || index > size - 1){
//            cout << "index not correct" << endl;
//            return;
//        }
//        if(index == 0){
//            addFirst(n);
//            return;
//        }
//        if(index == size - 1){
//            addLast(n);
//            return;
//        }
//        int cnt = 0;
//        node* curr = first;
//        node* temp;
//        size++;
//        while(true){
//            if(cnt == index - 1){
//                temp = curr->next;
//                curr->next = n;
//                n->next = temp;
//                return;
//            }
//            curr = curr->next;
//            cnt++;
//        }
//    }
//
//    void deleteFirst(){
//
//        node* old_head = first;
//
//        first = first->next;
//
//        delete old_head;
//        size--;
//    }
//
//    void deleteByIndex(int index){
//        if(index < 0 || index > size - 1){
//            cout << "index not correct" << endl;
//            return;
//        }
//        node* curr = first;
//        int cnt = 0;
//        while (cnt != index - 2) {
//            curr = curr->next;
//            cnt++;
//        }
//        node* nodeToDel = curr->next;
//        curr->next = curr->next->next;
//        delete nodeToDel;
//        size--;
//    }
//
//    void display() {
//        node* t = first;
//        cout << "list: ";
//        while (t) {
//            cout << t->value << " ";
//            t = t->next;
//        }
//    }
//
//    Goods get(int index){
//        node* t = first;
//        int current=0;
//        while(current != index){
//            current++;
//            t = t->next;
//        }
//        return t->getValue();
//    }
//
//};
//
//
//void printObject(Goods object) {
//
//    switch (object.type) {
//        case 0:
//        {
//            cout << "Type: Food" << "\n";
//            cout << "Name: " << object.name << "\n";
//            cout << "Price: " << object.price << "\n";
//            cout << "Calories: " << object.Object.Food.calories << "\n";
//            break;
//        }
//
//        case 1:
//        {
//            cout << "Type: Furniture" << "\n";
//            cout << "Name: " << object.name << "\n";
//            cout << "Price: " << object.price << "\n";
//            string isItForKitchen = object.Object.furniture.forKitchen ? "Yes":"Not really";
//            cout << "Kitchen furniture?: " << isItForKitchen << "\n";
//            string doesItHasSoftUpholstery = object.Object.furniture.softUpholstery ? "Yes":"Not really";
//            cout << "Upholstered?: " << doesItHasSoftUpholstery << "\n";
//            break;
//        }
//
//        case 2:
//        {
//            cout << "Type: Household Goods" << "\n";
//            cout << "Name: " << object.name << "\n";
//            cout << "Price: " << object.price << "\n";
//            break;
//        }
//    }
//}
//
//Goods initializeObject(int type) {
//    Goods newObj;
//
//    switch (type) {
//
//        case 0:
//        {
//            newObj.type = type;
//
//            cout << "Enter name: ";
//            cin >> newObj.name;
//            cout << "Enter price: ";
//            cin >> newObj.price;
//
//            cout << "Enter calories: ";
//            cin >> newObj.Object.Food.calories;
//
//            break;
//        }
//
//        case 1:
//        {
//            newObj.type = type;
//
//            cout << "Enter name: ";
//            cin >> newObj.name;
//            cout << "Enter price: ";
//            cin >> newObj.price;
//            cout << "Kitchen furniture? (0 or 1): ";
//            cin >> newObj.Object.furniture.forKitchen;
//            cout << "Is the upholstery soft? (0 or 1): ";
//            cin >> newObj.Object.furniture.softUpholstery;
//            break;
//        }
//
//        case 2:
//        {
//            newObj.type = type;
//            cout << "Enter name: ";
//            cin >> newObj.name;
//            cout << "Enter price: ";
//            cin >> newObj.price;
//
//            break;
//        }
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
//
//
// //   vector<Goods> objects;
//
//    Goods meat;
//    meat.type = 0;
//    meat.name = "Мясо";
//    meat.price = 500;
//
//    meat.Object.Food.calories = 300;
//
//
//    Goods milk;
//    milk.type = 0;
//    milk.name = "Молоко";
//    milk.price = 100;
//
//    milk.Object.Food.calories = 120;
//
//
//    Goods sofa;
//    sofa.type = 1;
//    sofa.name = "Диван";
//    sofa.price = 6378;
//
//    sofa.Object.furniture.softUpholstery = true;
//    sofa.Object.furniture.forKitchen = false;
//
//    Goods toothbrush;
//    toothbrush.type = 2;
//    toothbrush.name = "Щетка зубная";
//    toothbrush.price = 150;
//
//
////    objects.push_back(meat);
////    objects.push_back(milk);
////    objects.push_back(sofa);
////    objects.push_back(toothbrush);
//
//    list* l = new list();
//    l->addLast(new node(meat));
//
//    l->addLast(new node(milk));
//
//    l->addLast(new node(sofa));
//
//    cout << "0 - Add element" << "\n";
//    cout << "1 - Delete element" << "\n";
//    cout << "2 - Sout element" << "\n";
//    cout << "3 - Sout count of elements" << "\n\n";
//
//    while (true) {
//        int choose = -1;
//
//        cout << "Select action: ";
//        cin >> choose;
//
//        switch (choose) {
//
//            case 0:
//            {
//                int type = -1;
//                cout << "Select type of new object (0 - Food, 1 - furniture, 2 - household): ";
//                cin >> type;
//
//                Goods newObj = initializeObject(type);
//            //    objects.push_back(newObj);
//                l->addLast(new node(newObj));
//
//                break;
//            }
//
//            case 1:
//            {
//                int index = -1;
//                cout << "Input number for delete: ";
//                cin >> index;
//                index--;
//
//                if (index > l->getSize() - 1 || index < 0) {
//                    cout << "There isnt this element\n";
//                    break;
//                }
//
//                if (l->getSize() == 0) {
//                    cout << "Vector of objects is empty\n";
//                    break;
//                }
//
//              //  objects.erase(objects.begin() + index);
//              l->deleteByIndex(  index)
//                break;
//            }
//
//            case 2:
//            {
//                int index = -1;
//                cout << "Input number of element: ";
//                cin >> index;
//                index--;
//
//                if (index > l->getSize() - 1 || index < 0) {
//                    cout << "There isnt this element\n";
//                    break;
//                }
//
//                if (l->getSize() == 0) {
//                    cout << "Vector of objects is empty\n";
//                    break;
//                }
//
//                printObject(l->get(index));
//                break;
//            }
//
//            case 3:
//            {
//                cout << "Count of elements: " << l->size << "\n";
//                break;
//            }
//        }
//
//        cout << "\n";
//    }
//}
