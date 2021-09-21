//
//  main.cpp
//  lab2test
//
//  Created by Никита Стешов on 17.09.2021.
//

#include <iostream>
#include <gtest/gtest.h>
#include <math.h>
#include <nephroid.h>

int main(int argc, char * argv[]) {
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}

TEST(EmptyConstructor, ZeroXoY)
{
    nephroid a1;
    ASSERT_EQ(0, a1.x_coordinates());
    ASSERT_EQ(0, a1.y_coordinates());
    ASSERT_EQ(0, a1.get_rad());
}


TEST(SecondConstructor, InitConstructors)
{
    nephroid a2(3);
    ASSERT_EQ(3, a2.get_rad());
    ASSERT_EQ(12, a2.x_coordinates());
    ASSERT_EQ(0, a2.y_coordinates());
    
}

TEST(ThirdConstructor, InitConstructors)
{
    nephroid a3(3, 90);
    ASSERT_EQ(3, a3.get_rad());
    ASSERT_EQ(0, a3.x_coordinates());
    ASSERT_EQ(12, a3.y_coordinates());
}

TEST(lenght, length_done)
 {
    nephroid a4(5);
    ASSERT_EQ(120, a4.length());
    nephroid a7(6, 90);
    ASSERT_EQ(144, a7.length());
}

TEST(square, square_done)
{
    nephroid a5(5);
    ASSERT_NEAR(942.478, a5.square(), 0.01);
    nephroid a6(6, 90);
    ASSERT_NEAR(1357.17, a6.square(), 0.01);
}

TEST(curvature, curvature_done)
{
    nephroid a8(3, 80);
    ASSERT_NEAR(1.56283, a8.curvature(), 0.001);
    nephroid a9(4, 250);
    ASSERT_NEAR(4.10424, a9.curvature(), 0.001);
}

TEST(coordinates, coordinates_done)
{
    nephroid a10(10, 30);
    ASSERT_EQ(-40, a10.y_coordinates());
    ASSERT_NEAR(25.9808, a10.x_coordinates(), 0.01);
    nephroid a11(3, 90);
    ASSERT_EQ(0, a11.x_coordinates());
    ASSERT_EQ(12, a11.y_coordinates());
}

TEST(frm, frm_real)
{
    nephroid a12(3, 90);
    ASSERT_STREQ(" 0  + 12.00 ^ 2 - 4a^2 = 108a^4 * 12.00 ^2 \n", a12.frm(a12.x_coordinates(), a12.y_coordinates()));
}
