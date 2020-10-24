#include <iostream>
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


    return 0;
}
