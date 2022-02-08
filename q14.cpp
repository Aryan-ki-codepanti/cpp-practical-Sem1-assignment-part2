#include <iostream>
using namespace std;

float area(float r){
    return 3.14 * r * r; 
}

float circumference(float r){
    return 3.14 * r * 2; 
}

int main()
{
    float r;
    cout << "Enter radius of circle: ";
    cin >> r;
    if (r < 0){
        cout << "Radius can not be negative" << endl;
        exit(1);
    }

    cout << "Circumference: " << circumference(r) << " units." << endl;
    cout << "Area: " << area(r) << " sq.units." << endl;

    return 0;
}