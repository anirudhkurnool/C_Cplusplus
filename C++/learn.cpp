#include  <math.h>
#include  <vector>
#include <cassert>
#include<iostream>

void greet(std::string name) {
    std::cout << "Hello, " << name << "\n";
}

int add(int a, int b) {
    return a + b;
}

int mul(int a, int b) {
    return a * b;
}

int sub(int a, int b) {
    return a - b;
}

int n_div(int a, int b) {
    assert(b != 0);
    return a / b;
}

bool is_even(int num) {
    if (num % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

std::vector<int> sieve_of_eratosthenes(int num) {
    bool arr[num];
    for (int i = 0; i < num; i++){
        arr[i] = true;
    }

    arr[0] = false;
    std::vector<int> res = *(new std::vector<int>());
    for (int i = 1; i < num; i++){
        if (arr[i] == true) {
            for(int j = (2 * i + 1) ; j < num ; j += (i + 1)){
                arr[j] = false;
            }

            res.push_back(i + 1);
        }
    }

    return res;
}

std::string is_even_str(int num) {
    if (num % 2 == 0) {
        return "even";
    } else {
        return "odd";
    }
}

bool is_prime(int num) {
    int end = (int)std::ceil(std::sqrt(num));
    for(int i = 2; i <= end; i++){
        if (num % i == 0) { return false; }
    }

    return true;
}

float circumference_of_circle(double radius) {
    return (float)(2 * 3.14 * radius);
}

double area_of_circle(double radius) {
    return (3.141 * radius * radius);
}


class Rectangle {
    protected:
        float length, breadth;
    public:
        Rectangle(float l, float b) : length(l), breadth(b) {}
        //copy constructor (copy constructors can access private variable of the object they are copying provided it is of the same class)
        //In C++ access control happens at class level and not one object level ???
        Rectangle(const Rectangle& other) : length(other.length), breadth(other.breadth) {}


        //get and set length
        float get_length() { return this->length; }
        void set_length(float new_length) { this->length = new_length; }

        //get and set breadth
        float get_breadth() { return this->breadth; }
        void set_breadth(float new_breadth) { this->breadth = new_breadth; }

        float area() { return this->length * this->breadth; }
        //int gets automatically casted float ???
        float perimeter() { return 2 * (this->length + this->breadth); }

        void display() {
            std::cout << "===== Rectangle =====\n";
            std::cout << "length    : " << this->length << "\n";
            std::cout << "breadth   : " << this->breadth << "\n";
            std::cout << "area      : " << this->area() << "\n";
            std::cout << "perimeter : " << this->perimeter() << "\n";
        }
};

class Square : Rectangle {
    public:
        Square(float side_length) : Rectangle(side_length, side_length) {}
        void display() {
            std::cout << "===== Square =====\n";
            std::cout << "side-length    : " << this->length << "\n";
            std::cout << "area           : " << this->area() << "\n";
            std::cout << "perimeter      : " << this->perimeter() << "\n";
        }
};

int main() {
    std::cout << "Hello, World!!!" << std::endl;
    std::cout << "List of number from 1 to 10 : [ ";
    for(int i = 1;  i <= 10; i++) {
        std::cout << i << " , ";
    }

    std::cout << " ] \n";

    std::cout << "List of number from 10 to 20 : [ ";
    int num = 10;
    while (num < 21) {
        std::cout << num << " , ";
        num++;
    }
    std::cout << " ] \n";

    greet("Anirudh");

    std::cout << "Sum of " << 1 << " and "  << 2 << " is " << add(1, 2) << "\n";
    std::cout << "Product of "<< 3 << " and " << 4 << " is " << mul(3, 4) << "\n";
    std::cout << "Difference" << 4 << " and " << 5 << " is " << sub(4, 5) << "\n";
    std::cout << "Quotient of the op " << 5 << "/" << 2 << " is " << n_div(5, 2) << "\n";

    std::cout << "3 is " << is_even_str(3) << "\n";
    std::cout << "4 is " << is_even_str(4) << "\n";

    std::cout << "is 3 even : " << is_even(3) << "\n"; //bool and enum ???
    std::cout << "is 4 even : " << is_even(4) << "\n";

    std::cout << "is 3 a prime : " << is_prime(3) << "\n";
    std::cout << "is 4 a prime : " << is_prime(4) << "\n";

    std::vector<int> primes_below_100 = sieve_of_eratosthenes(100);
    std::cout << " [ ";
    for(int i : primes_below_100) {
        std::cout << i << " , ";
    }
    std::cout << " ]\n";

    std::cout << "Area of circle of radius 4.0 is : " << area_of_circle(4.0) << "\n";
    std::cout << "Circumference of circle of radius of 4.0 : " << circumference_of_circle(4.0) << "\n";

    Rectangle r1 = Rectangle(3.0, 4.0);
    Square s1 = Square(5.0);
    r1.display();
    s1.display();


    Rectangle r2 = r1;
    r2.display();
    r2.set_length(5.0);
    r2.display();
    r1.display();
}
