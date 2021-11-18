# Week 4: Mathematics
- [4.1 Logic](#41-Logic)
- [4.2 Set Theory](#42-set-theory)
- [4.3 Predicate Logic](#43-predicate-logic)
- [4.4 Probability](#44-probability)
- [4.5 Sequences and Summations](#45-sequences-and-summations)

## 4.1 Logic
[top](#week-4-mathematics)\
*May not use this stuff this term, but it will be important for later in the degree.*
### Propositional Logic
- A statement that has a truth value.
  - The sky is blue.
- Propositional variables: p,q,r,s...
- Truth values: **T** for true, **F** for false.

### Compound Propostions

- Negation (not):    &not;p
- Conjuction (and):  p&and;q
- Disjunction (or):  p&or;q
- Exclusive or:      p&oplus;q
- Implication:       p&rarr;q
- Biconditional:     p&##10231;q

### Not Truth Table
p==T | &not;p==F\
p==F | &not;p==T

### Conjunction "and"
p==T | q==T | p&and;q==T\
p==T | q==F | p&and;q==F\
p==F | q==T | p&and;q==F\
p==F | q==F | p&and;q==F
- Today is monday **and** it is raining
- There is no partially true in propositional logic.

### Disjunction "or"
p==T | q==T | p&or;q==T\
p==T | q==F | p&or;q==T\
p==F | q==T | p&or;q==T\
p==F | q==F | p&or;q==F
- Today is monday **or** today is friday
- Today is monday **or** it is raining

### Implication "Conditional"
p==T | q==T | p&rarr;q==T\
p==T | q==F | p&rarr;q==F\
p==F | q==T | p&rarr;q==T\
p==F | q==F | p&rarr;q==T

- *order matters
- 
- p is call the antecendent
- q is called the consequent
- p implies q
- whenever p is true, q must be true
- if p, then q
- q if p
- p is sufficient for q
- p only if q

### Biconditional
p==T | q==T | p&##10231;q==T\
p==T | q==F | p&##10231;q==F\
p==F | q==T | p&##10231;q==T\
p==F | q==F | p&##10231;q==T
- if it is monday it is raining

- p&##10231;q can also be written as:
  - (p&rarr;q)&and;(q&rarr;p)
- sometimes read as "p if and only if q"
- p if q
- p is equivalent to q

- Sparkling wine is champagne if and only if it is sparkling line produced in the Champagne region of France

### Understanding complex propositions
- if it rains or it is windy, then we will not play golf
- p: we will play golf
- r: it is raining
- q: it is windy
- r or q implies not p

p | r | q | r&or;q | &not;p | (r&or;q)&rarr;&not;p\
T   T   T     T        F              F\
T   T   F     T        F              F\
T   F   T     T        F              F\
T   F   F     F        F              T\
F   T   T     T        T              T\
F   T   F     T        T              T\
F   F   T     T        T              T\
F   F   F     F        T              T

### English and Logic
- You **cannot ride the roller coaster** (&not;q) if **you are under four feet tall** (r) unless **you are older than 16 years old** (s)
  - q: you can ride the roller coaster
  - r: you are under four feet tall
  - s: you are older than 16
  - (r&or;&not;s)&rarr;&not;q

### Logical Equivalence
- Terminology - a coumpound proposition is a:
  - Tautology if it is always true
  - Condtradiciton if it is always false
  - Contingency if it can be either true or false
- Tautologies
  - p &or; &not; q
  - p &rarr; p
  - (p &rarr; q) &and; p
- Contradictions
  - p &and; &not; p
  - p &and; F

### Logical Equivalence
- Two propositional expressions are **logically equivalent** if p&##10231;q is a tautology
- The notation p&equiv;q denotes that p and q are logically equivalent
- (p&rarr;q)&equiv;(&not;p&or;q)

p | q | p&rarr;q | &not;p | &not;p&or;q | (p&rarr;q)&##10231;(&not;p&or;q)\
T   T      T         F          T                      T\
T   F      F         F          F                      T\
F   T      T         T          T                      T\
F   F      T         T          T                      T

## 4.2 Set Theory
[top](#week-4-mathematics)
### Sets
- Used to group objects together
- objects of a set often have similar properties
- A **set** is an unordered collection of objects
- The objects in  set are called **elements** or **members**
- sets **contain** elements

### Notation
- s E S means that s is an element of S
- s ~~E~~ S means that s is not an element of S
- The set of all vowels can be written as V={a,e,i,o,u}
- Sets do not have to contain related elements

### Set Builder Notation
- Describes th emembership of a set by describing its members properties
- Set E of all even positive inegers less than 10
  - E={x|x is an even postive integer <10}
  - E={x|x%2=0 && x<10}
  - S={formula for elements|restrictions}

### Notation
- Natural Numbers: N={1,2,3}
- Integers: Z={...,-2,-1,0,1,2,...}
- Postive Integers: Z+ = {1,2,...}
- Rational Numbers: Q= {p/q|pEZ,qEz,q!=0}
- Real numbers: R={x|x is rational or x is irrational}
- {N,Z,Q,R} set of sets

### Empty Set and Singleton
- Empty {}
- Singleton {{}}

### Subset
- S is a subset of T **if and only if** every element of S is also an element of T
  - sES&rarr;sET

### Proper subset
- every element in a set is a subset

### Cardinality
- if S is a set and it ha ndistinct elements where n is a postivie integer, then S is a finite set
- |S|=n,n is the **cardinality** of S
  - |{a,b,c}|=3
  - |{{1,2,3}}|=1
  - |{}|-0
- if S is finite, we can sayt that |S|<|N|

### Power Set
- Given a set S, the power of set of S, P(S) is the set of all subsets of S
- The power set of {0,1,2}
- The empty set and set itself are always elements of the power set
- P({})={{},{{}}}
- power set has 2<sup>n</sup>

### Tupel
- An ordered n-tupel
- {x1,x2,...,xn}={y1,y2,...,yn} if xi=yi for i=1...n

### Ordered pairs
- 2-tupels are called ordered pairs

### Cartesian Product
- The **Cartesian product of sets S and T (XxT) is the set of all ordered pairs (s,t) where sES and tET
  - SxT={(s,t)|sES,tET}
- S={1,2}
- T={a,b}
- SxT={(1,a),(1,b),(2,a),(2,b)}
- TxS={(a,1),(b,1),(a,2),(b,2)}
- TxS ~~=~~ SxT

## Set operations
### Set Union
- The **union** of two sets is S and T is the set than contains those elements that are in S,T, or Both:
  - S &union; T={x|xES &or; xET}
### Intersection
- The **intersection** of two sets S and T is the set containing the elements that are in both S and T

### Difference
- The **difference** betweeen sets S and T (S-T) is the set containing those elements in S but not in T:
  - S--T={x|xE X&and; x~~E~~T}

### Complements
- The **universal** set is the set of all elements that are under consideration
- once the unviersal set U is specifies, the complement of a set can be definded.
- The complement of a set S is the set of elements that are in U but not in S:

- Sbar = {x|x~~E~~S &and;x EU}
- Sbar=U-S

### Disjoin Set
- Two sets S and T are disjoin if their intersectio is {}

### set identities
- See 4.2 section 3 ~5min

### Computer representation of Set
- We can represent set Membershiop using bit arrays or bit settings
- A[i]=1 then the ith element is present
- A[i]=0 then the ith element is not present

- **intersection** becomes **bit-wise** AND

## Functions and Relations
### Binary Relation
- A relation from S to T is just a subset of SxT
### Properties of Relations
- R is reflexive
- R is irreflexive
- R is symmetric
- R is antisymmetric
- R is transitive

### Functions
- A relation from S to T that contains ona dn only one , ordered pair(s,t) for every selemtn sES, defines a **function** f from S to T
- f(s)=t where (s,t) is the uique ordered pair in the relation for s.

### domain and range


## 4.3 Predicate Logic
[top](#week-4-mathematics)
### exponential function
- The funciton is defined by:
  - f(x)=b<sup>x</sup>, (b<0)
  - is called an exponential function with base b and exponent x.
  - The domain of f is the set of all real numbers.

### Laws of exponents
- They exist lol

### The Base e
- Exponential functions to the base e, where e is an irrational number whose value is 2.7182818... play an important role in both theoretical and applied problems.
- e=sum(from n=0 to infinity)[1/n!]

### Logarithms

- y=b<sup>x</sup>
- solve for y:
  - log<sub>b</sub>(x)
- Logarithm of x to the base b:
  - y=log<sub>b</sub>(x) &rarr; x=b<sup>y</sup> (x>0)

### Logarithmic Notation
- Common log: log(x)=log<sub>10</sub>(x)
- Natural log: ln(x)=log<sub>e</sub>(x)
- log<sub>b</sub>(mn)=log<sub>b</sub>(m)+log<sub>b</sub>(n)
- log<sub>b</sub>(m/n)=log<sub>b</sub>(m)-log<sub>b</sub>(n)
- log<sub>b</sub>(m<sup>n</sup>)=n*log<sub>b</sub>(m)
- log<sub>b</sub>(1)=0
- log<sub>b</sub>(b)=1

## Predicate Logic
### Calculus
- **Predicate function**: a function that returns a truth value given an object
- C(x): "x is a cat"
- G(x,y): "x>y"

### Quantifiers
- A **quantifier** is an operator that limits the variables of a proposition
- two types:
  1. Universal
  2. Existential

### Universal Quantifiers
- Represented by and upside-down A: &forall;
  - It means "for all"

**Let P(x)=x+1>x**

- We can state the following:
  - &forall;x P(x)
  - For all values of x, P(x) is true
  - For all values of x, x+1>x is true

- Let the universe be the real umbers.
  - Then &forall;x P(x) is true

**Let P(x)=x/2<x**

  - not true for negative numbers!
  - Thus, &forall;xP(x) is false
- In order to prove that a universal quantification is true, it must be shown for **all** cases
- In order to prove a universal quantification is false, it must be shown false for only **one** case
Given P(x) for x1,...,xn/
- Universal Quantification &forall;xP(x) implies:
P(x1)&and;P(x2)&and;...&and;P(xn)/

- Think of &forall; as a for loop;
- &forall; x P(x) where 1&le;x&le;10
- Can be translated as:
```C
int isTrue=1;
for (x=1;x<=10;x++){
    // is P(x) true?
    if(P(x)==false){
        isTrue = 0;
    }
}
```
- if P(x) is true for all parts of the loop, the &forall;x P(x)

### Existential Quantifications
- Represented by a backwards 'E': &exist;
  - It means "there exists"

**Let P(x)=x+1>x**

- We can state the following:
  - &exist;x P(x)
  - There exists a value of x such that P(x) is true
  - For at least one value of x, x+1>x is true
- You still have to specify your univers

**Let P(x)=x+1<x**

  - There is no numerical value x for which x+1<x
  - Thus, &exist;x P(x) is false

**Let P(x)=x+1>x**

  - There is a numerical value x for which x+1>x
  - Thus, &exist;x P(x) is true

- in order to show that the existential quantification is **true**, you only have to find **one** true value
- in order to show that the existential quantification is **false**, you have to show it's false for **all** values (difficult)

- Given some propositional function P(x)
- and values in the universe x1,...xn
- The existential quantification &exist;x P(x) implies:
  - P(x1)&or;P(x2)&or;...&or;P(xn)

### A note on quantifiers
- Recall that P(x) is a predicate function.
  - Let P(x) be x==0
- Recall that a proposition is a statement that is either true or false.
  - P(x) is **not** a proposition
- There are two ways to make a propositional function into a proposition
  1. Supply it with a value
    - P(5) is false, P(0) is true
  2. Provide a quantification
    - For example, &forall;x P(x) is false and &exist;x P(x) is true
      - Let the universe of discorse be the real numbers

## 4.4 Probability
[top](#week-4-mathematics)
### Simple Events
### Experiments
- an **experiment** is a prcedure whose outcome cannot be precisely predicted
  - an experiment can be repeated infinitely many times and has a well-defined set of possible outcomes.
- The set of all possible outcomes of an experiment is the **sample space**
- The **outcome** is the result of an experiment

### Sample Spaces
- Sample space is a set than can be **finite** or **infinite** in cardinality
- Sample space is **discrete** if it has infinitely many or countable infinity of elements
  - ie natural numbers
- Sample space is **continuous** if the elements of the sample space constitute a continuum.
  - ie real numbers

### Events
- A subset of the sample space is called an event
- if two events have an empty intersection, they are called mutually exclusive
  - They cannot both occur

### Permutations
- if **r** objects are chosen from a set of **n** distinct objects, any particular arrangment (or order) of those objects is called a **permutation**
- some permutations of {a,b,c,d}:
  - abcd
  - dcba

<sub>n</sub>P<sub>r</sub>=n!/(n-r)!

### Combinations
- number number of ways that **r** objects can be selected from a set of **n** distinct objects is call a **combination**

<sub>n</sub>C<sub>r</sub>=(n r)=n!/(r!(n-r)!)

- Notice that the set of combinations is less than the set of permutations

### Probability
- If there are n equally likely possibilities of which one must occur and are regarded as faorable, or as a "success", then the probability of a "success" is given by s/n
- The probability of an event (or outcome) is the proportion of times the event would occur in a long run of repeated events.

### Axioms of Probability
- Let S be the sample space
- **Axiom 1** 0&le;P(A)&le;1 for each event A in S
  - probs are real numbers on the interval from 0 to 1
- **Axiom 2** P(S)=1
  - the sample space as a whole has a prob of 1
- **Axiom 3** if A and B are mutually exclusive events in S the P(A &cup; B)=P(A)+P(B)
  - prob functions are additive

### Independent Events
- Two events A and B are independent if and only if:

P(A &cap; B)=P(A)*P(B)

- prob of getting two heads in a two flips of a balanced coin?
- P(heads)*P(heads)=0.25

### Statistics
### Mean >:(

- Most commonly called the average

u=(x1+...+xn)/n

u=&sum;xi/n

### Median
- The middle value when a variable's values are ranked in order; the point that divides a distribution into two equal halves.

### Mode
- The most common data point in a set

### Range
- The spread, or the distance, between the lowest and highest values of a variable

### Variance
- a measure of the spread of the recorded values on a variable; a measure of dispersion

1/n&sum;i=1 to n (xi-u)<sup>2</sup>

- the larger the variance, the further the individual cases are from the mean
- the smaller the variance, the closer the individual cases are to the mean

## 4.5 Sequences and Summations
[top](#week-4-mathematics)
### Sequence
- A sequence is a discrete structure uesd to represent an ordered list.
- A sequence is a function from a subset of the set of integers (usually either the set {0,1,2,...} or {1,2,3,...} to a set S).
- We use the notation a<sub>n</sub> to denote the image of the integer n. We call a<sub>n</sub> a term of the sequence.
- Notation to represent a sequence is {a<sub>n</sub>}
### Example
- {1,1/2,1/3,1/4,...} sequence {a<sub>n</sub>} where a<sub>n</sub> = 1/n, n&isin;Z<sup>+</sup>

- {2,4,8,16,32...} sequence {a<sub>n</sub>} where a<sub>n</sub> = 2<sup>n</sup>, n&isin;Z<sup>+</sup>
  - quite common - good to memorize the first 10 powers of 2

### Summation

- Notation for describing the sum of the terms a<sub>m</sub>,a<sub>m+1</sub>,...,a<sub>n</sub> from the sequence, {a<sub>n</sub>}

a<sub>m</sub>+a<sub>m+1</sub>+...+a<sub>n</sub>=&sum;(j=m to n)a<sub>j</sub>

- j is the index of summation (dummy variable)
- the index of summation runs throuh all integers from its lower limit, m, to its upper limit, n

### Closed form solutions to sums
- &sum;<sup>n</sup><sub>i=1</sub>c = cn
- &sum;<sup>n</sup><sub>i=1</sub>xf(i) = x*&sum;<sup>n</sup><sub>i=1</sub>f(i)
- &sum;<sup>n</sup><sub>i=1</sub>i = (n(n+1))/2
  - common in runtime analysis
- &sum;<sup>n</sup><sub>i=1</sub>log(i) = log(n)
- &sum;<sup>n</sup><sub>i=1</sub>i<sup>2</sup> = (n(n+1)(2n+1))/6
- &sum;<sup>n-1</sup><sub>i=1</sub>a<sup>i</sup> = (1-a<sup>n</sup>)/(1-a)

