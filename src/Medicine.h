#include<iostream>
using namespace std;

class Medicine {
private:
    string name;
public:
    /** 
	 * ����: gold
	 * ȸ����: hp
     */
    int gold, hp;
    Medicine(int gold, int hp);
    void printInfo(int i) const;
};