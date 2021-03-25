#include <iostream>
#include "Metrics/Metrics_test.h"
#include "GraphComponents/point.h"
using namespace std;
int main() {
    std::cout << "Simulator by Yuanhao Zhu\nAn undergraduate project directed by Prof. Lin Feng" << std::endl;
    std::cout << Metrics_test::test() << std::endl;
    std::cout << "asd" << std::endl;
    point* p = new point(1,0);
    cout<< "Point coordinates are:" << p -> getX() <<" and "<< p -> getY() << endl;
    return 0;
}
