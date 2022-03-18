/* 스택/큐 > 기능개발 문제풀이 (#5)
출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges */

#include <vector>

using namespace std;

int divide_round_up(int dividend, int divisor)
{
    return (dividend + (divisor - 1)) / divisor;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    auto fastest_day = 0;

    for (auto item = 0; item < progresses.size(); item++)
    {
        auto remaining_day = divide_round_up(100 - progresses[item], speeds[item]);
        
        if (fastest_day < remaining_day)
        {
            answer.push_back(1);
            fastest_day = remaining_day;
        }
        else
        {
            answer.back()++;
        }
    }

    return answer;
}

/*
테스트 1 〉	통과 (0.01ms, 3.63MB)
테스트 2 〉	통과 (0.01ms, 4.19MB)
테스트 3 〉	통과 (0.01ms, 4.18MB)
테스트 4 〉	통과 (0.01ms, 4.18MB)
테스트 5 〉	통과 (0.01ms, 4.18MB)
테스트 6 〉	통과 (0.01ms, 4.17MB)
테스트 7 〉	통과 (0.01ms, 3.59MB)
테스트 8 〉	통과 (0.01ms, 4.12MB)
테스트 9 〉	통과 (0.01ms, 4.11MB)
테스트 10 〉	통과 (0.01ms, 4.18MB)
테스트 11 〉	통과 (0.01ms, 3.68MB)
*/