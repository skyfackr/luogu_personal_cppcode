var a:array[1..10] of integer;
var h,ans,i:integer;
begin
	for i:=1 to 10 do
		read(a[i]);
	readln(h);
	h:=h+30;
	ans:=0;
	for i:=1 to 10 do

		if a[i]<=h then ans:=ans+1;

	writeln(ans);
end.
