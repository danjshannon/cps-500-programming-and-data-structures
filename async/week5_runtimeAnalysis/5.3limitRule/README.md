# 5.3 Limit Rule

lim(n->&infin;)f(n)/g(n)=c
- Where 0&le;c&le;+&infin;

- if 0 < c < +&infin; then f(n) &isin; &theta;(g(n)), O(g(n)), and &omega;(g(n))
- if c = 0 then f(n) &isin; O(g(n)), but f(n) &notin; &theta;(g(n)),&omega;(g(n))
- if c = &infin; then f(n) &isin; &omega;(g(n)), but f(n) &notin; &theta;(g(n)),O(g(n))

## Limit Rule Example
- FindMin: f(n)=n-1
- claim: f(n)=&theta;(n)
- lim(n&rarr;&infin;)f(n)/g(n)
- lim(n&rarr;&infin;)(n-1)/n
- lim(n&rarr;&infin;)[(n/n)-(1/n)]
- lim(n&rarr;&infin;)[1-(1/n)]
- lim(n&rarr;&infin;)[1-(1/&infin;)]
- lim(n&rarr;&infin;)[1-0]=1
- if 0<1<+&infin;, then f(n)=&theta;(n)

## Potential limit rule example
- f(n)=n<sup>3</sup>-n<sup>2</sup>-1
- claim: f(n)=&omega;(n)
- lim(n&rarr;&infin;)f(n)/g(n)
- lim(n&rarr;&infin;)(n<sup>3</sup>-n<sup>2</sup>-1)/n
- lim(n&rarr;&infin;)n<sup>2</sup>-n-(1/n)
- lim(n&rarr;&infin;)&infin;<sup>2</sup>-&infin;-(1/&infin;)
- lim(n&rarr;&infin;)&infin;-&infin;-0
- lim(n&rarr;&infin;)n<sup>2</sup>=&infin;
- Therefore f(n)=&omega;(n)

## Big-) limit rule example
- f(n)=n
- claim: f(n)=&omega;(n)
- lim(n&rarr;&infin;)f(n)/g(n)
- lim(n&rarr;&infin;)n/n<sup>2</sup>
- lim(n&rarr;&infin;)1/n
- lim(n&rarr;&infin;)1/&infin;=0;
- therefore f(n)&isin;O(n<sup>2</sup>)

