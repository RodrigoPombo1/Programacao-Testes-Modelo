#include "Piece.h"
#include "Domino.h"
#include <iostream>

using namespace std;

bool Piece::can_be_left_to(const Piece& other) const {
    return right_ == other.left_;
}

bool Piece::can_be_right_to(const Piece& other) const {
    return left_ == other.right_;
}

const Piece& Domino::left() const {
    return pieces_.front();
}

const Piece& Domino::right() const {
    return pieces_.back();
}

bool Domino::place_left(const Piece& p) {
    if (pieces_.empty() || p.can_be_left_to(pieces_.front())) {
        pieces_.push_front(p);
        return true;
    }
    return false;
}

bool Domino::place_right(const Piece& p) {
    if (pieces_.empty() || p.can_be_right_to(pieces_.back())) {
        pieces_.push_back(p);
        return true;
    }
    return false;
}

int main() {
    { Piece p (1, 2);
  cout << boolalpha 
       << p.can_be_left_to({2, 3}) << ' ' 
       << p.can_be_left_to({3, 2}) << ' ' 
       << p.can_be_right_to({3, 2}) << ' ' 
       << p.can_be_right_to({0, 1}) << '\n'; }
       { Domino d( { {1,2}, {2,0}, {0,6}, {6,6} } );
  cout << d.left().to_string() << ' '
       << d.right().to_string() << ' '
       << d.to_string() << '\n'; }
    return 0;
}