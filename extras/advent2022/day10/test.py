import sys
O=lambda x:chr([365,258,172,0,194,110,316,410,232,357,186,90,0,0,300,174,0,254,191,0,345,0,0,0,118,255].index(x)+65)
L=[1];e=enumerate
for l in open(sys.argv[1]):
	L+=[L[-1]]
	if l[0]=="a":L+=[L[-1]+int(l[5:])]
S=sum(v*(20+i*40) for i,v in e(L[19::40]));A=[0]*8
for i,v in e(sum(v-2<j<v+2 for v in L[j:-1:40]) for j in range(40)):A[i//5]+=v<<2*(i%5)
print(S,"".join(map(O,A)))