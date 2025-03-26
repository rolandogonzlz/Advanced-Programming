#include <iostream>
#include <concepts>

template <typename T>
T maxValue(T x,T y){
    return (x > y) ? x : y;
}

//   Overload a Template Function
template <typename T>
T maxValue(T x, T y, T z){
    return maxValue(maxValue(x, y), z);
}

// Concepts
template <typename T>
concept Num = std::integral<T> || std::floating_point<T>;

template <Num T>
T add(T x, T y){
    return x+y;
}

// Variadic Templates
template <typename T>
void printAll (T t){
    std::cout<< t <<std::endl;
}

template <typename T, typename... Args>
void printAll(T t, Args... args){
    std::cout<< t << " ";
    printAll(args...);
}

// Variadic Temaplate for Summation

template <typename T>
T sum(T t){
    return t;
}

template <typename T, typename... Args>
T sum(T t,Args... args){
    return t + sum(args...);
}

// Template Metaprogramming
template <int N>
struct Factorial {
    static constexpr int value = N * Factorial <N - 1>::value;
};
template <>
struct Factorial<0>{
    static constexpr int value = 1;
};

template <int N>
struct Fibonacci{
    static constexpr double value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template <>
struct Fibonacci<0>
{
    static constexpr double value = 0.0;
};

template <>
struct Fibonacci<1>
{
    static constexpr double value = 1.0;
};

int main()
{

    std::cout<<"El numero mas grande es: "<<maxValue(7,8)<<std::endl;
    std::cout<<"El numero mas grande es: "<<maxValue(6.9,3.2)<<std::endl;
    std::cout<<"Cadena mas grande es: "<<maxValue(std::string("Hellowww"), std::string("Rolando"))<<std::endl;
    
    //Overload a Template Function
    std::cout<<"\n      Overload a Template Function"<<std::endl;
    std::cout<<"El numero mas grande es: "<<maxValue(7,8,5)<<std::endl;
    std::cout<<"El numero mas grande es: "<<maxValue(6.9,3.2,15.5)<<std::endl;
    std::cout<<"Cadena mas grande es: "<<maxValue(std::string("Hellowww"), std::string("Rolando"), std::string("Dog"))<<std::endl;

    //Concept 1
    std::cout<<"\n      Concept "<<std::endl;
    std::cout<<"Add: "<<add(8,7)<<std::endl;
    std::cout<<"Add: "<<add(4.4,3.3)<<std::endl;

    // Variadic Template
    std::cout<<"\n      Variadic Template"<<std::endl;
    printAll(2, 3.5, "Helloww", 'f');


    //Varadic Template for Summatio
    std::cout<<"\n      Variadic Temaplete for Summation"<<std::endl;
    std::cout<<"Total sum: "<<sum(3,4,5,1,5)<<std::endl;
    std::cout<<"Total sum: "<<sum(8,1,1,-9,5)<<std::endl;

    //Template Metaporgramming 
    std::cout<<"\n      Temaplete Metaprogramming Factorial "<<std::endl;
    constexpr int result = Factorial<5>::value;
    std::cout<<"The result is: "<<result<<std::endl;

    // Temaplate Metroprograming
    std::cout<<"\n      Temaplete Metaprogramming Fibonacci "<<std::endl;
    constexpr double result_2 = Fibonacci<100>::value;
    std::cout<<"The result is: "<<result_2<<std::endl;
    return 0;
}