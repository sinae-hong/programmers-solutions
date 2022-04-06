# 스택/큐 > 주식가격 문제풀이 (#18)
# 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges

def solution(prices):
    answer = list(range(len(prices)-1, -1, -1))
    for left in range(len(prices)-1):
        for right in range(left+1, len(prices)):
            if prices[left] > prices[right]:
                answer[left] = right-left
                break
    return answer