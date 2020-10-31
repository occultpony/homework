#include <iostream>

using namespace std;

//Homework ¹2

//TASK 1
class Person
{
protected:
    string name;
    int age;
    const bool isMale;
    float weight;
public:
    Person(): name("[DATA LOST]"), age(20), isMale(true), weight(62.5) {};
    Person(string n_name, int n_age, bool n_isMale, float n_weight) : name(n_name), age(n_age), isMale(n_isMale), weight(n_weight){};

    string getName() const{ return name; }
    void setName(string newName) {name = newName;}

    int getAge() const { return age; }
    void setAge(int newAge) {name = newAge;}

    bool getGender() const { return isMale; }

    float getWeight() const { return weight; }
    void setWeight(float newWeight) {weight = newWeight; }
};

class Student : public Person
{
private:
protected:
    int yearOfStudy;
public:
    Student(): Person(), yearOfStudy(0){};
    Student(string n_name, int n_age, bool n_isMale, float n_weight, int n_yearOfStudy): Person(n_name, n_age, n_isMale, n_weight), yearOfStudy(n_yearOfStudy){};

    ~Student(){};

    void printStudent()
    {
        cout << "Name: " << name << " Gender: ";
        isMale ? cout << "Male" : cout << "Female";
        cout << " Weight: " << weight << " Year of study: " << yearOfStudy << endl;
    }

    int getYearOfStudy() const { return yearOfStudy; }
    void setYearOfStudy(int newYear) {yearOfStudy = newYear; }
    void increaseYearOfStudy() { yearOfStudy++; }
};

    //TASK 2

class Fruit
{
protected:
    string name;
    string color;
public:
    Fruit():name("fruit"), color("colorless"){};
    Fruit(string n_name, string n_color):name(n_name), color(n_color){};

    string getName(){ return name; }
    string getColor(){ return color; }

};

class Apple : public Fruit
{
public:
    Apple():Fruit("apple", "[DATA LOST]"){};
    Apple(string n_color):Fruit("apple", n_color){};
    Apple(string n_name, string n_color):Fruit(n_name, n_color){};
};

class Banana : public Fruit
{
public:
    Banana():Fruit("banana", "yellow"){};
};

class GrannySmith : public Apple
{
public:
    GrannySmith():Apple("Granny Smith apple","green"){};
};

int main()
{
    //TASK 1
    Student s1("Ivan", 21, true, 70, 3);
    Student s2("Maria", 18, false, 58, 1);
    Student s3("Daniil", 23, true, 65, 5);
    s1.printStudent();
    s2.printStudent();
    s3.printStudent();

    //TASK 2
    Apple a("red");
    Banana b;
    GrannySmith c;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}
