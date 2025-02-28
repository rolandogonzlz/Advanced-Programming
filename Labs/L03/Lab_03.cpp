#include <iostream>
#include <string>
#include <tuple>

//Part 4: Strcutred Binding
struct Point
{
    int x;
    int y;
    int z;
};



int main(){
    //Part 1: Varaible Initialization
    //Direct initalization
    std::cout<<"       Variable Initialization"<<std::endl;
    int num_a = 98;
    std::cout<<"Num a is: "<<num_a<<std::endl;

    //Uniform initialization

    double num_b{5.13};
    std::cout<<"Num b is: "<<num_b<<std::endl;

    //Structured Binding

    std::string c("Hello");
    std::cout<<"string: "<<c<<std::endl;
    bool d = true;
    std::cout<<"bool: "<<d<<"\n\n";


    // Part 3: References
    int& refA = num_a;
    double& refB = num_b;
    std::string& refC = c;
    bool& refD = d;

    refA = 42;
    refB = 10.2;
    refC = "Advanced programming";
    refD = false;

    std::cout<<"      Values modified by reference"<<std::endl;
    std::cout<<"int: "<<num_a<<std::endl;
    std::cout<<"double: "<<num_b<<std::endl;
    std::cout<<"string: "<<c<<std::endl;
    std::cout<<"bool: "<<d<<std::endl;

    //Part 4: Structred Binding

    Point p{4,6,8};
    auto [x, y, z] = p;

    std::cout<<"      Unpacked struct point values:"<<std::endl;
    std::cout<<"    x: "<<x<<", y: "<<y<<", z: "<<z<<"\n\n";


    //Part 5: Identifying l-values and r-values
    num_a = 42;                         //'num_a' -> l-value
    int x2 = num_a + num_b;             // num_a and num_b are l-values, (num_a + num_b) is a r-value
    &num_a;                             // l-value
    std::string s = c + "World";        // c is an l-value, "World" is an r-value, (c + "World") is an r-value
    int& refX = x2;                     // l-value reference
    int&& rref = 100;                   // r-value reference

    return 0;
}