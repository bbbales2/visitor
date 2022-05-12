#include <iostream>
#include "structures.hpp"

class Serializer3 : public Serializer {
public:
  void visit(const B* b) override {
    std::cout << "B: " << b->val << std::endl;
  }

  void visit(const C* c) override {
    std::cout << "C: " << c->val << std::endl;
  }

  void visit(const D* d) override {
    std::cout << "D: " << d->val << std::endl;
    d->bval.accept(*this);
  }
};

int main() {
  B b;
  C c;
  D d;

  Serializer3 serializer3;

  std::cout << "Serializer3 knows how to print b" << std::endl;
  static_cast<A*>(&b)->accept(serializer3);

  std::cout << "Serializer3 knows how to print c" << std::endl;
  static_cast<A*>(&c)->accept(serializer3);

  std::cout << "Serializer3 knows how to print d" << std::endl;
  static_cast<A*>(&d)->accept(serializer3);
}
