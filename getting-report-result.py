# 신고 결과 받기 문제풀이 (#9)
# 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges

def solution(id_list, report, k):
    answer = [0] * len(id_list)
    reportee_to_reporters = {id: [] for id in id_list}
    
    for str in set(report):
        pair = str.split()
        reportee_to_reporters[pair[1]].append(pair[0])
        
    for reporters in reportee_to_reporters.values():
        if len(reporters) >= k:
            for reporter in reporters:
                answer[id_list.index(reporter)] += 1
    
    return answer

# 정확성  테스트
# 테스트 1 〉	통과 (0.01ms, 10.1MB)
# 테스트 2 〉	통과 (0.02ms, 10.4MB)
# 테스트 3 〉	통과 (1120.79ms, 46.4MB)
# 테스트 4 〉	통과 (0.03ms, 10.3MB)
# 테스트 5 〉	통과 (0.03ms, 10.2MB)
# 테스트 6 〉	통과 (0.80ms, 10.4MB)
# 테스트 7 〉	통과 (1.39ms, 10.8MB)
# 테스트 8 〉	통과 (2.17ms, 11.1MB)
# 테스트 9 〉	통과 (281.47ms, 27.3MB)
# 테스트 10 〉	통과 (40.13ms, 27MB)
# 테스트 11 〉	통과 (462.26ms, 46.4MB)
# 테스트 12 〉	통과 (0.49ms, 10.3MB)
# 테스트 13 〉	통과 (0.21ms, 10.2MB)
# 테스트 14 〉	통과 (359.42ms, 24.2MB)
# 테스트 15 〉	통과 (63.92ms, 36.8MB)
# 테스트 16 〉	통과 (0.15ms, 10.1MB)
# 테스트 17 〉	통과 (0.19ms, 10.3MB)
# 테스트 18 〉	통과 (0.67ms, 10.4MB)
# 테스트 19 〉	통과 (1.06ms, 10.5MB)
# 테스트 20 〉	통과 (301.73ms, 24.1MB)
# 테스트 21 〉	통과 (567.62ms, 36.8MB)
# 테스트 22 〉	통과 (0.01ms, 10.4MB)
# 테스트 23 〉	통과 (0.01ms, 10.1MB)
# 테스트 24 〉	통과 (0.01ms, 10.2MB)