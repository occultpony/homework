#include <iostream>
<<<<<<< HEAD
#include <math.h>
#include <string.h>
#include <cassert>

using namespace std;

#define PI 3.14159265

//Homework в„–3

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
=======
#include <cstdint>

using namespace std;

class Power
{
private:
    int number = 1;
    int power = 1;
public:
    void set(int num, int pow)
    {
        number = num;
        power = pow;
    }

    void calculate()
    {
        int result = number;
        if(power == 0) result = 1;
        else
        {
            for(int i=1; i<power; i++)
            {
            result = result * number;
            }
        }
        //я хотела использовать здесь тернарный условный оператор как в Си, но компилятор ругается
        if(power<0) cout << "x power y equal " << "1/" << result << endl;
        else cout << "x power y equal " << result << endl;
    }
};

class RGBA
{
private:
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0;
    std::uint8_t m_alpha = 255;
public:
    RGBA(){}
    RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha)
    : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {}

    void print()
    {
        cout << "R:" << m_red + 0<< " G:" << m_green + 0<< " B:" << m_blue + 0 << " A:" << m_alpha + 0 << endl;
    }
};

class Stack
{
private:
    int M[9];
    unsigned int lenght;
public:
    void reset()
    {
        for(int i = 0; i<10; i++) M[i]=0;
        lenght = 0;
    }
    bool push(int n)
    {
        if(lenght==10) return false;
        else M[lenght] = n;
        lenght++;
        return true;
    }
    int pop()
    {
        if(lenght==0) cout << "Stack is empty" << endl;
        else return M[lenght];
    }
    void print()
    {
        cout << "( ";
        for(int i=0; i<lenght; i++) cout << M[i] << " ";
        cout << ")" << endl;
    }
};

int main()
{
    //TASK 1
    Power Power;
    int x, y;
    cout << "  1.\nEnter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;
    Power.set(x,y);
    Power.calculate();

    //TASK 2
    char answer;
    cout << "  2.\nWould you like to initialize RGBA with custom parameters?(y/n)" << endl;
    cin >> answer;
    if(answer == 'y')
    {
        unsigned int r, g, b, a;
        cout << "Enter R: ";
        cin >> r;
        cout << "Enter G: ";
        cin >> g;
        cout << "Enter B: ";
        cin >> b;
        cout << "Enter A: ";
        cin >> a;
        RGBA color((std::uint8_t)r, (std::uint8_t)g, (std::uint8_t)b, (std::uint8_t)a);
        color.print();
    }
    else if(answer == 'n')
    {
        RGBA color;
        color.print();
    }

    //TASK 3
    cout << "  3." << endl;

    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();


>>>>>>> e8755d608dd18afb38c755789c77b61a7a1c61ad
    return 0;
}
