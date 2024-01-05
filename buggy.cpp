#include <iostream>
#include <cstring> // memcpy defined here.
// First comment
// Second commnet
// FIXME: Add appropriate declarative regions to scope and other header files.
// EXPLAIN: Why are these required?
struct Point {
    int x, y;

    Point () : x(), y() {}
    Point (int _x, int _y) : x(_x), y(_y) {}
};

class Shape {
    private: // Needed so outside users cannot modify them directly.
    int vertices;
    Point** points;
    double *shape_area; // Stores the area of the shape and can be accessed later.

// FIXME: Add appropriate access modifiers.
// EXPLAIN: Why should we add the access modifier?
    public: // That way outside users can utilize them to create their desired values.
    Shape (int _vertices) {
        vertices = _vertices;
        points = new Point*[vertices+1];
    }

    //FIXME: Fill out the destructor.
    //EXPLAIN: Why should we fill destructors? What will happen if the destroyer is left empty?
    ~Shape () {
        for (int i = 0; i <= vertices; i++){
            delete points[i];
        }

        delete[] points; // deleting the array of points.
        delete shape_area; // deleting the newly created variable.
    }

    // FIXME
    void addPoints (/* formal parameter for unsized array called pts */ Point *pts) { // Pointer called pts for addPoints
        for (int i = 0; i <= vertices; i++) {
            //FIXME: Add an allocation of point
            //EXPLAIN: Why should we add the allocation of point?
            points[i] = new Point(); // Need to create a place for the new points to go.
            memcpy(points[i], &pts[i%vertices], sizeof(Point));
        }
    }

    // FIXME: update the computation
    double* area () {
        int temp = 0;
        // FIXME
        for (int i = 0; i < vertices; i++) {
            // FIXME: there are two methods to access members of pointers
            //        use one to fix lhs and the other to fix rhs
            int lhs = points[i]-> x * points[i+1]-> y;
            int rhs = points[i+1]-> x * points[i]-> y;
            temp += (lhs - rhs);
        }
        shape_area = new double(abs(temp)/2.0); // Deleted memory before, so now it is allocated adn can be accessed.
        
        return shape_area; // returning the newly calculated variable.  
    }
};

int main () {
    // FIXME: create the following points using the three different methods
    //        of defining structs:
    //          tri1 = (0, 0)
    //          tri2 = (1, 2)
    //          tri3 = (2, 0)
    Point tri1(0, 0);
    Point tri2 = {1, 2};
    Point tri3 = Point(2,0);
    // adding points to tri
    Point triPts[3] = {tri1, tri2, tri3};
    Shape* tri = new Shape(3);
    // FIXME
    tri ->addPoints(triPts); // pointer call function.

    // FIXME: create the following points using your preferred struct
    //        definition:
    //          quad1 = (0, 0)
    //          quad2 = (0, 2)
    //          quad3 = (2, 2)
    //          quad4 = (2, 0)
    Point quad1 = {0,0}; // Simpliest struct definition to me.
    Point quad2 = {0,2};
    Point quad3 = {2,2};
    Point quad4 = {2,0};


    // adding points to quad
    Point quadPts[4] = {quad1, quad2, quad3, quad4};
    Shape* quad = new Shape(4);
    quad ->addPoints(quadPts); // pointer call function.

    // FIXME: print out area of triangle and area of quad
    std::cout << "Triangle Area: " << *tri -> area() << std::endl;
    std::cout << "Quad Area: " << *quad -> area() << std::endl;

    // FIXME: clean-up dynamically allocated memory to avoid memory leaks
    // Calling the destructor for the two newly created shapes.
    delete quad; 
    delete tri;

    return 0;
}