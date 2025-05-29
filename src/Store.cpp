#include<iostream>
#include<vector>

#include "Store.h"

using namespace std;

Store::Store() {
    items.push_back({ 5, 10 });
    items.push_back({ 20, 20 });
    items.push_back({ 60, 50 });
}

void Store::displayItems() {
    cout << "������ �ִ� ������:\n"
         << "0. ���\n";
    for(int i=0;i<items.size();i++) {
        items[i].printInfo(i+1);
    }
}

bool Store::empty() const {
    return items.empty();
}

void Store::buyItem(int choice, Character*& character) {
    if(choice < 1 || choice > items.size()) {
        cout << "�߸��� �����Դϴ�.\n\n";
        return;
    }

    const auto &item = items[choice-1];
    if(!character->useMedicine(item.hp, item.gold)) return;
    items.erase(items.begin() + (choice-1));
}