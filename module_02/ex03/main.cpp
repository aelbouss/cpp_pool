# include "Point.hpp"


// Declare the bsp function prototype
bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
    // 1. Create the Triangle Corners
    // A triangle with corners at (0,0), (10,0), and (0,10)
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    std::cout << "--- Triangle Created: A(0,0), B(10,0), C(0,10) ---\n" << std::endl;

    // TEST 1: Point Inside
    // Point (1, 1) is safely inside
    Point p1(1.0f, 1.0f);
    if (bsp(a, b, c, p1) == true)
        std::cout << "Test 1 (Inside): \tPASS (Returned True)" << std::endl;
    else
        std::cout << "Test 1 (Inside): \tFAIL (Returned False)" << std::endl;

    // TEST 2: Point Outside
    // Point (20, 20) is way outside
    Point p2(20.0f, 20.0f);
    if (bsp(a, b, c, p2) == false)
        std::cout << "Test 2 (Outside): \tPASS (Returned False)" << std::endl;
    else
        std::cout << "Test 2 (Outside): \tFAIL (Returned True)" << std::endl;

    // TEST 3: Point On Edge
    // Point (5, 0) is exactly on the line between A and B
    // The subject says edges are OUTSIDE (False)
    Point p3(5.0f, 0.0f);
    if (bsp(a, b, c, p3) == false)
        std::cout << "Test 3 (On Edge): \tPASS (Returned False)" << std::endl;
    else
        std::cout << "Test 3 (On Edge): \tFAIL (Returned True)" << std::endl;

    // TEST 4: Point On Vertex
    // Point (0, 0) is exactly on corner A
    // Corners are also OUTSIDE (False)
    Point p4(0.0f, 0.0f);
    if (bsp(a, b, c, p4) == false)
        std::cout << "Test 4 (Vertex): \tPASS (Returned False)" << std::endl;
    else
        std::cout << "Test 4 (Vertex): \tFAIL (Returned True)" << std::endl;

    return 0;
}