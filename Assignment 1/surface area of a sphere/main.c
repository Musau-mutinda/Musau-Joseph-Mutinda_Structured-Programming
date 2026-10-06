#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592653589793

int main()
{
    double radius, surfaceArea;

    printf("--- Sphere Surface Area Calculator ---\n");
    printf("Enter the radius of the sphere: ");

    if (scanf("%lf", &radius) == 1 && radius >= 0)
    {
        surfaceArea = 4 * PI * radius * radius;
        printf("The surface area of the sphere with radius %.2lf is: %.2lf\n", radius, surfaceArea);
    }
    else
    {
        printf("Error: Please enter a valid non-negative number for the radius.\n");
    }

    return 0;
}
