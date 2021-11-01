# Sequences and Summations

## Sequence
- A sequence is a discrete structure uesd to represent an ordered list.
- A sequence is a function from a subset of the set of integers (usually either the set {0,1,2,...} or {1,2,3,...} to a set S).
- We use the notation a<sub>n</sub> to denote the image of the integer n. We call a<sub>n</sub> a term of the sequence.
- Notation to represent a sequence is {a<sub>n</sub>}
## Example
- {1,1/2,1/3,1/4,...} sequence {a<sub>n</sub>} where a<sub>n</sub> = 1/n, n&isin;Z<sup>+</sup>

- {2,4,8,16,32...} sequence {a<sub>n</sub>} where a<sub>n</sub> = 2<sup>n</sup>, n&isin;Z<sup>+</sup>
  - quite common - good to memorize the first 10 powers of 2

## Summation

- Notation for describing the sum of the terms a<sub>m</sub>,a<sub>m+1</sub>,...,a<sub>n</sub> from the sequence, {a<sub>n</sub>}

a<sub>m</sub>+a<sub>m+1</sub>+...+a<sub>n</sub>=&sum;(j=m to n)a<sub>j</sub>

- j is the index of summation (dummy variable)
- the index of summation runs throuh all integers from its lower limit, m, to its upper limit, n

## Closed form solutions to sums
- &sum;<sup>n</sup><sub>i=1</sub>c = cn
- &sum;<sup>n</sup><sub>i=1</sub>xf(i) = x*&sum;<sup>n</sup><sub>i=1</sub>f(i)
- &sum;<sup>n</sup><sub>i=1</sub>i = (n(n+1))/2
  - common in runtime analysis
- &sum;<sup>n</sup><sub>i=1</sub>log(i) = log(n)
- &sum;<sup>n</sup><sub>i=1</sub>i<sup>2</sup> = (n(n+1)(2n+1))/6
- &sum;<sup>n-1</sup><sub>i=1</sub>a<sup>i</sup> = (1-a<sup>n</sup>)/(1-a)

