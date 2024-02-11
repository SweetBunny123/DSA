t = int(input())
for _ in range(t):
    n, m, k = map(int, input().split())

    elementsA = set(map(int, input().split()))
    elementsB = set(map(int, input().split()))

    ptrA, ptrB = 1, 1
    countA, countB = 0, 0

    for j in range(1, k):
        if j in elementsA and (j not in elementsB):
            countA += 1
        elif j in elementsB and (j not in elementsA):
            countB += 1
        elif j in elementsA and j in elementsB:
            if countA > countB:
                countB += 1
            else:
                countA += 1
        else:
            print("NO")
            break

        if countA > k // 2 or countB > k // 2:
            print("NO")
            break
      else:
          if countA == k // 2 and countB == k // 2:
              print("YES")
          else:
              print("NO")
