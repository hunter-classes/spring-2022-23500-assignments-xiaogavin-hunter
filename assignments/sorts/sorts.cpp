#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>

void print_vector(std::vector<int> a) {
    for (auto i : a) {
        std::cout << i << ", ";
    }

    std::cout << "\n";
}

int find_min_index(std::vector<int> a, int start_index, int stop_index) {
    int min_index = start_index;
    int i;

    for (i = start_index; i < stop_index; i++) {
        if (a[i] < a[min_index]) {
            min_index = i;
        }
    }

    return min_index;
}

std::vector<int> ssort(std::vector<int> a) {
    int i, min_index, j, tmp;
    int len = a.size();

    // loop through the vector from 0 to end
    for (i = 0; i < len; i++) {
        // find the smallest value from i to the end
        min_index = find_min_index(a, i, len);

        // swap it into position i
        tmp = a[i];
        a[i] = a[min_index];
        a[min_index] = tmp;
    }
    
    return a;
}

/*
  left and right are already sorted

  merged should be a new vector with all the
  elements in left and right, and result
  should be sorted
*/
std::vector<int> merge(std::vector<int> left, std::vector<int> right) {
    std::vector<int> merged;

    // your code here

    int l_index = 0;
    int r_index = 0; 

    while(l_index < left.size() &&  r_index < right.size()) { 
        if(left[l_index] > right[r_index]) { 
            merged.push_back(right[r_index]);
            r_index++;
        } else { 
            merged.push_back(left[l_index]);
            l_index++;
        }  
    }

    while(l_index < left.size()) {
        merged.push_back(left[l_index]);
        l_index++;
    }

    while(r_index < right.size()) {
        merged.push_back(right[r_index]);
        r_index++;
    }

    // remember merged.push_back(n)
    // appends value n to the vector merged
    return merged;
}

std::vector<int> msort(std::vector<int> v) { 
    // If the list you’re sorting is less than size 2 then just return it.
    std::vector<int> left; 
    std::vector<int> right; 

    for(int i = 0; i < v.size() / 2; i++) { 
        left.push_back(v[i]);
    }

    for(int i = v.size() / 2; i < v.size(); i++) { 
        right.push_back(v[i]);
    }

    if(v.size() < 2) { 
        return v; 
    }

    return merge(msort(left), msort(right)); 
}

int main() {
    int size = 1000;
    int max_val = 100;

    srand(time(nullptr));
    std::vector<int> a(size);
    
    for(int i = 0; i < size; i++) {
        a[i] = rand() % max_val;
    }

    print_vector(a);
    std::cout << "\n";


    // a = ssort(a);
    // print_vector(a);
    // std::vector<int> left = { 1, 2, 5, 6, 10, 15 };
    // std::vector<int> right = { 3, 7, 8, 12, 16, 19, 20 };
    // print_vector(left);
    // print_vector(right);

    // print_vector(merge(left, right));

    print_vector(msort(a));

    return 0;
}
