# 点集的凸包 （二）

## Code

```cpp
#include <iostream>
#include <iterator>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Projection_traits_yz_3.h>
#include <CGAL/convex_hull_2.h>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K3;
typedef CGAL::Projection_traits_yz_3<K3> K;
typedef K::Point_2 Point_2;
int main()
{
  std::istream_iterator< Point_2 >  input_begin( std::cin );
  std::istream_iterator< Point_2 >  input_end;
  std::ostream_iterator< Point_2 >  output( std::cout, "\n" );
  CGAL::convex_hull_2( input_begin, input_end, output, K() );
  return 0;
}
```

## Explanation

计算投影到yz平面上的的2D点集的凸包。

## 链接

[点集的凸包 （二）](https://github.com/wblong/CGALDemo/tree/master/convex_hull_yz)

## Reference

1. [Hello World 之 CGAL](https://www.cnblogs.com/myboat/p/9943738.html)
2. [tutorial_hello_world](https://doc.cgal.org/latest/Manual/tutorial_hello_world.html)
