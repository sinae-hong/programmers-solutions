/* 완전탐색 > 모의고사 문제풀이 (#3)
출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges */

#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    const vector<vector<int>> patterns({
        { 1, 2, 3, 4, 5},
        { 2, 1, 2, 3, 2, 4, 2, 5},
        { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    });
    // 문제에 주어진 값을 잘못 입력해서 한참 삽질했다. 주의!
    // initializer를 사용해서 깔끔하게 상수로 정의할 수 있다

    const unsigned int NUM_STUDENT = patterns.size();
    vector<int> scores(NUM_STUDENT, 0);
    
    for (auto student = 0; student < NUM_STUDENT; student++)
    {
        auto& pattern = patterns[student];
        for (auto problem = 0; problem < answers.size(); problem++)    
        {
            if (answers[problem] == pattern[problem % pattern.size()]) scores[student]++;
        }
    }
    
    // sort -> max_element로 대체
    auto score_highest = *max_element(scores.begin(), scores.end());
    vector<int> answer;

    // 값의 순서가 바뀌지 않으므로 index를 따로 저장할 필요가 없다. loop로 최댓값 여부 확인
    for (auto student = 0; student < NUM_STUDENT; student++)
    {
        if (scores[student] != score_highest) continue;
        answer.push_back(student + 1);
    }

    return answer;
}

/*
정확성 테스트 결과
    테스트 1 〉	통과 (0.01ms, 4.03MB)
    테스트 2 〉	통과 (0.01ms, 3.69MB)
    테스트 3 〉	통과 (0.01ms, 3.72MB)
    테스트 4 〉	통과 (0.01ms, 3.67MB)
    테스트 5 〉	통과 (0.01ms, 3.56MB)
    테스트 6 〉	통과 (0.01ms, 4.08MB)
    테스트 7 〉	통과 (0.16ms, 3.79MB)
    테스트 8 〉	통과 (0.06ms, 4.16MB)
    테스트 9 〉	통과 (0.29ms, 4.14MB)
    테스트 10 〉	통과 (0.14ms, 4.09MB)
    테스트 11 〉	통과 (0.33ms, 4.1MB)
    테스트 12 〉	통과 (0.26ms, 3.83MB)
    테스트 13 〉	통과 (0.03ms, 4.16MB)
    테스트 14 〉	통과 (0.24ms, 4.16MB)
*/