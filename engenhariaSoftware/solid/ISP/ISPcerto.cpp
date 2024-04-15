#include <iostream>

using namespace std;

class Animal{
    private:
        string m_name;
    public:
        Animal(string name) : m_name(name){}

        void setName(const string name){
            m_name = name;
        }
        
        const string getName() const {
            return m_name;
        }
        
        virtual void makeSound() const = 0;
};

class Dog : public Animal{
    public:
        Dog(string name) : Animal(name){}
        void makeSound() const override{
            cout << this->getName() << " diz au au" << endl;
        }
};

class Cat : public Animal{
    public: 
        Cat(string name) : Animal(name){}
        
        void makeSound() const override{
            cout << this->getName() << " diz miau" << endl;
        }

    
};

int main(){

    Animal* cat = new Cat("apollo");
    Animal* dog = new Dog("pitty");

    cat->makeSound();
    dog->makeSound();

    delete cat;
    delete dog;

    return 0;
}