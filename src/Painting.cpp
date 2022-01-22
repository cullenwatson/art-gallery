#include "Painting.h"

Painting::Painting(int _id, int _val, int _width, int _height){
    id=_id;
    val=_val;
    width=_width;
    height=_height;
}
bool Painting::operator==(const Painting& other) const{
    return id == other.id;
}
bool Painting::operator<(const Painting& other) const{
    return id < other.id;
}
ostream& operator<<(ostream&out, const Painting& p){
    out << setw(10)<<p.id <<" "<< setw(9)<< p.val <<" "<< setw(9)<< p.width << " "<< setw(9) <<p.height << endl;
    return out;

}

