line=input()
line=list(map(int, input().split()))
max_score=max(line)
mean_score=sum(line)/len(line)
print(mean_score*100/max_score)