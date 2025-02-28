#include <iostream>
#include <cmath>
#include <utility>
//using namespace std;
std::pair<bool, std::pair<double, double>> solveQuadratic(double a, double b, double c)
{
    double dis = b *b - 4 * a * c;
    if (dis < 0)
    {
        return {false,{0,0}};
    }
    dis = sqrt(dis);
    return{true, {(-b -dis)/(2*a),(-b+dis)/(2*a)}};
    
}

int main() {
    double a = 1, b = -3, c =2; // Ecuación x² - 3x + 2 = 0
    auto result = solveQuadratic(a, b, c);

    if (result.first) {
        std::cout << "Las raices son: " << result.second.first << " y " << result.second.second << std::endl;
    } else {
        std::cout << "It has no real solutions." << std::endl;
    }

    return 0;
}