#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <fstream>
#include <CGAL/IO/File_poly.h>
#include <CGAL/draw_triangulation_2.h>
typedef CGAL::Exact_predicates_exact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K> Delaunay;
typedef K::Point_2  Point;
void write_triangle_poly_file(const Delaunay& t, std::ostream &f);

int main(){ 
    std::ifstream in("points.pts.cgal"); 
	Point p;
	std::vector<Point> points;

   // std::istream_iterator<Point> begin(in); 
    //std::istream_iterator<Point> end; 

    Delaunay dt;  
	while (in >> p) {
		// ignore whatever comes after x and y
		in.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
		points.push_back(p);
	}
	dt.insert(points.begin(), points.end());
	//dt.insert(begin, end);
	std::cout << "points: " << dt.number_of_vertices() << std::endl;
	std::cout << "triangles: " << dt.number_of_faces() << std::endl;
	std::ofstream output("out.poly");
	write_triangle_poly_file(dt, output);
	Delaunay::Finite_faces_iterator it;
	int i = 0;
	std::cout << "-------------------------------------------------------------------" << std::endl;
    for (it = dt.finite_faces_begin(); it != dt.finite_faces_end(); it++)
    {   
		std::cout << "triangle: " << i <<std::endl;
        std::cout << dt.triangle(it) << std::endl; 
        //要访问顶点可以这样写 
        std::cout<<dt.triangle(it).vertex(0).hx()<< " "<< dt.triangle(it).vertex(0).hy() <<std::endl;//得到第一个顶点坐标  
		std::cout << dt.triangle(it).vertex(1).hx() << " " << dt.triangle(it).vertex(1).hy() << std::endl;
		std::cout << dt.triangle(it).vertex(2).hx() << " " << dt.triangle(it).vertex(2).hy() << std::endl;
		std::cout << "-------------------------------------------------------------------" << std::endl;
		++i;
    }  
	CGAL::draw(dt);
    return 0;
}

void write_triangle_poly_file(const Delaunay& t, std::ostream &f) {
	typedef typename Delaunay::Vertex_handle Vertex_handle;
	typedef typename Delaunay::Finite_vertices_iterator
		Finite_vertices_iterator;
	typedef typename Delaunay::Finite_edges_iterator
		Finite_edges_iterator;

	std::map<Vertex_handle, unsigned int> index;
	// write vertices
	f << "# Shewchuk Triangle .poly file, produced by the CGAL::Mesh_2 package"
		<< std::endl
		<< "# Neither attributes nor boundary markers are used." << std::endl
		<< t.number_of_vertices() << " " << 2 << " "
		<< 0 << " " << 0 << std::endl;

	f << std::endl;

	unsigned int vertices_counter = 0;
	for (Finite_vertices_iterator vit = t.finite_vertices_begin();
		vit != t.finite_vertices_end();
		++vit)
	{
		f << ++vertices_counter << " " << vit->point() << std::endl;
		index[vit] = vertices_counter;
	}

	f << std::endl;
}