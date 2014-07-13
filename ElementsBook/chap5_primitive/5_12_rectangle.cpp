#include <iostream>
#include <string>
#include <utility>

using namespace std;

typedef pair<int, int> Point;

struct Rectangle{
  Point lower;
  int width, height;
    
  Rectangle(const Point &pt, unsigned w, unsigned h) : lower(pt), width(w), height(h) {}
  Rectangle() {;}
    
  // point lies within this rectange?
  bool liesWithin(const Point &pt) const {
    if  ((pt.first >= lower.first && pt.first <= (lower.first + width)) &&
	 (pt.second >= lower.second && pt.second <= (lower.second + height))){
      return true;
    }
    return false;
  }
    
  const Point getUpperRight() const { return Point(lower.first+width, lower.second+height);}
  const Point getLowerRight() const { return Point(lower.first+width, lower.second);}
  const Point getUpperLeft() const { return Point(lower.first, lower.second+height);}
  const Point getLowerLeft() const { return lower; }
    
  bool intersects(const Rectangle &rec){
    if (liesWithin(rec.getLowerLeft()) ||
	liesWithin(rec.getUpperLeft()) ||
	liesWithin(rec.getLowerRight())||
	liesWithin(rec.getUpperRight())){
      return true;
    }
    return false;
  }
    
  void print(){
    cout << "(" << lower.first <<","<<lower.second <<") \twidth=" << width <<"  height=" << height <<"\n";
  }
    
  bool getIntersectedRectangle(const Rectangle &other, Rectangle &out){
    if (liesWithin(other.getLowerLeft())){
      out.lower = other.lower;
      out.width = min(other.lower.first + other.width, lower.first + width - other.lower.first);
      out.height = min(other.lower.second + other.height, lower.second + height - other.lower.second);
    }
    else if (liesWithin(other.getLowerRight())){
      out.lower = {lower.first, other.lower.second};
      out.width = min(other.lower.first + other.width - lower.first, lower.first + width);
      out.height = min(other.lower.second + other.height - lower.second,  lower.second + height);
    }
    return false; // not intersected
  }

};



int main(int argc, const char * argv[])
{
  Rectangle rec1(make_pair<int,int>(0,0), 4, 6);
  Rectangle rec2(make_pair<int,int>(5,5), 4, 6);
  Rectangle rec3(make_pair<int,int>(3,2), 4, 6);
  Rectangle rec4(make_pair<int,int>(1,4), 4, 6);
  Rectangle rec5(make_pair<int,int>(0,5), 3, 4);

  Rectangle out;
  rec1.print();
  /*
    cout << rec1.liesWithin(make_pair<int,int>(1,1)) << "\n";
    cout << rec1.liesWithin(make_pair<int,int>(5,1)) << "\n";
    cout << rec1.intersects(rec2) << "\n";
    cout << rec1.intersects(rec3) << "\n";
  */
  rec1.getIntersectedRectangle(rec3, out);
  out.print();
  rec4.getIntersectedRectangle(rec5, out);
  out.print();
  std::cout << "Done!\n";
  return 0;
}

