# Advent of Code Day 1
Find problem 1 [here!](https://adventofcode.com/2022/day/1)

### Part A
For part A, I used a simple loop that summed the calories of each of the elves as it was read in, only keeping track of the max instead of storing all of the elements.

### Part B
For part B, I used another simple loop that summed the calories of each of the elves and added them to a list. Then, I used a heap to grab the largest 3 elements. I could've alternatively modified my prior solution to track the top 3 elements. This sounds like a better solution at first glance because it uses less space, but it suffers from added complexity and reduced scalability when compared to saving all of the elements and using a heap. That is, if we later want to grab more than 3 elements, we could, in the worst case, use just as much space as this solution while taking significantly longer.
