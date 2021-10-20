#include <stdio.h>
int min(int x, int y);
//fcuntion declaration
//<return type> function_name(data_type argument_1, ... , data_type argument_k);

//function definition
// return_type function_name(data_type argument_1...data_type argument_k)
// {
// return (if return_type void)
// return expression (otherwise)
// }
int min(int x, int y)
{
    if (x < y)
    {
        return x;
    }
    return y;
}

int main()
{
    return 0;
}
