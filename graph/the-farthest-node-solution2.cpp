/* 그래프 > 가장 먼 노드 문제풀이 (#8)
BFS를 활용한 방식
출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges */

#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> neighbors(n + 1);
    for (auto& vertex : edge)
    {
        neighbors[vertex[0]].push_back(vertex[1]);
        neighbors[vertex[1]].push_back(vertex[0]);
    }

    vector<bool> visited(n + 1, false);
    vector<vector<int>> nodes_per_depth(1);
    nodes_per_depth[0].push_back(1);
    visited[1] = true;

    int depth = 0;
    for (; nodes_per_depth[depth].size() > 0; depth++)
    {
        nodes_per_depth.push_back(vector<int>());
        for (auto node : nodes_per_depth[depth])
        {
            for (auto neighbor : neighbors[node])
            {
                if (visited[neighbor]) continue;
                visited[neighbor] = true;
                nodes_per_depth[depth + 1].push_back(neighbor);
            }
        }
    }

    return nodes_per_depth[depth - 1].size();
}

/*
정확성  테스트
테스트 1 〉	통과 (0.01ms, 3.67MB)
테스트 2 〉	통과 (0.01ms, 4.18MB)
테스트 3 〉	통과 (0.02ms, 4.17MB)
테스트 4 〉	통과 (0.09ms, 4.11MB)
테스트 5 〉	통과 (0.48ms, 4.16MB)
테스트 6 〉	통과 (0.71ms, 4.4MB)
테스트 7 〉	통과 (5.49ms, 10.7MB)
테스트 8 〉	통과 (9.80ms, 14.2MB)
테스트 9 〉	통과 (8.08ms, 14.1MB)
*/