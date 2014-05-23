/*
 * editstepladders.cpp
 * Exercise 5-4. Chapter 5 - The Algorithm Design Manual
 * URL: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=35&category=37&page=show_problem&problem=970

Problem C: Edit Step Ladders

An edit step is a transformation from one word x to another word y such that x and y are words in the dictionary, and x can be transformed to y by adding, deleting, or changing one letter. So the transformation from dig to dog or from dog to do are both edit steps. An edit step ladder is a lexicographically ordered sequence of words w1, w2, ... wn such that the transformation from wi to wi+1 is an edit step for all i from 1 to n-1.
For a given dictionary, you are to compute the length of the longest edit step ladder.

Input

The input to your program consists of the dictionary - a set of lower case words in lexicographic order - one per line. No word exceeds 16 letters and there are no more than 25000 words in the dictionary.
Output

The output consists of a single integer, the number of words in the longest edit step ladder.
Sample Input

cat
dig
dog
fig
fin
fine
fog
log
wine
Sample Output

5
 *
 *  Created on: May 21, 2014
 *      Author: vietnguyen
 */


