#include <iostream>
#include <math.h>
#include <string.h>
#include <cassert>

using namespace std;

#define PI 3.14159265

//Homework №3

//TASK 1
class Figure
{
public:
    virtual float area();
};

class Parallelogram : public Figure
{
protected:
    int lenght;
    int width;
    int angle1;
    int angle2;
public:
    Parallelogram(): lenght(1), width(1), angle1(90), angle2(90){};
    Parallelogram(int l, int w, int a): lenght(l), width(w), angle1(a), angle2(180-a){};

    float area() override{ return lenght*width*sin(angle1*PI/180); }
};

class Circle : public Figure
{
protected:
    int radius;
public:
    Circle(): radius(1){};
    Circle(int r): radius(r){};

    float area() override{ return PI * radius * radius; }
};

class Rectancgle : public Parallelogram
{
public:
    Rectancgle(int l, int w): Parallelogram(l, w, 90){};

    float area() override{ return lenght*width; }
};

class Square : public Parallelogram
{
public:
    Square(int s) : Parallelogram(s, s, 90){};

    float area() override { return lenght*lenght; }
};

class Rhombus : public Parallelogram
{
public:
    Rhombus(int s, int a): Parallelogram(s, s, a){};

    float area() override{ return lenght*width*sin(angle1*PI/180); }
};

//TASK 2

class Car
{
protected:
    string company;
    string model;
public:
    Car(): company("Volkswagen"), model("Passat"){cout << "Company: " << company << " Model: " << model << endl;};
    Car(string c, string m) : company(c), model(m){cout << "Company: " << company << " Model: " << model << endl;};
};

class PassengerCar : public Car
{
public:
    PassengerCar(): Car("Skoda", "Octavia"){};
};

class Bus : public Car
{
public:
    Bus(): Car("LiAZ", "4292"){};
};

class Minivan : public PassengerCar, public Bus
{
public:
    Minivan(){};
};

//TASK 3

int getGCF(int x, int y) //this needed for reduction of fractions
    {
        int r; //remainder
        x=abs(x), y=abs(y);
        if(x<y){int tmp=x; x=y; y=tmp;}
        r=x%y;
        while(r!=0)
        {
            x=y;
            y=r;
            r=x%y;
        }
        return y;
    }


class Fraction
{
protected:
    int numerator;
    int denominator;
public:
    Fraction():numerator(1), denominator(1){};
    Fraction(int n, int d): numerator(n), denominator(d){ assert(d!=0 && "Denominator can't be equal 0");};

    void print() const{cout << numerator << "/" << denominator;}
    Fraction reduce()
    {
        Fraction f;
        f.numerator = numerator/getGCF(numerator, denominator);
        f.denominator = denominator/getGCF(numerator, denominator);
        return f;
    }

    friend Fraction operator+(const Fraction &f1, const Fraction &f2);
    friend Fraction operator-(const Fraction &f1, const Fraction &f2);
    friend Fraction operator*(const Fraction &f1, const Fraction &f2);
    friend Fraction operator/(const Fraction &f1, const Fraction &f2);

    Fraction operator-() const;

    friend bool operator==(const Fraction &f1, const Fraction &f2);
    friend bool operator!=(const Fraction &f1, const Fraction &f2);

    friend bool operator>(const Fraction &f1, const Fraction &f2);
    friend bool operator<(const Fraction &f1, const Fraction &f2);
    friend bool operator>=(const Fraction &f1, const Fraction &f2);
    friend bool operator<=(const Fraction &f1, const Fraction &f2);

    friend ostream& operator<<(ostream& os, const Fraction &f);
    friend istream& operator>>(istream& is, Fraction &f);
};


Fraction operator+(const Fraction &f1, const Fraction &f2)
{
    Fraction result;
    result.denominator = f1.denominator * f2.denominator;
    result.numerator = f1.numerator*f2.denominator + f2.numerator*f1.denominator;
    return result;
}

Fraction operator-(const Fraction &f1, const Fraction &f2)
{
    Fraction result;
    result.denominator = f1.denominator * f2.denominator;
    result.numerator = f1.numerator*f2.denominator - f2.numerator*f1.denominator;
    return result;
}

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
    Fraction result;
    result.denominator = f1.denominator * f2.denominator;
    result.numerator = f1.numerator * f2.numerator;
    return result;
}

Fraction operator/(const Fraction &f1, const Fraction &f2)
{
    Fraction result;
    result.denominator = f1.denominator * f2.numerator;
    result.numerator = f1.numerator * f2.denominator;
    return result;
}

Fraction Fraction::operator-() const
{
    return Fraction(-numerator, -denominator);
}

bool operator==(const Fraction &f1, const Fraction &f2)
{
    return(f1.numerator == f2.numerator && f1.denominator == f2.denominator);
}

bool operator!=(const Fraction &f1, const Fraction &f2)
{
    return !(f1 == f2);
}

bool operator>(const Fraction &f1, const Fraction &f2) //here i am already too lazy
{
    float fl1 = (float)f1.numerator/(float)f1.denominator;
    float fl2 = (float)f2.numerator/(float)f2.denominator;
    return(fl1>fl2);
}

bool operator<(const Fraction &f1, const Fraction &f2)
{
    return!(f1>f2);
}

bool operator>=(const Fraction &f1, const Fraction &f2)
{
    float fl1 = (float)f1.numerator/(float)f1.denominator;
    float fl2 = (float)f2.numerator/(float)f2.denominator;
    return(fl1>=fl2);
}

bool operator<=(const Fraction &f1, const Fraction &f2)
{
    return!(f1>=f2);
}

ostream& operator<<(ostream& os, const Fraction &f) //here i got carried away
{
    os << f.numerator << "/" << f.denominator;
    return os;
}

istream& operator>> (istream& is, Fraction &f)
{
    char input[64];
    is.getline(input, 64);
    char* slash = NULL;
    slash = strchr(input, '/');
    assert(slash!=NULL && "Invalid input");

    char* strToInt;
    memcpy(strToInt, input, slash-input);
    f.numerator = atoi(strToInt);

    memcpy(strToInt, slash+1, input + strlen(input) - slash);
    f.denominator = atoi(strToInt);
    assert(f.denominator!=0 && "Denominator can't be equal 0");

    return is;
}

int main()
{
    //TASK 2
    cout << "=====1=====" << endl;
    Car car;
    PassengerCar passengercar;
    Bus Bus;
    Minivan minivan;

    //TASK 3
    cout << "=====2=====" << endl;
    cout << "Enter fraction using slash:" << endl;
    cout << "(examples: 1/2, -3/5, 15/8 etc)" << endl;
    Fraction f1;
    cin >> f1;
    cout << "Enter another fraction:" << endl;
    Fraction f2;
    cin >> f2;
    cout << "What you want to do with this fractions?" << endl; //lazy again
    cout << "Enter one of this operators: +, -, *, /, ==, !=, >, <, >=, <=, -u(unary -):" << endl;
    string input;
    cin >> input;
    if(input=="+") cout << f1 << " + " << f2 << " = " << (f1+f2).reduce() << endl;
    else if (input=="-") cout << f1 << " - " << f2 << " = " << (f1-f2).reduce() << endl;
    else if (input=="*") cout << f1 << " * " << f2 << " = " << (f1*f2).reduce() << endl;
    else if (input=="/") cout << f1 << " : " << f2 << " = " << (f1/f2).reduce() << endl;
    else if (input=="==") cout << f1 << " == " << f2 << " " << (f1==f2 ? "true" : "false") << endl;
    else if (input=="!=") cout << f1 << " != " << f2 << " " << (f1!=f2 ? "true" : "false") << endl;
    else if (input==">") cout << f1 << " > " << f2 << " " << (f1>f2 ? "true" : "false") << endl;
    else if (input=="<") cout << f1 << " < " << f2 << " " << (f1<f2 ? "true" : "false") << endl;
    else if (input==">=") cout << f1 << " >= " << f2 << " " << (f1>=f2 ? "true" : "false") << endl;
    else if (input=="<=") cout << f1 << " <= " << f2 << " " << (f1<=f2 ? "true" : "false") << endl;
    else if (input=="-u") cout << "first fraction: " << -f1 << " second fraction: " << -f2 << endl;


    /*Fraction f1(1,2);
    Fraction f2(3,4);

    Fraction f3 = f1 + f2;
    f3.reduce();
    f3.print(); cout << endl;

    f3 = f1 - f2;
    f3.reduce();
    f3.print(); cout << endl;

    f3 = f1 * f2;
    f3.reduce();
    f3.print(); cout << endl;

    f3 = f1 / f2;
    f3.reduce();
    f3.print(); cout << endl;

    f3 =- f3;
    f3.print(); cout << endl;
    bool b = f1==f2;
    cout << b << endl;

    b = f1<f2;
    cout << b << endl;
*/
    return 0;
}
