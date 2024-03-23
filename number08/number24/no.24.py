# 우선순위 큐를 이용해 숫자를 정렬하는 프로그램을 구현해 보자.
# 숫자로 이루어진 리스트를 입력받아 우선순위 큐에 모두 넣은 다음 순서대로 하나씩 꺼내서 원래의 리스트에 저장하면 정렬할 수 있다.
# 우선순위 큐로는 파이썬의 heapq 모듈을 사용하라 (8.6절 허프만 코드에서 heapq의 사용법 참고)


import heapq # 우선순위 heapq 임포트

list = [] # 사용자의 입력을 받는 리스트
heap = [] # 우선순위 큐

a = 1

while a != 0:
    a = int(input('정수를 입력하세요 (0입력시 종료): '))
    if(a != 0):
         list.append(a)             # append() 함수는 파이썬에서 리스트의 끝에 새로운 요소를 추가하는 메소드입니다.
         heapq.heappush(heap , a)   # 힙큐(우선순위 큐) 에 입력한 정수 넣기


for i in range(len(list)):
     list[i] = heapq.heappop(heap)  # 우선순위에 에서 가장 작은 원소를 삭제하고 반환한다.
     

print(list)