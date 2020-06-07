# 准确断言和准确构建

## Code

```cpp
#include <iostream>
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <sstream>
typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;
typedef Kernel::Point_2 Point_2;
int main()
{
  Point_2 p(0, 0.3), q, r(2, 0.9);
  {
    q  = Point_2(1, 0.6);
    std::cout << (CGAL::collinear(p,q,r) ? "collinear\n" : "not collinear\n");
  }
  
  {
    std::istringstream input("0 0.3   1 0.6   2 0.9");
    input >> p >> q >> r;
    std::cout << (CGAL::collinear(p,q,r) ? "collinear\n" : "not collinear\n");
  }
  
  {
    q = CGAL::midpoint(p,r);
    std::cout << (CGAL::collinear(p,q,r) ? "collinear\n" : "not collinear\n");   
  }
 
  return 0;
}
```

## Result

```
not collinear
collinear
collinear
```

## Explanation

第一个结果仍然是错的，原因与前面相同，它们仍然是浮点运算。
第二个结果不同，它由字符串生成（`construct`），则准确地代表了字符串所表示的数。
第三个结果通过构建（`construct`)中点得到第三个点，构建操作获得的值跟原始值是一致准确的（计算得到的），所以结果也是正确的。

在很多情况下，操作“精确”浮点数据，它们是由计算得到或由传感器得到的。它们不是象“0.1”这样的字符串，也不是象"1.0/10.0"这样动态（on the fly）生成的，它是一个全精度的浮点数。如果它们只是被传递入某个算法并且没有构建（`construct`）操作时，你可以使用支持精确断言（`predicate`）和非精确构建（`construct`）的`kernel`。

由于高精度的计算需要消耗比普通计算多的资源，内存、时间等，所以使用时需要考虑。

## 链接

[准确断言和准确构建](https://github.com/wblong/CGALDemo/tree/master/exact)

## Reference

1. [Hello World 之 CGAL](https://www.cnblogs.com/myboat/p/9943738.html)
2. [tutorial_hello_world](https://doc.cgal.org/latest/Manual/tutorial_hello_world.html)