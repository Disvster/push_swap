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

## more brainstorming 24/05

I can use the LIS (longest increasing or decreasing subsequence) for sorting.

If I commit to organizing each chunk then I need to always check for **rr** and **rrr** when I'm rotating Stack B.
If this is the case then SB will be rotating for organization purposes and SA will be rotating to prepare the nodes in the next chunk to be processed, so that they can be pushed to B when B is done organizing itself.

I can also implement a type of **Binary Search** but instead of searching I'll be **Binary Sorting**. This is basically quick sort I think.

My initial idea was attribute a chunk number to each node. The floored square root determines the size of each chunk and how many chunks I'll have.
Having the values divided into groups I theorized it would be easier to sort each group individually at a time.
E.g.: If I have 16 disorganized numbers then I'll have 4 chunks (from 0 - 3). I would start with chunk 3, meaning that I would look for all nodes containing the chunk-id == 3 in A and push them to B. I would then organize B in descending order. A would be used as a helper stack for B when needed.
Then look for nodes with chunk-id == 2 and repeat the process. In the end I would have a B organized in descending order and an empty A. I would push everything to A and it would end up being organized in ascending order.

### 2 things to note here:
1. inefficiency when searching for nodes in to-be-processed chunk:
    * node/chunk search in A would be based on 1st, 2nd and last node (ra-rra-sa);
2. still no algorithm for organizing, just a chunk dream;

### Solutions:
1. determine costs:
    * create like a hash map of all the numbers I'm looking for in the node that I'm processing;
    * **pb** based on cost from least to biggest (this would be calculated to determine which node I would move in that instance, every time I need to make a node-to-be-pushed decision);
2. sort based on LIS and/or Binary Sorting:
    * LIS - I would get the longest (in my case) decreasing sequence, in order to organize B and possibly ignoring completely other numbers from previous organized chunks. This would mean having some sort of node-targeting-another-node based on adjacent values logic OR
    * B.S. - binary sorting whatever I wanted, be it a whole stack and ditching my chunk logic or binary sorting within the bounds of a node. This would mean I would keep diving stack or chunk into smaller, halved sized sections with an anchor point. One halve < another side >= than anchor until I end up with 1 (?); 

### What to do next:
- get to a point where you have all nodes in A associated with their respective chunks;
- create a function which pushes these chunks into B.

When I have this, I can then start working on the sorting part and test how and if chunk sorting will work.
