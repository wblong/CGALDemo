# 点集的凸包（一）

## Code 

利用数组进行输入输出

```cpp
#include <iostream>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;
int main()
{
  Point_2 points[5] = { Point_2(0,0), Point_2(10,0), Point_2(10,10), Point_2(6,5), Point_2(4,1) };
  Point_2 result[5];
  // ptr - result : 地址偏移量即点的个数 ptr：指针移动的下一个位置
  Point_2 *ptr = CGAL::convex_hull_2( points, points+5, result );
  std::cout <<  ptr - result << " points on the convex hull:" << std::endl;
  for(int i = 0; i < ptr - result; i++){
    std::cout << result[i] << std::endl;
  }
  return 0;
}
```
标准库中的vector类来进行输入和输出
```cpp
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>
 
#include <vector>
 
typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef std::vector<Point_2> Points;
 
int main()
{
Points points, result;
points.push_back(Point_2(0,0));
points.push_back(Point_2(10,0));
points.push_back(Point_2(10,10));
points.push_back(Point_2(6,5));
points.push_back(Point_2(4,1));
 
 
CGAL::convex_hull_2( points.begin(), points.end(), std::back_inserter(result) );
std::cout << result.size() << " points on the convex hull" << std::endl;
return 0;
}

```
## Result

```
3 points on the convex hull:
0 0
10 0
10 10
```
vector示例

```
3 points on the convex hull
```

## Expalnation

准确断言和非准确构建的`kernel`来生成程序。

## 链接

[点集的凸包（一）](https://github.com/wblong/CGALDemo/tree/master/array_convex_hull_2)

## Reference

1. [Hello World 之 CGAL](https://www.cnblogs.com/myboat/p/9943738.html)
2. [tutorial_hello_world](https://doc.cgal.org/latest/Manual/tutorial_hello_world.html)



