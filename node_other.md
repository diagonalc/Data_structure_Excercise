# Other Notes

### Note about header files  
Including a header is basically copying everything inside the header and pasting it into where you include it.   

What a header should include: declarations, structures  
What a .c file should include: functions, macros, variables

Why a header file shouldn't include complete functions?  
As if two .c files included the header, the function will be defined twice, leading to error.  

Then why structures can be included in a header file?  
Structures can be defined twice in **different** .c file. Meanwhile, header guard (```#ifndef```,  ```#endif```) can prevent repeated defination of a structure in one .c file. 