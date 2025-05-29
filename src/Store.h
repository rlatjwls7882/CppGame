#include<vector>

#include "Medicine.h"
#include "Character.h"

class Store {
private:
    vector<Medicine> items;
public:
    Store();
    void displayItems();
    bool empty() const;
    void buyItem(int choice, Character*& character);
};