abstract class eval {
int value;
}
public class terminal extends eval{
terminal(int value)
{
super.value=value;
}
}

public class add extends eval{
add(eval[] terminals){
int value=terminals[0].value;
for(int i = 1;i < terminal.length; i++)
value += terminals[i].value;
super.value=value;
}
}
public class subtract extends eval{
subtract(eval[] terminals){
int value=terminals[0].value;
for(int i=1;i<terminal.length;i++)
value-=terminals[i].value;
super.value=value;
}
}
public class multiply extends eval{
multiply(eval[] terminals){
int value=terminals[0].value;
for(int i=1;i<terminal.length;i++)
value*=terminals[i].value;
super.value=value;
}
}
public class divide extends eval{
divide(eval[] terminals){
int value=terminals[0].value;
for(int i=1;i<terminal.length;i++)								if(terminals[i].value!=0)
value/=terminals[i].value;
else
{
value=0;
break;
}
super.value=value;
}
}

public class solve{
eval e= new add (new terminal (1), new subtract(new terminal (2),new terminal(3) ) );
return e.value;
}
