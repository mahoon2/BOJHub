n=[40]*5
for i in range(len(n)):
    inp=int(input())
    if inp>n[i]:
        n[i]=inp
print(int(sum(n)/len(n)))