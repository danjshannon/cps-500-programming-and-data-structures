# Week 5 Runtime Analysis
**Topics**
- Rutime Analysis
- Proportional Rates of Growth
- Limit Rule
- Loop Analysis
- Sorting Examples

## Runtime Analysis
- Hard to do by experimentations
- Estimate is usually good enough
  - Find straight line code- constant run time
  - Determine how many time it is run, in terms of n

## Big-O Notation
- Upper bound of run time
  - 0&le;f(n)&le;c*g(n)
  - f(n) actual run time of code
  - g(n) upper bound of f(n)
  - c constanst that makes it true for all cases
- only care about dominant term
- try and keep g(n) smallest possible
- use simplest expression

## Big omega
- Lower bound
- &omega;(g(n)) = {f(n): there exist positie constants c and n<sub>n</sub> such that 0&le;c*g(n)&le;f(n), for all n&ge;n<sub>0</sub>}

## Big Theta
- Upper and lower bounds
- &Theta;(g(n))

## Limit Rule
lim(n->&infin;)(f(n)/g(n))=c

## Loop Analysis rules
- Simple loop - O(n)
- Loop incrementing by multiples - O(log(n))
- Nested Loops (independent) - O(inner loop)* O(outer loop)
- Nested Loops (dependent) - must perform math