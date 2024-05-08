from msvcrt import kbhit
i,j,k =0  

A = {1+3+4, 4,6,1}
len(A)
sum(A)
3 in A
A.add(7)
A.intersection_update({"novo conjunto"})
A = {(x+1)for x in A}
B = {(x*2)for x in A if x!=3}
{x*y for x in A for y in B if x*y < 45 if x > 3}
set() #conjunto vazio#


[1,3,4,{6,5}, "Hello World!"] #lista
[x*y for x in A for y in B]
A[0] = 3
A.append()
#A.insert(<posição>, <número>)
A.insert(3,5) #adiciona 5 na posição 3
A[1:4] # Vai do elemento 1 até o (4-1)  == > [3]
A[2:5:3] #Ele pula de 3 em 3 nessa sequencia
[x+y for [x,y] in [[1,2], [3,7]]]
zip([1,4,5], [8,9,10]) 
list(zip([1,4,5], [8,9,10]))
[x + " plays " + y for x in {"João", "Humberto", "Eduardo"} for y in {"baskertball", "Voleiball", "Tennis"}]
A.sort(reversed)
(1,2,3) #Tupla
#Tuplas não são mutaveis
{(2,4), 3,6,"Hello World!"}
A = [int(x) for x in input("Values: ").split(" ")]

#range
range(i,j,k)
#vai de "i" até "j" de "k" em "k"
[x*3 for x in range(0,1000,7)]
list(range(0,10,2)) #forma uma lista 

#Dicionário

B = {3:"HI", 4:"There", 5:"How", 6:"are", 7:"You"}
B[3] = "HI"
#print(B[3]+B[7]) = "hi You"