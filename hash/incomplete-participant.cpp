/* 해시 > 완주하지 못한 선수 문제풀이 (#2)
출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges */

#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    const auto NUM_PARTICIPANT = participant.size();
    vector<vector<string>> hash_table(NUM_PARTICIPANT);

    for (const auto& name : participant)
    {
        const auto key = hash<string>{}(name) % NUM_PARTICIPANT;
        hash_table[key].push_back(name);
    }

    for (const auto& name : completion)
    {
        const auto key = hash<string>{}(name) % NUM_PARTICIPANT;
        auto result = find(hash_table[key].begin(), hash_table[key].end(), name);
        hash_table[key].erase(result);
    }

    for (auto key = 0UL; key < NUM_PARTICIPANT; key++)
    {
        if (hash_table[key].size() != 0)
        {
            return hash_table[key][0];
        }
    }

    return "";
}
