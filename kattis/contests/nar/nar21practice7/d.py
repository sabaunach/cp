from collections import defaultdict

n,m,k=map(int, input())
teamranks = defaultdict(list)
playerranks = defaultdict(list)
for i in range(n):
    team, *ranks = input().split()
    teamranks[team].extend(ranks)
for i in range(k):
    player, *ranks = input().split()
    playerranks[player].extend(ranks)
