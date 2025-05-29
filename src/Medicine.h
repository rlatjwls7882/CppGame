#include<iostream>
using namespace std;

class Medicine {
private:
    string name;
public:
    /** 
	 * 가격: gold
	 * 회복량: hp
     */
    int gold, hp;
    Medicine(int gold, int hp);
    void printInfo(int i) const;
};