#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigInteger {
    vector<int> digits;
    bool isNegative = false;

    void trimZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false;
        }
    }

    static BigInteger addAbs(const BigInteger& a, const BigInteger& b) {
        BigInteger result;
        int carry = 0;
        size_t maxLen = max(a.digits.size(), b.digits.size());

        for (size_t i = 0; i < maxLen || carry; ++i) {
            int sum = carry;
            if (i < a.digits.size()) sum += a.digits[i];
            if (i < b.digits.size()) sum += b.digits[i];
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }
        return result;
    }

    static BigInteger subAbs(const BigInteger& a, const BigInteger& b) {
        BigInteger result;
        int borrow = 0;

        for (size_t i = 0; i < a.digits.size(); ++i) {
            int diff = a.digits[i] - borrow;
            if (i < b.digits.size()) diff -= b.digits[i];
            
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits.push_back(diff);
        }
        result.trimZeros();
        return result;
    }

    static bool lessAbs(const BigInteger& a, const BigInteger& b) {
        if (a.digits.size() != b.digits.size()) {
            return a.digits.size() < b.digits.size();
        }
        for (int i = a.digits.size() - 1; i >= 0; --i) {
            if (a.digits[i] != b.digits[i]) {
                return a.digits[i] < b.digits[i];
            }
        }
        return false;
    }

    public:
        BigInteger() : digits{0} {}
        BigInteger(long long num) {
            if (num < 0) {
                isNegative = true;
                num = -num;
            }
            do {
                digits.push_back(num % 10);
                num /= 10;
            } while (num > 0);
        }
        BigInteger(const string& s) {
            int start = 0;
            if (s[0] == '-') {
                isNegative = true;
                start = 1;
            }
            for (int i = s.size() - 1; i >= start; --i) {
                if (isdigit(s[i])) {
                    digits.push_back(s[i] - '0');
                }
            }
            trimZeros();
        }

        BigInteger operator-() const {
            BigInteger result = *this;
            if (result.digits.size() == 1 && result.digits[0] == 0) {
                result.isNegative = false;
            } else {
                result.isNegative = !isNegative;
            }
            return result;
        }

        BigInteger operator+(const BigInteger& other) const {
            if (isNegative == other.isNegative) {
                BigInteger result = addAbs(*this, other);
                result.isNegative = isNegative;
                return result;
            }
            if (lessAbs(*this, other)) {
                BigInteger result = subAbs(other, *this);
                result.isNegative = other.isNegative;
                return result;
            }
            BigInteger result = subAbs(*this, other);
            result.isNegative = isNegative;
            return result;
        }

        BigInteger operator-(const BigInteger& other) const {
            return *this + (-other);
        }

        BigInteger operator*(const BigInteger& other) const {
            BigInteger result;
            result.digits.resize(digits.size() + other.digits.size(), 0);

            for (size_t i = 0; i < digits.size(); ++i) {
                int carry = 0;
                for (size_t j = 0; j < other.digits.size() || carry; ++j) {
                    long long product = result.digits[i + j] + carry;
                    if (j < other.digits.size()) {
                        product += digits[i] * other.digits[j];
                    }
                    result.digits[i + j] = product % 10;
                    carry = product / 10;
                }
            }
            result.isNegative = isNegative != other.isNegative;
            result.trimZeros();
            return result;
        }

        bool operator==(const BigInteger& other) const {
            return isNegative == other.isNegative && digits == other.digits;
        }

        bool operator!=(const BigInteger& other) const {
            return !(*this == other);
        }

        bool operator<(const BigInteger& other) const {
            if (isNegative != other.isNegative) {
                return isNegative;
            }
            if (isNegative) {
                return lessAbs(other, *this);
            }
            return lessAbs(*this, other);
        }

        bool operator>(const BigInteger& other) const {
            return other < *this;
        }

        bool operator<=(const BigInteger& other) const {
            return !(other < *this);
        }

        bool operator>=(const BigInteger& other) const {
            return !(*this < other);
        }

        friend ostream& operator<<(ostream& os, const BigInteger& num);
        friend istream& operator>>(istream& is, BigInteger& num);
};

ostream& operator<<(ostream& os, const BigInteger& num) {
    if (num.isNegative) {
        os << '-';
    }
    for (auto it = num.digits.rbegin(); it != num.digits.rend(); ++it) {
        os << *it;
    }
    return os;
}

istream& operator>>(istream& is, BigInteger& num) {
    string s;
    is >> s;
    num = BigInteger(s);
    return is;
}

int main() {
    BigInteger a("12345678901234567890");
    BigInteger b("98765432109876543210");
    
    cout << "a = " << a << "\n";
    cout << "b = " << b << "\n";
    cout << "a + b = " << a + b << "\n";
    cout << "a - b = " << a - b << "\n";
    cout << "a * b = " << a * b << "\n";
    
    if (a < b) {
        cout << "a is less than b" << endl;
    }
    
    return 0;
}