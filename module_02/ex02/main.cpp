# include "Fixed.hpp"

int	main( void )
{

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

// #include <iostream>
// #include "Fixed.hpp"

// int main( void ) {
    
//     // -------------------------------------------------------
//     // 1. CONSTUCTORS AND BASICS
//     // -------------------------------------------------------
//     std::cout << "--- 1. Constructors & Basics ---" << std::endl;
//     Fixed a;
//     Fixed const b( 10 );
//     Fixed const c( 42.42f );
//     Fixed const d( b );

//     std::cout << "a is " << a << std::endl;
//     std::cout << "b is " << b << std::endl;
//     std::cout << "c is " << c << std::endl;
//     std::cout << "d is " << d << std::endl;
//     std::cout << std::endl;

//     // -------------------------------------------------------
//     // 2. ARITHMETIC OPERATORS
//     // -------------------------------------------------------
//     std::cout << "--- 2. Arithmetic Operators ---" << std::endl;
//     Fixed x(10);
//     Fixed y(2.5f);

//     std::cout << "x (" << x << ") + y (" << y << ") = " << (x + y) << std::endl;
//     std::cout << "x (" << x << ") - y (" << y << ") = " << (x - y) << std::endl;
//     std::cout << "x (" << x << ") * y (" << y << ") = " << (x * y) << std::endl;
//     std::cout << "x (" << x << ") / y (" << y << ") = " << (x / y) << std::endl;
//     std::cout << std::endl;

//     // -------------------------------------------------------
//     // 3. INCREMENT / DECREMENT (The Epsilon Tests)
//     // -------------------------------------------------------
//     std::cout << "--- 3. Increment/Decrement (Epsilon) ---" << std::endl;
//     Fixed e;

//     std::cout << "Start e: " << e << std::endl;
    
//     std::cout << "Pre-inc (++e): " << ++e << std::endl;
//     std::cout << "After Pre-inc: " << e << std::endl;
    
//     std::cout << "Post-inc (e++): " << e++ << std::endl;
//     std::cout << "After Post-inc: " << e << std::endl;

//     // Let's verify the value is actually epsilon (approx 0.00390625 for 8 bits)
//     // 0 -> 0.0039 (pre) -> 0.0039 -> 0.0039 (post returns old) -> 0.0078
//     std::cout << "Final e value:  " << e << std::endl;
//     std::cout << std::endl;

//     // -------------------------------------------------------
//     // 4. COMPARISON OPERATORS
//     // -------------------------------------------------------
//     std::cout << "--- 4. Comparison Operators ---" << std::endl;
//     Fixed small(10);
//     Fixed big(20);

//     // Using std::boolalpha to print "true"/"false" instead of 1/0
//     std::cout << std::boolalpha; 
//     std::cout << "10 < 20: " << (small < big) << std::endl;
//     std::cout << "10 > 20: " << (small > big) << std::endl;
//     std::cout << "10 <= 10: " << (small <= small) << std::endl;
//     std::cout << "10 >= 20: " << (small >= big) << std::endl;
//     std::cout << "10 == 10: " << (small == small) << std::endl;
//     std::cout << "10 != 20: " << (small != big) << std::endl;
//     std::cout << std::endl;

//     // -------------------------------------------------------
//     // 5. MIN / MAX FUNCTIONS
//     // -------------------------------------------------------
//     std::cout << "--- 5. Min / Max ---" << std::endl;
//     Fixed f1( 5.05f );
//     Fixed f2( 2 );
    
//     // Test non-const versions
//     std::cout << "min(5.05, 2): " << Fixed::min(f1, f2) << std::endl;
//     std::cout << "max(5.05, 2): " << Fixed::max(f1, f2) << std::endl;

//     // Test const versions (using the const objects from section 1)
//     std::cout << "min(const 10, const 42.42): " << Fixed::min(b, c) << std::endl;
//     std::cout << "max(const 10, const 42.42): " << Fixed::max(b, c) << std::endl;

//     return 0;
// }