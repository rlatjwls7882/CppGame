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
    cout << "상점에 있는 아이템:\n"
         << "0. 취소\n";
    for(int i=0;i<items.size();i++) {
        items[i].printInfo(i+1);
    }
}

bool Store::empty() const {
    return items.empty();
}

void Store::buyItem(int choice, Character*& character) {
    if(choice < 1 || choice > items.size()) {
        cout << "잘못된 선택입니다.\n\n";
        return;
    }

    const auto &item = items[choice-1];
    if(!character->useMedicine(item.hp, item.gold)) return;
    items.erase(items.begin() + (choice-1));
}