#include <stdio.h>

void printBinary(int n, int i)
{

	int k;
	for (k = i - 1; k >= 0; k--) {

		if ((n >> k) & 1)
			printf("1");
		else
			printf("0");
	}
}

typedef union {

	float f;
	struct
	{

		unsigned int mantissa : 23;
		unsigned int exponent : 8;
		unsigned int sign : 1;

	} raw;
} myfloat;

// Function to convert real value
// to IEEE floating point representation
void printIEEE(myfloat var)
{

	// Prints the IEEE 754 representation
	// of a float value (32 bits)

	printf("%d | ", var.raw.sign);
	printBinary(var.raw.exponent, 8);
	printf(" | ");
	printBinary(var.raw.mantissa, 23);
	printf("\n");
}

// Driver Code
int main(void)
{

	// Instantiate the union
	myfloat var;

	// Get the real value
    scanf("%f", &var.f);

	// Get the IEEE floating point representation
	printf("IEEE 754 representation of %f is : \n",
		var.f);
	printIEEE(var);

	return 0;
}
