# 스택/큐 > 프린터 문제풀이 (#14)
# 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges

from operator import itemgetter

def solution(priorities, location):
    answer = 0
    waiting = list(enumerate(priorities))
    target = waiting[location]
    while target in waiting:
        answer += 1
        document = max(waiting, key=itemgetter(1))
        pos = waiting.index(document)
        waiting = waiting[pos+1:] + waiting[:pos]
    return answer