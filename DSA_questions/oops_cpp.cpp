#include <iostream>
#include <string>
using namespace std;

class Something {

private:
  int private_variable; // as the name says its a private variable so that means
                        // it can only be accesed by some helper function not by
                        // instance/object_of_calls.variable_name in this cas
                        // its private variable
  void private_method(int private_variable) {
    private_variable = private_variable;
    cout << "something ain't right " << private_variable << endl;
  }

public:
  static int
      some; // this is a static variable means no matter how many instances it
            // create the varible will be chnage for all if it is changed in one
  static void static_funck(void) {
    cout << "this is how to initialize the static functions" << endl;
  }
  void somefunck(void) {
    some++;
    cout << "this is some function inside the public of a class " << some
         << endl;
    private_method(110);
  }
};
int Something::some =
    1; // this it the initialization of the static some variable usaully it is
       // initialized outside the class but it is still a part of class but
       // not instance of any object
       //

class Learning_virtual {
public:
  virtual void somefunck(string some) {
    cout << "this is the learning_virtual class and the string is  " << some
         << endl;
  }; // this is a virtual function which is taking in a value and the whole
     // function Learning_virtual can be something else if we want to just
  virtual void pure_virtual(
      string some) = 0; // this another of one of those virtual function where
                        // it is not nessacary to set virtual value to something
                        // we can set it to even empty or 0
};
class Inheriting_learnig_virtual : public Learning_virtual {
public:
  void somefunck(string some) override {
    cout << "this is Inheriting_learnig_virtual class so yea we've changed the "
            "somefunck method "
         << some << endl;
  }
  void pure_virtual(string some) override {
    cout << "this is the new abstract/pure virtual method" << some << endl;
  }
};
int main() {
  // using the class
  Something some;
  some.somefunck();
  Something::static_funck();
  some.somefunck();

  // virtual classes
  Inheriting_learnig_virtual *l =
      new Inheriting_learnig_virtual(); // this is a method of using heap insted
                                        // of stack thats it
  l->somefunck("hemlo");
  l->pure_virtual("something");
  delete l;
  return 0;
}
