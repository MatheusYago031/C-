#include <iostream>
#include <thread>

class TestClass{
    int i;

    public:
        TestClass(int n) { i = n; }
            void greeting(std:: string const& msg) const{
                std:: cout << msg << std:: endl;
                std:: cout << "My number: " << i << std:: endl; 
                std:: this_thread:: sleep_for(std::chrono::milliseconds(100));
                std:: cout <<"...." << std:: endl;
        }
};

int main(){
    TestClass obj(10);

    //for (int i = 0; i < 10; i++)
    std:: thread t(&TestClass:: greeting, &obj, "Hello!!");

    t.join();

    return 0; 
}