/* 깊이/너비 우선 탐색(DFS/BFS) > 타겟 넘버 문제풀이 (#4)
출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges */

#include <vector>

using namespace std;

int search_dfs(vector<int>& numbers, const int position, const int accumulation, const int target)
{
    if (position == numbers.size()) return (accumulation == target) ? 1 : 0;
    
    const int current = numbers.at(position);

    return search_dfs(numbers, position + 1, accumulation - current, target) + 
        search_dfs(numbers, position + 1, accumulation + current, target);
}

int solution(vector<int> numbers, int target) {
    return search_dfs(numbers, 0, 0, target);
}

/*
테스트 1 〉	통과 (5.64ms, 3.64MB)
테스트 2 〉	통과 (5.42ms, 4.18MB)
테스트 3 〉	통과 (0.01ms, 4.11MB)
테스트 4 〉	통과 (0.03ms, 4.12MB)
테스트 5 〉	통과 (0.31ms, 4.11MB)
테스트 6 〉	통과 (0.02ms, 3.64MB)
테스트 7 〉	통과 (0.01ms, 4.21MB)
테스트 8 〉	통과 (0.05ms, 4.11MB)
*/