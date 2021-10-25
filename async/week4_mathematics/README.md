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
p==T | q==T | p&and;q==T
p==T | q==F | p&and;q==F
p==F | q==T | p&and;q==F
p==F | q==F | p&and;q==F
- Today is monday **and** it is raining
- There is no partially true in propositional logic.

## Disjunction "or"
p==T | q==T | p&or;q==T
p==T | q==F | p&or;q==T
p==F | q==T | p&or;q==T
p==F | q==F | p&or;q==F
- Today is monday **or** today is friday
- Today is monday **or** it is raining

## Exclusive or
p==T | q==T | p&rarr;q==T
p==T | q==F | p&rarr;q==F
p==F | q==T | p&rarr;q==T
p==F | q==F | p&rarr;q==T

