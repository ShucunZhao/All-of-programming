#include <iostream>
#include <cstdlib>

class Animal {
protected:
  const std::string name;
public:
  Animal(std::string n): name(n) {}//Fluffy,Leon
  virtual void speak()const  = 0;
  virtual ~Animal() {
    std::cout << "~Animal(" << name << ")" << std::endl;
  }
};
class Cat : public Animal {
public:
  Cat(std::string n): Animal(n) {//
    speak();
  }
  virtual void speak() const {
    std::cout << name << " purrs." << std::endl;
  }
  virtual ~Cat() {
    std::cout << "~Cat(" << name << ")" << std::endl;
    speak();
  }

};
class Lion: public Cat {
public:
  Lion(std::string n): Cat(n) {
    speak();
  }
  virtual void speak() const {
    std::cout << name << " roars." << std::endl;
  }

  virtual ~Lion() {
    std::cout << "~Lion(" << name << ")" << std::endl;
    speak();
  }
};

/*Output:
 *Fluffy purrs.
 *Leon purrs.
 *Leon roars.
 *Aslan purrs.
 *Aslan roars.
 *Fluffy purrs.
 *Leon roars.
 *Aslan roars.
 *Don't forget your destructor!
 *~Lion(Aslan)
 *Aslan roars.
 *~Cat(Aslan)
 *Aslan purrs.
 *~Animal(Aslan)
 *~Lion(Leon)
 *Aslan roars.
 *~Cat(Leon)
 *Leon purrs.
 *~Animal(Leon)
 *~Cat(Fluffy)
 *Fluffy purrs.
 *~Animal(Fluffy)
 */

int main(void) {
  Cat cat1("Fluffy");
  Lion lion1("Leon");
  Lion lion2("Aslan");
  Animal * animals[3];
  animals[0] = &cat1;
  animals[1] = &lion1;
  animals[2] = &lion2;
  for (int i= 0; i < 3; i++) {
    animals[i]->speak();
  }  
  std::cout << "Don't forget your destructors!" << std::endl;
  return EXIT_SUCCESS;
}
