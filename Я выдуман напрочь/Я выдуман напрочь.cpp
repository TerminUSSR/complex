#include <iostream>
using namespace std;
class Complex {
    int ir; // мнимый
    int no; // действительный
public:
    Complex(int ir, int no) : ir(ir), no(no) {}
    Complex(const Complex& it) : Complex(it.ir, it.no) {}
    int getIr() const {
        return ir;
    }
    void print() const{
        cout << ir << "i " << (no >= 0? "+ " : "- ") << abs(no);
    }
    Complex operator +=(const Complex& it) {
        ir += it.ir;
        no += it.no;
        return *this;
    }
    Complex operator +(const Complex& it) const {
        Complex c(*this);
        c += it;
        return c;
    }
    Complex operator -=(const Complex& it) {
        ir -= it.ir;
        no -= it.no;
        return *this;
    }
    Complex operator -(const Complex& it) const {
        Complex c(*this);
        c -= it;
        return c;
    }
    Complex operator *=(const Complex& it) {
        int c = ir;
        ir = (no * it.ir) + (ir * it.no);
        no = (no * it.no) - (c * it.ir);
        return *this;
    }
    Complex operator *(const Complex& it) const {
        Complex c(*this);
        c *= it;
        return c;
    }
    Complex operator /=(const Complex& it) {
        int c = ir;
        ir = (ir * it.no - no * it.ir) / (it.no * it.no + it.ir * it.ir);
        no = (no * it.no + c * it.ir) / (it.no * it.no + it.ir * it.ir);
        return *this;
    }
    Complex operator /(const Complex& it) const{
        Complex c(*this);
        c /= it;
        return c;
    }
    Complex& operator =(const Complex& it) {
        if (&it == this) {
            return;
        }
        ir = it.ir;
        no = it.no;
        return *this;
    }
};
int main(){
    Complex c(2, 1), b(4, 3);
    c /= b;
    c.print();
}