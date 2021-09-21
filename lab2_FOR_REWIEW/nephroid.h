//
//  nephroid.h
//  lab2
//
//  Created by Никита Стешов on 15.09.2021.
//

#ifndef nephroid_h
#define nephroid_h




template <class T>
bool getNum(T &a)
{
    while (!(std::cin >> a))
    {
        if (std::cin.eof())
            return false;
    //if (!std::cin.good()) //error
        //return false;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return true;
    
}

class nephroid{
private:
    double r, t; // r - radius, t - angle [0; 2PI]
public:
    nephroid():r(0), t(0){}; // empty constructor. Center of the first circle at the origin of XoY, the radius of the second circle is 0
    nephroid(double radius):r(radius), t(0){}; //second constructor. Assigns a radius value.
    nephroid(double radius, double angle):r(radius), t(angle){}; //second constructor. Assigns a radius and angle value.
    double length() const;
    double curvature() const;
    double square() const;
    double x_coordinates() const;
    double y_coordinates() const;
    char *frm(double x, double y) const;
    double get_rad() const;
    // еще уравнение
};

#endif /* nephroid_h */
