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


## 插曲

`back_inserter`用于在末尾插入元素。
实现方法是构造一个迭代器，这个迭代器可以在容器末尾添加元素。
这个迭代器是以插入（`insert`）方式而非覆盖（`overwrite`）方式运作的。

可以使用`back_inserter`的容器是有`push_back`成员函数的容器，比如`vector`, `deque` 和 `list`等。

#### 在末尾添加一个元素
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>


int main()
{
    std::vector<int> v1{ 1, 2, 3, 4, 5, 6 };

    *(std::back_inserter(v1)) = 10;

    std::cout << "v1:   ";
    for (int i : v1) {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    return 0;
}
```
结果：
```
v1:   1    2       3       4       5       6       10
```
#### 拷贝v2到v1的末尾

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> v1{ 1, 2, 3, 4, 5, 6};
    std::vector<int> v2{ 10, 20, 30, 40, 50, 60};

    std::copy(v2.begin(), v2.end(), std::back_inserter(v1));

    std::cout << "v1:   ";
    for (int i : v1) {
        std::cout << i << "\t";
    }
    std::cout << std::endl;

    return 0;
}
```

结果：
```
v1:   1 2       3       4       5       6       10      20      30      40      50      60
```

