#include <iostream>                                                              
#include <algorithm>                                                             
#include <map>                                                                   
#include <string>                                                                
#include <math.h>                                                                
#include <string.h>                                                              
#include <stdlib.h>                                                              
#include <vector>    

int main(){
    int h, m;
    std::cin >> h;
    std::cin >> m;
    if(h > 24 || h < 0 || m > 60 || m < 0)
        return 1;
    if(m >= 45)
        std::cout << h << " " << m - 45 << std::endl;       
    else if(m < 45 && h == 0)
        std::cout << "23" << " " <<  m + 15 << std::endl;
    else
        std::cout <<  h - 1 << " " << m + 15 << std::endl;
	return 0;
}