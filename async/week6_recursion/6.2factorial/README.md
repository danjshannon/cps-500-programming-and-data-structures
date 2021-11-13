# 6.2 Factorial Example

n! = n* (n-1)*(n-2)*...*1

```C
// Iterative
int factorial(int n){
    int result =1;
    for( int i = 2; i<=n;i++){
        result *= i;
    }
    return result;
}
```
```C
// Recursive
int factorial(int n){
    if (n==0) {
        return 1;
    }
    return n * factorial(n-1);
}
```

## Recursive Runtime
- For now:
  - number of recursive calls **times** work to break problem up **times** work to combine results
- Factorial example is O(n) runtime
