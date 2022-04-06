#include <iostream>
#include <vector>

using namespace std;

namespace zich
{
    class Matrix
    {
    private:
        int num_of_rows;
        int num_of_columns;
        vector<double> values;
    public:
        Matrix();
        Matrix(vector<double> values, int num_of_rows, int num_of_columns);
        ~Matrix();
        Matrix operator+ (Matrix const & matrix);
        void operator+= (const Matrix matrix);
        Matrix operator- (const Matrix matrix);
        void operator-= (const Matrix matrix);
        Matrix operator+ ();
        Matrix operator- ();
        bool operator> (const Matrix matrix);
        bool operator>= (const Matrix matrix);
        bool operator< (const Matrix matrix);
        bool operator<= (const Matrix matrix);
        Matrix operator= (const Matrix matrix);
        bool operator!= (const Matrix matrix);
        bool operator== (Matrix const & matrix);
        Matrix operator++ ();// prefix
        Matrix operator++ (const int postfix_inc); // postfix
        Matrix operator-- (); // prefix
        Matrix operator-- (const int postfix_dec); // postfix
        friend Matrix operator* (const double num, const Matrix& matrix);
        friend Matrix operator* (const Matrix& matrix, const double num);
        friend Matrix operator*= (const Matrix& matrix, const double num);
        void operator*= (const double num);
        Matrix operator* (const Matrix matrix);
        void operator*= (const Matrix matrix);
        friend ostream& operator<< (ostream& output, const Matrix& matrix);
        friend istream& operator>> (istream& input , Matrix& matrix);
    };
}