#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

/*
n = 5: 13 solutions
1, 2, 3 can be used 

1 1 1 1 1

1 1 1 2
1 1 2 1 
1 2 1 1
2 1 1 1

1 2 2
2 2 1
2 1 2

1 1 3
1 3 1
3 1 1

2 3
3 2
*/

// n = 1, 1 solu 0
// n = 2, 2 solu 1 
// n = 3, 4 solu 2 
// n = 4, 7 solu 3 
// n = 5, 13 solu 4
// n = 6, 
// n = 7, 44 solu

int stepPerms(int n) { // n is the # of steps 
    if(n == 1) { 
        return 1; 
    } else if(n < 0) { 
        return 0; 
    } else { 
        return 
        // Unsure how to start, we need to test all three at once, since we cannot check that one number, 1, 2, 3 has already been tested. 
        // 
    }
} 

int main() {
    std::cout << stepPerms(5) << std::endl;

    return 0;
}