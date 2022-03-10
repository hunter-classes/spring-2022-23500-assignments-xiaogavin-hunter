#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>
#include <climits>

// this will return the number of times value appears in the unsorted vector v.
int count(std::vector<int> v, int value) { 
    int count = 0;
    for(auto a : v) { 
        if(value == a) { 
            count++;
        }
    }

    return count; 
}

// this will return the largest value in vector v.
int largest(std::vector<int> v) { 
    int largest = INT_MIN;
    for(auto a : v) { 
        if(a > largest) { 
            largest = a; 
        }
    } 

    return largest; 
}

// which returns the mode of std::vector v, that is, the item that appears the most frequently. 
// If there are more than one mode then just return any of them. That is, if the vector contains 1, 5, 4, 6, 4, 8, 6, 4, 12, 6, 22 
// then you could return 4 or 6 because both appear most frequently - 3 times.
int mode(std::vector<int> v) { 
    std::vector<int> num_count; 
    for(int i = 0; i < largest(v) + 1; i++) { 
        num_count.push_back(count(v, i));
    }

    std::cout << std::endl;


    int large = largest(num_count);
    for(int i = 0; i < num_count.size(); i++) { 
        if(large == num_count[i]) { 
            return i;
        }
    }

    return 0;
}

void print_vector(std::vector<int> v) { 
    for(auto a : v) { 
        std::cout << a << "\n";
    }

    std::cout << std::endl;
}

int mode2(std::vector<int> v) {
    std::vector<int> nums(largest(v) + 1);
    int large = 0;

    for(int i = 0; i < v.size(); i++) { 
        nums[v[i]]++;

        if(nums[v[i]] > large) { 
            large = v[i];
        }
    }
    return large;
}


int main(int argc, char *argv[]) {
    srand(time(NULL));
    int size = 10;
    int max_value = 2;
    std::vector<int> nums(size);

    for(int i = 0; i < size; i++) { 
        nums[i] = rand() % max_value;
    }



    // mode(nums);
    print_vector(nums);

    double solu = mode2(nums) + .1;
    std::cout << solu << std::endl;

    return 0;
}