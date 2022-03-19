/* 힙 > 더 맵게 문제풀이 (#6)
출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges */

#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> min_heap(scoville.begin(), scoville.end());
    
    while (min_heap.size() > 1)
    {
        auto smallest = min_heap.top();
        if (smallest >= K) return answer;
        
        min_heap.pop();
        auto second = min_heap.top();
        min_heap.pop();
        
        min_heap.push(smallest + 2 * second);
        answer++;
    }
    
    return (min_heap.top() >= K) ? answer : -1;
}

/*
정확성  테스트
    테스트 1 〉	통과 (0.01ms, 3.65MB)
    테스트 2 〉	통과 (0.01ms, 3.7MB)
    테스트 3 〉	통과 (0.01ms, 4.15MB)
    테스트 4 〉	통과 (0.01ms, 3.65MB)
    테스트 5 〉	통과 (0.01ms, 4.18MB)
    테스트 6 〉	통과 (0.08ms, 4.18MB)
    테스트 7 〉	통과 (0.06ms, 3.66MB)
    테스트 8 〉	통과 (0.01ms, 4.25MB)
    테스트 9 〉	통과 (0.01ms, 4.17MB)
    테스트 10 〉	통과 (0.06ms, 3.63MB)
    테스트 11 〉	통과 (0.04ms, 4.11MB)
    테스트 12 〉	통과 (0.14ms, 4.09MB)
    테스트 13 〉	통과 (0.06ms, 3.64MB)
    테스트 14 〉	통과 (0.02ms, 4.14MB)
    테스트 15 〉	통과 (0.11ms, 4.17MB)
    테스트 16 〉	통과 (0.01ms, 4.17MB)
효율성  테스트
    테스트 1 〉	통과 (26.81ms, 8.86MB)
    테스트 2 〉	통과 (54.48ms, 14MB)
    테스트 3 〉	통과 (229.32ms, 39.2MB)
    테스트 4 〉	통과 (21.23ms, 7.82MB)
    테스트 5 〉	통과 (242.20ms, 40.9MB)
*/