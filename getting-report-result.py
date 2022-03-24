# 신고 결과 받기 문제풀이 (#9)
# 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges

def solution(id_list, report, k):
    reportee_to_reporters = dict()
    answer = []
    for user in id_list:
        reportee_to_reporters[user] = set()
        answer.append(0)
    
    for str in report:
        pair = str.split()
        reporters = reportee_to_reporters[pair[1]]
        reporters.add(pair[0])
        
    for reporters in reportee_to_reporters.values():
        if len(reporters) >= k:
            for reporter in reporters:
                answer[id_list.index(reporter)] += 1
    
    return answer