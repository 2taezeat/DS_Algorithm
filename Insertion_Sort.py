# INPUT : list 하나 입력 받기
list1 = list()
a = input().split()
for i in a:
    list1.append(int(i))
 
# InsertionSort
for j in range(1,len(list1)):
    key = list1[j] # key 값 = 삽입할 값
    i = j - 1
 
    while(i >= 0 and list1[i] > key ): # key값과 배열에서 바로전의 값과 비교
        list1[i+1] = list1[i]           # key값이 작으면 하나씩 기존 배열 하나씩 밀림
        i = i - 1
 
    list1[i+1] = key # key값이 바로 전 값(list[i])보다 크면 key값은 바로 전 값 바로 앞에 값에 넣어짐.
 
# OUTPUT : InsertionSort 완료후 정렬된 배열 출력
print(list1)