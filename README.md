# josephus_problem
Solutions to the Josephus Problem

## Description
The problem is described–by the authors of *Concrete Mathematics*, Graham, Knuth, and Patashnik–as follows:  
>Legend has it that Josephus wouldn't have lived to become famous without his mathmatical talents. During the Jewish-Roman war, he was among a band of 41 Jewish rebels trapped in a cave by the Romans. Preferring suicide to capture, the rebels decided to form a circle and, proceeding around it, to kill every third remaining person until no one was left. But Josephus, along with an unindicted co-conspirator, wanted none of this suicide nonsense; so he quickly calculated where he and his friend should stand in the vicious circle.  

### The Problem  
If there are *n* persons in the circle, what position (numbered from 1 to *n*) would you have to be in order to survive what I call *The circle of death*, if instead of killing every *third* remaining person, it was the *second* remaining person? This could be rewritten as, what is the last position to be removed from the circle?
Imagine this collection to be a circle with *n* = 10; `[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]`. The circle starts at 1. If we start removing every second remaining person from the collection, we would first remove 2, 4, 6, and 8, and the resulting circle is now `[1, 3, 5, 7, 9]`, then we must do the same and remove every third person, 3, 7, and 1–remember that it is a circle–and result in `[5, 9]`, finally, repeating the same process, we remove 9 and stay with 5 as the survivor of the circle of death.
## Approach Solution
This problem can be approached mathematically by applying recurrence relation rules, that is, we must define the solution to J(n) in terms of itself. In Computer Science, that is a recursive function. But first, we must find how J(n) is defined in terms of itself–find the recurrence relation.  
### Finding the Recurrence Relation
To find a recurrence relation, I usually take two steps (Mathematicians, please don't hate me for ignoring for formal methods); we can build a table and see if we can tell what the relation between the current J(n) and some J(n - m) values. Build a table works well if the relation is easy to see and useful to find a closed form of J(n). However, it can also be useful to reason about the problem itself. The second step is to reason about the problem and how adjacent and non-adjacent cases are related.  

Let's build a table of the first few values and see if we can find what the recurrence relation is.  

| n   | J(n)   |
| --- | ------ |
| 1   | 1      |
| 2   | 1      |
| 3   | 3      |
| 4   | 1      |
| 5   | 3      |
| 6   | 5      |
| 7   | 7      |
| 8   | 1      |
| 9   | 3      |
| 10  | 5      |

The first thing one can notice is that J(n) is always odd (at least for our listed cases). The reason for it is that on the first trip around the circle, we kill all even-numbered persons. The other thing that is always counts up by 2 but resets on every power of 2 (1, 2, 4, 8, ...), if we continued building our table, I am willing to bet that J(16) = 1. That could perhaps help us see a closed form, but that is not really what we are after, so let's move on to our second step.  
**Note: This reasoning was taken from the book Concrete Mathematics, Second Edition.**   
