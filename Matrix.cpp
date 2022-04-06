//
// Created by matan on 05/04/2022.
//
#include "Matrix.hpp"

using namespace zich;

Matrix::Matrix()
{
    this->num_of_rows = 0;
    this->num_of_columns = 0;
}
Matrix::Matrix(vector<double> values, int num_of_rows, int num_of_columns)
{
    this->num_of_columns = num_of_columns;
    this->num_of_rows = num_of_rows;
    this->values = values;
}
Matrix::~Matrix()
{
    //cout << "Destructor" << endl;
}
Matrix Matrix::operator+ (Matrix const & matrix)
{
    if (this->num_of_rows != matrix.num_of_rows || this->num_of_columns != matrix.num_of_columns)
    {
        throw invalid_argument("Matrices sized must be equal!");
    }
    vector<double> output_vector;
    for (unsigned int i = 0; i < matrix.values.size(); ++i) {
        output_vector.push_back(this->values.at(i)+matrix.values.at(i));
    }
    Matrix output_matrix{output_vector, this->num_of_rows, this->num_of_columns};
    return output_matrix;
}
void Matrix::operator+= (const Matrix matrix)
{
    if (this->num_of_rows != matrix.num_of_rows || this->num_of_columns != matrix.num_of_columns)
    {
        throw invalid_argument("Matrices sized must be equal!");
    }
    for (unsigned int i = 0; i < matrix.values.size(); ++i) {
        this->values.at(i) += matrix.values.at(i);
    }
}
Matrix Matrix::operator- (const Matrix matrix)
{
    if (this->num_of_rows != matrix.num_of_rows || this->num_of_columns != matrix.num_of_columns)
    {
        throw invalid_argument("Matrices sized must be equal!");
    }
    vector<double> output_vector;
    for (unsigned int i = 0; i < matrix.values.size(); ++i) {
        output_vector.push_back(this->values.at(i)-matrix.values.at(i));
    }
    Matrix output_matrix{output_vector, this->num_of_rows, this->num_of_columns};
    return output_matrix;
}
void Matrix::operator-= (const Matrix matrix)
{
    if (this->num_of_rows != matrix.num_of_rows || this->num_of_columns != matrix.num_of_columns)
    {
        throw invalid_argument("Matrices sized must be equal!");
    }
    for (unsigned int i = 0; i < matrix.values.size(); ++i) {
        this->values.at(i) -= matrix.values.at(i);
    }
}
Matrix Matrix::operator+ (){return Matrix();} // unari
Matrix Matrix::operator- (){return Matrix();} // unari
bool Matrix::operator> (const Matrix matrix)
{
    if (this->num_of_rows != matrix.num_of_rows || this->num_of_columns != matrix.num_of_columns)
    {
        throw invalid_argument("Matrices sized must be equal!");
    }
    double sum1 = 0, sum2 = 0;
    for (unsigned int i = 0; i < this->values.size(); ++i)
    {
        sum1 += this->values.at(i);
        sum2 += matrix.values.at(i);
    }
    bool ans = sum1 > sum2;
    return ans;
}
bool Matrix::operator>= (const Matrix matrix)
{
    if (this->num_of_rows != matrix.num_of_rows || this->num_of_columns != matrix.num_of_columns)
    {
        throw invalid_argument("Matrices sized must be equal!");
    }
    double sum1 = 0, sum2 = 0;
    for (unsigned int i = 0; i < this->values.size(); ++i)
    {
        sum1 += this->values.at(i);
        sum2 += matrix.values.at(i);
    }
    bool ans = sum1 >= sum2;
    return ans;
}
bool Matrix::operator< (const Matrix matrix)
{
    if (this->num_of_rows != matrix.num_of_rows || this->num_of_columns != matrix.num_of_columns)
    {
        throw invalid_argument("Matrices sized must be equal!");
    }
    double sum1 = 0, sum2 = 0;
    for (unsigned int i = 0; i < this->values.size(); ++i)
    {
        sum1 += this->values.at(i);
        sum2 += matrix.values.at(i);
    }
    bool ans = sum1 < sum2;
    return ans;
}
bool Matrix::operator<= (const Matrix matrix)
{
    if (this->num_of_rows != matrix.num_of_rows || this->num_of_columns != matrix.num_of_columns)
    {
        throw invalid_argument("Matrices sized must be equal!");
    }
    double sum1 = 0, sum2 = 0;
    for (unsigned int i = 0; i < this->values.size(); ++i)
    {
        sum1 += this->values.at(i);
        sum2 += matrix.values.at(i);
    }
    bool ans = sum1 <= sum2;
    return ans;
}
Matrix Matrix::operator= (const Matrix matrix)
{
    Matrix output_matrix{matrix.values, matrix.num_of_rows, matrix.num_of_columns};
    return output_matrix;
}
bool Matrix::operator!= (const Matrix matrix)
{
    if (this->num_of_rows != matrix.num_of_rows || this->num_of_columns != matrix.num_of_columns)
    {
        throw invalid_argument("Matrices sized must be equal!");
    }
    bool ans = false;
    for (unsigned int i = 0; i < this->values.size(); ++i) {
        if (this->values.at(i) != matrix.values.at(i))
        {
            ans = true;
        }
    }
    return ans;
}
bool Matrix::operator== (Matrix const & matrix)
{
    if (this->num_of_rows != matrix.num_of_rows || this->num_of_columns != matrix.num_of_columns)
    {
        throw invalid_argument("Matrices sized must be equal!");
    }
    bool ans = true;
    for (unsigned int i = 0; i < this->values.size(); ++i) {
        if (this->values.at(i) != matrix.values.at(i))
        {
            ans = false;
        }
    }
    return ans;
}
Matrix Matrix::operator++ () // prefix
{
    for (unsigned int i = 0; i < this->values.size(); ++i) {
        this->values.at(i)++;
    }
    return *this;
}
Matrix Matrix::operator++ (const int postfix_inc) // postfix
{
    Matrix output_matrix{this->values, this->num_of_rows, this->num_of_columns};
    for (unsigned int i = 0; i < this->values.size(); ++i) {
        this->values.at(i)++;
    }
    return output_matrix;
}
Matrix Matrix::operator-- () // prefix
{
    for (unsigned int i = 0; i < this->values.size(); ++i) {
        this->values.at(i)--;
    }
    return *this;
}
Matrix Matrix::operator-- (const int postfix_dec) // postfix
{
    Matrix output_matrix{this->values, this->num_of_rows, this->num_of_columns};
    for (unsigned int i = 0; i < this->values.size(); ++i) {
        this->values.at(i)--;
    }
    return output_matrix;
}
Matrix zich::operator* (const double num, const Matrix& matrix)
{
    return matrix * num;
}
Matrix zich::operator* (const Matrix& matrix, const double num)
{
    Matrix output_matrix = matrix;
    for (unsigned int i = 0; i < output_matrix.values.size(); ++i) {
        output_matrix.values.at(i) *= num;
    }
    return output_matrix;
}
void Matrix::operator*= (const double num)
{
    for (unsigned int i = 0; i < this->values.size(); ++i) {
        this->values.at(i) *= num;
    }
}
Matrix Matrix::operator* (const Matrix matrix)
{
    if (this->num_of_columns != matrix.num_of_rows)
    {
        throw invalid_argument("the left matrix number of columns must be equal to the right matrix number of rows");
    }
    vector<double> output_vector;
    for (unsigned int i = 0; i < matrix.values.size(); ++i) {
        output_vector.push_back(this->values.at(i)*matrix.values.at(i));
    }
    Matrix output_matrix{output_vector, this->num_of_rows, this->num_of_columns};
    return output_matrix;
}
void Matrix::operator*= (const Matrix matrix)
{
    if (this->num_of_columns != matrix.num_of_rows)
    {
        throw invalid_argument("Matrices sized must be equal!");
    }
    for (unsigned int i = 0; i < matrix.values.size(); ++i) {
        this->values.at(i) *= matrix.values.at(i);
    }
}
ostream& zich::operator<< (ostream& output, const Matrix& matrix) {return output;}
istream& zich::operator>> (istream& input , Matrix& matrix) {return input;}