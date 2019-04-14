import heapq

if __name__ == "__main__":
    while True:
        n = int(input())
        if n == 0:
            break

        pq = list(map(int,input().split()))
        heapq.heapify(pq)

        cost = 0;

        while len(pq) > 1:
            n1 = heapq.heappop(pq)
            n2 = heapq.heappop(pq)
            s = n1 + n2
            cost += s
            heapq.heappush(pq, s)


        print(cost)










