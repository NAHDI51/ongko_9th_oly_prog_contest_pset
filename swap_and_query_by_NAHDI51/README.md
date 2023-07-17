# Swap and Query

You are given a tree of $n$ vertices. Based on this tree, you will have to perform $q$ queries. Each of the queries will be of one of the two following types: 

### **Query type 1**
$0$ $i$ $j$ <br>
The first $0$ indicates that the query is of type 1, and you will have to **swap** the places of vertices $i$ and $j$. You will **not** need to output anything in this type of query.

### **Query type 2**
$1$ $i$ $j$ <br>
The first $1$ indicates that the query is of type 2, and you will have to output the **length** of the [Shortest Path](https://en.wikipedia.org/wiki/Shortest_path_problem#:~:text=In%20graph%20theory%2C%20the%20shortest,its%20constituent%20edges%20is%20minimized.) between vertices $i$ and $j$.


Please refer to the example illustrated below to understand the queries better. 

### Input Format

The first line will contains two integers $n$ and $q$, the number of $vertices$ in the graph, and the number of $queries$, respectively.
The following $n-1$ lines will contain two integers $v$ and $u$, meaning that exists an edge $(u,v)$. 
The next $q$ lines will contain three integers $(t,i,j)$, the type of the query, and vertex $i$ and vertex $j$, respectively.

### Constraints

$1 \le n \le 2 \times 10^5$ <br>
$1 \le q \le 2 \times 10^5$ <br>
$1 \le i,j,u,v \le n$ <br>
$t \in [0,1]$ <br>

Note that the queries are not unique, i.e, we can have two queries $t_1$ $i_1$ $j_1$ we can have the following condition: $t_2$ $i_2$ $j_2$, and $t_1=t_2$, $i_1=i_2$, and $j_1=j_2$.

### Output Format 

For the query of type $2$, output the length of the shortest path between vertex $i$ and vertex $j$.

### Sample input 1

```
5 5
1 2
2 3
3 4
4 5
1 1 5
0 2 4
1 4 5
0 4 3
1 2 3
```

### Sample output 1

```
4
3
2
```

### Explanation

Initiallity, we have a straight path.

For the first query, we will return $dist(1,5)$,which, according to the picture, is $4$. <br> 
<img src="https://github.com/NAHDI51/ongko_9th_oly_prog_contest_pset/blob/master/swap_and_query_by_NAHDI51/assets/1-min.png?raw=true"></p>

For the second query, we will have to $swap(2,4)$. After this operation, the graph will look like this: <br>
<img src="https://github.com/NAHDI51/ongko_9th_oly_prog_contest_pset/blob/master/swap_and_query_by_NAHDI51/assets/2-min.png?raw=true"></p>

For the third query, we will have to return $dist(4,5)$, which, according to the picture, is $3$. <br>
<img src="https://github.com/NAHDI51/ongko_9th_oly_prog_contest_pset/blob/master/swap_and_query_by_NAHDI51/assets/3-min.png?raw=true"></p>

For the fourth query, we will have to $swap(4,3)$.After this operation, the graph will look like this: <br>
<img src="https://github.com/NAHDI51/ongko_9th_oly_prog_contest_pset/blob/master/swap_and_query_by_NAHDI51/assets/4-min.png?raw=true"></p>

Finally, for the fifth query, we will have to return $dist(2,3)$, which, according to the picture, is $2$. <br>
<img src="https://github.com/NAHDI51/ongko_9th_oly_prog_contest_pset/blob/master/swap_and_query_by_NAHDI51/assets/5-min.png?raw=true"></p></div></div>