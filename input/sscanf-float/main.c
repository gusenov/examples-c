#include <stdio.h>



int main(int argc, char const * argv[]) {
    char const *kInput = "{3.14,2.7,6.6}";

    float pi = 0, e = 0, g = 0;

    int number_of_variables_filled = sscanf(kInput, "{%f,%f,%f}", &pi, &e, &g);
    printf("number of variables filled = %d\n", number_of_variables_filled);

    printf("π = %f\n", pi);
    printf("e = %f\n", e);
    printf("g = %f\n", g);


    printf("\n");


    char const *kToday = "8/11/2019";

    float d = 0, m = 0, y = 0;

    number_of_variables_filled = sscanf(kToday, "%f/%f/%f", &d, &m, &y);
    printf("number of variables filled = %d\n", number_of_variables_filled);

    printf("%.0f / %.0f / %.0f\n", d, m, y);


    return 0;
}
