N = int(input())
sheep = list(map(int, input().split()))

star = [0]*N
visited = set()
i = 0
while i not in visited and 0 <= i < N:
    visited.add(i)
    if sheep[i] > 0:
        sheep[i] -= 1
        star[i] = 1
    if (sheep[i] + 1) % 2 == 0:  
        i -= 1
    else:
        i += 1

sum_trek = sum(star)
sum_sheep = sum(sheep)

print(sum_trek, sum_sheep)

