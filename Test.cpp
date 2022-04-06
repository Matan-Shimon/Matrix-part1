//
// Created by matan on 05/04/2022.
//

#include "doctest.h"
#include "Matrix.hpp"

using namespace std;
using namespace zich;

TEST_CASE("+ operator: good")
{
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix matrix1{vec1, 3, 3};
    Matrix check1 = matrix1 + matrix1;
    vector<double> ans_vec1 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix ans1{ans_vec1,3,3};
    bool check = check1 == ans1;
    CHECK(check == true);
    vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
    Matrix matrix2{vec2,3,3};
    Matrix check2 = matrix1 + matrix2;
    Matrix check3 = matrix2 + matrix1;
    vector<double> ans_vec2 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    Matrix ans2{ans_vec2,3,3};
    check = check2 == ans2;
    CHECK(check == true);
    check = check3 == ans2;
    CHECK(check == true);
    vector<double> vec3 = {-1, 1, 1, 1, -1, 1, 1, 1, -1};
    Matrix matrix3{vec3,3,3};
    Matrix check4 = matrix1 + matrix3;
    Matrix check5 = matrix3 + matrix1;
    vector<double> ans_vec3 = {0, 1, 1, 1, 0, 1, 1, 1, 0};
    Matrix ans3{ans_vec3,3,3};
    check = check4 == ans3;
    CHECK(check == true);
    check = check5 == ans3;
    CHECK(check == true);
}

TEST_CASE("+ operator: bad")
{
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
    Matrix matrix1{vec1, 2, 5};
    Matrix matrix2{ vec1, 5, 2};
    CHECK_THROWS(matrix1+matrix2);
    CHECK_THROWS(matrix2+matrix1);
    vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
    Matrix matrix3{vec2, 2, 4};
    Matrix matrix4{vec2, 8, 1};
    CHECK_THROWS(matrix1+matrix3);
    CHECK_THROWS(matrix3+matrix1);
    CHECK_THROWS(matrix3+matrix2);
    CHECK_THROWS(matrix3+matrix2);
    CHECK_THROWS(matrix3+matrix4);
    CHECK_THROWS(matrix4+matrix3);
}

TEST_CASE("+= operator: good")
{
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix matrix1{vec1, 3, 3};
    matrix1 += matrix1;
    vector<double> ans_vec1 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix ans1{ans_vec1,3,3};
    CHECK_EQ(matrix1 == ans1, true);
    vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
    Matrix matrix2{vec2,3,3};
    matrix2 += matrix1;
    Matrix ans2{vec1,3,3};
    CHECK_EQ(matrix2 == ans2, true);
    vector<double> vec3 = {-1, 1, 1, 1, -1, 1, 1, 1, -1};
    Matrix matrix3{vec3,3,3};
    matrix3 += matrix2;
    vector<double> ans_vec2 = {0, 1, 1, 1, 0, 1, 1, 1, 0};
    Matrix ans3{ans_vec2,3,3};
    CHECK_EQ(matrix3 == ans3, true);
}

TEST_CASE("+= operator: bad")
{
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
    Matrix matrix1{vec1, 2, 5};
    Matrix matrix2{ vec1, 5, 2};
    CHECK_THROWS(matrix1+=matrix2);
    CHECK_THROWS(matrix2+=matrix1);
    vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
    Matrix matrix3{vec2, 2, 4};
    Matrix matrix4{vec2, 8, 1};
    CHECK_THROWS(matrix1+=matrix3);
    CHECK_THROWS(matrix3+=matrix1);
    CHECK_THROWS(matrix3+=matrix2);
    CHECK_THROWS(matrix3+=matrix2);
    CHECK_THROWS(matrix3+=matrix4);
    CHECK_THROWS(matrix4+=matrix3);
}

TEST_CASE("- operator: good")
{
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix matrix1{vec1, 3, 3};
    Matrix check1 = matrix1 - matrix1;
    vector<double> ans_vec1 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    Matrix ans1{ans_vec1,3,3};
    CHECK_EQ(check1 == ans1, true);
    vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
    Matrix matrix2{vec2,3,3};
    Matrix check2 = matrix1 - matrix2;
    Matrix check3 = matrix2 - matrix1;
    vector<double> ans_vec2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    vector<double> ans_vec3 = {-2, 0, 0, 0, -2, 0, 0, 0, -2};
    Matrix ans2{ans_vec2,3,3};
    Matrix ans3{ans_vec3,3,3};
    CHECK_EQ(check2 == ans2, true);
    CHECK_EQ(check3 == ans3, true);
    vector<double> vec3 = {-1, 1, 1, 1, -1, 1, 1, 1, -1};
    Matrix matrix3{vec3,3,3};
    Matrix check4 = matrix1 - matrix3;
    Matrix check5 = matrix3 - matrix1;
    vector<double> ans_vec4 = {2, -1, -1, -1, 2, -1, -1, -1, 2};
    Matrix ans4{ans_vec4,3,3};
    CHECK_EQ(check4 == ans4, true);
    vector<double> ans_vec5 = {0, 1, 1, 1, 0, 1, 1, 1, 0};
    Matrix ans5{ans_vec5,3,3};
    CHECK_EQ(check5 == ans5, true);
}

TEST_CASE("- operator: bad")
{
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
    Matrix matrix1{vec1, 2, 5};
    Matrix matrix2{ vec1, 5, 2};
    CHECK_THROWS(matrix1-matrix2);
    CHECK_THROWS(matrix2-matrix1);
    vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
    Matrix matrix3{vec2, 2, 4};
    Matrix matrix4{vec2, 8, 1};
    CHECK_THROWS(matrix1-matrix3);
    CHECK_THROWS(matrix3-matrix1);
    CHECK_THROWS(matrix3-matrix2);
    CHECK_THROWS(matrix3-matrix2);
    CHECK_THROWS(matrix3-matrix4);
    CHECK_THROWS(matrix4-matrix3);
}

TEST_CASE("-= operator: good")
{
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix matrix1{vec1, 3, 3};
    matrix1 -= matrix1;
    vector<double> ans_vec1 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    Matrix ans1{ans_vec1,3,3};
    CHECK_EQ(matrix1 == ans1, true);
    vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
    Matrix matrix2{vec2,3,3};
    matrix1 -= matrix2;
    vector<double> ans_vec2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix ans2{ans_vec2,3,3};
    CHECK_EQ(matrix1 == ans2, true);
    vector<double> vec3 = {-1, 1, 1, 1, -1, 1, 1, 1, -1};
    Matrix matrix3{vec3,3,3};
    matrix3 -= matrix1;
    Matrix check5 = matrix3 - matrix1;
    vector<double> ans_vec4 = {-3, 1, 1, 1, -3, 1, 1, 1, -3};
    Matrix ans4{ans_vec4,3,3};
    CHECK_EQ(matrix3 == ans4, true);
}

TEST_CASE("-= operator: bad")
{
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix matrix1{vec1, 2, 5};
    Matrix matrix2{ vec1, 5, 2};
    CHECK_THROWS(matrix1-=matrix2);
    CHECK_THROWS(matrix2-=matrix1);
    vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
    Matrix matrix3{vec2, 2, 4};
    Matrix matrix4{vec2, 8, 1};
    CHECK_THROWS(matrix1-=matrix3);
    CHECK_THROWS(matrix3-=matrix1);
    CHECK_THROWS(matrix3-=matrix2);
    CHECK_THROWS(matrix3-=matrix2);
    CHECK_THROWS(matrix3-=matrix4);
    CHECK_THROWS(matrix4-=matrix3);
}

TEST_CASE("+ operator (unari): good")
{

}

TEST_CASE("+ operator (unari): bad")
{

}

TEST_CASE("- operator (unari): good")
{

}

TEST_CASE("- operator (unari): bad")
{

}

TEST_CASE("> operator: good")
{
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix matrix1{vec1, 3, 3};
    Matrix check1 = matrix1 + matrix1;
    CHECK_EQ(check1 > matrix1, true);
    vector<double> vec3 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
    Matrix matrix3{vec3,3,3};
    CHECK_NE(matrix3 > matrix1, true);
    vector<double> vec4 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    Matrix matrix4{vec4,3,3};
    CHECK_EQ(matrix4 > matrix3, true);
    vector<double> vec5 = {1, 1 ,1 ,0 ,0 ,0 ,0, 0, 0};
    Matrix matrix5{vec5, 3, 3};
    CHECK_NE(matrix1 > matrix5, true);
    CHECK_NE(matrix5 > matrix1, true);
}

TEST_CASE("> operator: bad")
{
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
    Matrix matrix1{vec1, 2, 5};
    Matrix matrix2{ vec1, 5, 2};
    CHECK_THROWS(bool check = matrix1>matrix2);
    CHECK_THROWS(bool check = matrix2>matrix1);
    vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
    Matrix matrix3{vec2, 2, 4};
    Matrix matrix4{vec2, 8, 1};
    CHECK_THROWS(bool check = matrix1>matrix3);
    CHECK_THROWS(bool check = matrix3>matrix1);
    CHECK_THROWS(bool check = matrix3>matrix2);
    CHECK_THROWS(bool check = matrix3>matrix2);
    CHECK_THROWS(bool check = matrix3>matrix4);
    CHECK_THROWS(bool check = matrix4>matrix3);
}

TEST_CASE(">= operator: good")
{
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix matrix1{vec1, 3, 3};
    Matrix check1 = matrix1 + matrix1;
    CHECK_EQ(check1 >= matrix1, true);
    vector<double> vec3 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
    Matrix matrix3{vec3,3,3};
    CHECK_NE(matrix3 >= matrix1, true);
    vector<double> vec4 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    Matrix matrix4{vec4,3,3};
    CHECK_EQ(matrix4 >= matrix3, true);
    vector<double> vec5 = {1, 1 ,1 ,0 ,0 ,0 ,0, 0, 0};
    Matrix matrix5{vec5, 3, 3};
    CHECK_EQ(matrix1 >= matrix5, true);
    CHECK_EQ(matrix5 >= matrix1, true);
}

TEST_CASE(">= operator: bad")
{
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
    Matrix matrix1{vec1, 2, 5};
    Matrix matrix2{ vec1, 5, 2};
    CHECK_THROWS(bool check = matrix1>=matrix2);
    CHECK_THROWS(bool check = matrix2>=matrix1);
    vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
    Matrix matrix3{vec2, 2, 4};
    Matrix matrix4{vec2, 8, 1};
    CHECK_THROWS(bool check = matrix1>=matrix3);
    CHECK_THROWS(bool check = matrix3>=matrix1);
    CHECK_THROWS(bool check = matrix3>=matrix2);
    CHECK_THROWS(bool check = matrix3>=matrix2);
    CHECK_THROWS(bool check = matrix3>=matrix4);
    CHECK_THROWS(bool check = matrix4>=matrix3);
}

TEST_CASE("< operator: good")
{
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix matrix1{vec1, 3, 3};
    Matrix check1 = matrix1 + matrix1;
    CHECK_EQ(matrix1 < check1, true);
    vector<double> vec3 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
    Matrix matrix3{vec3,3,3};
    CHECK_NE(matrix1 < matrix3, true);
    vector<double> vec4 = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    Matrix matrix4{vec4,3,3};
    CHECK_EQ(matrix3 < matrix4, true);
    vector<double> vec5 = {1, 1 ,1 ,0 ,0 ,0 ,0, 0, 0};
    Matrix matrix5{vec5, 3, 3};
    CHECK_NE(matrix5 < matrix1, true);
    CHECK_NE(matrix1 < matrix5, true);
}

TEST_CASE("< operator: bad")
{
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
    Matrix matrix1{vec1, 2, 5};
    Matrix matrix2{ vec1, 5, 2};
    CHECK_THROWS(bool check = matrix1<matrix2);
    CHECK_THROWS(bool check = matrix2<matrix1);
    vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
    Matrix matrix3{vec2, 2, 4};
    Matrix matrix4{vec2, 8, 1};
    CHECK_THROWS(bool check = matrix1<matrix3);
    CHECK_THROWS(bool check = matrix3<matrix1);
    CHECK_THROWS(bool check = matrix3<matrix2);
    CHECK_THROWS(bool check = matrix3<matrix2);
    CHECK_THROWS(bool check = matrix3<matrix4);
    CHECK_THROWS(bool check = matrix4<matrix3);
}

TEST_CASE("!= operator: good")
{
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix matrix1{vec1, 3, 3};
    Matrix check1 = matrix1 + matrix1;
    vector<double> ans_vec1 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix ans1{ans_vec1,3,3};
    CHECK_NE(check1 != ans1, true);
    CHECK_EQ(matrix1 != check1, true);
    CHECK_EQ(ans1 != matrix1, true);
    vector<double> vec2 = {1, 0, 1, 0, 0, 0, 1, 0, 0};
    Matrix matrix2{vec2, 3, 3};
    CHECK_NE(matrix1 != matrix2, true);
    CHECK_NE(matrix2 != matrix1, true);
}

TEST_CASE("!= operator: bad")
{
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0};
    Matrix matrix1{vec1, 2, 5};
    Matrix matrix2{ vec1, 5, 2};
    CHECK_THROWS(bool check = matrix1!=matrix2);
    CHECK_THROWS(bool check = matrix2!=matrix1);
    vector<double> vec2 = {1, 0, 0, 1, 0, 1, 1, 0};
    Matrix matrix3{vec2, 2, 4};
    Matrix matrix4{vec2, 8, 1};
    CHECK_THROWS(bool check = matrix1!=matrix3);
    CHECK_THROWS(bool check = matrix3!=matrix1);
    CHECK_THROWS(bool check = matrix3!=matrix2);
    CHECK_THROWS(bool check = matrix3!=matrix2);
    CHECK_THROWS(bool check = matrix3!=matrix4);
    CHECK_THROWS(bool check = matrix4!=matrix3);
}

TEST_CASE("++ operator: good")
{
    vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix matrix1{vec1, 3, 3};
    matrix1++;
    vector<double> ans_vec1 = {2, 1, 1, 1, 2, 1, 1, 1, 2};
    Matrix ans1{ans_vec1,3,3};
    CHECK_EQ(matrix1 == ans1, true);
    vector<double> vec2 = {-1, 0, 0, 0, -1, 0, 0, 0, -1};
    Matrix matrix2{vec2,3,3};
    matrix2++;
    vector<double> ans_vec2 = {0, 1, 1, 1, 0, 1, 1, 1, 0};
    Matrix ans2{ans_vec2,3,3};
    CHECK_EQ(matrix2 == ans2, true);
    vector<double> vec3 = {-1, 1, 1, 1, -1, 1, 1, 1, -1};
    Matrix matrix3{vec3,3,3};
    Matrix matrix4 = matrix3;
    matrix3++;
    vector<double> ans_vec3 = {0, 2, 2, 2, 0, 2, 2, 2, 0};
    Matrix ans3{ans_vec3,3,3};
    CHECK_EQ(matrix3 == ans3, true);
    CHECK_NE(matrix3 == matrix4, true);
}