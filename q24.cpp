#include <iostream>
using namespace std;

class Box
{
    float a, b, c;

public:
    Box()
    {
        a = 0;
        b = 0;
        c = 0;
    }
    Box(float a, float b, float c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    float surface_area()
    {
        return 2 * (a * b + b * c + c * a);
    }
    float volume()
    {
        return a * b * c;
    }
    string boxType()
    {
        if (a == b && a == c)
        {
            return "Cube";
        }
        return "Cuboid";
    }
};

int main()
{
    float a, b, c;
    cout << "Enter sides of box" << endl;
    cin >> a >> b >> c;
    char choice;
    Box box = Box(a, b, c);

    while (true)
    {
        cout << "------MENU------" << endl;
        cout << "1.Surface Area" << endl;
        cout << "2.Volume" << endl;
        cout << "3.Is cuboid/cube" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == '4')
        {
            cout << "Exiting program..." << endl;
            break;
        }
        else if (choice == '1')
        {
            cout << box.surface_area() << " sq units." << endl;
        }
        else if (choice == '2')
        {
            cout << box.volume() << " cu units." << endl;
        }
        else if (choice == '3')
        {
            cout << "Type: " << box.boxType() << endl;
        }
        else
        {
            cout << "Enter a valid  " << endl;
        }
    }
    return 0;
}