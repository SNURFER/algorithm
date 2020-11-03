#include <iostream>                                                              
#include <algorithm>                                                             
#include <map>                                                                   
#include <string>                                                                
#include <math.h>                                                                
#include <string.h>                                                              
#include <stdlib.h>                                                              
#include <vector>    

int main(){
    int a, b, b1, b2, b3;
    std::cin >> a;
    std::cin >> b;
    b1 = b % 10;
    b2 = ((b - b1) / 10) % 10;
    b3 = b / 100;
    std::cout << a * b1 << std::endl;
    std::cout << a * b2 << std::endl;
    std::cout << a * b3 << std::endl;
    std::cout << a * b;
	return 0;
}