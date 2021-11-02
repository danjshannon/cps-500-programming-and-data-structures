# 5.4 Loop Analysis

- State of the O of each of the following loops in terms of N
1. 
```C
for (int i =1; i<N; i*=2){...}
```
  - i=1
  - i=2
  - i=4
  - i=8
  - general form: i=2<sup>k</sup>, where k is the number of iterations
  - stop when i&ge;N
  - 2<sup>k</sup>&ge;N
  - 2<sup>k</sup>=N
  - log<sub>2</sub>(2<sup>k</sup>)=log<sub>2</sub>(N)
  - k=log<sub>2</sub>(N)
  - k is the number of iterations, so the loop with run *log<sub>2</sub>(N)* times.
  - O(log(N))

2. 
```C
for (int i =0;i<N*N;i+=3){
    for( int j=N; j>0; j-=4){...}
}
```
  - when the step function is + or -
  - |start-end|/|step size|
  - outer loop
    - for (int i =0;i<N*N;i+=3)
    - |N<sup>2</sup>-0|/|3| = N<sup>2</sup>/3=O(N<sup>2</sup>)
  - inner loop
    - for( int j=N; j>0; j-=4)
    - |N-0|/|4| = N/4 = O(N)
  - since the two loops have no dependencies on variables we can multiply:
  - O(N<sup>2</sup>) * O(N) = O(N<sup>3</sup>)
3. 
```C
for (int i =1;i<N;i*=3){
    for( int j=0; j<i; j++){...}
}
```
  - Outer loop
    - (int i =1;i<N;i*=3)
    - Similar to loop #1, we get O(log(N))
  - Inner Loop
    - for( int j=0; j<i; j++)
    - |i=0|/1=O(i)...?
      - we want O(n) not O(i)
    - 