#include "triangle.h"

#include <algorithm>
#include <stdexcept>

using namespace std;

namespace triangle {
    
    flavor kind(double a_length, double b_length, double c_length) {
    	if (a_length <= 0 || b_length <= 0 || c_length <= 0) {
    		throw domain_error{"Degenerate Triangle has side <= 0>"};
    	}
    
    	double args[] = {a_length, b_length, c_length};
    	sort(args, args + 3);
    
    	double sum_of_smallest = args[0] + args[1];
    	double longest_length = args[2];
    
    	if (longest_length >= sum_of_smallest) {
    		throw domain_error{"Degenerate Triangle has side longer or equal to the sum of other two"};
    	}
    
    	if (a_length == b_length && b_length == c_length) {
    		return flavor::equilateral;
    	} else if (a_length == b_length || a_length == c_length || b_length == c_length) {
    		return flavor::isosceles;
    	} else {
    		return flavor::scalene;
    	}
    }

}
