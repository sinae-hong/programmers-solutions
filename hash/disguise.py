# 해시 > 위장 문제풀이 (#15)
# 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges

def solution(clothes):
    types = {}
    for cloth_name, cloth_type in clothes:
        try:
            types[cloth_type] += 1
        except:
            types[cloth_type] = 1
    
    answer = 1
    for number in types.values():
        answer *= number + 1
    return answer - 1