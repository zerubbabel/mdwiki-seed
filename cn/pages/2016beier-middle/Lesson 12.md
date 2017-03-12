# Lesson 12

ex1:
for i:=3 to 6 do
s:=s+1;
writeln(s);

ex2:
for i:=3 to 6 do
s:=s+i;
writeln(s);

ex3:
a:=0;b:=1;
for i:=1 to 4 do
begin
    c:=a+b;
    a:=b;
    b:=c;
end;
writeln(c);

ex4:
s:=0;t:=1;
for i:=1 to 4 do
begin
    t:=t*i;
    s:=s+t;
end;
writeln(s,' ',t);

ex4:
t:=1;
for i:=1 to 4 do
begin
    s:=0;
    t:=t*i;
    s:=s+t;
end;
writeln(s,' ',t);

ex6:
for i:=1 to 5 do
a[i]:=2*i+1;

ex7:
a[1]:=1;
for i:=2 to 5 do
a[i]:=a[i-1]*2

ex8:
a[1]:=0;a[2]:=1;
for i:=3 to 5 do
a[i]:=a[i-1]+a[i-2];

ex9:
for i:=1 to 7 do
a[i]:=i;
for i:=1 to 3 do
begin
    t:=a[i];
    a[i]:=a[7-i];
    a[7-i]:=t;
end;

ex10:
for i:=1 to 7 do
a[i]:=7-i;
for i:=1 to 7 do
if a[i]>4 then writeln(i,' ',a[i]);

## middle 2
数组读程序
选择排序


