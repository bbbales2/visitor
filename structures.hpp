class B;
class C;
class D;

class Serializer {
public:
  virtual void visit(const B*) {};
  virtual void visit(const C*) {};
  virtual void visit(const D*) {};
};

class A {
public:
  virtual void accept(Serializer &serializer) const = 0;
};

class B : public A {
public:
  int val = 1;

  void accept(Serializer &serializer) const {
    serializer.visit(this);
  }
};

class C : public A {
public:
  char val = 'c';

  void accept(Serializer &serializer) const {
    serializer.visit(this);
  }
};


class D : public A {
public:
  float val = 1.7;
  B bval;

  void accept(Serializer& serializer) const {
    serializer.visit(this);
  }
};
