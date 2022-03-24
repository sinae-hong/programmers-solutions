# 신고 결과 받기 문제풀이 (#9)
# 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges

def solution(id_list, report, k):
    num_reported = [0] * len(id_list)
    answer = [0] * len(id_list)

    for r in set(report):
        num_reported[id_list.index(r.split()[1])] += 1
    
    for r in set(report):
        if (num_reported[id_list.index(r.split()[1])] >= k):
            answer[id_list.index(r.split()[0])] += 1
    
    return answer

# 정확성  테스트
# 테스트 1 〉	통과 (0.02ms, 10.2MB)
# 테스트 2 〉	통과 (0.03ms, 10.1MB)
# 테스트 3 〉	통과 (4119.93ms, 39.6MB)
# 테스트 4 〉	통과 (0.04ms, 10.3MB)
# 테스트 5 〉	통과 (0.04ms, 10.2MB)
# 테스트 6 〉	통과 (3.60ms, 10.4MB)
# 테스트 7 〉	통과 (6.20ms, 10.7MB)
# 테스트 8 〉	통과 (7.56ms, 10.8MB)
# 테스트 9 〉	통과 (1094.25ms, 24MB)
# 테스트 10 〉	통과 (699.23ms, 24MB)
# 테스트 11 〉	통과 (3033.50ms, 39.3MB)
# 테스트 12 〉	통과 (1.91ms, 10.2MB)
# 테스트 13 〉	통과 (0.82ms, 10.2MB)
# 테스트 14 〉	통과 (1244.15ms, 20.2MB)
# 테스트 15 〉	통과 (1197.85ms, 31.6MB)
# 테스트 16 〉	통과 (0.59ms, 10.2MB)
# 테스트 17 〉	통과 (1.28ms, 10.2MB)
# 테스트 18 〉	통과 (1.91ms, 10.2MB)
# 테스트 19 〉	통과 (3.53ms, 10.3MB)
# 테스트 20 〉	통과 (1215.53ms, 20.2M
# 테스트 21 〉	통과 (1658.08ms, 31.3MB)
# 테스트 22 〉	통과 (0.01ms, 10.2MB)
# 테스트 23 〉	통과 (0.01ms, 10.2MB)
# 테스트 24 〉	통과 (0.01ms, 10.2MB)