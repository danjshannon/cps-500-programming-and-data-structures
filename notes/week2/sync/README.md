# Week 2 - Controls

*example.c*\
*header.h*\
*exampleFunction.c*

## if statements
Only the line following the if statment will be part of the conditional.
```
if (test)
    printf("This if statement was true\n");
printf("This is statemtn #1 \n");
printf("This is statemtn #2 \n");
```
vs
```
if (test){
    printf("This if statement was true\n");
    printf("This is statemtn #1 \n");
    printf("This is statemtn #2 \n");
}
```

including {} around **if** statements does not change compiler output if the block statement isn't changed or the scope of the variable definitions isn't changed.\
**Chech this out** - check the size of the compiled output of a test file.*They are the same size - see test1.c vs test2.c sizes*

If statements __should__ be true/false. They don't have to be - 5 would evaluate true.
```
true=1
false=0
```

## Switch Statements
%c for char

If you don't include the break statement, the switch will continue to the other cases.

## While

```
while (something is true){
    keep doing this
}
```
If you don't change the counter (or the threshold), you will get an infinite loop!
```
while (counter < threshold)
{
    printf("");
    change counter
}
```
 ## do while
 Will always happen at least once!

 ## for loops
 3 parts:
 1. Initialization 
    - if declared within the for initialization, only exists within that scope.
 2. Condition 
    - if the condition is true, it executes the block
 3. Update
    - happens after the condition
 ```
for(initialization; condition;update)
 ```
 ## break
 You can break out of loops; If you break in a loop, good idea to put a comment in.
 ## continue
 You've hit a condition - you don't want to keep going so you can restart (go to update).
 ## goto
 goto some label - DO NOT USE PLEASE
 __makes spaghetti__

 ## functions
 void is the key for C - I;ve though about it and I don't want to use anything

 ```
returnType functionName(inputType variableName){
    return 
}
 ```
 functions are great because you only have to change the codeblock within the function in one place.

## variable scoping
 - __block scope__ If it is defined in a block, it is only available within the block.
 - __global scope__ Defined outside blockscope - can be used wherever

## static variable
 Maintains value through execution!
Declaration only takes place one time.

## header files
- provided libraries use #include<>
- user defined header files use #include ""
