## Lifetimes

There are four kinds of lifetimes(storage duration)

- variables defined within a block without `static` gets automatic lifetime and get dropped when the block is out of scope — automatic storage duration 
- static variables have static storage durations and exists from the time created to the end of the program — static storage duration 
- variables for which memory is allocated at runtime have dynamic memory storage exist when created and goes out of scope when dropped — dynamic storage duration
- variables created with `thread_local` have thread storage duration. — thread storage duration 

Remember that the lifetime and scope of a variable are different things. Lifetime is the period of
execution time over which a variable survives. Scope is the region of program code over which the variable
name can be used. It’s important not to get these two ideas confused.
