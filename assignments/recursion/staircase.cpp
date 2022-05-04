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

int solu[1000]; 

int stepPerms(int n) { // n is the # of steps 
    // if(n == 1) { 
    //     return 1; 
    // } else if(n == 2) { 
    //     return 1 + stepPerms(n - 1);
    // } else if (n == 3) { 
    //     return 1 + stepPerms(n - 2) + stepPerms(n - 1); 
    // }

    if(n == 0) { 
        return 1;
    }
    
    if(solu[n] != 0) { 
        return solu[n];
    } else { 
        int w = 0;
        for (int i = 3; i >= 1; i--){
            int x = n - i;
            if (x >= 0)
                w = w + stepPerms(x);
        }
        solu[n] = w;
        return w;
    }
} 

int main() {
    for(int i = 0; i <= 100; i++) { 
        std::cout << i << ": " << stepPerms(i) << std::endl;
    }

    return 0;
}   