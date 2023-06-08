#include "Operation.h"
#include <iostream>

using namespace std;

class Sum : public Operation {
public:
    Sum(int a, int b) : Operation(a, b) {}
    int operation() const;
};

// é preciso por fora da classe n sei pq, até funciona bem no meu pc se for dentro mas falha nos testes se for fora
int Sum::operation() const {
    return get_op1() + get_op2();
}

class Power : public Operation {
public:
    Power(int a, int b) : Operation(a, b) {}
    int operation() const;
};

// é preciso por fora da classe n sei pq, até funciona bem no meu pc se for dentro mas falha nos testes se for fora
int Power::operation() const {
    int result = 1;
    for (int i = 0; i < get_op2(); i++) {
        result *= get_op1();
    }
    return result;
}

int main() {
    { const Operation& s = Sum(2, 10); cout << s.operation() << ' '; 
  const Operation& p = Power(2, 10); cout << p.operation() << endl; }
  { Sum s(6, -2); cout << s.operation() << ' '; 
  Power p(-3, 0); cout << p.operation() << endl; }
  { Sum s(-6, 2); cout << s.operation() << ' '; 
  Power p(-2, 5); cout << p.operation() << endl; }
  { Sum s(-6, -2); cout << s.operation() << ' '; 
  Power p(2, 7); cout << p.operation() << endl; }
    return 0;
}