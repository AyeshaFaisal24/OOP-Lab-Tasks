#include <iostream>
using namespace std;

class Matrix {
    private:
        int rows;
        int coloumns;
        int data[5][5]; 

    public:
        Matrix(int r, int c) : rows(r), coloumns(c) {
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < coloumns; ++j) {
                    data[i][j] = 0; 
                }
            }
        }

        int getRows() const {
            return rows;
        }

        int getColoumns() const {
            return coloumns;
        }

        void setElement(int i, int j, int num) {
            if (i >= 0 && i < rows && j >= 0 && j < coloumns) {
                data[i][j] = num;
            } else {
                cout << "Index out of bounds!!!" << endl;
            }
        }

        void display() const {
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < coloumns; ++j) {
                    cout << data[i][j] << " ";
                }
                cout << endl;
            }
        }

        Matrix add(const Matrix& second) {
            if (rows != second.rows || coloumns != second.coloumns) {
                cout << "Matrices cannot be added" << endl;
                return Matrix(0, 0);
            }
            Matrix sum(rows, coloumns);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < coloumns; ++j) {
                    sum.data[i][j] = data[i][j] + second.data[i][j];
                }
            }
            return sum;
        }

        Matrix multiply(const Matrix& second) {
            if (coloumns != second.rows) {
                cout << "Matrices cannot be multiplied!!" << endl;
                return Matrix(0, 0);
            }
            Matrix product(rows, second.coloumns);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < second.coloumns; ++j) {
                    product.data[i][j] = 0;
                    for (int k = 0; k < coloumns; ++k) {
                        product.data[i][j] += data[i][k] * second.data[k][j];
                    }
                }
            }
            return product;
        }
};

int main(int argc, char* argv[]) {
    if (argc < 9) {
        cout << "Insufficient arguments!!" << endl;
        return 1;
    }
    
    int r1 = atoi(argv[1]);
    int c1 = atoi(argv[2]);
    int r2 = atoi(argv[3]);
    int c2 = atoi(argv[4]);
    
    Matrix m1(r1, c1);
    Matrix m2(r2, c2);
    
    int index = 5;
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            m1.setElement(i, j, atoi(argv[index++]));
        }
    }
    
    for (int i = 0; i < r2; ++i) {
        for (int j = 0; j < c2; ++j) {
            m2.setElement(i, j, atoi(argv[index++]));
        }
    }
    
    cout << "Matrix 1:" << endl;
    m1.display();
    
    cout << "Matrix 2:" << endl;
    m2.display();
    
    Matrix sum = m1.add(m2);
    cout << "Sum of Matrices:" << endl;
    sum.display();
    
    Matrix product = m1.multiply(m2);
    cout << "Product of Matrices:" << endl;
    product.display();
    
    return 0;
}
