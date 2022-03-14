/* 정렬 > K번째수 문제 첫번째 풀이
출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges */

#include <vector>
#include <utility>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (vector<int>& command : commands)
    {
        // 간단하게 assign operator로 복사 (deep copy 지원, array 크기가 작음)
        vector<int> array_sorted = array;
        
        const auto FIRST = command[0] - 1, LAST = command[1], TARGET = command[0] + command[2] - 2;
        for (auto position = FIRST; position <= TARGET; position++)
        {
            for (auto compare = position + 1; compare < LAST; compare++)
            {
                if (array_sorted[position] > array_sorted[compare])
                    // std library 활용
                    swap(array_sorted[position], array_sorted[compare]);
            }
        }
        
        answer.push_back(array_sorted[TARGET]);
    }
    
    return answer;
}
