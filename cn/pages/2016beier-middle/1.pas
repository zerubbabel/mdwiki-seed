var n:integer;
procedure p(n:integer);
begin
	if n =0 then exit
	else 
	begin
		write(n mod 10);
		p(n div 10);
	end;
end;
begin
	read(n);
	p(n);
end;