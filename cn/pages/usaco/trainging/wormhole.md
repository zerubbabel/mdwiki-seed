# P1444 [USACO1.3]虫洞wormhole
题目描述
农夫约翰爱好在周末进行高能物理实验的结果却适得其反，导致N个虫洞在农场上（2<=N<=12，n是偶数），每个在农场二维地图的一个不同点。

根据他的计算，约翰知道他的虫洞将形成 N/2 连接配对。例如，如果A和B的虫洞连接成一对，进入虫洞A的任何对象体将从虫洞B出去，朝着同一个方向，而且进入虫洞B的任何对象将同样从虫洞A出去，朝着相同的方向前进。这可能发生相当令人不快的后果。

例如，假设有两个成对的虫洞A(1，1) 和 B(3，1)，贝茜从(2，1)开始朝着 +x 方向（右）的位置移动。贝茜将进入虫洞 B（在(3,1)），从A出去（在(1,1)），然后再次进入B，困在一个无限循环中！
```
| . . . .
| A > B .      贝茜会穿过B，A，
+ . . . .      然后再次穿过B
```
农夫约翰知道他的农场里每个虫洞的确切位置。他知道贝茜总是向 +x 方向走进来，虽然他不记得贝茜的当前位置。请帮助农夫约翰计算不同的虫洞配对（情况），使贝茜可能被困在一个无限循环中，如果她从不幸的位置开始。

输入格式
第1行：N(N<=12)，虫洞的数目

第2到N+1行：每一行都包含两个空格分隔的整数，描述一个以(x,y)为坐标的单一的虫洞。每个坐标是在范围 0-1000000000。

输出格式
第1行：会使贝茜从某个起始点出发沿+x方向移动卡在循环中的不同的配对

输入输出样例
输入 #1复制
4
0 0
1 0
1 1
0 1
输出 #1复制
2
说明/提示
如果我们将虫洞编号为1到4，然后通过匹配 1 与 2 和 3 与 4，贝茜会被卡住，如果她从(0，0)到(1,0)之间的任意位置开始或(0，1)和(1,1)之间。
```
| . . . .
4 3 . . .      贝茜会穿过B，A，
1-2-.-.-.      然后再次穿过B
```
相似的，在相同的起始点，如果配对是 1-3 和 2-4，贝茜也会陷入循环。（如果贝西从3进去，1出来，她会走向2，然后被传送到4，最后又回到3）

仅有1-4和2-3的配对允许贝茜从任何二维平面上的点向+x方向走不出现循环。
## problem(en)
```
Wormholes
Farmer John's hobby of conducting high-energy physics experiments on weekends has backfired, causing N wormholes (2 <= N <= 12, N even) to materialize on his farm, each located at a distinct point on the 2D map of his farm (the x,y coordinates are both integers).

According to his calculations, Farmer John knows that his wormholes will form N/2 connected pairs. For example, if wormholes A and B are connected as a pair, then any object entering wormhole A will exit wormhole B moving in the same direction, and any object entering wormhole B will similarly exit from wormhole A moving in the same direction. This can have rather unpleasant consequences.

For example, suppose there are two paired wormholes A at (1,1) and B at (3,1), and that Bessie the cow starts from position (2,1) moving in the +x direction. Bessie will enter wormhole B [at (3,1)], exit from A [at (1,1)], then enter B again, and so on, getting trapped in an infinite cycle!

   | . . . .
   | A > B .      Bessie will travel to B then
   + . . . .      A then across to B again
Farmer John knows the exact location of each wormhole on his farm. He knows that Bessie the cow always walks in the +x direction, although he does not remember where Bessie is currently located.

Please help Farmer John count the number of distinct pairings of the wormholes such that Bessie could possibly get trapped in an infinite cycle if she starts from an unlucky position. FJ doesn't know which wormhole pairs with any other wormhole, so find all the possibilities (i.e., all the different ways that N wormholes could be paired such that Bessie can, in some way, get in a cycle). Note that a loop with a smaller number of wormholes might contribute a number of different sets of pairings to the total count as those wormholes that are not in the loop are paired in many different ways.

PROGRAM NAME: wormhole
INPUT FORMAT:
Line 1:	The number of wormholes, N.
Lines 2..1+N:	Each line contains two space-separated integers describing the (x,y) coordinates of a single wormhole. Each coordinate is in the range 0..1,000,000,000.
SAMPLE INPUT (file wormhole.in):
4
0 0
1 0
1 1
0 1
INPUT DETAILS:
There are 4 wormholes, forming the corners of a square.

OUTPUT FORMAT:
Line 1:	The number of distinct pairings of wormholes such that Bessie could conceivably get stuck in a cycle walking from some starting point in the +x direction.
SAMPLE OUTPUT (file wormhole.out):
2
OUTPUT DETAILS:
If we number the wormholes 1..4 as we read them from the input, then if wormhole 1 pairs with wormhole 2 and wormhole 3 pairs with wormhole 4, Bessie can get stuck if she starts anywhere between (0,0) and (1,0) or between (0,1) and (1,1).

   | . . . .
   4 3 . . .      Bessie will travel to B then
   1-2-.-.-.      A then across to B again
Similarly, with the same starting points, Bessie can get stuck in a cycle if the pairings are 1-3 and 2-4 (if Bessie enters WH#3 and comes out at WH#1, she then walks to WH#2 which transports here to WH#4 which directs her towards WH#3 again for a cycle).

Only the pairings 1-4 and 2-3 allow Bessie to walk in the +x direction from any point in the 2D plane with no danger of cycling.
```