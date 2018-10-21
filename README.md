# Challenge5

The aim of this challenge was to create a program that organises a round-robin style tournament of a 2-player game.
A round-robin tournament is one where everybody plays everybody else, in this case twice.
Players face each opponent twice as it is assumed that the game in question has a first turn advantage.
The program takes a text file containing a list of competators and organises which players play against each other in each round.
It then makes another set of rounds where players have swapped order in order to compensate for first turn advantage.
This program also compensates for having an odd number of players, organising which player sits out during a round.
An example input and output file are given below:    

Input:
```
Player1
Player2
Player3
Player4
Player5
```

This would generate 10 output files, 1 for each round in the tournament, the output file for round 1 is given below:

Output:
```
Player1 vs. Player4
Player2 vs. Player5
Player3 vs. Nobody
```
