
double myPow(double x, int n) {

        bool isnegative = n < 0; 
        
        if (isnegative) { 
            n = n * -1; 
        }
        
        if (n == 0) 
            return 1; 
        
        if (n == 1)
            return (isnegative) ? 1/x : x; 

		// use divide and conquer         
        auto tmp = myPow(x, n/2); 
        auto result = tmp * tmp; 
        
		// take care if exponent is odd 
        if (n & 1) 
            result *= x; 
        
		// take care if exponent is negative 
        if (isnegative && result) 
            result = 1/result; 
        
        return result; 
}

int main()
{ 
	return 0; 
} 
