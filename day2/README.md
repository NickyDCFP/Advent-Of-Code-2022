# Advent of Code Day 2
Find problem 2 [here!](https://adventofcode.com/2022/day/2)

### Part A
For this problem, I wanted to avoid jumping to a trivial solution that used switch statements and hash maps. These solutions would likely be hard-coded with rock, paper, and scissors, would be pretty unnecessarily bulky, and wouldn't be as scalable if we wanted to have more move types. Instead, I wanted to purely use arithmetic to get scores from moves and combinations. For that reason, instead of treating the options as rock, paper, and scissors, I just treated them as a looping set of 3 integers (starting at 1) where any difference of 1 resulted in a win for the second chronological integer (not necessarily the larger integer, because they're looping). This way, that condition would hold for any n integers, and the only factor that would need to be considered when scaling would be the interactions between moves with differences larger than 1, which aren't present in a looping set of 3 integers.

In order to implement this wraparound, I first added (n - 1) to our move to ensure that subtracting another move would remain nonnegative. Then, I subtracted the opponent's move and modded the whole set by n. I've written out all possibilities for rock = 1, paper = 2, and scissors = 3 below, and you can notice that this function always produces 2 for a draw, 1 if we lose, and 0 if we win.
```
Rock: (value 1)
    vs Rock: (value 1)
        (1 + 2 - 1) % 3 = 2, DRAW
    vs Paper: (value 2)
        (1 + 2 - 2) % 3 = 1, LOSE
    vs Scissors (value 3)
        (1 + 2 - 3) % 3 = 0, WIN
Paper: (value 2)
    vs Rock: (value 1)
       (2 + 2 - 1) % 3 = 0, WIN
    vs Paper (value 2)
       (2 + 2 - 2) % 3 = 2, DRAW
    vs Scissors (value 3)
       (2 + 2 - 3) % 3 = 1, LOSE
Scissors: (value 3)
    vs Rock: (value 1)  
       (3 + 2 - 1) % 3 = 1, LOSE
    vs Paper: (value 2)
       (3 + 2 - 2) % 3 = 0, WIN
    vs Scissors: (value 3)
       (3 + 2 - 3) % 3 = 2, DRAW
```
I then present two ways to convert this to a score. First, you could simply map the values to their respective scores, which is fast, and since these values would remain constant (the function will always return 2 for a draw, 1 for loss, 0 for win) for any n integers, it wouldn't hurt the scalability. In my code, I also show (commented out, because it's slower) a mathematical way to convert this function value to a score with some modding and multiplying.

As for the overall code, I first used character arithmetic to convert A/B/C and X/Y/Z character literals into integers (1, 3) for use in the above functions.

### Part B
I approached this problem with a similar idea to the part A–I wanted a pure arithmetic solution if possible. In this case, it was pretty easy given that I had completed the first part. I basically flipped the computations from part A and used a slightly different map that gave us the return values from the functions in part A so we could work our way back to the desired move. 
