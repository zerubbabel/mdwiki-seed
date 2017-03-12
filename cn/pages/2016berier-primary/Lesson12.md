# Lesson 12

s=1*2*3*4*...*8
水仙花数
s=1+4+7+…+298

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



