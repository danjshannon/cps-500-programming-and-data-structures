# 6.3 GCD Example
## Greatest Common Divisor
- The greatest common divisor of two or more integers (which are not both zero) is the largest positive integer that divides each of the integers.
```C
int gcd(int x, int y) {
    if (y==0) {
        return x;
    }
    return gcd(y, x%y);
}
```
## GCD Number of Recursive Calls
- Assume: A>B
- Claim:  A%B<.5A
- if B=.5A then A%B=0
- if B<.5A then X%B<B<.5A
- if B>.5A then A%B<=A-B<.5A
- Proof of running time
  - GCD(A,B) calls GCD (B,<.5A)
  - Which calls GCD(<.5A,B%<.5A)
