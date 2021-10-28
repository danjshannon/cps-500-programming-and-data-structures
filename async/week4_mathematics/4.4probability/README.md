# 4.4 Probability
## Simple Events
## Experiments
- an **experiment** is a prcedure whose outcome cannot be precisely predicted
  - an experiment can be repeated infinitely many times and has a well-defined set of possible outcomes.
- The set of all possible outcomes of an experiment is the **sample space**
- The **outcome** is the result of an experiment

## Sample Spaces
- Sample space is a set than can be **finite** or **infinite** in cardinality
- Sample space is **discrete** if it has infinitely many or countable infinity of elements
  - ie natural numbers
- Sample space is **continuous** if the elements of the sample space constitute a continuum.
  - ie real numbers

## Events
- A subset of the sample space is called an event
- if two events have an empty intersection, they are called mutually exclusive
  - They cannot both occur

## Permutations
- if **r** objects are chosen from a set of **n** distinct objects, any particular arrangment (or order) of those objects is called a **permutation**
- some permutations of {a,b,c,d}:
  - abcd
  - dcba

<sub>n</sub>P<sub>r</sub>=n!/(n-r)!

## Combinations
- number number of ways that **r** objects can be selected from a set of **n** distinct objects is call a **combination**

<sub>n</sub>C<sub>r</sub>=(n r)=n!/(r!(n-r)!)

- Notice that the set of combinations is less than the set of permutations

## Probability
- If there are n equally likely possibilities of which one must occur and are regarded as faorable, or as a "success", then the probability of a "success" is given by s/n
- The probability of an event (or outcome) is the proportion of times the event would occur in a long run of repeated events.

## Axioms of Probability
- Let S be the sample space
- **Axiom 1** 0&le;P(A)&le;1 for each event A in S
  - probs are real numbers on the interval from 0 to 1
- **Axiom 2** P(S)=1
  - the sample space as a whole has a prob of 1
- **Axiom 3** if A and B are mutually exclusive events in S the P(A &cup; B)=P(A)+P(B)
  - prob functions are additive

## Independent Events
- Two events A and B are independent if and only if:

P(A &cap; B)=P(A)*P(B)

- prob of getting two heads in a two flips of a balanced coin?
- P(heads)*P(heads)=0.25

# Statistics
## Mean >:(

- Most commonly called the average

u=(x1+...+xn)/n

u=&sum;xi/n

## Median
- The middle value when a variable's values are ranked in order; the point that divides a distribution into two equal halves.

## Mode
- The most common data point in a set

## Range
- The spread, or the distance, between the lowest and highest values of a variable

## Variance
- a measure of the spread of the recorded values on a variable; a measure of dispersion

1/n&sum;i=1 to n (xi-u)<sup>2</sup>

- the larger the variance, the further the individual cases are from the mean
- the smaller the variance, the closer the individual cases are to the mean

