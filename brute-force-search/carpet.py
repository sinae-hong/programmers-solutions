# 완전탐색 > 카펫 문제풀이 (#17)
# 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges

def solution(brown, yellow):
    for yellow_h in range(1, int(yellow**0.5)+1):
        if yellow % yellow_h == 0:
            yellow_w = yellow / yellow_h
            if 2*(yellow_w + yellow_h) + 4 == brown:
                return [ yellow_w+2, yellow_h+2 ]
    return []