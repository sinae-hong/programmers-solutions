# 스택/큐 > 다리를 지나는 트럭 문제풀이 (#16)
# 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges

def solution(bridge_length, weight, truck_weights):
    bridge = [0] * bridge_length + truck_weights
    answer = 0
    sum_weight = 0
    while bridge:
        try:
            next_truck = bridge[bridge_length]
        except:
            next_truck = 0
        sum_weight -= bridge[0]
        bridge = bridge[1:]
        if sum_weight + next_truck <= weight:
            sum_weight += next_truck
        else:
            bridge.insert(bridge_length-1, 0)
        answer += 1
    return answer