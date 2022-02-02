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

// n = 1, 1 solu 
// n = 2, 2 solu 
// n = 3, 4 solu 
// n = 4, 7 solu 
// n = 5, 13 solu 
// n = 6, 
// n = 7, 44 solu

int stepPerms(int n) { // n is the # of steps 
    if(n == 1) { 
        return 1; 
    } else if(n < 0) { 
        return 0; 
    } else { 
        return stepPerms(n - 1) + stepPerms(n - 2) + stepPerms(n - 3);
        // Unsure how to start, we need to test all three at once, since we cannot check that one number, 1, 2, 3 has already been tested. 
        // 
    }
} 

int main() {
    std::cout << stepPerms(3) << std::endl;

    return 0;
}