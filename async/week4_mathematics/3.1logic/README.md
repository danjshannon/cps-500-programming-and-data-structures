# Logic
*May not use this stuff this term, but it will be important for later in the degree.*
## Propositional Logic
- A statement that has a truth value.
  - The sky is blue.
- Propositional variables: p,q,r,s...
- Truth values: **T** for true, **F** for false.

## Compound Propostions

- Negation (not):    &not;p
- Conjuction (and):  p&and;q
- Disjunction (or):  p&or;q
- Exclusive or:      p&oplus;q
- Implication:       p&rarr;q
- Biconditional:     p&#10231;q

## Not Truth Table
p==T | &not;p==F\
p==F | &not;p==T

## Conjunction "and"
p==T | q==T | p&and;q==T\
p==T | q==F | p&and;q==F\
p==F | q==T | p&and;q==F\
p==F | q==F | p&and;q==F
- Today is monday **and** it is raining
- There is no partially true in propositional logic.

## Disjunction "or"
p==T | q==T | p&or;q==T\
p==T | q==F | p&or;q==T\
p==F | q==T | p&or;q==T\
p==F | q==F | p&or;q==F
- Today is monday **or** today is friday
- Today is monday **or** it is raining

## Implication "Conditional"
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

## Biconditional
p==T | q==T | p&#10231;q==T\
p==T | q==F | p&#10231;q==F\
p==F | q==T | p&#10231;q==T\
p==F | q==F | p&#10231;q==T
- if it is monday it is raining

- p&#10231;q can also be written as:
  - (p&rarr;q)&and;(q&rarr;p)
- sometimes read as "p if and only if q"
- p if q
- p is equivalent to q

- Sparkling wine is champagne if and only if it is sparkling line produced in the Champagne region of France

## Understanding complex propositions
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

## English and Logic
- You **cannot ride the roller coaster** (&not;q) if **you are under four feet tall** (r) unless **you are older than 16 years old** (s)
  - q: you can ride the roller coaster
  - r: you are under four feet tall
  - s: you are older than 16
  - (r&or;&not;s)&rarr;&not;q

## Logical Equivalence
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

## Logical Equivalence
- Two propositional expressions are **logically equivalent** if p&#10231;q is a tautology
- The notation p&equiv;q denotes that p and q are logically equivalent
- (p&rarr;q)&equiv;(&not;p&or;q)

p | q | p&rarr;q | &not;p | &not;p&or;q | (p&rarr;q)&#10231;(&not;p&or;q)\
T   T      T         F          T                      T\
T   F      F         F          F                      T\
F   T      T         T          T                      T\
F   F      T         T          T                      T
