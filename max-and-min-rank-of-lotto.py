# 로또의 최고 순위와 최저 순위 문제풀이 (#10)
# 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges

def get_rank(num_match):
    rank_dict = { 6: 1, 5: 2, 4: 3, 3: 4, 2: 5, 1: 6, 0: 6 }
    return rank_dict[num_match]

def solution(lottos, win_nums):
    min_match = 0
    unknown = 0
    
    for number in lottos:
        if number == 0:
            unknown += 1
        elif number in win_nums:
            min_match += 1
            
    return [ get_rank(min_match + unknown), get_rank(min_match) ]