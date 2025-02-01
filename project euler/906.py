# which layer are we on and how many of the elements have already been added to the left

N=int(input())
fact=[1]
for i in range(1, N+1):
  fact.append(fact[-1]*i)

def npr(n:int , r:int) -> float:
  return fact[n]//fact[n-r]

dp=[[-1 for i in range(N+1)] for j in range(3)]

def fun(layer:int, left:int)->int:
  if layer==3:
    return 1
  if dp[layer][left]!=-1:
    return dp[layer][left]
  dp[layer][left]=0
  for i in range(N-left):
    dp[layer][left]+=npr(N-left-1, i)*fact[N-1-i]*fun(layer+1, left+i)
  return dp[layer][left]

nom=N*fun(0, 0)
den=fact[N]**3
print(N, nom/den)