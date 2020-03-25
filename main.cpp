#include <bits/stdc++.h>
#include "Fractie.h"

using namespace std;

int cmmdc(int a, int b){
    int r;
    while (b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

    Fractie::Fractie( int x=1, int y=1 ): f1(x),f2(y){};
    Fractie::Fractie(Fractie &other):f1(other.f1), f2(other.f2){};

    istream& operator>> (istream&in, Fractie& f){
        in >> f.f1 >> f.f2;
        return in;
    }

    ostream& operator<< (ostream& out, Fractie& f){
        if (f.f1 % f.f2 == 0){
            out << f.f1 / f.f2;
            out << '\n';
            return out;
        }
        else
        if (f.f1 < 0 && f.f2 < 0){
            out << -f.f1 << '/' << -f.f2;
            out << '\n';
            return out;
        }
        else
        if (f.f2 < 0){
            out << -f.f1 << '/' << -f.f2;
            out << '\n';
            return out;
        }
        else
            {
        out << f.f1 << '/' << f.f2;
        out << '\n';
        return out;}
            }
    Fractie Fractie::operator +(Fractie fr1) {
        Fractie fr2(*this), fr3;
        fr3.f1 = fr1.f1 * fr2.f2 + fr2.f1 * fr1.f2;
        fr3.f2 = fr1.f2 * fr2.f2;
        return fr3;
    }

    Fractie Fractie::operator -(Fractie fr1) {
        Fractie fr2(*this), fr3;
        fr3.f1 = fr2.f1 * fr1.f2 - fr1.f1 * fr2.f2;
        fr3.f2 = fr1.f2 * fr2.f2;
        return fr3;
    }

    Fractie Fractie::operator *(Fractie fr1) {
        Fractie fr2(*this), fr3;
        fr3.f1 = fr1.f1 * fr2.f1;
        fr3.f2 = fr1.f2 * fr2.f2;
        return fr3;
    }

    Fractie Fractie::operator/(Fractie fr1) {
        Fractie fr2(*this), fr3;
        fr3.f1 = fr1.f1 * fr2.f2;
        fr3.f2 = fr1.f2 * fr2.f1;
        return fr3;

    }


    void Fractie::simplifica (Fractie& f){
        int aux = cmmdc(f.f1 , f.f2);
        f.f1 /= aux;
        f.f2 /= aux;
    }

    Fractie Fractie::operator * (int intreg) {
        Fractie f (*this);
        f.f1 = f.f1 * intreg;
        return f;
    }

    Fractie::~Fractie(){};

   inline int Fractie::getNum(){
        return this->f1;
    }

    inline int Fractie::getDenom(){
        return this->f2;
    }

    inline void Fractie::setNum(int numarator){
        this -> f1 = numarator;
    }

    inline void Fractie::setDenom(int numitor){
        this -> f2 = numitor;
    }



int main()
{Fractie f1, f2, f3, f4, f5, f6;
Fractie x, y;
Fractie aux, aux1, aux2, aux3;

/* sistemul are forma:
f1*x + f2*y = f3
f4*x +f5*y = f6 */

cin >> f1 >> f2 >> f3 >> f4 >> f5 >> f6;

f1.simplifica(f1);
f2.simplifica(f2);
f3.simplifica(f3);
f4.simplifica(f4);
f5.simplifica(f5);
f6.simplifica(f6);

x = f2 * f6;
aux = f3 * f5;
x = x - aux;
aux1 = f2 * f4;
aux2 = f1 * f5;
aux3 = aux1 - aux2;
x = x / aux3;
x.simplifica(x);

y = f1 * f6;
aux = f3 * f4;
y = y - aux;
aux1 = f1 * f5;
aux2 = f2 * f4;
aux3 = aux1 - aux2;
y = y / aux3;
y.simplifica(y);

cout << "x = " << x;
cout << "y = " << y;

}
