# 가장 큰 수 문제풀이 (#11)
# 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges

def solution(numbers):
    str_list = [str(x) for x in numbers]
    str_list.sort(key = lambda x: x*3, reverse = True)  # '3' should be before '30'; '333' > '303030'
    answer = str(int(''.join(str_list)))    # '0000000' should be suppressed to '0'
    return answer