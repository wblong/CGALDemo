## 浮点数进行的几何运算的问题

### code
```cpp
#include <iostream>
#include <CGAL/Simple_cartesian.h>
typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_2 Point_2;
int main()
{
  {
    Point_2 p(0, 0.3), q(1, 0.6), r(2, 0.9);
    std::cout << (CGAL::collinear(p,q,r) ? "collinear\n" : "not collinear\n");   
  }
  {
    Point_2 p(0, 1.0/3.0), q(1, 2.0/3.0), r(2, 1);
    std::cout << (CGAL::collinear(p,q,r) ? "collinear\n" : "not collinear\n");   
  }  
  {
    Point_2 p(0,0), q(1, 1), r(2, 2);
    std::cout << (CGAL::collinear(p,q,r) ? "collinear\n" : "not collinear\n");   
  }  
  return 0;
}
```

### result
```
not collinear
not collinear
collinear
```

### Explanation

因为小数作为双精度数是不可被描述的，共线测试内部的计算是一个3X3行列式（`determinant`），它可以得到近似值，但不能得到误差为0的精确值。所以得出前两种情况为不共线的结论。
其他的`predicate`也会有同样的问题，如`CGAL::orientation(p,q,m)`运算可能会由于舍入误差，可能得出不同于实际的结论。
如果需要使小数被全精度解析，可以使用精确断言和精确构建的`CGAL kernel`。 

## 链接
[FloatCompute](https://github.com/wblong/CGALDemo/tree/master/FloatCompute)

## Reference

1. [Hello World 之 CGAL](https://www.cnblogs.com/myboat/p/9943738.html)
2. [tutorial_hello_world](https://doc.cgal.org/latest/Manual/tutorial_hello_world.html)