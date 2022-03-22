/* 탐욕법 > 체육복 문제풀이 (#7)
출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges */

#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> clothes(n, 1);
    for (auto s : lost) clothes[s-1]--;
    for (auto s : reserve) clothes[s-1]++;

    int answer = n;

    for (auto s = 0; s < n; s++)
    {
        if (clothes[s] == 0)
        {
            if (s > 0 && clothes[s-1] == 2) continue;
            if (s < n && clothes[s+1] == 2)
            {
                clothes[s+1]--;
                continue;
            }
            
            answer--;
        }
    }
    
    return answer;
}