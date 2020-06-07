//#include <iostream>
//#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
//#include <CGAL/convex_hull_2.h>
//typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
//typedef K::Point_2 Point_2;
//int main()
//{
//  Point_2 points[5] = { Point_2(0,0), Point_2(10,0), Point_2(10,10), Point_2(6,5), Point_2(4,1) };
//  Point_2 result[5];
//  Point_2 *ptr = CGAL::convex_hull_2( points, points+5, result );
//  std::cout <<  ptr - result << " points on the convex hull:" << std::endl;
//  for(int i = 0; i < ptr - result; i++){
//    std::cout << result[i] << std::endl;
//  }
//  return 0;
//}

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>

#include <vector>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef std::vector<Point_2> Points;

int main()
{
	Points points, result;
	points.push_back(Point_2(0, 0));
	points.push_back(Point_2(10, 0));
	points.push_back(Point_2(10, 10));
	points.push_back(Point_2(6, 5));
	points.push_back(Point_2(4, 1));


	CGAL::convex_hull_2(points.begin(), points.end(), std::back_inserter(result));
	std::cout << result.size() << " points on the convex hull" << std::endl;
	return 0;

}