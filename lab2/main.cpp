//
//  main.cpp
//  lab2
//
//  Created by Никита Стешов on 15.09.2021.
//
#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>
#include <strstream>
#include "/Users/steshoff/Documents/labs/lab2lib/nephroid.h"


int main(){
    double r, t;
    char *s = nullptr;
    std::cout << "Введите радиус" << std::endl;
    if (!getNum(r))
        return -1;
    if (r >= 0){
        std::cout << "Введите угол [0, 180]" << std::endl;
        if (!getNum(t))
            return -1;
        nephroid a1(r, t);
        double x = a1.x_coordinates();
        double y = a1.y_coordinates();
        std::cout << "Length = " << a1.length();
        std::cout << "\nSquare = " << a1.square();
        std::cout << "\nCurvature ="  << a1.curvature();
        std::cout << "\nX = " << x;
        std::cout << "\nY = " << y << std::endl;
        nephroid frm(x, y);
        s = frm.frm(x, y);
        std::cout << s << std::endl;
        delete [] s;
                return 0;
        
    }
    else {
        std::cout << "Ошибка радиуса" << std::endl;
        return 0;
    }
    
}
