0, ,<,L
0,0,0,L
0,1,1,L
L,0,<,L
L,1,<,L
L, ,>,go
go,0,A,wa
wa,A,>,r0
go,1,B,wb
wb,B,>,r1
go, ,#,go
r0,0,>,r0
r0,1,>,r0
r0, ,*,n0
n0,*,>,n0b
n0b, ,!,s0
r0,*,>,s0
r1,0,>,r1
r1,1,>,r1
r1, ,*,n1
n1,*,>,n1b
n1b, ,!,s1
r1,*,>,s1
s0,.,>,s0
s0,-,>,s0
s0, ,>,s0
s0,!, ,zq
s1,.,>,s1
s1,-,>,s1
s1, ,>,s1
s1,!, ,oq
zq, ,>,z1
z1, ,-,zw1
zw1,-,>,z2
z2, ,-,zw2
zw2,-,>,z3
z3, ,-,zw3
zw3,-,>,z4
z4, ,-,zw4
zw4,-,>,z5
z5, ,-,zw5
zw5,-,>,z6
z6, ,!,zw6
zw6,!,<,back
oq, ,>,o1
o1, ,.,ow1
ow1,.,>,o2
o2, ,-,ow2
ow2,-,>,o3
o3, ,-,ow3
ow3,-,>,o4
o4, ,-,ow4
ow4,-,>,o5
o5, ,-,ow5
ow5,-,>,o6
o6, ,!,ow6
ow6,!,<,back
back,0,<,back
back,1,<,back
back,X,<,back
back,Y,<,back
back,*,<,back
back,.,<,back
back,-,<,back
back, ,<,back
back,A,>,q0
back,B,>,q0
q0,X,>,q0
q0,Y,>,q0
q0,0,X,wx
wx,X,>,r0
q0,1,Y,wy
wy,Y,>,r1
q0,*,>,t
t,.,>,t
t,-,>,t
t, ,>,t
t,!, ,t2
t2, ,<,u
u,.,<,u
u,-,<,u
u, ,<,u
u,*, ,e1
e1, ,<,erase
erase,X, ,e1
erase,Y, ,e1
erase,A, ,f1
erase,B, ,f1
f1, ,>,fin
fin, ,>,fin
fin,.,#,fin
fin,-,#,fin
