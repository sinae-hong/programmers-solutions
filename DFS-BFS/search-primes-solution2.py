# 완전탐색 > 소수 찾기 문제풀이 (#13)
# 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges

from itertools import permutations

def solution(numbers):
    answer = set()
    for l in range(1, len(numbers)+1):
        answer |= set(map(lambda x: int(''.join(x)), permutations(numbers, l)))
    
    answer -= {0, 1}
    limit = max(answer)
    for k in range(2, int(limit**0.5)+1):
        answer -= set(range(2*k, limit+1, k))

    return len(answer)