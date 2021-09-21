//
//  nephroid_class.cpp
//  lab2
//
//  Created by Никита Стешов on 17.09.2021.
//
#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>
#include <strstream>
#include "nephroid.h"
 

double nephroid::length() const{
    return 24.0 * r;
}

double nephroid::square() const{
    return 12.0 * M_PI * r * r;
}

double nephroid::curvature() const{
    return abs(3 * r * cos(t * M_PI / 180));
}

double nephroid::x_coordinates() const{
    return r * (3 * cos(t * M_PI / 180) + cos(3 * (t * M_PI / 180)));
}

double nephroid::y_coordinates() const{
    return (-1) * (r * (3 * sin(3 * t * M_PI / 180) + sin(3 * (t * M_PI / 180))));
}

double nephroid::get_rad() const{
    return r;
}

// decart form of nephroid equation
char *nephroid::frm(double x, double y) const // Nephroid equation (x^2 + y^2 - 4a^2)^3 = 108 * a^4 * y^2
{

    char s1[] = " ^ 2 +  ^ 2 - 4a^2 = 108a^4 *  ^2 \n"; // const part
    unsigned long l = strlen(s1) + 1; // null byte
    char num[20]; // memory for double in char
    snprintf(num, 20, "%.2f", x); // x in char
    l += strlen(num);
    snprintf(num, 20, "%.2f", y); // y in char
    l += strlen(num);
    // выделяем необходимую память
    char *s = new char[l];
    // если x y 0 - не выводятся
    if (x == 0)
        snprintf(s, l, " 0 ");
    else
        snprintf(s, l, "%.2f ^ 2", x);
    unsigned long k = strlen(s);
    if (y == 0)
        snprintf(s + k, l - k, " + 0 ");
    else
        snprintf(s + k, l - k, " + %.2f ^ 2 - 4a^2", y);
    k = strlen(s);
    snprintf(s + k, l - k, " = 108a^4 * %.2f ^2 \n", y);
    return s;
}

