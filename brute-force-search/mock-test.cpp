/* 완전탐색 > 모의고사 문제풀이 (#3)
출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges */

#include <utility>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> solution(vector<int> answers) {
    constexpr unsigned int NUM_STUDENT = 3;
    vector<pair<int,int>> scores;
    vector<int> pattern[NUM_STUDENT];
    pattern[0].assign({ 1, 2, 3, 4, 5});
    pattern[1].assign({ 2, 1, 2, 3, 2, 4, 2, 5});
    pattern[2].assign({ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5});
    // 문제에 주어진 값을 잘못 입력해서 한참 삽질했다. 주의!
    
    for (auto student = 0; student < NUM_STUDENT; student++)
    {
        const auto RECURRENT_CYCLE = pattern[student].size();
        int score_temp = 0;
        
        for (auto problem = 0; problem < answers.size(); problem++)
        {
            const auto pattern_index = problem % RECURRENT_CYCLE;
            if (answers[problem] == pattern[student][pattern_index]) score_temp++;
        }
        
        scores.push_back(make_pair(score_temp, student + 1));
    }
    
    sort(scores.begin(), scores.end());
    auto score_highest = scores.back().first;
    
    vector<int> answer;
    for (auto& score : scores)
    {
        if (score.first != score_highest) continue;
        answer.push_back(score.second);
    }

    return answer;
}

/*
정확성 테스트 결과
    테스트 1 〉	통과 (0.01ms, 4.18MB)
    테스트 2 〉	통과 (0.01ms, 4.16MB)
    테스트 3 〉	통과 (0.01ms, 4.16MB)
    테스트 4 〉	통과 (0.01ms, 4.18MB)
    테스트 5 〉	통과 (0.01ms, 4.11MB)
    테스트 6 〉	통과 (0.02ms, 4.17MB)
    테스트 7 〉	통과 (0.12ms, 4.19MB)
    테스트 8 〉	통과 (0.05ms, 4.18MB)
    테스트 9 〉	통과 (0.33ms, 4.17MB)
    테스트 10 〉	통과 (0.11ms, 4.12MB)
    테스트 11 〉	통과 (0.30ms, 4.1MB)
    테스트 12 〉	통과 (0.20ms, 4.17MB)
    테스트 13 〉	통과 (0.03ms, 4.04MB)
    테스트 14 〉	통과 (0.24ms, 4.07MB)
*/