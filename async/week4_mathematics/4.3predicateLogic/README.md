# 4.3 Predicate Logic
## exponential function
- The funciton is defined by:
  - f(x)=b<sup>x</sup>, (b<0)
  - is called an exponential function with base b and exponent x.
  - The domain of f is the set of all real numbers.

## Laws of exponents
- They exist lol

## The Base e
- Exponential functions to the base e, where e is an irrational number whose value is 2.7182818... play an important role in both theoretical and applied problems.
- e=sum(from n=0 to infinity)[1/n!]

## Logarithms

- y=b<sup>x</sup>
- solve for y:
  - log<sub>b</sub>(x)
- Logarithm of x to the base b:
  - y=log<sub>b</sub>(x) &rarr; x=b<sup>y</sup> (x>0)

## Logarithmic Notation
- Common log: log(x)=log<sub>10</sub>(x)
- Natural log: ln(x)=log<sub>e</sub>(x)
- log<sub>b</sub>(mn)=log<sub>b</sub>(m)+log<sub>b</sub>(n)
- log<sub>b</sub>(m/n)=log<sub>b</sub>(m)-log<sub>b</sub>(n)
- log<sub>b</sub>(m<sup>n</sup>)=n*log<sub>b</sub>(m)
- log<sub>b</sub>(1)=0
- log<sub>b</sub>(b)=1

# Predicate Logic
## Calculus
- **Predicate function**: a function that returns a truth value given an object
- C(x): "x is a cat"
- G(x,y): "x>y"

## Quantifiers
- A **quantifier** is an operator that limits the variables of a proposition
- two types:
  1. Universal
  2. Existential

## Universal Quantifiers
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

## Existential Quantifications
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

## A note on quantifiers
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