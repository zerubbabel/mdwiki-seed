# 删除K个数字，使剩下的数字串最大

---
题目描述：
一个n位的数，去掉其中的k位，问怎样去掉使得留下来的那个（n-k）位的数最大？

分析：
可以直接用贪心来求解，每次寻找从头开始的连续递减序列，删除递减序列的最后一个元素，重复K次，最后剩下的数字串组成的数字最大。

比如：

```
“13787323”
第一次，递减序列只有1，删除1，得到3787323
第二次，递减序列只有3，删除3，得到787323
第三次，递减序列只有7，删除7，得到87323
第四次，递减序列是8732，删除2，得到8733
```

```cpp
#include <stdio.h>
#include <iostream>
using namespace std;

char *itoa(int value, char *string, int radix)
{
    int rt=0;
    if(string==NULL)
        return NULL;
    if(radix<=0 || radix>30)
        return NULL;
    rt = snprintf(string, radix, "%d", value);
    if(rt>radix)
        return NULL;
    string[rt]='\0';
    return string;
}

bool cmp(char a, char b, bool reverse){
    if (reverse) {
        return a<=b;
    }else{
        return a>=b;
    }
}

int num_after_remove_k(char num_str[], int k, int num_len, bool (*cmp)(char, char, bool), bool reverse)
{
    const char RMFLAG = 'x';
    while(k>0){
        int cur = 0;
        int pre = 0;
        while(cur < num_len && 
            (num_str[cur] == RMFLAG || (*cmp)(num_str[cur], num_str[pre], reverse))) {
            if (num_str[cur] != RMFLAG)
                pre = cur;
            cur++;
        }
        num_str[pre] = RMFLAG;
        k--;
    }
    int res = 0;
    for(int i=0; i<num_len; i++){
        if (num_str[i] == RMFLAG) continue;
        res *= 10;
        res += (num_str[i] - '0');
    }
    return res;
}

int maxnum_after_remove_k(int num, int k){
    if (num == 0 || k <= 0) return 0;
    bool flag = true;
    if(num < 0){
        flag = false;
        num = -num;
    }
    char num_str[32];
    itoa(num, num_str, 10);
    int num_len = strlen(num_str);
    return num_after_remove_k(num_str, k, num_len, &cmp, flag) * (flag?1:-1);
}

int main()
{
    cout<<maxnum_after_remove_k(236311, 3);
    return 0;
}
```

```cpp
	#include <iostream>  
using namespace std;  
#define MAX 0x7fffffff  
  
int main()  
{  
    int start;      //指针指向保存后数字串的最后一位  
    int end;        //指向以前的数字串数字  
    int a[] = {MAX, 1,3,7,8,7,3,2,3};   //在这里面加入一个哨兵，放在最前面，不用考虑start会越界问题  
  
    int k = 4;      //删除字符的个数  
    int len = sizeof(a) / sizeof(a[0]);  
  
    start =  0;  
    end = 1;  
    int count = 0;  
  
    while(end <= len && count != k)  
    {  
        if(a[end] <= a[start])  
            a[++start] = a[end++];  
        else  
        {  
            start--;  
            count++;    //每次删除，记录一次  
        }  
    }  
  
    while(end <= len)    //删除已经完成，保存后面的字符  
    {  
        a[++start] = a[end++];  
    }  
  
    for(int i = 1; i < len - k; i++)  
        cout << a[i] << " ";  
  
    cout << endl;  
  
    return 0;  
}  
```

测试用例可以是：1,2,3,4,5,6,7,8；8,7,6,5,4,3,2,1；
总结：

典型的贪心应用，而且使用两个指针的方式，从头往后找，时间复杂度是O(n)，空间复杂度是O(1)。