// Решите поставленную задачу в формате четвёрок
0, ,<,id
id,0,<,id
id,1,<,id
id, ,>,id+
id+,0,a,mra
id+,1,b,mrb
id+, ,<,repm
repm,a,<,repm
repm,b,<,repm
repm, ,>,rep
rep,a,0,rep+
rep,b,1,rep+
rep, ,>,ir-
ir-,0,>,ir-
ir-,1,>,ir-
ir-, ,<,ir
rep+,0,>,rep
rep+,1,>,rep
mra,a,>,mra
mra,0,>,mra
mra,1,>,mra
mra, ,>,mra+
mra+,0,>,mra+
mra+,1,>,mra+
mra+, ,0,ml
mrb,b,>,mrb
mrb,0,>,mrb
mrb,1,>,mrb
mrb, ,>,mrb+
mrb+,0,>,mrb+
mrb+,1,>,mrb+
mrb+, ,1,ml
ml,0,<,ml
ml,1,<,ml
ml, ,<,ml
ml,a,>,id+
ml,b,>,id+
ir,0,<,c0
ir,1,<,c1
c0,0,<,c0
c0,1,<,c0
c0, ,>,ch0
ch0,0, ,re
ch0,1,>,har
c1,0,<,c1
c1,1,<,c1
c1, ,>,ch1
ch1,1, ,re
ch1,0,>,har
re, ,>,ret
ret,0,>,ret
ret,1,>,ret
ret, ,<,cl
cl,0, ,ir-
cl,1, ,ir-
cl, ,<,ply
ply, ,<,ply
ply,0,>,-y
ply,1,>,-y
-y, ,>,y
y, ,1,end
har,0,>,har
har,1,>,har
har, ,<,ann
ann,0, ,ann+
ann,1, ,ann+
ann, ,<,ann2
ann2, ,<,ann2
ann2,0,>,-n
ann2,1,>,-n
ann+, ,<,ann
-n, ,>,n
n, ,0,end