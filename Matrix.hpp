#include <iostream>
#include <vector>

using namespace std;

namespace zich
{
    class Matrix
    {
    private:
        vector<double> values;
    public:
        int num_of_rows;
        int num_of_columns;
        Matrix(){}
        Matrix(vector<double> values, int num_of_rows, int num_of_columns){}
        ~Matrix(){}
        Matrix operator+ (Matrix const & matrix){return matrix;}
        Matrix operator+= (const Matrix matrix){return matrix;}
        Matrix operator- (const Matrix matrix){return matrix;}
        Matrix operator-= (const Matrix matrix){return matrix;}
        Matrix operator+ (){return Matrix();}
        Matrix operator- (){return Matrix();}
        bool operator> (const Matrix matrix){return true;}
        bool operator>= (const Matrix matrix){return true;}
        bool operator< (const Matrix matrix){return true;}
        bool operator<= (const Matrix matrix){return true;}
        Matrix operator= (const Matrix matrix){return matrix;}
        bool operator!= (const Matrix matrix){return true;}
        bool operator== (Matrix const & matrix){return true;}
        Matrix operator++ (){return Matrix();} // prefix
        Matrix operator++ (const int postfix_inc){return Matrix();} // postfix
        Matrix operator-- (){return Matrix();} // prefix
        Matrix operator-- (const int postfix_dec){return Matrix();} // postfix
        friend Matrix operator* (const double num, const Matrix& matrix) {return matrix;}
        //friend Matrix operator* (const int num, const Matrix& matrix) {return Matrix();}
        void operator*= (const double num) {}
        Matrix operator* (const Matrix matrix){return matrix;}
        void operator*= (const Matrix matrix){}
        friend ostream& operator<< (ostream& output, const Matrix& matrix) {return output;}
        friend istream& operator>> (istream& input , Matrix& matrix) {return input;}
    };
}