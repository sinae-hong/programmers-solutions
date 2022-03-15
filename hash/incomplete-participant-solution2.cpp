/* 해시 > 완주하지 못한 선수 문제풀이 (#2)
출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges */

#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    const auto HASH_TABLE_SIZE = completion.size();
    vector<vector<string>> hash_table(HASH_TABLE_SIZE);

    for (const auto& name : completion)
    {
        const auto key = hash<string>{}(name) % HASH_TABLE_SIZE;
        hash_table[key].push_back(name);
    }

    for (const auto& name : participant)
    {
        const auto key = hash<string>{}(name) % HASH_TABLE_SIZE;
        auto result = find(hash_table[key].begin(), hash_table[key].end(), name);
        if (result == hash_table[key].end()) return name;
        hash_table[key].erase(result);
    }

    return "";
}

/*
정확성 테스트 결과
    테스트 1 〉	통과 (0.01ms, 3.64MB)
    테스트 2 〉	통과 (0.01ms, 4.18MB)
    테스트 3 〉	통과 (0.12ms, 4.12MB)
    테스트 4 〉	통과 (0.25ms, 4.17MB)
    테스트 5 〉	통과 (0.25ms, 4.12MB)
효율성 테스트 결과
    테스트 1 〉	통과 (13.04ms, 17.9MB)
    테스트 2 〉	통과 (21.83ms, 25MB)
    테스트 3 〉	통과 (24.08ms, 30MB)
    테스트 4 〉	통과 (26.06ms, 32.5MB)
    테스트 5 〉	통과 (33.86ms, 32.4MB)
*/
