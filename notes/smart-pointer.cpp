#include <iostream>
#include <string> 
#include <memory>

class pt { 
    private: 
        int x, y;
    public: 
        pt() {
            this->x = 0;
            this->y = 0; 
        }

        pt(int x, int y) { 
            this->x = x;
            this->y = y; 
        }

        ~pt() { 
            std::cout << "destructor for " << this->toString() << std::endl; 
        }

        std::string toString() {
            return "<" + std::to_string(this->x) + ", " + std::to_string(this->y) + ">\n";
        }
};

int main() {
    pt mypoint(10, 20);
    pt *px = new pt(1, 2);

    std::cout << px->toString();
    std::cout << mypoint.toString();

    delete px;

    std::shared_ptr<pt> p(new pt(400, 600));


    return 0;
}