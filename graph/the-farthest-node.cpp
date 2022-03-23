/* 그래프 > 가장 먼 노드 문제풀이 (#8)
Dijkstra 알고리즘을 활용한 방식
출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges */

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> neighbors(n + 1);
    for (auto& vertex : edge)
    {
        neighbors[vertex[0]].push_back(vertex[1]);
        neighbors[vertex[1]].push_back(vertex[0]);
    }
    
    const int INF = 100000;
    vector<int> distance(n + 1, INF);
    distance[1] = 0;    // itself
    
    priority_queue<pair<int,int>> stopover;
    stopover.push({0, 1});
    
    while(stopover.empty() == false)
    {
        auto current_distance = -stopover.top().first;
        auto current_node = stopover.top().second;
        stopover.pop();
        
        for (auto& new_node : neighbors[current_node])
        {
            auto new_distance = current_distance + 1;
            if (distance[new_node] > new_distance)
            {
                distance[new_node] = new_distance;
                stopover.push({-new_distance, new_node});
            }
        }
    }
    
    auto max_distance = *max_element(distance.begin() + 1, distance.end());
    return count(distance.begin(), distance.end(), max_distance);
}

/*
정확성  테스트
테스트 1 〉	통과 (0.02ms, 4.15MB)
테스트 2 〉	통과 (0.02ms, 3.73MB)
테스트 3 〉	통과 (0.03ms, 4.11MB)
테스트 4 〉	통과 (0.08ms, 3.6MB)
테스트 5 〉	통과 (0.44ms, 4.08MB)
테스트 6 〉	통과 (0.76ms, 4.42MB)
테스트 7 〉	통과 (6.73ms, 10.6MB)
테스트 8 〉	통과 (16.91ms, 14MB)
테스트 9 〉	통과 (10.45ms, 14MB)
*/