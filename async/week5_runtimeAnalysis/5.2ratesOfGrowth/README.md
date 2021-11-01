# Proportional Rates of Growth
## Big-O

O(g(n))={f(n):there exists (&exist;) positive constances c and n<sub>0</sub> such that 0&le;f(n)&le;c*g(n),for all n&ge;n<sub>0</sub>}

- n is the size of the input to the problem
- f(n) is a function that characterizes the *actual* running time of the alogrithm
- g(n) is a function that characterizes an upper bounds on f(N). It is a limit on the running time of the algorithm
- n<sub>0</sub>, c are arbitrary constants that make the above formula true

**f(n) &isin; O(g(n))**
- we want to create an upper bound on f(n)
- g(n) is an **asymptotic upper bound** for f(n)
- if f(n) &isin; O(g(n)), we write f(n)=O(g(n))

### Example:
- 2n<sup>2</sup>=O(n<sup>3</sup>) with M=1 and x<sub>0</sub>=2
- functions in O(n<sup>2</sup>)
  - n<sup>2</sup>
  - n<sup>2</sup> + n
  - n<sup>2</sup> + 1000n
  - 1000n<sup>2</sup> + 1000n

## Big-O notation in practice
- Pay attention to dominant terms
- Don't include constants in O
- We generally only care about the smallest g such that f(x) is int (O(g(x)))

## Big-O rules
1. If f(n) is a polynomial of degree d, then f(n) is O(n<sup>d</sup>)
2. Use the smallest possible class of functions if possible
3. Use the simplest expression of the class

# Bit-Omega (Lower Bound)
&omega;(g(n))={f(n): &exist; positive constances c and n<sub>0</sub> such that 0&le;c*g(n)&le;f(n), for all n&ge;n<sub>0</sub>}
- looking for a lower bound.
- g(n) is a function that characterizes a lower bound on f(n). It is a limit on how fast the running time of the algo can be.

**f(n) &isin; &omega;(g(n))**
### example

f(n)=100n<sup>2</sup>+8000n+97

- Claim f is in &omega;(n)
- n&le;100n<sup>2</sup>+8000n+97, for n>0
- c=1, n<sub>0</sub>=0

### example

&radic;n = &omega;(lg(n))

- c=1, n<sub>0</sub>=16

# Big Theta

&theta;(g(n))={f(n): &exist; positive constants c<sub>1</sub> and c<sub>2</sub> such that 0&le;c<sub>1</sub>*g(n)&le;f(n)&le;c<sub>2</sub>*g(n) for all n&ge;n<sub>0</sub>}

- g(n) is a function that characterizes a tight bounds on f(n). 
- It is a limit on how fast and how slow the running time of the algo can be.

**f(n) &isin; &theta;(g(n))**

- g(n) is **asymptotically tight bound** for f(n)
- **Theorem**: &theta;(g(n))=O(g(n))&cap;&omega;(g(n))
- f(n)=&theta;(n)&rarr;f(n)=O(g(n)) and f(n)=&omega;(g(n))

### &theta; Notation Example
- n<sup>2</sup>/2-n=&theta;(n<sup>2</sup>) with c1=1/4, c2=1/2, n0=8

## Asymptotic Analysis
- **Asymptotic Analysis** is a way to describe behavior of functions in the limit
- Describes the growth of functions
- abstract away lower order terms and constant functions
  - focus on what's important
- How we indicate running times of algorithms

O&asymp;&le;

&omega;&asymp;&ge;

&theta;&asymp;=

