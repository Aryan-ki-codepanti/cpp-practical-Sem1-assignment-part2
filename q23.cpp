#include <iostream>
#include <cmath>
using namespace std;

class Triangle{
    float a , b , c, base , height;

    public:
    Triangle(float v1 , float v2 , float v3){
        a = v1;
        b = v2;
        c = v3;        
        base = 0;
        height = 0;
    }

    Triangle(float v1 , float v2){
        a = 0;
        b = 0;
        c = 0;        
        base = v1;
        height = v2;        
    }

    float getArea(){
        if (a != 0){
            float s = (a + b + c)/2.0;
            float area = sqrt(s * (s - a) * (s - b) * (s - c));
            return area;
        }
        return 0.5 * base * height;
    }

};

int main()
{
    Triangle t1 = Triangle(9 , 9 , 9);
    Triangle t2 = Triangle(3 ,2.4);
    cout << t1.getArea() << " sq units" << endl;
    cout << t2.getArea() << " sq units" <<  endl;

    return 0;
}