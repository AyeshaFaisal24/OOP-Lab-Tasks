#include <iostream>
#include <vector>
using namespace std;

class PolyUtils; // Forward declaration

class Polynomial {
    vector<int> coeffs; 

    void trimZeros() {
        while (!coeffs.empty() && coeffs.back() == 0) {
            coeffs.pop_back();
        }
    }

    public:
        Polynomial() = default;
        
        Polynomial(const vector<int>& coefs) : coeffs(coefs) {
            trimZeros();
        }

        int getDeg() const {
            if (coeffs.empty()) return -1;
            return coeffs.size() - 1;
        }

        friend class PolyUtils;

        Polynomial operator+(const Polynomial& other) const {
            vector<int> res(max(coeffs.size(), other.coeffs.size()), 0);
            
            for (size_t i = 0; i < coeffs.size(); ++i)
                res[i] += coeffs[i];
            
            for (size_t i = 0; i < other.coeffs.size(); ++i)
                res[i] += other.coeffs[i];
            
            return Polynomial(res);
        }

        Polynomial operator-(const Polynomial& other) const {
            vector<int> res(max(coeffs.size(), other.coeffs.size()), 0);
            
            for (size_t i = 0; i < coeffs.size(); ++i)
                res[i] += coeffs[i];
            
            for (size_t i = 0; i < other.coeffs.size(); ++i)
                res[i] -= other.coeffs[i];
            
            return Polynomial(res);
        }

        Polynomial operator*(const Polynomial& other) const {
            if (coeffs.empty() || other.coeffs.empty())
                return Polynomial();
            
            vector<int> res(coeffs.size() + other.coeffs.size() - 1, 0);
            
            for (size_t i = 0; i < coeffs.size(); ++i)
                for (size_t j = 0; j < other.coeffs.size(); ++j)
                    res[i + j] += coeffs[i] * other.coeffs[j];
            
            return Polynomial(res);
        }

        friend ostream& operator<<(ostream& os, const Polynomial& poly);
};

class PolyUtils {
    public:
        static int eval(const Polynomial& poly, int x) {
            int res = 0;
            int pow = 1; 
            
            for (int coef : poly.coeffs) {
                res += coef * pow;
                pow *= x;
            }
            
            return res;
        }

        static Polynomial deriv(const Polynomial& poly) {
            if (poly.coeffs.empty() || poly.coeffs.size() == 1)
                return Polynomial();
            
            vector<int> derivCoefs(poly.coeffs.size() - 1);
            
            for (size_t i = 1; i < poly.coeffs.size(); ++i)
                derivCoefs[i - 1] = poly.coeffs[i] * i;
            
            return Polynomial(derivCoefs);
        }
};

ostream& operator<<(ostream& os, const Polynomial& poly) {
    if (poly.coeffs.empty()) {
        os << "0";
        return os;
    }
    
    for (int i = poly.coeffs.size() - 1; i >= 0; --i) {
        if (poly.coeffs[i] == 0) continue;
        
        if (i < poly.coeffs.size() - 1) {
            os << (poly.coeffs[i] > 0 ? " + " : " - ");
        } else if (poly.coeffs[i] < 0) {
            os << "-";
        }
        
        int absCoef = abs(poly.coeffs[i]);
        
        if (absCoef != 1 || i == 0)
            os << absCoef;
        
        if (i > 0) {
            os << "x";
            if (i > 1)
                os << "^" << i;
        }
    }
    
    return os;
}

int main() {

    Polynomial p1({1, 2, 3}); // 3x^2 + 2x + 1
    Polynomial p2({0, 1, -1}); // -x^2 + x
    
    cout << "p1: " << p1 << "\n";
    cout << "p2: " << p2 << "\n";
    cout << "p1 + p2: " << (p1 + p2) << "\n";
    cout << "p1 - p2: " << (p1 - p2) << "\n";
    cout << "p1 * p2: " << (p1 * p2) << "\n";
    
    cout << "p1 at x=2: " << PolyUtils::eval(p1, 2) << endl;
    cout << "Derivative of p1: " << PolyUtils::deriv(p1) << endl;
    
    return 0;
}