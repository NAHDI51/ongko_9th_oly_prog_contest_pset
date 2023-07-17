# SERIES

Problem link: [Series](https://www.hackerrank.com/contests/9th-ongko-olympiad-programming-contest/challenges/series-48)

You are given an array of integers $a_1, a_2, a_3, ..., a_n$ of length $n$. You will need to determine whether they form an [addition series](https://en.wikipedia.org/wiki/Summation) or not. If it does, return the absolute difference between two consecutive terms. If it does not, return $-1$.

### Input Format

The first line of the contains an integer $n$, the number of elements. 
The second line contains $n$ space-seperated integers, where the $i^{th}$ number represents $a_i$.

### Constraints

* $1 \le n \le 2 \times 10^5$
<br>
* $-10^{18} \le a_i \le 10^{18}$

**Note:** You should use a $64bit$ integer data-type, because the standard $32bit$ integer type will not be able to store numbers bigger than $2^{32}$.

### Output format

If the numbers form an addition series, return the absolute difference between two consecutive terms. For example, if the difference is $d$, return $abs(d)$. Otherwise, return $-1$. **If the number of element is $1$, return $-1$.**

### Sample input 1

```
4
5 10 15 20
```

### Sample output 1

```
5
```

### Sample input 2
```
4
3 6 7 9
```
### Sample output 2
```
-1
```

### Explanation

In the first sample, we see that

$$ 5=5 $$
$$ 10=5+5 $$
$$ 15=5+5+5 $$
$$ 20=5+5+5+5 $$

which means that they create an addition series with difference of $5$ in-between. Thus, we return $5$.

In the second example, we see that

$$ 6=3+3 $$
$$ 7=3+3+1 $$

Which means, it does not form an addition series. Thus, we return $-1$.

