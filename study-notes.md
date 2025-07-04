# My push_swap notes

We need to sort the values of a **Stack** (Stack A) in ascending order. We have another empty stack (Stack B). We have a limited set (and limited number) of operations we can use to achieve this:

- **sa** (swap a) : swap the first 2 elements at the top of Stack A
    - do nothing if empty or only 1 element
- **sb** (swap b) : swap the first 2 elements at the top of Stack B
    - do nothing if empty or only 1 element
- **ss** : **sa** and **sb** at the same time
- **pa** (push a) : put 1st element of **B** at top of **A**
    - do nothing if **B** empty
- **pb** (push b) : put 1st element of **A** at top of **B**
    - do nothing if **A** empty
- **ra** (rotate a) : move 1st element to last, shift 1up all other elems
- **rb** (rotate b) : same as ra but for **B**
- **rr** : **ra** and **rb** at the same time
- **rra** (reverse rotate a) : move last element to 1st, shift 1down all other elems
- **rrb** (reverse rotate b) : same as rra but for **B**
- **rrr** : **rra** and **rrb** at the same time
