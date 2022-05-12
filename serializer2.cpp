#include <iostream>
#include "structures.hpp"

class Serializer2 : public Serializer {
public:
  void visit(const B* b) override {
    std::cout << "B: " << b->val << std::endl;
  }
};

int main() {
  B b;
  C c;
  D d;

  Serializer2 serializer2;

  std::cout << "Serializer2 knows how to print b" << std::endl;
  static_cast<A*>(&b)->accept(serializer2);

  std::cout << "Serializer2 does not know how to print c" << std::endl;
  static_cast<A*>(&c)->accept(serializer2);

  std::cout << "Serializer2 does not know how to print d" << std::endl;
  static_cast<A*>(&d)->accept(serializer2);
}
