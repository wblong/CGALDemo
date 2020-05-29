
## 点和线段

如何创建点和线段，并计算两点之间的距离、点到线段的距离、点与线段的位置关系和中点。

- 定义Kernel(几何图元)
- 操作predicate(位置，距离和中点)

## Code
``` c++
#include <iostream>
#include <CGAL/Simple_cartesian.h>
typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_2 Point_2;
typedef Kernel::Segment_2 Segment_2;
int main()
{
  //!笛卡尔坐标系双精度浮点类型的点和线段
  Point_2 p(1,1), q(10,10);
  std::cout << "p = " << p << std::endl;
  std::cout << "q = " << q.x() << " " << q.y() << std::endl;
  std::cout << "sqdist(p,q) = " 
            << CGAL::squared_distance(p,q) << std::endl;
  
  Segment_2 s(p,q);
  Point_2 m(5, 9);
  
  std::cout << "m = " << m << std::endl;
  std::cout << "sqdist(Segment_2(p,q), m) = "
            << CGAL::squared_distance(s,m) << std::endl;
  std::cout << "p, q, and m ";
  //!方位
  switch (CGAL::orientation(p,q,m)){
  case CGAL::COLLINEAR: 
    std::cout << "are collinear\n";
    break;
  case CGAL::LEFT_TURN:
    std::cout << "make a left turn\n";
    break;
  case CGAL::RIGHT_TURN: 
    std::cout << "make a right turn\n";
    break;
  }
  std::cout << " midpoint(p,q) = " << CGAL::midpoint(p,q) << std::endl;
  return 0;
}
```
## Result
```
p = 1 1
q = 10 10
sqdist(p,q) = 162
m = 5 9
sqdist(Segment_2(p,q), m) = 8
p, q, and m make a left turn
 midpoint(p,q) = 5.5 5.5

```
## 链接
[HelloWorld](https://github.com/wblong/CGALDemo/tree/master/HelloWorld)
## Reference

1. [Hello World 之 CGAL](https://www.cnblogs.com/myboat/p/9943738.html)
2. [tutorial_hello_world](https://doc.cgal.org/latest/Manual/tutorial_hello_world.html)
