# My push_swap notes

We need to sort the values of a **Stack** (Stack A) in ascending order. We have another empty stack (Stack B). We have a limited set (and limited number) of operations we can use to achieve this:

- **sa** (swap a) : swap the first 2 elements at the top of Stack A
    * do nothing if empty or only 1 element
- **sb** (swap b) : swap the first 2 elements at the top of Stack B
    * do nothing if empty or only 1 element
- **ss** : **sa** and **sb** at the same time
- **pa** (push a) : put 1st element of **B** to top of **A**
    * do nothing if **B** empty
- **pb** (push b) : put 1st element of **A** to top of **B**
    * do nothing if **A** empty
- **ra** (rotate a) : move 1st element to last, shift 1up all other elems
- **rb** (rotate b) : same as ra but for **B**
- **rr** : **ra** and **rb** at the same time
- **rra** (reverse rotate a) : move last element to 1st, shift 1down all other elems
- **rrb** (reverse rotate b) : same as rra but for **B**
- **rrr** : **rra** and **rrb** at the same time

## brainstorm

I'm gonna need to read the arguments and convert them to ints with an ft_atoi while simultaneously sending them to a list-like structure acting as **A**.

Each node of the list will contain an int (which we will use to compare with the other ints in the other nodes and organize them accordingly) and a pointer to the address of the next node and another the address of the previous node.

### swap:

After Stack A is created I can organize each node according to where they are vs where they should be.
I iterate through the stack and compare the real index of where they are (`i`) with the value stored as `final_index`.
I can also send bunches of nodes to stack B, organized them there and send them back to A, then do
the same again but instead of a bunch of nodes send a bunch of bunches of organized nodes.
Like start with (idk) 3 (I heard that 3 is hard-coded) nodes to B, organize them there. ex:
- 5-6-7 then 2-3-4 then 8-9-10
Then :
- (1-3-4)-(5-6-7)-(8-9-10)
