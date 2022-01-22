#ifndef CS3353_PA01_PAINTING_H
#define CS3353_PA01_PAINTING_H
#include <iostream>
#include<iomanip>
using namespace std;
class Painting{
    int id, val, width, height;
public:
    // constructor
    Painting(int, int, int, int);

    // relational operators
    bool operator==(const Painting&) const;
    bool operator<(const Painting&) const;

    // accessors
    int getId() const { return id; };
    int getVal() const { return val; };
    int getWidth() const { return width; };
    int getLength() const { return height; };

    // output
    friend ostream& operator<<(ostream&, const Painting&);
};

#endif //CS3353_PA01_PAINTING_H
