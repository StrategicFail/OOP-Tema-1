#ifndef FRACTIE_H_INCLUDED
#define FRACTIE_H_INCLUDED

class Fractie{
private:
    int f1, f2;
public:
    explicit Fractie(int, int);
    Fractie(Fractie&);
    friend std::ostream& operator<<(std::ostream&, Fractie&);
    friend std::istream& operator>>(std::istream&, Fractie&);
    Fractie operator +(Fractie);
    Fractie operator -(Fractie);
    Fractie operator *(Fractie);
    Fractie operator /(Fractie);
    void simplifica(Fractie&);
    Fractie operator *(int intreg);
    ~Fractie();
    inline int getNum();
    inline int getDenom();
    inline void setNum(int);
    inline void setDenom(int);
};

std::ostream& operator<<(std::ostream&, Fractie&);
std::istream& operator>>(std::istream&, Fractie&);

#endif // FRACTIE_H_INCLUDED
