# Binary Search
---
## Overview
### What is Binary Search?
Binary Search is one of the most fundamental and useful algorithms in Computer Science. It describes the process of searching for a specific value in an ordered collection.
> Terminology used in Binary Search:

> * Target - the value that you are searching for
> * Index - the current location that you are searching
> * Left, Right - the indicies from which we use to maintain our search Space
> * Mid - the index that we use to apply a condition to determine if we should search left or right

Other Binary Search Defintions:

[Wikipedia](https://en.wikipedia.org/wiki/Binary_search_algorithm)

## Background
The goal of this chapter is to explain the mechanics of how Binary Search works, different ways to identify Binary Search, and give a brief introduction to the 3 commonly used Binary Search Templates.

### How does it work?

In its simplest form, Binary Search operates on a contiguous sequence with a specified left and right index. This is called the Search Space. Binary Search maintains the left, right, and middle indicies of the search space and compares the search target or applies the search condition to the middle value of the collection; if the condition is unsatisfied or values unequal, the half in which the target cannot lie is eliminated and the search continues on the remaining half until it is successful. If the search ends with an empty half, the condition cannot be fulfilled and target is not found.

In the following chapters, we will review how to identify Binary Search problems, reasons why we use Binary Search, and the 3 different Binary Search templates that you might be previously unaware of. Since Binary Search is a common interview topic, we will also categorize practice problems to different templates so you can practice using each.

**Note :**
> Binary Search can take many alternate forms and might not always be as straight forward as searching for a specific value. Sometimes you will have to apply a specific condition or rule to determine which side (left or right) to search next.

### Binary Search

Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. If target exists, then return its index, otherwise return -1.

**Example 1:**
```
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```

**Example 2:**
```
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
```

**Note :**

1. You may assume that all elements in nums are unique.
2. n will be in the range [1, 10000].
2. The value of each element in nums will be in the range [-9999, 9999].

**Solution :**
```python
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        l,r=0,len(nums)-1
        while l<=r:
            m=l+(r-l)//2
            if nums[m]==target:return m
            elif nums[m]>target:
                r=m-1
            else:
                l=m+1
        return -1        
```

### Identification and Template Introduction

#### How do we identify Binary Search?
As mentioned in earlier, Binary Search is an algorithm that divides the search space in 2 after every comparison. Binary Search should be considered every time you need to search for an index or element in a collection. If the collection is unordered, we can always sort it first before applying Binary Search.

#### 3 Parts of a Successful Binary Search

Binary Search is generally composed of 3 main sections:

1. Pre-processing - Sort if collection is unsorted.

1. Binary Search - Using a loop or recursion to divide search space in half after each comparison.

1. Post-processing - Determine viable candidates in the remaining space.

#### 3 Templates for Binary Search
When we first learned Binary Search, we might struggle. We might study hundreds of Binary Search problems online and each time we looked at a developer's code, it seemed to be implemented slightly differently. Although each implementation divided the problem space in 1/2 at each step, one had numerous questions:

* Why was it implemented slightly differently?

* What was the developer thinking?

* Which way was easier?

* Which way is better?

After many failed attempts and lots of hair-pulling, we found 3 main templates for Binary Search. To prevent hair-pulling and to make it easier for new developers to learn and understand, we have provided them in the next chapter.

## Template I
This chapter shows a snippet of code for Template #1. It gives a brief explanation of when to use the template and highlights the key syntax differences between the 3 templates.
### Binary Search Template I
```python
def binarySearch(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: int
    """
    if len(nums) == 0:
        return -1

    left, right = 0, len(nums) - 1
    while left <= right:
        mid = (left + right) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    # End Condition: left > right
    return -1
```
Template #1 is the most basic and elementary form of Binary Search. It is the standard Binary Search Template that most high schools or universities use when they first teach students computer science. Template #1 is used to search for an element or condition which can be determined by accessing a single index in the array.
**Key Attributes:**

---

* Most basic and elementary form of Binary Search
* Search Condition can be determined without comparing to the element's neighbors (or use specific elements around it)
* No post-processing required because at each step, you are checking to see if the element has been found. If you reach the end, then you know the element is not found


**Distinguishing Syntax:**

---

* Initial Condition: left = 0, right = length-1
* Termination: left > right
* Searching Left: right = mid-1

### Sqrt(x)
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

**Example 1:**
```
Input: 4
Output: 2
```
**Example 2:**
```
Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since
             the decimal part is truncated, 2 is returned.
```
**Solution:**
```python
class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        l,r=0,x
        while l<=r:
            m=(l+r)//2
            if m*m==x:return m
            elif m*m>x:
                r=m-1
            else:
                l=m+1
        return r   
```

### Search in Rotated Sorted Array
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

**Example 1:**
```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```
**Example 2:**
```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```
**Solution:**
```python
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums)==0:return -1
        l,r=0,len(nums)-1
        while l<=r:
            m=(l+r)//2
            if nums[m]==target:return m
            if nums[l]<=nums[m]:#如果前半部分是有序的
                if nums[l]<=target<=nums[m]:#目标在前半部分
                    r=m-1
                else:
                    l=m+1
            else:
                if nums[m]<=target<=nums[r]:
                    l=m+1
                else:
                    r=m-1
        return -1                    
```                

## Template II
```python
def binarySearch(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: int
    """
    if len(nums) == 0:
        return -1

    left, right = 0, len(nums)
    while left < right:
        mid = (left + right) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid

    # Post-processing:
    # End Condition: left == right
    if left != len(nums) and nums[left] == target:
        return left
    return -1
```
Template #2 is an advanced form of Binary Search. It is used to search for an element or condition which requires accessing the current index and its immediate right neighbor's index in the array.

**Key Attributes:**

---
* An advanced way to implement Binary Search.
* Search Condition needs to access element's immediate right neighbor
* Use element's right neighbor to determine if condition is met and decide whether to go left or right
* Gurantees Search Space is at least 2 in size at each step
* Post-processing required. Loop/Recursion ends when you have 1 element left. Need to assess if the remaining element meets the condition.


**Distinguishing Syntax:**

---
* Initial Condition: left = 0, right = length
* Termination: left == right
* Searching Left: right = mid
* Searching Right: left = mid+1

### First Bad Version
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

**Example:**
```
Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version.
```

**Solution:**
```python
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        l,r=1,n
        while l<r:
            m=l+(r-l)//2
            if not isBadVersion(m):
                l=m+1
            else:
                r=m
        if l<=n and isBadVersion(l):return l
        return -1
```                

### Find Peak Element
A peak element is an element that is greater than its neighbors.

Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that nums[-1] = nums[n] = -∞.

**Example 1:**
```
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.
```
**Example 2:**
```
Input: nums = [1,2,1,3,5,6,4]
Output: 1 or 5
Explanation: Your function can return either index number 1 where the peak element is 2,
             or index number 5 where the peak element is 6.
```
**Note :**
Your solution should be in logarithmic complexity.

**Hint :**
```
Basic Idea: Binary search

Elaboration:
 if an element(not the right-most one) is smaller than its right neighbor, then there must be a peak element on its right, because the elements on its right is either
   1. always increasing  -> the right-most element is the peak
   2. always decreasing  -> the left-most element is the peak
   3. first increasing then decreasing -> the pivot point is the peak
   4. first decreasing then increasing -> the left-most element is the peak  

   Therefore, we can find the peak only on its right elements( cut the array to half)

   The same idea applies to that an element(not the left-most one) is smaller than its left neighbor.

Conditions:
     1. array length is 1  -> return the only index
     2. array length is 2  -> return the bigger number's index
     3. array length is bigger than 2 ->
           (1) find mid, compare it with its left and right neighbors  
           (2) return mid if nums[mid] greater than both neighbors
           (3) take the right half array if nums[mid] smaller than right neighbor
           (4) otherwise, take the left half
```
**Solution :**
```python

```
## GitHub上二分查找的总结
要准确实现二分查找，首先要把握下面几个要点：

* 关于right的赋值
* right = n-1 => while(left <= right) => right = middle-1;
* right = n => while(left < right) => right = middle;
* middle的计算不能写在while循环外，否则无法得到更新。

以下是一份参考实现：
```c++
int BinarySearch(int array[], int n, int value)
{
    int left = 0;
    int right = n - 1;
    //如果这里是int right = n 的话，那么下面有两处地方需要修改，以保证一一对应：
    //1、下面循环的条件则是while(left < right)
    //2、循环内当 array[middle] > value 的时候，right = mid

    while (left <= right)  //循环条件，适时而变
    {
        int middle = left + ((right - left) >> 1);  //防止溢出，移位也更高效。同时，每次循环都需要更新。

        if (array[middle] > value)
        {
            right = middle - 1;  //right赋值，适时而变
        }
        else if(array[middle] < value)
        {
            left = middle + 1;
        }
        else
            return middle;
        //可能会有读者认为刚开始时就要判断相等，但毕竟数组中不相等的情况更多
        //如果每次循环都判断一下是否相等，将耗费时间
    }
    return -1;
}
```
#### 总结

---
编写二分查找的程序时

* 如果令 left <= right，则right = middle - 1;
* 如果令left < right，则 right = middle;`
换言之，算法所操作的区间,是左闭右开区间,还是左闭右闭区间,这个区间,需要在循环初始化。且在循环体是否终止的判断中,以及每次修改left, right区间值这三个地方保持一致,否则就可能出错。
<!--referrence-->

#### 参考
[你真的会写二分查找吗](http://www.cnblogs.com/luoxn28/p/5767571.html)
[二分查找](https://subetter.com/articles/binary-search.html)
[GitHub. 有序数组的查找.](https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/04.01.md)
