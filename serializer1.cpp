#include <iostream>
#include "structures.hpp"

class Serializer1 : public Serializer {
public:
  void visit(const B* b) override {
    std::cout << "B: " << b->val << std::endl;
  }
};

int main() {
  B b;
  C c;
  D d;

  Serializer1 serializer1;

  std::cout << "Serializer1 knows how to print b" << std::endl;
  static_cast<A*>(&b)->accept(serializer1);

  std::cout << "Serializer1 does not know how to print c" << std::endl;
  static_cast<A*>(&c)->accept(serializer1);

  std::cout << "Serializer1 does not know how to print d" << std::endl;
  static_cast<A*>(&d)->accept(serializer1);
}
