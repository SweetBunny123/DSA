def turnpike(a, b, differences, max):
  #turnpike([0,9],  [2,3,4,5,6,9], [2,3,4,5,6], 9)1st 
  result = False
  if differences == []:#if diffences empty
    return True
  a.sort()
  differences.sort()
  current_max = max#current = 3
  for i in range(len(differences)-1,-1,-1):
    if differences[i] != current_max and differences[i]<=current_max:
      current_max = differences[i]

      break
  check  = isValid(a+[current_max], b)
  a.sort()
  check1 = isValid(a+[a[-1]-current_max], b)
  if not check and  not check1 and current_max==max:
    return False
  elif not check and not check1 and current_max!= max:
    result = turnpike(a, b, differences, current_max)
  i = 1
  #checking is valid ( 0,9,6,  [2,3,4,5,6,9])
  way = 'right'
  if not check:
    way = 'left'

  if check and way=='right':
    a.append(current_max)
    a.sort()
    temp = differences.copy()
    differences = b.copy()
    v = 0
    for i in range(len(a)-1):
      for j in range(i+1, len(a)):
        if abs(a[j]-a[i]) not in differences and not v:
          way = 'left'
          v = 1
          differences = temp.copy()
          a.remove(current_max)
          break
        else:
          differences.remove(abs(a[j]-a[i]))
      if v == 1:
        break
    if way=='right':
      result = turnpike(a, b, differences, current_max)
      if not result:
        differences = temp.copy()
        a.remove(current_max)
        i = 0
        way = 'left'

  if way=='left' and check1:
    val = abs(a[-1]-current_max)
    a.append(val)
    temp = differences.copy()
    differences = b.copy()
    a.sort()
    for i in range(len(a)-1):
      for j in range(i+1, len(a)):
        if abs(a[j]-a[i]) not in differences:
          v = 1
          differences = temp.copy()
          a.remove(a[-1]-current_max)
          way = 'move ahead'
          break
        else:
          differences.remove(abs(a[j]-a[i]))

    result = turnpike(a, b, differences, current_max)
    if not result:
      differences = temp.copy()
      a.remove(val)
      i = 0
      way = 'move ahead'
  return result





def isValid(a, b):
  dic = {}
  dic2 = {}
  for i in range(len(b)):
    if b[i] not in dic.keys():
      dic[b[i]] = 1
    else:
      dic[b[i]] += 1
  for i in range(len(a)):
    for j in range(i+1, len(a)):
      if abs(a[j]-a[i]) not in dic2.keys():
        dic2[abs(a[j]-a[i])] = 1
      else:
        dic2[abs(a[j]-a[i])] = +1
  return all(not (key not in dic or dic2[key] > dic[key]) for key in dic2)





def solve(a, b):

    differences = []
  #differences = [0]
    differences.append(0)
  #differences = [0,9]
    differences.append(max(a))
    temp = a.copy()
    #temp = [2,3,4,5,6,9]
    #temp = [2,3,4,5,6]
    temp.remove(max(a))
    if turnpike(differences, a, temp, max(a)):
    #turnpike([0,3], [1,2,3], [1,2], 3)
      return differences
    else:
      no = []
      for _ in range(b):
        no.append(-1)
      return no

n = int(input())
res = list(map(int, input().split()))
res = solve(res, n)
for i in res:
  print(i, end=" ")
